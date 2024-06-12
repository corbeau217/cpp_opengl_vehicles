# opengl_project_structurings

---
---
---

## About

* repo is a follow on from [opengl_learnables](https://github.com/corbeau217/opengl_learnables/)
* this repo will be an attempt to clean up some of the structure for larger projects
* whilst the other repo will be kept as a method of getting started (maybe later it can be for multiple platforms)
* some of the notes in this will be regarding usage of different functions and structuring of code in C++

---
---
---

## Contents

| SECTION | LINK |
| --- | --- |
| **Notes** | [[link]](#notes) |
| -> *including other files* | [[link]](#including-other-files) |
| -> *header files* | [[link]](#header-files) |
| -> ***classes*** | [[link]](#classes) |
| ---> *constructors* | [[link]](#class-constructor) |
| ---> *destructors* | [[link]](#class-destructor) |
| -> *input and output* | [[link]](#input-and-output) |
| -> *notes on inheritance* | [[link]](#notes-on-inheritance-and-control-flow) |
| -> *opengl bindings* | [[link]](#opengl-bindings) |
| **Changes from base** | [[link]](#changes-from-base) |

---
---
---

## Notes 

---
[[Contents]](#contents)

* please refer to the [opengl_learnables](https://github.com/corbeau217/opengl_learnables/) repo for detailed setup environment setup and references

---

### including other files

--- 
[[Contents]](#contents)

* C++ has a weird way of doing it, kinda inherited from C

---

#### including files example 1

let's suppose you have files `A`, `B`, and `C`:

```c++
// FILE A

// ABCD
// EFGH
// IJKL
```

```c++
// FILE B

// MNOP
// QRST
// UVWX
```

```c++
// FILE C

// Z123
// 4567
// 890-
```

you could then have a file `D`, that just includes all three, since there's no overlap in the code

```c++
// FILE D

#include "FILE_A.cpp"
#include "FILE_B.cpp"
#include "FILE_C.cpp"

// @!#$
// %^&*

```

to the compiler, this would result in a file it reads that looks like

```c++

// ABCD
// EFGH
// IJKL

// MNOP
// QRST
// UVWX

// Z123
// 4567
// 890-

// @!#$
// %^&*

```

if you were to instead order your imports as 

```c++
// FILE D

#include "FILE_C.cpp"
#include "FILE_B.cpp"
#include "FILE_A.cpp"

// @!#$
// %^&*

```

the end result would also change to be more like:


```c++

// Z123
// 4567
// 890-

// MNOP
// QRST
// UVWX

// ABCD
// EFGH
// IJKL

// @!#$
// %^&*

```

this begins to highlight one of the reasons we need header files

---

#### including files example 2

* sometimes when we have a very large project we want to include things in various places
* things like shared utilities etc

let's suppose this time we have files


```c++
// FILE MONCH

// BITE
// CHEW
// DIGEST
```

```c++
// FILE UTIL

// DO_SOME_MATH
// PRINT_A_THING
// EAT_A_PIE                [uses BITE/CHEW/DIGEST]
```

```c++
// FILE HUNGRY

// INFORM_THEM              [uses PRINT_A_THING]
// EAT_ALL_PIES             [uses EAT_A_PIE]
```

```c++
// FILE LUNCH

// EAT_A_SANDWICH           [uses BITE/CHEW/DIGEST]
// CALCULATE_PIES_NEEDED    [uses DO_SOME_MATH]
// SPEAK_AND_PRINT          [uses PRINT_A_THING]
```

now you've got files that require each other to function

the file `MONCH` is fine, it doesnt need anything so it can just exist
the file `UTIL` will need to include `MONCH` so you would just have something like:

```c++
// FILE UTIL
#include "MONCH.cpp"

// DO_SOME_MATH
// PRINT_A_THING
// EAT_A_PIE                [uses BITE/CHEW/DIGEST]
```

which results in 'unwrapped' file:

```c++
// FILE UTIL

// BITE
// CHEW
// DIGEST

// DO_SOME_MATH
// PRINT_A_THING
// EAT_A_PIE                [uses BITE/CHEW/DIGEST]
```

there's no issues there.
we move on to `HUNGRY`, which would need to include the `UTIL` file:


```c++
// FILE HUNGRY
#include "UTIL.cpp"

// INFORM_THEM              [uses PRINT_A_THING]
// EAT_ALL_PIES             [uses EAT_A_PIE]
```

and results in the 'unwrapped' file:

```c++
// FILE HUNGRY

// BITE
// CHEW
// DIGEST

// DO_SOME_MATH
// PRINT_A_THING
// EAT_A_PIE                [uses BITE/CHEW/DIGEST]

// INFORM_THEM              [uses PRINT_A_THING]
// EAT_ALL_PIES             [uses EAT_A_PIE]
```

now is where it gets dicey, the safe thing in `LUNCH` would be to include `HUNGRY` and then leave it at that, because now we get every one of the previous things only once
but, if we were in a real project, it's hard to keep track of which ones use what, so you often end up with something like:


```c++
// FILE LUNCH

#include "MONCH.cpp" // for EAT_A_SANDWICH
#include "UTIL.cpp" // for CALCULATE_PIES_NEEDED and SPEAK_AND_PRINT

// EAT_A_SANDWICH           [uses BITE/CHEW/DIGEST]
// CALCULATE_PIES_NEEDED    [uses DO_SOME_MATH]
// SPEAK_AND_PRINT          [uses PRINT_A_THING]
```

since this is a very simple example, it's noticeably how to resolve this, but the more files you add the quicker it is that you cant just resolve these issues easily
so we need some way to let the other files know about the functions or variables or even the classes, without repeating definitions and confusing the compiler.

ultimately when you say `BITE` you want it to only use the method that was defined within `MONCH`

---

### header files

---
[[Contents]](#contents)

* header files in C++ are a way of telling other parts of our code about our `bindings`/`symbols`/`functions`/`classes`/`methods`/etc in a way that doesnt cause redefinitions of our code
* additionally, header files solve one of the other issues with C++ which is that all functions need to be defined before they can be used
* this would mean that without header files, we're forced to constantly keep track of the order in which things are defined and who uses what, and map out the dependencies of every element of the project.
* instead we can just announce that the thing exists, and write out the full definition later 

to do this, we have a file:
```c++
// FILE_A.hpp

// existable_thing // [declaration/announcement]
```

then somewhere, usually the same folder and name, the definition of what that thing does
```c++
// FILE_A.cpp

// existable_thing { /* abcdef */ } // [definition]
```

this way, we can include the header file wherever and not risk repeating ourselves, and even announce the function for use before we're ready to give it substance

* something to note is that, without the use of preprocessor functions, we'll still run into the same issues so a common method of getting around this is to wrap the header file in a `ifndef` expression, then inside defining the variable you check for like so:

```c++
// FILE_A.hpp
#ifndef FILE_A_HPP
#define FILE_A_HPP

// existable_thing [declaration]

#endif
```

* this means that only when the `FILE_A_HPP` isnt defined, that it'll declare/announce `existable_thing`, otherwise it'll do nothing and skip it entirely.
* this way works well and is fine and all, but the preprocessor naming bloat can be a real headache, especially if you have files with the same name, and we're living in `insert-current-year`, so we have access to the newer way to do things `#pragma once`
* it's important to know there's some wackiness with backwards compatibility, but like apple with 32 bit support, we dont care about backwards compatibility (rip tf2 on macOS, you will be missed)

this ends up with the really neat:
```c++
// FILE_A.hpp
#pragma once

// existable_thing [declaration]
```

and protects us from redeclaring methods in our code

---

### classes

---
[[Contents]](#contents)

#### class constructor

* class constructors are methods inside the class declaration with the same name as the class
* they're also missing a return type
* however you need to make sure they're placed within the class's code block and that they're within the region of that code block for the visibility you want
* also for some reason classes have a semicolon at the end of their code block / definition scope

if i wanted public access to the constructor i could put it like:
```c++
class MyClass {
    public:
        // public stuff here
        MyClass(){
            // ...
        }
        // public stuff here
    private:
        // private stuff here
};
```
if instead i wanted private access:
```c++
class MyClass {
    public:
        // public stuff here
    private:
        // private stuff here
        MyClass(){
            // ...
        }
        // private stuff here
};
```

#### class destructor

* almost entirely the same as the constructor in the way it's defined, however you cant specify and 'formal parameters' for it `no parameters in the round brackets`
* it also has a little `~` right before the name
* there is some weirdness that happens with making a destructor private, but this appears to be for controlling who can destroy the dynamically created objects

an example of a destructor definition:
```c++
class MyClass {
    public:
        // public stuff here
        MyClass(){
            // ... create stuff here
        }
        ~MyClass(){
            // ... destroy stuff here
        }
        // public stuff here
    private:
        // private stuff here
};
```

it's important to note that you should destroy things created by the constructor in the reverse of the order they were created

### input and output

---
[[Contents]](#contents)

* pain and suffering idk

### notes on inheritance and control flow

---
[[Contents]](#contents)

#### Scene graph

* needs to be a tree (non binary as a node could have more than 2 children)
* will need backtracking to get `modelToWorldMatrix`
* will use an expandable list for the child nodes
    * probably just using [`vector`](https://cplusplus.com/reference/vector/vector/) rather than reinventing the wheel
    * *almost ended up making something similar to flash memory in a kind of train car fashion*
        * *each block could be like, 10 or 14 for the neat ness*
            * *the first could be the parent reference or the `head` carriage element*
            * *the last could be `next carriage` element*
            * *every other element is an item in the list*
            * *using structs*
            * *would also make this able to be done concurrently (each car a thread)*
        * *could also steal the direct/indirect/double indirect/triple indirect style to handle them*
            * *improves storage management requiring decreasing reorganising operations*
        * *somehow would need to merge that with quad or oct trees*
            * *to improve search speeds and only accessing elements that are necessary*
* aaaa?

### transformations of matrices

---
[[Contents]](#contents)

* [an excellent write up](https://jsantell.com/model-view-projection/) of the different transformations with great diagrams (we should get some of those tbh)

```
------------------------------------------------------

T = translation
R = rotation
S = scale

------------------------------------------------------

M = T * R * S
ModelMatrix = ModelTranslation * ModelRotation * ModelScale

vWrld = M * vMdl
vertexWorld = ModelMatrix * vertexModel

vCam = V * M * vMdl
vCam = V * vWrld
vertexCamera = ViewMatrix * ModelMatrix * vertexModel

vClp = P * V * M * vMdl
vClp = P * V * vWrld
vClp = P * vCam
vertexClip = PerspectiveMatrix * ViewMatrix * ModelMatrix * vertexModel

------------------------------------------------------

cameraT = cameraTranslation
cameraR = cameraRotation
cameraS = cameraScale

matrixCameraToWorld = cameraT * cameraR * cameraS

matrixWorldToCamera = matrixCameraToWorld^-1
matrixWorldToCamera = cameraS^-1 * cameraR^-1 * cameraT^-1

matrixWorldToCamera = P * V

P = cameraS^-1
V = cameraR^-1 * cameraT^-1

------------------------------------------------------
```

* model stuff has a negative Z value to the camera???
* also the w value is wonky? they divide the xyz by the w? huh
    * oh to go to cartesian from homogenous
* also [this one has some cool diagrams](https://www.songho.ca/opengl/gl_projectionmatrix.html)

### opengl bindings

---
[[Contents]](#contents)

* big think

---
---
---

## Changes from base

---
[[Contents]](#contents)

* `07/06/2024` - changed to using the `App` object for handling the main structure
    * currently it's a little wonky, but it takes everything out of `main.cpp`
    * `framebuffer_size_callback` is declared static right now to make the program happy, so we'll need to make the `App` use singleton pattern
* `07/06/2024` - changed the `App` object to have a `Scene` object to handle the drawing and shader data
* `07/06/2024` - moved shader library stuff to be handled by `ShaderHandle` namespace
* `08/06/2024` - began scene objects
* `08/06/2024` - began integration of matrices/coordinate frames
* `08/06/2024` - focusing on scene graph
* `09/06/2024` - finished the scene graph
* `10/06/2024` - focusing on matrices
* `10/06/2024` - focusing on camera
* `10/06/2024` - camera done, need to give matrix to shaders
* `10/06/2024` - need delta time
* `10/06/2024` - delta time implemented
* `10/06/2024` - matrices given to shader, just a bit goofy


---
---
---

