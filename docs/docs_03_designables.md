# DOCS 03 : Designs and details

---
---

## Doc links

Documentation page links:
* [**[readme]**](./readme.md#doc-links)
* [**[docs 00 : overview]**](./docs_00_overview.md#doc-links)
* [**[docs 01 : conceptual]**](./docs_01_conceptual.md#doc-links)
* [**[docs 02 : requirements]**](./docs_02_requirements.md#doc-links)
* [***[docs 03 : designables]***](./docs_03_designables.md#doc-links)
    * [**[docs 03 : designables : render texture experimenting]**](./docs_03_designables_experiments_01.md#doc-links)
* [**[docs 04 : developments]**](./docs_04_developments.md#doc-links)

---

## About

* much detail will happen
* will include the full uml hopefully

---

## Contents

* [***[Pre-Design stage checklist]***](#pre-design-stage-checklist)
* [***[Compilation pipeline]***](#compilation-pipeline)
* [***[C++ compilation and linking]***](#c-compilation-and-linking)
    * [*[C++ compilation and linking [draft 01]]*](#c-compilation-and-linking-draft-01)
    * [*[C++ compilation and linking [draft 02]]*](#c-compilation-and-linking-draft-02)
    * [*[C++ compilation and linking [draft 03]]*](#c-compilation-and-linking-draft-03)
    * [*[C++ compilation and linking [draft 04]]*](#c-compilation-and-linking-draft-04)
* [***[Project render flow]***](#project-render-flow)
    * [*[Project render flow [draft 01]]*](#project-render-flow-draft-01)
* [***[Model diagrams]***](#model-diagrams)
* [***[Library documentation]***](#library-documentation)
    * [*[Library references : Github repos]*](#library-references--github-repos)
    * [*[Library references : GLFW]*](#library-references--glfw)
    * [*[Library references : GLAD]*](#library-references--glad)
    * [*[Library references : GLM]*](#library-references--glm)
    * [*[Library references : OpenGL pipeline [draft 01]]*](#library-references--opengl-pipeline-draft-01)
    * [*[Library references : template repo structure [draft 01]]*](#library-references--template-repo-structure-draft-01)
* [***[General references]***](#general-references)
    * [*[General references : Markdown badges]*](#general-references--markdown-badges)
    * [*[General references : Design patterns]*](#general-references--design-patterns)
        * [[General references : Design patterns : adapter pattern]](#general-references--design-patterns--adapter-pattern)
        * [[General references : Design patterns : command pattern]](#general-references--design-patterns--command-pattern)
        * [[General references : Design patterns : facade pattern]](#general-references--design-patterns--facade-pattern)
        * [[General references : Design patterns : mediator pattern]](#general-references--design-patterns--mediator-pattern)
        * [[General references : Design patterns : observer pattern]](#general-references--design-patterns--observer-pattern)
        * [[General references : Design patterns : singleton pattern]](#general-references--design-patterns--singleton-pattern)
        * [[General references : Design patterns : state pattern]](#general-references--design-patterns--state-pattern)
        * [[General references : Design patterns : strategy pattern]](#general-references--design-patterns--strategy-pattern)

---

## Pre-design stage checklist

* [x] - `PDDR_01` - ~~Required fields~~
    * *~~Required data held by our objects~~*
* [x] - `PDDR_02` - ~~suggested design patterns for actors/objects~~
    * *~~proposed design patterns~~*
* [x] - `PDDR_03` - ~~listing deadlock avoidance methods~~
    * *~~a list of the deadlock avoidance methods that work for our system~~*
* [x] - `PDDR_04` - ~~simple architectural diagrams for our system~~
    * *~~to show how the actors/object connect to each other and make sure we're not doing spooky design choices sooner rather than later~~*
* [x] - `PDDR_05` - ~~reorganise documentation~~
    * *~~putting things in the correct documentation files~~*
* [x] - `PDDR_06` - ~~requirement dependency map~~
    * *~~mapped out requirement dependencies~~*
* [x] - `PDDR_07` - ~~importance of requirements~~
    * *~~importance of each requirement~~*
* [x] - `PDDR_08` - ~~risk mapping~~
    * *~~risk assessment for work required for a thing to function (and how likely to get it working first try) in relation to importance~~*
* [x] - `PDDR_09` - ~~checklist table for all the requirements~~
    * *~~somewhere having a checklist for our requirements so we can tick off what's complete~~*
* [x] - `PDDR_10` - ~~concept diagrams of models in documentation~~
    * *~~adding the various model concept diagram drafts to the documentation~~*

---

## Compilation pipeline

[***[back to Contents]***](#contents)

* pipeline for compilation

```mermaid
---
title: compilation pipeline
---
flowchart LR
    subgraph FRONTEND
    LEXER --> PARSER --> TYPECHECKER
    end
    subgraph BACKEND
    ANALYSIS --> OPTIMIZATION --> CODEGEN
    end
    FRONTEND ==> BACKEND
    TYPECHECKER -.-> ANALYSIS
```
```mermaid
---
title: compilation pipeline
---
flowchart 
    SOURCECODE{{Input Source Code}}
    SOURCECODE --> LEXICALANALYZER
    subgraph ANALYSIS[Source . . . Analysis]
    LEXICALANALYZER[Lexical Analyzer]
    SYNTAXANALYZER[Syntax Analyzer]
    SEMANTICANALYZER[Semantic Analyzer]
    LEXICALANALYZER ==> SYNTAXANALYZER ==> SEMANTICANALYZER
    end
    subgraph SYNTHESIS[Output . . . Synthesis]
    INTERMEDIATECODEGEN[Intermediate Code Generator]
    CODEOPTIMIZATION[Code Optimizer]
    TARGETCODEGEN[Target Code Generator]
    INTERMEDIATECODEGEN ==> CODEOPTIMIZATION ==> TARGETCODEGEN
    end
    TARGETCODE{{Target Code Output}}
    SEMANTICANALYZER ==> INTERMEDIATECODEGEN
    TARGETCODEGEN --> TARGETCODE
```


## C++ compilation and linking

### C++ compilation and linking [draft 01]

[***[back to Contents]***](#contents)

* possibly wrong, may need correcting later

```mermaid
---
title: C++ compilation and linking draft 01
---
flowchart LR
    subgraph CODE
    CODECPP[[.cpp File]]
    CODEC[[.c File]]
    CODEHPP[[.hpp File]]
    end
    
    CODEHPP --> CODECPP --> CODEC

    subgraph ASSEMBLYCODE
    ASMFILE[[.asm File]]
    end
    
    subgraph OBJECTCODE
    OBJFILE[[.o File]]
    end
    
    CODE == translated to ==> ASSEMBLYCODE == translated to ==> OBJECTCODE

    subgraph LIBCODE
    ARCHIVEFILE[[.a File]]
    DLLFILE[[.dll File]]
    end

    subgraph EXECUTABLECODE
    EXECFILE[[.out file]]
    end

    ARCHIVER{Archiver}
    EXECBUILDLINKER{Linker}

    OBJECTCODE == built to architecture ==> EXECBUILDLINKER
    OBJECTCODE == referenced for ==> ARCHIVER
    ARCHIVER == generates ==> LIBCODE
    LIBCODE == used to build ==> EXECBUILDLINKER

    EXECBUILDLINKER == generates ==> EXECUTABLECODE

    LIBCODE -. used to run .-> EXECUTABLECODE
```

### C++ compilation and linking [draft 02]

[***[back to Contents]***](#contents)

* version 2, idk

```mermaid
---
title: C++ compilation and linking draft 02
---
flowchart LR
    SOURCEFILE{{<i>Source File</i><br><b><code>.c</code>, <code>.cpp</code>, <code>.h</code>, <code>.hpp</code></b>}}
    PREPROCESSOR[<i>Pre-Processor</i><br><b><code>cpp</code></b>]
    PREPROCESSEDFILE[/<i>Preprocessed File</i><br><b><code>.i</code>, <code>.ii</code></b>/]
    COMPILER[<i>Compiler</i><br><b><code>gcc</code>, <code>g++</code></b>]
    ASSEMBLYFILE[/<i>Assembly File</i><br><b><code>.s</code></b>/]
    ASSEMBLER[<i>Assembler</i><br><b><code>as</code></b>]
    OBJECTFILE[/<i>Object File</i><br><b><code>.o</code></b>/]
    LINKER[<i>Linker</i><br><b><code>ld</code></b>]
    STATICLIBRARY{{<i>Static Library</i><br><b><code>.lib</code>, <code>.a</code></b>}}
    EXECUTABLEFILE{{<i>Executable File</i><br><b><code>.exe</code>, <code>.out</code></b>}}

    SOURCEFILE -.-> PREPROCESSOR ==> PREPROCESSEDFILE -.-> COMPILER
    COMPILER ==> ASSEMBLYFILE -.-> ASSEMBLER ==> OBJECTFILE -.-> LINKER
    STATICLIBRARY -.-> LINKER ==> EXECUTABLEFILE
```

### C++ compilation and linking [draft 03]

[***[back to Contents]***](#contents)

* version 3, idk

```mermaid
---
title: C++ compilation and linking draft 03
---
flowchart
    subgraph CODE
    SOURCECODE{{Source code<br><code>.c</code> file}}
    ASSEMBLYCODE{{Assembly code}}
    OBJECTCODE{{Object code}}
    end
    subgraph COMPILATION
    PREPROCESSOR[[Preprocessor]]
    COMPILER[[Compiler]]
    ASSEMBLER[[Assembler]]
    LINKER[[Linker]]
    end
    subgraph LIBRARY
    LIBRARIES{{Libraries}}
    end

    SOURCECODE --> PREPROCESSOR
    PREPROCESSOR --> COMPILER
    COMPILER --> ASSEMBLYCODE --> ASSEMBLER
    LIBRARIES --> LINKER
    ASSEMBLER --> OBJECTCODE --> LINKER
```

### C++ compilation and linking [draft 04]

[***[back to Contents]***](#contents)

* version 4, idk

```mermaid
---
title: C++ compilation and linking draft 04
---
flowchart LR
    subgraph SOURCECODE
    HEADERFILE01{{<code>.h</code>}}
    HEADERFILE02{{<code>.hpp</code>}}
    SOURCEFILE01{{<code>.cpp</code>}}
    SOURCEFILE02{{<code>.cpp</code>}}
    HEADERFILE03{{<code>.h</code>}}
    SOURCEFILE03{{<code>.cpp</code>}}
    end
    PREPROCESSOR01((Pre-processor))
    PREPROCESSOR02((Pre-processor))
    PREPROCESSOR03((Pre-processor))
    subgraph MERGEDCODE
    MERGEDTEMPFILE01[Temp file<br><b>.ii</b>]
    MERGEDTEMPFILE02[Temp file<br><b>.ii</b>]
    MERGEDTEMPFILE03[Temp file<br><b>.ii</b>]
    end
    COMPILER01((Compiler))
    COMPILER02((Compiler))
    COMPILER03((Compiler))
    subgraph ASSEMBLYCODE
    ASSEMBLYCODE01[Assembly code<br><b>.s</b>]
    ASSEMBLYCODE02[Assembly code<br><b>.s</b>]
    ASSEMBLYCODE03[Assembly code<br><b>.s</b>]
    end
    ASSEMBLER01((Assembler))
    ASSEMBLER02((Assembler))
    ASSEMBLER03((Assembler))
    subgraph MACHINECODE
    OBJECTFILE01[Object file<br><b>.o</b>]
    OBJECTFILE02[Object file<br><b>.o</b>]
    OBJECTFILE03[Object file<br><b>.o</b>]
    end
    subgraph ENVFILES
    DYNAMICRUNTIMELIB01[Runtime lib]
    STATICLINKINGLIB01[static lib]
    STATICLINKINGLIB02[static lib]
    end
    subgraph LINKING
    LINKER((Linker))
    end
    subgraph PROGRAM
    EXEFILE[<b>exe</b>]
    end

    HEADERFILE01 --> PREPROCESSOR01
    HEADERFILE02 --> PREPROCESSOR01
    HEADERFILE03 --> PREPROCESSOR03
    SOURCEFILE01 --> PREPROCESSOR01 --> MERGEDTEMPFILE01 --> COMPILER01 --> ASSEMBLYCODE01 --> ASSEMBLER01 --> OBJECTFILE01 -----> LINKER
    SOURCEFILE02 --> PREPROCESSOR02 --> MERGEDTEMPFILE02 --> COMPILER02 --> ASSEMBLYCODE02 --> ASSEMBLER02 --> OBJECTFILE02 -----> LINKER
    SOURCEFILE03 --> PREPROCESSOR03 --> MERGEDTEMPFILE03 --> COMPILER03 --> ASSEMBLYCODE03 --> ASSEMBLER03 --> OBJECTFILE03 -----> LINKER

    DYNAMICRUNTIMELIB01 -..-> EXEFILE
    DYNAMICRUNTIMELIB01 --> LINKER
    STATICLINKINGLIB01 --> LINKER
    STATICLINKINGLIB02 --> LINKER
    LINKER --> EXEFILE


```

---

## project render flow

### project render flow [draft 01]

[***[back to Contents]***](#contents)

```mermaid
---
title: project rendering flow
---
flowchart LR
    %% ==============================
    CONTROLLER_STATE[Controller]
    DIAGNOSTIC_RENDER_BUFFER[(Diagnositics<br>render<br>buffer)]
    DIAGNOSTIC_SCREEN_MESH(Diagnostic<br>screen<br>mesh)
    CAR_MESH(Car<br>mesh)
    TERRAIN_MESH(Terrain<br>mesh)
    LIGHTS_MESH(LIGHTS<br>mesh)
    PERLIN_NOISE{{Perlin<br>noise}}
    CLOUD_RENDER_BUFFER[(Cloud<br>render<br>buffer)]
    SKYBOX_CUBEMAP(Skybox<br>cubemap)
    APP_WINDOW[[Application<br>window]]
    %% ------------------------
    CONTROLLER_STATE -.-> DIAGNOSTIC_RENDER_BUFFER -.-> DIAGNOSTIC_SCREEN_MESH
    %% ------------------------
    PERLIN_NOISE -.-> CLOUD_RENDER_BUFFER -.-> SKYBOX_CUBEMAP
    %% ------------------------
    CAR_MESH --> APP_WINDOW
    TERRAIN_MESH --> APP_WINDOW
    LIGHTS_MESH --> APP_WINDOW
    SKYBOX_CUBEMAP --> APP_WINDOW
    DIAGNOSTIC_SCREEN_MESH --> APP_WINDOW
    %% ==============================
```

---

## Model diagrams

[***[back to Contents]***](#contents)

* this is where we put the diagrams for building the model

### Model diagrams : Vehicles

* Vehicle diagrams

#### Model diagrams : Vehicles : Notes

* something to note is that they should be made from squishing a sphere and flattening one for the most part


---

## Library documentation

### Library references : Github repos

[***[back to Contents]***](#contents)

* [![GLAD GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLAD)](https://github.com/Dav1dde/glad)
    * text heavy documentation in wiki sub section
    * [main documentation page](https://github.com/Dav1dde/glad/wiki/C)
    * [cmake building from source](https://github.com/Dav1dde/glad/wiki/C#cmake)

* [![GLFW GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLFW)](https://github.com/glfw/glfw)
    * has links to extensive documentation with graphics
    * [notes about `glfwCreateWindow` on MacOS X 10.7 and later](https://www.glfw.org/docs/latest/compat_guide.html#compat_osx)
    * [compiling and building documentation reference](https://www.glfw.org/docs/latest/compile_guide.html)
        * [cmake building and linking from source](https://www.glfw.org/docs/latest/build_guide.html#build_link_cmake_source)

* [![GLM GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLM)](https://github.com/g-truc/glm)
    * has information on the cmake building
    * documentation is very text / code heavy
    * documentation uses doxygen

### Library references : GLFW

[***[back to Contents]***](#contents)

* [[GLFW quick guide]](https://www.glfw.org/docs/latest/quick_guide.html)
* [[GLFW intro to API]](https://www.glfw.org/docs/latest/intro_guide.html)
    * [[GLFW window guide]](https://www.glfw.org/docs/latest/window_guide.html)
    * [[GLFW context guide]](https://www.glfw.org/docs/latest/context_guide.html)
    * [[GLFW monitor guide]](https://www.glfw.org/docs/latest/monitor_guide.html)
    * [[GLFW input guide]](https://www.glfw.org/docs/latest/input_guide.html)
    * [[GLFW compile guide]](https://www.glfw.org/docs/latest/compile_guide.html)
    * [[GLFW build guide]](https://www.glfw.org/docs/latest/build_guide.html)

### Library references : GLAD

[***[back to Contents]***](#contents)

* lorem ipsum

### Library references : GLM 

[***[back to Contents]***](#contents)

* lorem ipsum

### Library references : OpenGL pipeline [draft 01]

[***[back to Contents]***](#contents)

* minimalist diagram to illustrate the pipeline process
* [khronos page for the rendering pipeline](https://www.khronos.org/opengl/wiki/Rendering_Pipeline_Overview)
* [this github pages page seems useful](https://kenny-designs.github.io/zim-websites/opengl/Shaders_and_the_Rendering_Pipeline.html)

```mermaid
flowchart TB
    %% ==============================
    APP[Application<br><i>Vertex specification</i>]
    %% ------------------------
    VERTEXSHADER(<i>-programmable-</i><br>Vertex Shader)
    RASTERISATION{{Rasterisation}}
    FRAGMENTSHADER(<i>-programmable-</i><br>Fragment Shader)
    FRAMEBUFFEROPERATIONS{{Frame buffer operations}}
    %% ------------------------
    DISPLAY[Display]
    %% ==============================
    APP --> VERTEXSHADER --> RASTERISATION --> FRAGMENTSHADER --> FRAMEBUFFEROPERATIONS --> DISPLAY
    %% ==============================
```

### Library references : template repo structure [draft 01]

[***[back to Contents]***](#contents)

```mermaid
---
title: base program rendering flow
---
flowchart LR
    %% ==============================
    INT_MAIN ====> APP_APP
    APP_APP ==> SCENE_SCENE
    %% ------------------------
    INT_MAIN ----- APP_DEAPP
    APP_DEAPP --- SCENE_DESCENE
    %% ==============================
    APP_RUN ---> APP_INIT
    APP_INIT --> SCENE_INIT
    %% ------------------------
    APP_UPDATE --> SCENE_UPDATE
    SCENE_UPDATE --> SCENE_UPDATESELF
    %% ------------------------
    APP_DRAW ---> SCENE_DRAW
    SCENE_DRAW --> SCENE_GETWORLDTOCAMERAMATRIX
    SCENE_DRAW --> SCENE_DRAWSELF
    %% ==============================
    subgraph main.cpp
    INT_MAIN{{"main<br><i>int main(int,char**)</i>"}}
    end
    %% ==============================
    subgraph App.hpp
    %% ------------------------
    subgraph App_namespace["namespace App"]
    %% ------------------------
    APP_APP{{"App::App<br><i>App::App(int,int)</i>"}}
    APP_DEAPP{{"App::~App<br><i>App::~App()</i>"}}
    APP_RUN{{"App::run<br><i>int App::run()</i>"}}
    APP_INIT{{"App::init<br><i>int App::init()</i>"}}
    APP_RUNLOOP{render loop}
    subgraph app_render_loop["while( !glfwWindowShouldClose(window) )"]
    %% ------------------------
    APP_PREPAREFRAME{{"App::prepareFrame<br><i>void App::prepareFrame()</i>"}}
    APP_PROCESSINPUT{{"App::processInput<br><i>void App::processInput(GLFWwindow*)</i>"}}
    APP_UPDATE{{"App::update<br><i>void App::update()</i>"}}
    APP_DRAW{{"App::draw<br><i>void App::draw()</i>"}}
    APP_PUSHCHANGES{{"App::pushChanges<br><i>void App::pushChanges()</i>"}}
    %% ------------------------
    %% end of app_render_loop
    end
    %% ------------------------
    %% end of App_namespace
    end
    %% ------------------------
    %% end of App.hpp
    end
    %% ==============================
    INT_MAIN --> APP_RUN
    APP_RUN --> APP_RUNLOOP
    %% ------------------------
    APP_RUNLOOP --> APP_PREPAREFRAME
    APP_RUNLOOP --> APP_PROCESSINPUT
    APP_RUNLOOP --> APP_UPDATE
    APP_RUNLOOP --> APP_DRAW
    APP_RUNLOOP --> APP_PUSHCHANGES
    %% ==============================
    subgraph Scene.hpp
    %% ------------------------
    subgraph Scene_namespace
    %% ------------------------
    SCENE_SCENE{{"Scene::Scene"}}
    SCENE_DESCENE{{"Scene::~Scene"}}
    SCENE_INIT{{"Scene::init"}}
    SCENE_UPDATE{{"Scene::update"}}
    SCENE_UPDATESELF{{"Scene::updateSelf"}}
    SCENE_DRAW{{"Scene::draw"}}
    SCENE_DRAWSELF{{"Scene::drawSelf"}}
    SCENE_GETWORLDTOCAMERAMATRIX{{"Scene::getWorldToCameraMatrix"}}
    %% SCENE_GETMODELTOWORLDMATRIX{{"Scene::getModelToWorldMatrix"}}
    %% SCENE_SETMODELMATRIX{{"Scene::setModelMatrix"}}
    %% SCENE_SETPARENT{{"Scene::setParent"}}
    %% SCENE_ADDCHILD{{"Scene::addChild"}}
    %% ------------------------
    %% end of Scene_namespace
    end
    %% ------------------------
    %% end of Scene.hpp
    end
    %% ==============================
    %% ------------------------
    %% ==============================
```

---

## General references

### General references : Markdown badges

[***[back to Contents]***](#contents)

* [repo with a list of the badge sources](https://github.com/alexandresanlim/Badges4-README.md-Profile)
* [page with details about parameters](https://shields.io/badges/static-badge)

### General references : Design patterns

* [Refactoring guru design patterns catalogue](https://refactoring.guru/design-patterns/catalog)
* the design patterns suggested in requirements:
    * [adapter pattern](https://refactoring.guru/design-patterns/adapter)
    * [command pattern](https://refactoring.guru/design-patterns/command)
    * [facade pattern](https://refactoring.guru/design-patterns/facade)
    * [mediator pattern](https://refactoring.guru/design-patterns/mediator)
    * [observer pattern](https://refactoring.guru/design-patterns/observer)
    * [state pattern](https://refactoring.guru/design-patterns/state)
    * [strategy pattern](https://refactoring.guru/design-patterns/strategy)

#### General references : Design patterns : adapter pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/adapter">[refactoring.guru] adapter pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td><b>Also known as:</b></td>
<td><i>Wrapper</i></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>Adapter</b> is a structural design pattern that allows objects with incompatible interfaces to collaborate
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/adapter/adapter-en-2x.png?id=e0ab0f6103b0b7b0648a8fda592ffab8" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
flowchart TB
    NOTE02["<b><i><code>2.</code></i></b> The <b>Client Interface</b> describes a\nprotocol that other classes must\nfollow to be able to collaborate\nwith the client code"]
    NOTE03["<b><i><code>3.</code></i></b> The <b>Service</b> is some useful\nclass (usually 3rd-party or\nlegacy). The client can't use\nthis class directly because it\nhas an incompatible interface."]
```
```mermaid
classDiagram
    direction LR
    note "<b><i><code>1.</code></i></b> The <b>Client</b> is a class\nthat contains the\nexisting business\nlogic of the program"

    class Client
    class ClientInterface["Client Interface"]{
        <<interface>>
        +method(data)
    }
    class Adapter{
        -adaptee Service
        +method(data)
    }
    note for Adapter "specialData = convertToServiceFormat(data)\n<b>return</b> adaptee.serviceMethod(specialData)"
    class Service{
        ...
        +serviceMethod(specialData)
    }
    Client --> ClientInterface
    Adapter ..|> ClientInterface
    Adapter --> Service
```
```mermaid
flowchart TB
    NOTE05["<b><i><code>5.</code></i></b> The client code doesn't get\ncoupled to the concrete adapter\nclass as long as it works with the\nadapter via the client interface.\nThanks to this, you can introduce\nnew types of adapters into the\nprogram without breaking the\nexisting client code. This can be\nuseful when the interface of the\nservice class gets changed or\nreplaced: you can just create a\nnew adapter class without\nchanging the client code."]
    NOTE04["<b><i><code>4.</code></i></b> The <b>Adapter</b> is a class that's able to work with both the client\nand the service: it implements the client interface, while\nwrapping the service object. The adapter receives calls from the\nclient via the client interface and translates them into calls to\nthe wrapped service object in a format it can understand."]
```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : command pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/command">[refactoring.guru] command pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td><b>Also known as:</b></td>
<td><i>Action, Transaction</i></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>Command</b> is a behavioural design pattern that turns a request into a stand-alone object that contains all information about the request. This transformation lets you pass requests as a method arguments, delay or queue a request's execution and support undoable operations.
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/command/command-en-2x.png?id=6149af804cbbbd5cb18595c30b856d89" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction TB
    class Client
    class Invoker{
        -command
        +setCommand(command)
        +executeCommand()
    }
    class Command{
        <<interface>>
        +execute()
    }
    class Receiver {
        ...
        +operation(a,b,c)
    }
    class ConcreteCommand1{
        -receiver
        -params
        +Command1(receiver,params)
        +execute()
    }
    class ConcreteCommand2{
        +execute()
    }
    Command <|.. ConcreteCommand1
    Command <|.. ConcreteCommand2
    Client ..> ConcreteCommand1
    Client --> Receiver
    Receiver --> ConcreteCommand1 :  aaa
    Client --> Invoker
    Invoker --> Command

```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : facade pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/facade">[refactoring.guru] facade pattern</a></th>
</tr>
<tr>
<td>Intent</td>
<td><b>Facade</b> is a structural design pattern that provides a simplified interface to a library, a framework, or any other complex set of classes
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/facade/facade-2x.png?id=b69fce5943703f5f07c0ba38e3baaed0" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction LR
    class Client
```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : mediator pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/mediator">[refactoring.guru] mediator pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td><b>Also known as:</b></td>
<td><i>Intermediary, Controller</i></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>Mediator</b> is a behavioral design pattern that lets you reduce chaotic dependencies between objects. The pattern restricts direct communications between the objects and forces them to collaborate only via a mediator object.
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/mediator/mediator-2x.png?id=250c2bf72ca1fdee2e6d97ed5a4765f2" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction TB

    class ComponentC
    class ComponentA
    class ConcreteMediator
    class Mediator{
        <<interface>>
    }
    class ComponentB
    class ComponentD

    ComponentC --> Mediator
    ComponentA --> Mediator
    ConcreteMediator *--> ComponentC
    ConcreteMediator *--> ComponentA
    ConcreteMediator ..|> Mediator
    ConcreteMediator *--> ComponentB
    ConcreteMediator *--> ComponentD
    ComponentB --> Mediator
    ComponentD --> Mediator
    

```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : observer pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/observer">[refactoring.guru] observer pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td><b>Also known as:</b></td>
<td><i>Event-Subscriber, Listener</i></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>Observer</b> is a behavioral design pattern that lets you define a subscription mechanism to notify multiple objects about any events that happen to the object they're observing.
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/observer/observer-2x.png?id=d5a83e115528e9fd633f04ad2650f1db" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction BT

    class Client
    class Publisher
    class Subscriber{
        <<interface>>
    }
    class ConcreteSubscribers

    Client --> Publisher
    Client ..> ConcreteSubscribers
    Publisher o--> Subscriber
    ConcreteSubscribers ..|> Subscriber
```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : singleton pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/singleton">[refactoring.guru] singleton pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>Singleton</b> is a creational design pattern that lets you ensure that a class has only one instance, while providing a global access point to this instance.
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center"><img src="https://refactoring.guru/images/patterns/content/singleton/singleton-2x.png?id=accb2cc7594f7a491ce01dddf0d2f876" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction TB
    class Client
    class Singleton{
        -instance Singleton$
        -Singleton()
        +getInstance() Singleton$
    }
    Singleton --> Singleton
    Client --> Singleton 
    
    note for Singleton "<b>if</b>(instance == <b>null</b>){\n// Note: if you're creating an app with\n// multithreading support, you should\n// place a thread lock here\ninstance = <b>new</b> Singleton()\n}\n<b>return</b> instance"

    note "<b><i><code>1.</code></i></b> The <b>Singleton</b> class declares the static method\n<code>getInstance</code> that returns the same instance\nof its own class\n\n\nThe Singleton's constructor should be hidden\nfrom the client code. Calling the\n<code>getInstance</code> method should be the only way\nof getting the Singleton object"
    
```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : state pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/state">[refactoring.guru] state pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>State</b> is a behavioural design pattern that lets an object alter its behaviour when its internal state changes. it appears as if the object changed its class
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/state/state-en-2x.png?id=dfd427a938223ae880291c2850f3e34a" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction BT

    class Client
    class ConcreteStates
    class Context
    class State{
        <<interface>>
    }

    Client ..> ConcreteStates
    Client --> Context
    Context o--> State
    ConcreteStates ..|> State
    ConcreteStates --> Context
```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

#### General references : Design patterns : strategy pattern

[***[back to Contents]***](#contents)

<table>
<!-- =================================== -->
<!-- ----------------------------------- -->
<tr>
<th></th>
<th><a href="https://refactoring.guru/design-patterns/stategy">[refactoring.guru] stategy pattern</a></th>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Intent</td>
<td><b>Stategy</b> is a behavioural design pattern that lets you define a family of algorithms, put each of them into a separate class, and make their objects interchangeable.
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td align="center">
<img src="https://refactoring.guru/images/patterns/content/strategy/strategy-2x.png?id=1cee47d05a76fddf07dce9c67b700748" alt="metaphor" width="60%" /></td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td>Diagram</td>
<td align="center">

```mermaid
classDiagram
    direction BT

    class Client
    class ConcreteStrategies
    class Context
    class Strategy{
        <<interface>>
    }

    Client ..> ConcreteStrategies
    Client --> Context
    Context o--> Strategy
    ConcreteStrategies ..|> Strategy
```
</td>
</tr>
<!-- ----------------------------------- -->
<tr>
<td></td>
<td></td>
</tr>
<!-- ----------------------------------- -->
<!-- =================================== -->
</table>

---

