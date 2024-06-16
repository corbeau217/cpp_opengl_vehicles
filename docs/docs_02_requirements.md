# DOCS 02: requirements etc stuffs

---
---

## About

[**[return to overview]**](./docs_00_overview.md#docs-02--requirements-building-the-things-and-interactions)

* this is the requirements mappings page and will be for all the what does the huh where??
* also will do the domain model

---

## Contents

* [***[Nonfunctional requirements]***](#nonfunctional-requirements)
* [***[Functional requirements]***](#functional-requirements)
* [***[The requirements that are hard to place]***](#the-requirements-that-are-hard-to-place)
* [***[Domain models]***](#domain-models)
    * [*[Domain model [draft 01]]*](#domain-model-draft-01)

---

## nonfunctional requirements

### nonfunctional  - development environment

[**[Back to Contents]**](#contents)

| requirement ID | requirement | description |
| ---: | :---: | :--- |
| `NFR_DE_01` | developed on `MacOS` | because we are using macOS |
| `NFR_DE_02` | developed with `VSCODE` | we need the keybinds and extensions |
| `NFR_DE_03` | developed using `OpenGL` | because what's the hemkn point otherwise |
| `NFR_DE_04` | `C++` programming language | main language that the project is written in, to use objects and learn |
| `NFR_DE_05` | `GLAD` library | OpenGL function pointer wrapper |
| `NFR_DE_06` | `GLFW` library | window event handle wrapper because we dont want to cry over metals yet |
| `NFR_DE_07` | `GLM` library | maths for vectors/matrices so it's less painful to usue |
| `NFR_DE_08` | `opengl_project_structurings` as template | to reduce starting and initial setup time |

### nonfunctional - miscellaneous 

[**[Back to Contents]**](#contents)

| requirement ID | requirement | description |
| ---: | :---: | :--- |
| `NFR_M_01` | `Left-handed traffic` | because we live in australia, we drive on the left side of the road |
| `NFR_M_02` | uses the `Concurrency` for the lights and cars | concurrency is being used to manage the car positioning and movement and the lights |
| `NFR_M_03` | traffic control system state display | display shows the state of traffic lights for the different lanes |
| `NFR_M_04` | day night cycles  | day night cycles exist in the scene with shaders for both  |

### nonfunctional - procedural generation

[**[Back to Contents]**](#contents)

| requirement ID | requirement | description |
| ---: | :---: | :--- |
| `NFR_PG_01` | cars are procedurally generated | car models are procedurally generated through settings and from a catalogue of options |
| `NFR_PG_02` | clouds are procedurally generated | procedurally generated clouds exist in the skybox |
| `NFR_PG_03` | stars are procedurally generated | procedurally generated stars exist in the skybox |
| `NFR_PG_04` | buildings are procedurally generated | procedurally generated buildings in the scene exist |
| `NFR_PG_05` | terrain is procedurally generated | procedurally generated terrain including road/intersection generation |

---

## functional requirements

[**[Back to Contents]**](#contents)

| requirement ID | requirement | description |
| ---: | :---: | :--- |
| `FR_01` | cars only travel when their lane's light is green | that the cars check they have a green light to travel |
| `FR_02` | cars wait to travel when their lane has a red light | that the cars wait for their turn when their lane has a red light  |
| `FR_03` | cars queue in a line for their lane | that they dont overlap or try to occupy the same space  |

---

## the requirements that are hard to place

[**[Back to Contents]**](#contents)

| requirement ID | requirement | description |
| ---: | :---: | :--- |
| `IDK_01` | ... | ... |

---

## Domain models

### Domain model [draft 01]

[**[Back to Contents]**](#contents)

* lazy draft, half way through we stopped putting the relationships in properly
```mermaid
classDiagram
    title Domain model draft 01

    class Scene {
        SkyBox skybox
        Car[] cars
        Terrain terrain
    }
    class SkyBox {
        SkyDay skyday
        SkyNight skynight
        Clouds clouds
    }
    class SkyDay {
        Color skyColour
        Sun sun
    }
    class SkyNight {
        Color skyColour
        Moon moon
    }
    class Sun {
        %% ...
    }
    class Moon {
        %% ...
    }
    class Clouds {
        %% ...
    }
    class Car {
        State state
        CarLights carlights
        Lane currentLane
        Wheel[] wheels
        Mesh mesh
    }
    class CarLights {
        State state
    }
    class Wheel {
        Mesh mesh
    }
    class Lane {
        TrafficLight trafficlight
    }
    class TrafficLight {
        State state
        Mesh mesh
    }
    class Mesh {
        Vector4f[] vertices
    }
    class CarThread {
        Car car
    }
    class TrafficThread {
        Intersection intersection
    }
    class MainThread {
        %% ...
    }
    class Intersection {
        TrafficLight[] trafficlight
        Lane[] lane
        Mesh mesh
    }
    class Building {
        Mesh mesh
    }
    class Terrain {
        Intersection intersection
        Building[] buildings
    }
    class DiagnosticScreen {
        Intersection intersection
    }
    class App {
        Scene scene
    }

    %% ====================

    MainThread ..|> App
    App *--> Scene
    MainThread .. CarThread
    MainThread .. TrafficThread

    %% ====================

    Scene *--> SkyBox

    %% ====================

    SkyBox *--> SkyDay
    SkyBox *--> Clouds
    SkyBox *--> SkyNight

    %% ====================

    Car *--> CarLights
    Car *--> Wheel
    Car *--> Mesh
    Car --> Lane
    Car --> TrafficLight

    %% ====================

    Wheel --> Mesh

    %% ====================

    Lane --> TrafficLight

    %% ====================

    Scene --> Car
    Scene --> Terrain
    Scene --> DiagnosticScreen

    %% ====================

    SkyDay --> Sun

    %% ====================
    
    SkyNight --> Moon

    %% ====================

    CarThread ..|> Car
    CarThread --> Intersection

    %% ====================

    TrafficThread --> Intersection

    %% ====================

    DiagnosticScreen --> Intersection

    
    %% ====================

    TrafficLight --> Mesh

    %% ====================

    Intersection --> Mesh
    Intersection --> Lane
    Intersection --> TrafficLight

    %% ====================

    Terrain --> Intersection
    Terrain --> Building

    %% ====================
    
    Scene --> Building

    %% ====================

    Building --> Mesh

    %% ====================
```
