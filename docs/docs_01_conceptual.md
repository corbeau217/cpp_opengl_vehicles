# DOCS 01 : conceptual stuffs

---
---

## Doc links

Documentation page links:
* [**[docs 00 : overview]**](./docs_00_overview.md#docs-01--concepts-and-some-throwing-around-ideas)
* [***[docs 01 : conceptual]***](./docs_01_conceptual.md)
* [**[docs 02 : requirements]**](./docs_02_requirements.md)
* [**[docs 03 : designables]**](./docs_03_designables.md)
* [**[docs 04 : developments]**](./docs_04_developments.md)

---

## About

* initial research and thoughtables
* can be actor identifying and the use case stuffs
* will be the use case diagrams and sequence diagrams too
* include the context model
* mah haps the architecture

| ![early diagram](./images/projectoverviewdiagram_12062024.png) |
| :---: |
| *an early conceptual diagram of the project* - `12/06/2024` |

---

## Contents

* [**[Previous conceptual information]**](#previous-conceptual-information)
* [**[Actor Identification]**](#actor-identification)
    * [*[Concept identification listing [draft 01]]*](#concept-identification-listing-draft-01)
    * [*[Concept identification listing [draft 02]]*](#concept-identification-listing-draft-02)
    * [*[Concept identification listing [draft 03]]*](#concept-identification-listing-draft-03)
* [**[Use cases]**](#use-cases)
    * [*[Use cases [draft 01]]*](#use-cases-draft-01)
    * [*[Use cases [draft 02]]*](#use-cases-draft-02)
* [**[Concept-Domain models]**](#concept-domain-models)
    * [*[Concept-Domain model [draft 01]]*](#concept-domain-model-draft-01)
    * [*[Concept-Domain model [draft 02]]*](#concept-domain-model-draft-02)
    * [*[Concept-Domain model [draft 03]]*](#concept-domain-model-draft-03)
* [**[Sequence diagrams]**](#sequence-diagrams)
    * [*[Sequence diagram [draft 01]]*](#sequence-diagram-draft-01)
        * [*Sequence diagram [draft 01] : `Sky box`*](#sequence-diagram-draft-01--sky-box)
        * [*Sequence diagram [draft 01] : `Terrain`*](#sequence-diagram-draft-01--terrain)
        * [*Sequence diagram [draft 01] : `Traffic Controller`*](#sequence-diagram-draft-01--traffic-controller)
        * [*Sequence diagram [draft 01] : `Car`*](#sequence-diagram-draft-01--car)
            * [*Sequence diagram [draft 01] : `Car.init()`*](#sequence-diagram-draft-01--carinit)
            * [*Sequence diagram [draft 01] : `Car.update()` and `Car.draw()`*](#sequence-diagram-draft-01--carupdate-and-cardraw)
* [**[State Diagrams]**](#state-diagrams)
    * [*[State diagram [draft 01]]*](#state-diagram-draft-01)
* [**[Architecture]**](#architecture)
    * [*Server-Client relationship [draft 01]*](#server-client-relationship-draft-01)
    * [*Server-Client relationship [draft 02]*](#server-client-relationship-draft-02)
* [**[Context Models]**](#context-models)
    * [*[Context Model [draft 01]]*](#context-model-draft-01)
* [**[Concept Diagrams]**](#concept-diagrams)
* [**[Experimentation details]**](#experimentation-details)


---

## previous conceptual information

[**[Back to Contents]**](#contents)

* [[Suppliment 01]](./docs_01_conceptual_suppliment_01.md) - the previous conceptual documentation

---

## Actor identification

### Concept identification listing [draft 01]

[**[Back to Contents]**](#contents)

* car
* traffic light
* traffic controller
* traffic control diagnostic system
* road
* lane
* light
* sky
* cloud
* building
* wheel
* sun
* moon
* wheel

### Concept identification listing [draft 02]

[**[Back to Contents]**](#contents)

* [`Scene`](#scene-draft-01)
* [`Sky day`](#sky-day-draft-01)
* [`Sky night`](#sky-night-draft-01)
* [`Sun`](#concept-identification-listing-draft-02)
* [`Clouds`](#clouds-draft-01)
* [`Moon`](#concept-identification-listing-draft-02)
* [`Car`](#car-draft-01)
* [`Car Lights`](#concept-identification-listing-draft-02)
* [`Wheel`](#concept-identification-listing-draft-02)
* [`Diagnostic Screen`](#traffic-diagnostics-screen-draft-01)
* [`Traffic Controller`](#traffic-controller-draft-01)
* [`Lane`](#lane-draft-01)
* [`Traffic Light`](#traffic-light-draft-01)
* [`Intersection`](#intersection-draft-01)
* [`Terrain`](#concept-identification-listing-draft-02)
* [`Building`](#concept-identification-listing-draft-02)
* [`Mesh`](#concept-identification-listing-draft-02)

### Concept identification listing [draft 03]

[**[Back to Contents]**](#contents)

* [`WindowsDeveloper`](#use-cases-draft-02--windowsdeveloper)
* [`MacOSDeveloper`](#use-cases-draft-02--macosdeveloper)
* [`WindowsUser`](#use-cases-draft-02--windowsuser)
* [`MacOSUser`](#use-cases-draft-02--macosuser)
* [`MainThread`](#use-cases-draft-02--mainthread)
* [`TrafficThread`](#use-cases-draft-02--trafficthread)
* [`CarThread`](#use-cases-draft-02--carthread)
* [`App`](#use-cases-draft-02--app)
* [`Scene`](#use-cases-draft-02--scene)
* [`Skybox`](#use-cases-draft-02--skybox)
* [`SkyDay`](#use-cases-draft-02--skyday)
* [`SkyNight`](#use-cases-draft-02--skynight)
* [`Clouds`](#use-cases-draft-02--clouds)
* [`Sun`](#use-cases-draft-02--sun)
* [`Moon`](#use-cases-draft-02--moon)
* [`Terrain`](#use-cases-draft-02--terrain)
* [`Building`](#use-cases-draft-02--building)
* [`Intersection`](#use-cases-draft-02--intersection)
* [`DiagnosticScreen`](#use-cases-draft-02--diagnosticscreen)
* [`TrafficLight`](#use-cases-draft-02--trafficLight)
* [`Lane`](#use-cases-draft-02--lane)
* [`Car`](#use-cases-draft-02--car)
* [`Wheel`](#use-cases-draft-02--wheel)
* [`CarLights`](#use-cases-draft-02--carlights)
* [`Mesh`](#use-cases-draft-02--mesh)

### Concept identification listing [draft 04]

[**[Back to Contents]**](#contents)

* ***smells like complexity demon! begone foul creature!***

* stakeholders
    * [`WindowsDeveloper`]()
    * [`MacOSDeveloper`]()
    * [`WindowsUser`]()
    * [`MacOSUser`]()
* threads
    * [`MainThread`]()
    * [`DiagnosticsThread`]()
    * [`ControllerThread`]()
    * [`LightThread`]()
    * [`CarThread`]()
* containers
    * [`App`]()
    * [`Scene`]()
    * [`Skybox`]()
    * [`Lane`]()
* containers with models/shaders
    * [`SkyDay`]()
    * [`SkyNight`]()
    * [`Terrain`]()
    * [`Intersection`]()
    * [`DiagnosticScreen`]()
    * [`Car`]()
* models/shaders
    * [`Clouds`]()
    * [`Sun`]()
    * [`Moon`]()
    * [`Building`]()
    * [`TrafficLight`]()
    * [`Wheel`]()
    * [`CarLights`]()
    * [`Mesh`]()

## Use cases

### Use cases [draft 01]

[**[Back to Contents]**](#contents)

#### `Car` [draft 01]

* as a `Car` i want to ***travel straight*** through `Intersection`
* as a `Car` i want to ***turn left***
* as a `Car` i want to **turn right**
* as a `Car` queued in `Lane`, i want to ***move*** up to the `Intersection`
* as a `Car` at the start of the queue, i want to ***begin moving*** through the `Intersection`
* as a `Car` i want to ***generate*** a `Mesh` to use
* as a `Car` i want to ***move forward*** when it's *safe to move*
* as a `Car` i want to ***stop*** when it's *not safe to move*
* as a `Car` i want to ***rotate*** my `Wheel`s when i *move*
* as a `Car` i want to ***update*** my `Car lights` to show my *behaviour*

#### `Clouds` [draft 01]

* as the `Clouds` i want to ***move*** with the *wind*

#### `Lane` [draft 01]

* as a `Lane` i want to have a `Traffic Light` ***state*** holder

#### `Scene` [draft 01]

* as a `Scene` i want to ***generate*** a `Sky Day`
* as a `Scene` i want to ***generate*** a `Sky Night`
* as a `Scene` i want to ***generate*** a `Car`
* as a `Scene` i want to ***generate*** an `Intersection`
* as a `Scene` i want to ***generate*** a `Building`
* as a `Scene` i want to ***generate*** the `Terrain`
* as a `Scene` i want to ***generate*** the `Clouds`

#### `Sky Day` [draft 01]

* as a `Sky Day` i want to ***check*** the `time of day`
* as a `Sky Day` i want to ***display*** the `Clouds`
* as a `Sky Day` i want to ***display*** the `Sun`
* as a `Sky Day` i want to ***display*** the `Atmosphere colour`

#### `Sky Night` [draft 01]

* as a `Sky Night` i want to ***check*** the `time of day`
* as a `Sky Night` i want to ***display*** the `Clouds`
* as a `Sky Night` i want to ***display*** the `Moon`
* as a `Sky Night` i want to ***display*** the `Stars`

#### `Traffic Controller` [draft 01]

* as a `Traffic Controller` i want to ***change*** the `Lane` which can *move*

#### `Traffic diagnostics screen` [draft 01]

* as a `Traffic diagnostics screen` i want to ***check*** the ***state*** of the `Traffic Controller`
* as a `Traffic diagnostics screen` i want to ***check*** the *number* of `Car`s in a `Lane`

#### `Traffic Light` [draft 01]

* as a `Traffic Light` i want to ***update*** my ***state***
* as a `Traffic Light` ***state*** holder i want to ***generate*** my `Mesh`

#### `Intersection` [draft 01]

* as an `Intersection` i want to ***generate*** the `Intersection` `Mesh`
* as an `Intersection` i want to ***generate*** the `Lane` objects

### Use cases [draft 02]

* [**[Back to Contents]**](#contents)
* [**Use cases [draft 02]**](#use-cases-draft-02)
    * [*Use cases [draft 02] : `WindowsDeveloper`*](#use-cases-draft-02--windowsdeveloper)
    * [*Use cases [draft 02] : `MacOSDeveloper`*](#use-cases-draft-02--macosdeveloper)
    * [*Use cases [draft 02] : `WindowsUser`*](#use-cases-draft-02--windowsuser)
    * [*Use cases [draft 02] : `MacOSUser`*](#use-cases-draft-02--macosuser)
    * [*Use cases [draft 02] : `MainThread`*](#use-cases-draft-02--mainthread)
    * [*Use cases [draft 02] : `TrafficThread`*](#use-cases-draft-02--trafficthread)
    * [*Use cases [draft 02] : `CarThread`*](#use-cases-draft-02--carthread)
    * [*Use cases [draft 02] : `App`*](#use-cases-draft-02--app)
    * [*Use cases [draft 02] : `Scene`*](#use-cases-draft-02--scene)
    * [*Use cases [draft 02] : `Skybox`*](#use-cases-draft-02--skybox)
    * [*Use cases [draft 02] : `SkyDay`*](#use-cases-draft-02--skyday)
    * [*Use cases [draft 02] : `SkyNight`*](#use-cases-draft-02--skynight)
    * [*Use cases [draft 02] : `Clouds`*](#use-cases-draft-02--clouds)
    * [*Use cases [draft 02] : `Sun`*](#use-cases-draft-02--sun)
    * [*Use cases [draft 02] : `Moon`*](#use-cases-draft-02--moon)
    * [*Use cases [draft 02] : `Terrain`*](#use-cases-draft-02--terrain)
    * [*Use cases [draft 02] : `Building`*](#use-cases-draft-02--building)
    * [*Use cases [draft 02] : `Intersection`*](#use-cases-draft-02--intersection)
    * [*Use cases [draft 02] : `DiagnosticScreen`*](#use-cases-draft-02--diagnosticscreen)
    * [*Use cases [draft 02] : `TrafficLight`*](#use-cases-draft-02--trafficLight)
    * [*Use cases [draft 02] : `Lane`*](#use-cases-draft-02--lane)
    * [*Use cases [draft 02] : `Car`*](#use-cases-draft-02--car)
    * [*Use cases [draft 02] : `Wheel`*](#use-cases-draft-02--wheel)
    * [*Use cases [draft 02] : `CarLights`*](#use-cases-draft-02--carlights)
    * [*Use cases [draft 02] : `Mesh`*](#use-cases-draft-02--mesh)

#### Use cases [draft 02] : `WindowsDeveloper`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a windows developer I want to compile and run the code on windows

#### Use cases [draft 02] : `MacOSDeveloper`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a MacOS developer, I want to compile and run the code on MacOS

#### Use cases [draft 02] : `WindowsUser`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a windows user, I want to run the program on windows

#### Use cases [draft 02] : `MacOSUser`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a MacOS user, I want to run the program on MacOS

#### Use cases [draft 02] : `MainThread`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the Main thread, I want to initialise the App
* as the Main thread, I want to create the Traffic thread
* as the Main thread, I want to create the Car thread
* as the Main thread, I want to draw the scene each frame

#### Use cases [draft 02] : `TrafficThread`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the traffic thread, I want to access lane information to update lane states
* as the traffic thread, I want to stop a lane from moving so that another may start
* as the traffic thread i want to change the traffic light object state information
* as the traffic thread i want to connect to my traffic light objects
    * are we server -> client model?
    * perhaps we should

#### Use cases [draft 02] : `CarThread`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the car thread, I want to generate a car to use when I am created
* as the car thread, I want to access and update my specific car object
* as the car thread, I want to access and use information in the lane to change my car object
* as the car thread, I want to know about the car in front of me, so that I can avoid crashing
* as the car thread, I want to check where I am in lane, to know if I should be looking at the traffic lights
* as the car thread, I want to observe the traffic lights when I am at the start of the queue, to know if I should enter the intersection
* as the car thread, I want to finish moving through the intersection when I have entered it.

#### Use cases [draft 02] : `App`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* As the app, I want to create the scene
* As the app, I want to start the draw calls
* As the app, I want to handle input events
* As the app, I want to handle closing the window
* As the app, I want to handle cleaning up the objects

#### Use cases [draft 02] : `Scene`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the scene i want to create the skybox
* as the scene i want to create the terrain
* as the scene i want to tell the skybox about the time of day
* as the scene i want to get the clouds to move
* as the scene i want to update the buildings

#### Use cases [draft 02] : `Skybox`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the skybox i want to determine which sky do use by time of day
* as the skybox i want to manage the clouds and their movement
* as the skybox i want to not move in camera space

#### Use cases [draft 02] : `SkyDay`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the sky day, i want to change colour with the time of day

#### Use cases [draft 02] : `SkyNight`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the sky night, i want to show the stars move with the time of nights

#### Use cases [draft 02] : `Clouds`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the clouds, i want to change over time using perlin noise

#### Use cases [draft 02] : `Sun`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the sun i want to always face the camera
* as the sun i want to move with the time of day

#### Use cases [draft 02] : `Moon`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the moon i want to always face the camera
* as the moon i want to move with the time of day
* as the moon i want to show the current moon phase

#### Use cases [draft 02] : `Terrain`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the terrain i want to generate a height map to use for my mesh
* as the terrain i want to generate the road map to use for creating intersections
* as the terrain i want to create an intersection object where roads intersect
* as the terrain i want to generate a mesh based on the height map i made
* as the terrain i want to generate a normal map for my mesh
* as the terrain i want to generate a bump map for my mesh
* as the terrain i want to generate buildings around the intersection

#### Use cases [draft 02] : `Building`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a building i want to roll for the number of floors i have
* as a building i want to generate a mesh based on how many floors i should have
* as a building i want to generate a normal map for fragments
* as a building i want to generate a bump map for my window distortion
* as a building i want to reflect the scene from my windows

#### Use cases [draft 02] : `Intersection`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the intersection i want to generate the lanes that exist for the intersection
* as the intersection i want to generate the traffic light objects for the intersection
* as the intersection i want to generate the road mesh that is used in the intersection
* as the intersection i want to generate the generate the normal mapping for the road mesh
* as the intersection i want to generate the generate the bump mapping for the road mesh

#### Use cases [draft 02] : `DiagnosticScreen`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as the diagnostic screen i want to show the status of all lanes
* as the diagnostic screen i want to show how long before the next state change
* as the diagnostic screen i want to show my planned change in state
* as the diagnostic screen i want to show my sensor information
* as the diagnostic screen i want to show my connection to traffic lights information
* as the diagnostic screen i want to read the traffic light object state information
* as the diagnostic screen i want to render my data to a screen
* as the diagnostic screen i want to only render my data to the screen when in view

#### Use cases [draft 02] : `TrafficLight`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a traffic light i want to generate a mesh based on the lanes i service
* as a traffic light i want to update my state based on what the traffic controller tells me
* as a traffic light i want to generate a normal map for my model
* as a traffic light i want to use my state information to display the lights

#### Use cases [draft 02] : `Lane`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a lane, i want to let cars queue for the intersection
* as a lane, i want to observe the traffic lights for when my cars can move
    * *lane threads instead of car threads?????*
* *as a lane, i want to hold a queue of the cars currently in my lane*
* *as a lane, i want to allow the first car to move when it is save*
* *as a lane, i want to move the other cars when they're allowed to??*

#### Use cases [draft 02] : `Car`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a car i want to update my wheel models as i move
* as a car i want to generate a mesh to use
* as a car i want to generate a normal map for my mesh
* as a car i want to generate a specularity map for my mesh
* as a car i want to know when it's safe to move
* as a car i want to know which lane i am in
* as a car i want to know which lane i want to travel to

#### Use cases [draft 02] : `Wheel`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a wheel i want to turn when my car moves
* as a wheel i want to generate a wheel mesh
* as a wheel i want to generate a normal map
* as a wheel i want to generate a specularity map to make my rims shiny

#### Use cases [draft 02] : `CarLights`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as car lights i want to display the behaviour state of my owner car
* as car lights i want to create light for the scene to use
* as car lights i want to tell the scene about my light
* as car lights i want to update my blinkers to blink when im using them
* as car lights i want to light up the brakelights when my owner car is slowing down or stopped

#### Use cases [draft 02] : `Mesh`

[***click to return to subheading [Use cases [draft 02]]***](#use-cases-draft-02)

* as a mesh i want to have vertex information for my owner object
* as a mesh i want to have shader information for my owner
* as a mesh i want to have uv mapping for my owner
* as a mesh i want to be able to be drawn by my owner
* as a mesh i want to be able to be transformed by my owner


---

## Concept-Domain models

* mermaid chart [[flow chart syntax reference]](https://mermaid.js.org/syntax/flowchart.html)
* mermaid chart [[class diagram syntax reference]](https://mermaid.js.org/syntax/classDiagram.html)
* the need for the model didnt really fit fully within either model so we made our own kind.
* a proper domain model will be made later

### Concept-Domain model [draft 01]

[**[Back to Contents]**](#contents)

* kinda context model of the things, rly simple flow

```mermaid
flowchart TD
    SCENE[Scene] -->|owns| CAR[Car]
    SCENE -->|owns| ROAD[Road]
    SCENE -->|owns| TRAFFICLIGHT[Traffic light]
    CAR -->|uses| LANE[Lane]
    ROAD -->|consists of| LANE
    LANE -->|informed by| TRAFFICLIGHT
    CONTROLLER[Traffic light controller] -->|determines the state of| TRAFFICLIGHT
    SCENE -->|owns| SUN[Sun]
    SCENE -->|owns| MOON[Moon]
    SCENE -->|owns| SKYBOX[Sky box]
    SCENE -->|owns| BUILDING[Building]
    SKYBOX -->|owns| CLOUDS[Clouds]

```

### Concept-Domain model [draft 02]

[**[Back to Contents]**](#contents)

* second attempt after doing the use cases
* `Atmosphere` was a suggestion to deal with some wackiness for cloud access
    * currently commented out in the diagram
* part way through making it we discovered that this doesnt fully fall within context or domain model
    * context loses the shapes to highlight the types of actors/objects
    * domain loses the shapes and current structure.
    * will need a simple domain model later to show number of items in their interactions
* `Scene` / `Terrain` / `Lane`
    * are controllers and high level concepts for their child nodes
    * warehouses for information
* `Sky day` / `Sky night` / `Car` / `Diagnostic Screen` / `Intersection`
    * are objects that hold behaviour and child nodes
    * these could be separate threads
* `Sun` / `Clouds` / `Moon` / `Car Lights` / `Traffic Light` / `Building`
    * these are mostly meshes and shaders, with some information
* `Traffic Controller`
    * 100% seperate thread to the rest of the system
    * controls the `Lane` child nodes
* `Mesh`
    * interface / object type to hold model information
    * will be very about the handling the model and texturing
* after completing the diagram we found the being able to send things more layers by using `-->` / `--->` / `---->` / `----->` 
    * will do this in next draft may haps

```mermaid
flowchart TD
    %% ========================================

    SCENE[(Scene)]
    SUN{{Sun}}
    CLOUDS{{Clouds}}
    MOON{{Moon}}
    TRAFFICCONTROLLER((Traffic Controller))
    TRAFFICLIGHT{{Traffic Light}}
    INTERSECTION[Intersection]
    DIAGNOSTICSSCREEN[Diagnostic Screen]
    LANE[(Lane)]
    SKYDAY[Sky day]
    %% ATMOSPHERE[Atmosphere]
    SKYNIGHT[Sky night]
    CAR[Car]
    WHEEL(Wheel)
    CARLIGHTS{{Car Lights}}
    MESH[[Mesh]]
    TERRAIN[(Terrain)]
    BUILDING{{Building}}

    %% ========================================

    SKYDAY --> CLOUDS
    %% SCENE --> ATMOSPHERE
    %% ATMOSPHERE --> CLOUDS
    SCENE --> CLOUDS
    SKYNIGHT --> CLOUDS

    %% ====================

    CAR --> CARLIGHTS
    CAR --> WHEEL
    CAR --> MESH
    CAR --> LANE
    CAR --> TRAFFICLIGHT

    %% ====================

    WHEEL --> MESH

    %% ====================

    LANE --> TRAFFICLIGHT

    %% ====================

    SCENE --> SKYDAY
    SCENE --> SKYNIGHT
    SCENE --> CAR
    SCENE --> INTERSECTION
    SCENE --> TERRAIN
    SCENE --> DIAGNOSTICSSCREEN

    %% ====================

    SKYDAY --> SUN

    %% ====================
    
    SKYNIGHT --> MOON

    %% ====================

    TRAFFICCONTROLLER --> LANE

    %% ====================

    DIAGNOSTICSSCREEN --> TRAFFICCONTROLLER
    DIAGNOSTICSSCREEN --> LANE

    %% ====================

    TRAFFICLIGHT --> MESH

    %% ====================

    INTERSECTION --> MESH
    INTERSECTION --> LANE
    INTERSECTION --> TRAFFICLIGHT

    %% ====================

    TERRAIN --> INTERSECTION
    TERRAIN --> BUILDING
    SCENE --> BUILDING

    %% ====================

    BUILDING --> MESH

    %% ========================================
```

### Concept-Domain model [draft 03]

[**[Back to Contents]**](#contents)

* mild changes to reflect discoveries in the sequence diagram draft 1

```mermaid
flowchart TD
    %% ========================================

    MAINTHREAD((Main Thread))
    SKYBOX[(Sky box)]
    SCENE[(Scene)]
    SUN{{Sun}}
    MOON{{Moon}}
    TRAFFICLIGHT{{Traffic Light}}
    INTERSECTION[Intersection]
    DIAGNOSTICSSCREEN[Diagnostic Screen]
    LANE[(Lane)]
    SKYDAY[Sky day]
    SKYNIGHT[Sky night]
    CLOUDS{{Clouds}}
    CAR[Car]
    WHEEL(Wheel)
    CARLIGHTS{{Car Lights}}
    MESH[[Mesh]]
    TERRAIN[(Terrain)]
    BUILDING{{Building}}
    TRAFFICTHREAD((Traffic Thread))
    CARTHREAD((Car Thread))

    %% ========================================


    MAINTHREAD --- SCENE
    MAINTHREAD -...- CARTHREAD
    MAINTHREAD -..- TRAFFICTHREAD

    %% ====================

    SCENE ==> SKYBOX

    %% ====================

    SKYBOX ==> SKYDAY
    SKYBOX ==> CLOUDS
    SKYBOX ==> SKYNIGHT

    %% ====================

    CAR ==> CARLIGHTS
    CAR ==> WHEEL
    CAR ==> MESH
    CAR -.- LANE
    CAR -..- TRAFFICLIGHT

    %% ====================

    WHEEL ==> MESH

    %% ====================

    LANE --- TRAFFICLIGHT

    %% ====================

    SCENE ==> CAR
    SCENE ==> TERRAIN
    SCENE ==> DIAGNOSTICSSCREEN

    %% ====================

    SKYDAY ==> SUN

    %% ====================
    
    SKYNIGHT ==> MOON

    %% ====================

    CARTHREAD --- CAR
    CARTHREAD -.- INTERSECTION
    

    %% ====================

    TRAFFICTHREAD --- INTERSECTION

    %% ====================

    DIAGNOSTICSSCREEN -..- INTERSECTION

    
    %% ====================

    TRAFFICLIGHT ==> MESH

    %% ====================

    INTERSECTION ==> MESH
    INTERSECTION ==> LANE
    INTERSECTION ==> TRAFFICLIGHT

    %% ====================

    TERRAIN ==> INTERSECTION
    TERRAIN ==> BUILDING

    %% ====================
    
    SCENE -.- BUILDING

    %% ====================

    BUILDING ==> MESH

    %% ========================================
```

---

## Sequence diagrams

* mermaid chart [[sequence diagrams syntax reference]](https://mermaid.js.org/syntax/sequenceDiagram.html)
* will probably need to redo after we fully confirm the things with a proper domain model

### Sequence diagram [draft 01]

[**[Back to Contents]**](#contents)

* will be based on [***[Concept-Domain model [draft 02]]***](#concept-domain-model-draft-02)
* sub heading links:
    * [***[`Sky box`]***](#sequence-diagram-draft-01--sky-box)
    * [***[`Terrain`]***](#sequence-diagram-draft-01--terrain)
    * [***[`Traffic Controller`]***](#sequence-diagram-draft-01--traffic-controller)
    * [***[`Car`]***](#sequence-diagram-draft-01--car)

#### Sequence diagram [draft 01] : `Sky box`

* [*[return to sequence diagram sub heading]*](#sequence-diagram-draft-01)

```mermaid
---
title: Sky box interaction model - draft 1
---
sequenceDiagram
    autonumber
    %% -------------------------------------------------
    participant SCENE as Scene
    participant SKYBOX as Skybox
    participant SKYDAY as Sky day
    participant SKYNIGHT as Sky night
    participant CLOUDS as Clouds
    %% -------------------------------------------------
    note over SCENE,CLOUDS: . . . 
    %% -------------------------------------------------
    critical Initialise
    note left of SCENE: creater calls<br>scene.init()
    activate SCENE
    SCENE ->>+ SKYBOX: initialise sky
    SKYBOX ->>+ SKYDAY: initialise day
    SKYDAY -->>- SKYBOX: done
    SKYBOX ->>+ SKYNIGHT: initialise night
    SKYNIGHT -->>- SKYBOX: done
    SKYBOX ->>+ CLOUDS: initialise clouds
    CLOUDS -->>- SKYBOX: done
    SKYBOX ->>- SCENE: finished initialisation
    deactivate SCENE
    note left of SCENE: returns control<br>to creator
    end
    %% -------------------------------------------------
    note over SCENE,CLOUDS: . . . 
    %% -------------------------------------------------
    loop Draw
    note left of SCENE: creator calls<br>scene.draw()
    activate SCENE
    SCENE ->>+ SKYBOX: Draw sky
    activate SKYBOX
    par Day sky drawing
    SKYBOX ->>+ SKYDAY: Draw atomosphere
    SKYDAY -->>- SKYBOX: done
    and Night sky drawing
    SKYBOX ->>+ SKYNIGHT: Draw stars
    SKYNIGHT -->>- SKYBOX: done
    end
    SKYBOX ->>+ CLOUDS: Draw clouds
    CLOUDS -->>- SKYBOX: done
    SKYBOX -->>- SCENE: finished
    deactivate SCENE
    note left of SCENE: returns control<br>to creator
    end
    %% -------------------------------------------------
    note over SCENE,CLOUDS: . . . 
    %% -------------------------------------------------
```

#### Sequence diagram [draft 01] : `Terrain`

* [*[return to sequence diagram sub heading]*](#sequence-diagram-draft-01)

```mermaid
---
title: Terrain interaction model - draft 1
---
sequenceDiagram
    autonumber
    %% -------------------------------------------------
    participant SCENE as Scene
    participant TERRAIN as Terrain
    participant INTERSECTION as Intersection
    participant LANE as Lane
    participant TRAFFICLIGHT as Traffic Light
    participant BUILDING as Building
    %% ...
    %% -------------------------------------------------
    note over SCENE,BUILDING: . . . 
    %% -------------------------------------------------
    critical Initialise
    note left of SCENE: creater calls<br>scene.init()
    activate SCENE
    SCENE ->>+ TERRAIN: initialise
    TERRAIN ->>+ INTERSECTION: initialise
    loop for each lane
    INTERSECTION ->>+ LANE: initialise
    LANE ->>+ TRAFFICLIGHT: initialise
    TRAFFICLIGHT -->>- LANE: done
    LANE -->>- INTERSECTION: done
    end
    INTERSECTION -->>- TERRAIN: done
    loop for each building
    TERRAIN ->>+ BUILDING: initialise
    BUILDING -->>- TERRAIN: done
    end
    TERRAIN -->>- SCENE: done
    deactivate SCENE
    note left of SCENE: returns control<br>to creator
    end
    %% -------------------------------------------------
    note over SCENE,BUILDING: . . . 
    %% -------------------------------------------------
    loop Draw
    note left of SCENE: creator calls<br>scene.draw()
    activate SCENE
    %% ...
    SCENE ->>+ TERRAIN : Draw
    TERRAIN ->>+ INTERSECTION : Draw
    loop for each traffic light object
    INTERSECTION ->>+ TRAFFICLIGHT : Draw
    TRAFFICLIGHT -->>- INTERSECTION : Done
    end
    INTERSECTION -->>- TERRAIN : done
    loop for each building object
    TERRAIN ->>+ BUILDING : Draw
    BUILDING -->>- TERRAIN : Done
    end
    TERRAIN -->>- SCENE : done
    %% ...
    deactivate SCENE
    note left of SCENE: returns control<br>to creator
    end
    %% -------------------------------------------------
    note over SCENE,BUILDING: . . . 
    %% -------------------------------------------------
```
 
#### Sequence diagram [draft 01] : `Traffic Controller`

* [*[return to sequence diagram sub heading]*](#sequence-diagram-draft-01)

```mermaid
---
title: Traffic Controller interaction model - draft 1
---
sequenceDiagram
    autonumber
    %% -------------------------------------------------
    Actor TRAFFICTHREAD as Traffic Controller<br>thread
    Actor MAINTHREAD as Main<br>thread
    participant SCENE as Scene
    participant TRAFFICCONTROLLER as Traffic Controller
    participant INTERSECTION as Intersection
    participant LANE as Lane
    participant TRAFFICLIGHT as Traffic Light
    %% ...
    %% -------------------------------------------------
    %% -------------------------------------------------
    activate MAINTHREAD
    note over TRAFFICTHREAD,TRAFFICLIGHT: at program start
    %% -------------------------------------------------
    critical Initialise scene
    MAINTHREAD ->>+ SCENE : Initialise scene
    SCENE -->>- MAINTHREAD : done
    MAINTHREAD ->>+ TRAFFICCONTROLLER : Initialise traffic<br>controller data
    TRAFFICCONTROLLER -->>- MAINTHREAD : finished initialising
    end
    %% -------------------------------------------------
    critical Initialise traffic controller thread
    MAINTHREAD ->>+ TRAFFICTHREAD : Initialise thread
    TRAFFICTHREAD -->>- MAINTHREAD : finished initialising
    end
    %% -------------------------------------------------
    critical Start Traffic controller thread
    MAINTHREAD ->> TRAFFICTHREAD : Start traffic controller<br>thread
    activate TRAFFICTHREAD
    TRAFFICTHREAD -->> MAINTHREAD : thread started
    end
    %% -------------------------------------------------
    loop Draw
    MAINTHREAD ->>+ SCENE : Draws scene
    SCENE ->>+ TRAFFICCONTROLLER : Draws traffic controller<br>status object
    TRAFFICCONTROLLER -->>- SCENE : done status draw
    SCENE -->>- MAINTHREAD : done draw call
    end
    %% -------------------------------------------------
    loop Update traffic state
    TRAFFICTHREAD ->>+ TRAFFICCONTROLLER : update data
    TRAFFICCONTROLLER ->>+ INTERSECTION : handle update
    loop update each lane
    INTERSECTION ->>+ LANE : update lane
    LANE ->>+ TRAFFICCONTROLLER : get current state
    TRAFFICCONTROLLER -->>- LANE : current state data
    LANE ->>+ LANE : state change check
    LANE ->>+ TRAFFICLIGHT : had state change,<br>update traffic light
    TRAFFICLIGHT -->>- LANE : done light
    LANE -->>- LANE : finish state update
    LANE -->>- INTERSECTION : done lane
    end
    INTERSECTION -->>- TRAFFICCONTROLLER : done intersection
    TRAFFICCONTROLLER -->>- TRAFFICTHREAD : done update traffic
    end
    %% -------------------------------------------------
    %% -------------------------------------------------
    note over TRAFFICTHREAD,TRAFFICLIGHT: at program end
    %% -------------------------------------------------
    deactivate TRAFFICTHREAD
    MAINTHREAD ->> TRAFFICTHREAD : dispose of thread
    TRAFFICTHREAD -->> MAINTHREAD : 
    MAINTHREAD ->> SCENE : dispose of scene
    SCENE -->> MAINTHREAD : 
    deactivate MAINTHREAD
    %% -------------------------------------------------
```
 
#### Sequence diagram [draft 01] : `Car`

* [*[return to sequence diagram sub heading]*](#sequence-diagram-draft-01)
* [`init()`](#sequence-diagram-draft-01--carinit)
* [`update()` and `draw()`](#sequence-diagram-draft-01--carupdate-and-cardraw)

##### Sequence diagram [draft 01] : `Car.init()`

```mermaid
---
title: Car.init() interaction model - draft 1
---
sequenceDiagram
    autonumber
    %% -------------------------------------------------
    Actor CARTHREAD as Car thread
    Actor MAINTHREAD as Main thread
    %% ---------------------------------
    participant SCENE as Scene
    participant LANE as Lane
    participant CAR as Car
    participant CARLIGHTS as Car Lights
    participant WHEEL as Wheel
    %% -------------------------------------------------
    note left of MAINTHREAD : MAIN THREAD<br>[starting]
    activate MAINTHREAD
    MAINTHREAD ->> MAINTHREAD : initialise app
    activate MAINTHREAD
    %% -------------------------------------------------
    critical Initialise main
    MAINTHREAD ->>+ SCENE : init scene
    activate MAINTHREAD
    critical init scene
    %% ---------------------------------
    loop All lanes
    activate SCENE
    SCENE ->>+ LANE : init lane
    critical init lane
    note over LANE : create lane<br>stuffs
    end
    LANE -->>- SCENE : done lane
    deactivate SCENE
    end
    %% ---------------------------------
    note right of MAINTHREAD: when fixed car count
    loop for all cars
    activate SCENE
    SCENE ->>+ CARTHREAD : init car thread
    critical init car thread
    CARTHREAD ->>+ CAR : init car
    critical init car
    activate CARTHREAD
    %% ..........................
    CAR ->>+ CARLIGHTS : init lights object
    activate CAR
    CARLIGHTS -->>- CAR : done lights
    deactivate CAR
    loop All wheels
    CAR ->>+ WHEEL : init wheel object
    activate CAR
    WHEEL -->>- CAR : done wheel
    CAR ->>+ LANE : get lane to associate
    activate CAR
    note left of LANE : associate with lane retreived<br>through `Intersection`
    LANE -->>- CAR : 
    deactivate CAR
    deactivate CAR
    end
    %% ..........................
    end
    CAR -->>- CARTHREAD : done car object
    CARTHREAD ->>+ SCENE : attach car to scene
    SCENE -->>- CARTHREAD : attached to scene
    deactivate CARTHREAD
    end
    CARTHREAD -->>- SCENE : done car thread
    deactivate SCENE
    %% ---------------------------------
    end
    note right of SCENE : other scene<br>init
    %% ---------------------------------
    end
    SCENE -->>- MAINTHREAD : done scene init
    deactivate MAINTHREAD
    %% ---------------------------------
    note right of MAINTHREAD : when everything<br>else initialised
    MAINTHREAD ->> MAINTHREAD : start car threads
    activate MAINTHREAD
    loop for all car threads
    MAINTHREAD ->>+ CARTHREAD : start car thread
    note left of CARTHREAD : CAR THREAD<br>[starting]
    CARTHREAD -->> MAINTHREAD : started
    end
    deactivate MAINTHREAD
    MAINTHREAD -->> MAINTHREAD : done car threads
    %% ---------------------------------
    end
    deactivate MAINTHREAD
    MAINTHREAD -->> MAINTHREAD : done app<br>initialisation
    %% -------------------------------------------------
    note over CARTHREAD,WHEEL : . . .
    note over CARTHREAD,WHEEL : . . .
    %% -------------------------------------------------
    note left of CARTHREAD : CAR THREAD<br>[ending]
    %% -------------------------------------------------
    deactivate CARTHREAD
    %% -------------------------------------------------
    note over MAINTHREAD,WHEEL : . . .
    note over MAINTHREAD,WHEEL : . . .
    %% ---------------------------------
    note left of MAINTHREAD : MAIN THREAD<br>[ending]
    %% ---------------------------------
    deactivate MAINTHREAD
```

##### Sequence diagram [draft 01] : `Car.update()` and `Car.draw()`

* [***return to `Car`***](#sequence-diagram-draft-01--car)

```mermaid
---
title: Car.draw() and Car.update() interaction model - draft 1
---
sequenceDiagram
    autonumber
    %% -------------------------------------------------
    Actor TRAFFICTHREAD as Traffic thread
    Actor CARTHREAD as Car thread
    Actor MAINTHREAD as Main thread
    %% ---------------------------------
    participant SCENE as Scene
    participant LANE as Lane
    participant CAR as Car
    participant CARLIGHTS as Car Lights
    participant WHEEL as Wheel
    %% -------------------------------------------------
    %% -------------------------------------------------
    note left of MAINTHREAD : MAIN THREAD<br>[starting]
    activate MAINTHREAD
    %% -------------------------------------------------
    note right of MAINTHREAD : . . .
    note over MAINTHREAD,LANE : init scene
    note over CARTHREAD,MAINTHREAD : init car thread
    note over CARTHREAD,WHEEL : init car
    note right of MAINTHREAD : . . .
    note over TRAFFICTHREAD,LANE : init traffic thread
    note right of MAINTHREAD : . . .
    %% -------------------------------------------------
    %% -------------------------------------------------
    note left of CARTHREAD : CAR THREAD<br>[starting]
    activate CARTHREAD
    note over CARTHREAD,MAINTHREAD : start car thread
    %% -------------------------------------------------
    %% -------------------------------------------------
    note left of TRAFFICTHREAD : TRAFFIC THREAD<br>[starting]
    activate TRAFFICTHREAD
    note over TRAFFICTHREAD,MAINTHREAD : start traffic thread
    %% -------------------------------------------------
    %% -------------------------------------------------
    note right of MAINTHREAD : . . .
    %% ---------------------------------
    par MAIN THREAD
    %% ---------------------------------
    %% ---------------------------------
    MAINTHREAD ->>+ SCENE : update scene
    activate MAINTHREAD
    critical scene update
    %% -------------------------------
    note over SCENE : update
    %% -------------------------------
    end
    SCENE -->>- MAINTHREAD : done scene update
    deactivate MAINTHREAD
    %% -------------------------------
    MAINTHREAD ->>+ SCENE : draw scene
    activate MAINTHREAD
    critical scene draw
    %% -------------------------------
    note over SCENE,WHEEL : draw
    %% -------------------------------
    end
    SCENE -->>- MAINTHREAD : done scene draw
    deactivate MAINTHREAD
    %% -------------------------------
    %% ---------------------------------
    %% ---------------------------------
    and TRAFFIC CONTROL THREAD
    %% ---------------------------------
    %% ---------------------------------
    note over LANE : [suggestion]<br>sensor update
    %% -------------------------------
    TRAFFICTHREAD ->>+ LANE : update lane
    activate TRAFFICTHREAD
    critical lane update
    %% -------------------------------
    note over LANE : update
    %% -------------------------------
    end
    LANE -->>- TRAFFICTHREAD : done lane update
    deactivate TRAFFICTHREAD
    %% -------------------------------
    %% ---------------------------------
    %% ---------------------------------
    %% ---------------------------------
    %% ---------------------------------
    and CAR THREAD
    %% ---------------------------------
    %% ---------------------------------
    note over CAR,WHEEL : [suggestion]<br>sensor update
    %% -------------------------------
    CARTHREAD ->>+ CAR : update car
    activate CARTHREAD
    critical car update
    %% -------------------------------
    note over CAR,WHEEL : update
    %% -------------------------------
    end
    CAR -->>- CARTHREAD : done car update
    deactivate CARTHREAD
    %% -------------------------------
    %% ---------------------------------
    %% ---------------------------------
    end
    %% -------------------------------------------------
    %% -------------------------------------------------
    note left of CARTHREAD : CAR THREAD<br>[ending]
    deactivate CARTHREAD
    note right of MAINTHREAD : . . .
    %% -------------------------------------------------
    %% -------------------------------------------------
    note left of TRAFFICTHREAD : TRAFFIC THREAD<br>[ending]
    deactivate TRAFFICTHREAD
    note right of MAINTHREAD : . . .
    %% -------------------------------------------------
    note over MAINTHREAD,WHEEL : app cleanup
    %% -------------------------------------------------
    note left of MAINTHREAD : MAIN THREAD<br>[ending]
    deactivate MAINTHREAD
    %% -------------------------------------------------
    %% -------------------------------------------------
```
 

---

## State diagrams

### State diagram [draft 01]

[**[Back to Contents]**](#contents)

* simple car state diagram

```mermaid
stateDiagram-v2
    DRIVESIN : Enters scene
    DRIVESOUT : Exits scene
    INQUEUE : somewhere in the<br>lane queue
    FRONTQUEUE : Front of the<br>lane queue
    ININTERSECTION : Passing through<br>the intersection
    PASTINTERSECTION : Past the<br>intersection
    %%  --------------------
    %%  --------------------
    [*] --> DRIVESIN
    %%  --------------------
    DRIVESIN --> INQUEUE
    INQUEUE --> FRONTQUEUE
    FRONTQUEUE --> ININTERSECTION
    ININTERSECTION --> PASTINTERSECTION
    PASTINTERSECTION --> DRIVESOUT
    %%  --------------------
    DRIVESOUT --> [*]
```

---

## Architecture

### Server-Client relationship [draft 01]

[**[Back to Contents]**](#contents)

#### Server-Client relationship [draft 01] : Table

* table A

| client for | thread | server for | 
| ---: | :---: | :--- |
| n/a | **traffic control system** | *traffic light* |
| *traffic control system* | **traffic light** | *car at front* |
| *traffic light* | **car at front** | *car in queue* |
| *car at front* | **car in queue** | *car in queue* |

* table B

| client for | thread | server for | 
| ---: | :---: | :--- |
| n/a | **traffic control system** | *traffic light* |
| *traffic control system* | **traffic light** | *car at front* |
| *traffic light* | **car at front** | *car* |
| *traffic light* | **only car** | *n/a* |
| *car* | **car in queue** | *car* |
| *car* | **last car in queue** | *n/a* |


#### Server-Client relationship [draft 01] : Diagram

* suddenly forgotten how the cardinality works
* ***smells like complexity demon! begone foul creature!***

```mermaid
---
title: traffic server-client connection diagram
---
classDiagram
    class TrafficServer ["Traffic Control Server"]
    class TrafficLight ["Traffic Light"]
    class Car

    TrafficServer "1/1" -- "0/*" TrafficLight : control connection
    TrafficLight "0/*" .. "0/*" Car : light observation
    Car "0/1" <.. "1/1" Car : car in front
```

### Server-Client relationship [draft 02]

[**[Back to Contents]**](#contents)

#### Server-Client relationship [draft 02] : Table

| client for | thread | server for | 
| ---: | :---: | :--- |
| n/a | **traffic control system** | *traffic light* |
| *traffic control system* | **traffic light** | *lane* |
| *traffic light* | **lane** | n/a |


#### Server-Client relationship [draft 02] : Diagram

```mermaid
---
title: server-client connection diagram
---
classDiagram
    class TrafficServer ["Traffic Control Server"]
    class TrafficLight ["Traffic Light"]
    class Lane

    TrafficServer "1/1" -- "0/*" TrafficLight : control connection
    TrafficLight "0/*" .. "1/*" Lane : light observation
```

## Context Models

### Context Model [draft 01]

[**[Back to Contents]**](#contents)

```mermaid
---
title: context model [draft 01] - cars and light dependencies
---
classDiagram
    class Intersection

    class TLight_01["Traffic Light"]
    class Lane_01["Lane"]
    class Car_01["Car"]
    class Car_11["Car"]
    class Car_12["Car"]
    class Lane_02["Lane"]
    class Car_02["Car"]

    class TLight_02["Traffic Light"]
    class Lane_03["Lane"]
    class Car_03["Car"]
    class Lane_04["Lane"]
    class Car_04["Car"]

    class TLight_03["Traffic Light"]
    class Lane_05["Lane"]
    class Car_05["Car"]
    class Car_10["Car"]
    class Lane_06["Lane"]
    class Car_06["Car"]
    class Car_13["Car"]

    class TLight_04["Traffic Light"]
    class Lane_07["Lane"]
    class Car_07["Car"]
    class Lane_08["Lane"]
    class Car_08["Car"]
    class Car_09["Car"]

    %% =============================================
    %% =============================================
    %% ----------------------------------------
    %% --- UP LEFT LEFT

    Car_12 ..> Lane_01 : relates to
    Car_11 ..> Lane_01 : relates to
    Car_01 ..> Lane_01 : relates to
    Lane_01 ..> TLight_01 : relates to
    Car_12 <-- Car_11 : changes state
    Car_11 <-- Car_01 : changes state
    Car_01 <-- TLight_01 : changes state
    
    %% ----------------------------------------
    %% --- UP LEFT RIGHT

    Car_02 <-- TLight_01 : changes state
    Car_02 ..> Lane_02 : relates to
    Lane_02 ..> TLight_01 : relates to

    %% ----------------------------------------

    TLight_01 ..> Intersection : drawn by
    TLight_01 <-- Intersection : change state

    %% ----------------------------------------
    %% =============================================
    %% =============================================
    %% ----------------------------------------
    %% --- UP RIGHT LEFT

    Car_03 ..> Lane_03 : relates to
    Lane_03 ..> TLight_02 : relates to
    Car_03 <-- TLight_02 : changes state

    %% ----------------------------------------
    %% --- UP RIGHT RIGHT

    Car_04 <-- TLight_02 : changes state
    Car_04 ..> Lane_04 : relates to
    Lane_04 ..> TLight_02 : relates to
    
    %% ----------------------------------------

    TLight_02 <-- Intersection : change state
    TLight_02 ..> Intersection : drawn by

    %% ----------------------------------------
    %% =============================================
    %% =============================================
    %% ----------------------------------------
    %% --- DOWN LEFT LEFT
    
    TLight_03 <.. Lane_05 : relates to
    Lane_05 <.. Car_05 : relates to
    Lane_05 <.. Car_10 : relates to
    TLight_03 --> Car_05 : change state
    Car_05 --> Car_10 : change state

    %% ----------------------------------------
    %% --- DOWN LEFT RIGHT
    
    TLight_03 --> Car_06 : change state
    Car_06 --> Car_13 : change state
    Lane_06 <.. Car_06 : relates to
    Lane_06 <.. Car_13 : relates to
    TLight_03 <.. Lane_06 : relates to
    
    %% ----------------------------------------

    Intersection <.. TLight_04 : drawn by
    Intersection --> TLight_04 : change state

    %% ----------------------------------------
    %% =============================================
    %% =============================================
    %% ----------------------------------------
    %% --- DOWN RIGHT LEFT
    
    TLight_04 --> Car_07 : change state
    TLight_04 <.. Lane_07 : relates to
    Lane_07 <.. Car_07 : relates to

    %% ----------------------------------------
    %% --- DOWN RIGHT RIGHT
    
    TLight_04 <.. Lane_08 : relates to
    Lane_08 <.. Car_08 : relates to
    Lane_08 <.. Car_09 : relates to
    TLight_04 --> Car_08 : change state
    Car_08 --> Car_09 : change state
    
    %% ----------------------------------------

    Intersection --> TLight_03 : change state
    Intersection <.. TLight_03 : drawn by
    
    %% ----------------------------------------
    %% =============================================
    %% =============================================
```

---

## Concept Diagrams

[**[Back to Contents]**](#contents)

| ![simple architecture model](./images/simplearchitecturemodel_12062024.png) |
| :---: |
| *A simple model of the system somewhere between architecture and data flow models* - `12/06/2024` |

---

| ![abstracted diagram](./images/artisticdiagramwithnotes_12062024.png) |
| :---: |
| *An artistic abstraction of the lanes as conveyor belts with notes on queues and client-server model design* - `12/06/2024` |

---

| ![diagram of nodes](./images/lanelabeldiagram_12062024.png) |
| :---: |
| ![data flow diagram](./images/lanedataflowdiagram_12062024.png) |
| *An artistic abstraction of the lanes as conveyor belts with notes on queues and client-server model design* - `12/06/2024` |

---

## Experimentation details

### Misc

[***[back to Contents]***](#contents)

* `20/06/2024` - another project reminded us of the power of getting things to work with 1 instance before moving onto working with multiple.

### Render textures

[***[back to Contents]***](#contents)

* `19/06/2024` - managed to get render buffers to work in another repo, but still need to experiment more with vertex attributes

---
