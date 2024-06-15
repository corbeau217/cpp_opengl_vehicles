# DOCS 01 : conceptual stuffs

---
---

## About

[**[return to overview]**](./docs_00_overview.md#docs-01--concepts-and-some-throwing-around-ideas)

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
* [**[Use cases]**](#use-cases)
    * [*[Simple use cases]*](#simple-use-cases)
* [**[Concept-Domain models]**](#concept-domain-models)
    * [*[Concept-Domain model [draft 01]]*](#concept-domain-model-draft-01)
    * [*[Concept-Domain model [draft 02]]*](#concept-domain-model-draft-02)
* [**[Sequence diagrams]**](#sequence-diagrams)
    * [*[Sequence diagram [draft 01]]*](#sequence-diagram-draft-01)
* [**[Concept Diagrams]**](#concept-diagrams)

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

* [`Scene`](#scene)
* [`Sky day`](#sky-day)
* [`Sky night`](#sky-night)
* [`Sun`](#concept-identification-listing-draft-02)
* [`Clouds`](#clouds)
* [`Moon`](#concept-identification-listing-draft-02)
* [`Car`](#car)
* [`Car Lights`](#concept-identification-listing-draft-02)
* [`Wheel`](#concept-identification-listing-draft-02)
* [`Diagnostic Screen`](#traffic-diagnostics-screen)
* [`Traffic Controller`](#traffic-controller)
* [`Lane`](#lane)
* [`Traffic Light`](#traffic-light)
* [`Intersection`](#intersection)
* [`Terrain`](#concept-identification-listing-draft-02)
* [`Building`](#concept-identification-listing-draft-02)
* [`Mesh`](#concept-identification-listing-draft-02)

## Use cases

### simple use cases

[**[Back to Contents]**](#contents)

#### `Car`

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

#### `Clouds`

* as the `Clouds` i want to ***move*** with the *wind*

#### `Lane`

* as a `Lane` i want to have a `Traffic Light` ***state*** holder

#### `Scene`

* as a `Scene` i want to ***generate*** a `Sky Day`
* as a `Scene` i want to ***generate*** a `Sky Night`
* as a `Scene` i want to ***generate*** a `Car`
* as a `Scene` i want to ***generate*** an `Intersection`
* as a `Scene` i want to ***generate*** a `Building`
* as a `Scene` i want to ***generate*** the `Terrain`
* as a `Scene` i want to ***generate*** the `Clouds`

#### `Sky Day`

* as a `Sky Day` i want to ***check*** the `time of day`
* as a `Sky Day` i want to ***display*** the `Clouds`
* as a `Sky Day` i want to ***display*** the `Sun`
* as a `Sky Day` i want to ***display*** the `Atmosphere colour`

#### `Sky Night`

* as a `Sky Night` i want to ***check*** the `time of day`
* as a `Sky Night` i want to ***display*** the `Clouds`
* as a `Sky Night` i want to ***display*** the `Moon`
* as a `Sky Night` i want to ***display*** the `Stars`

#### `Traffic Controller`

* as a `Traffic Controller` i want to ***change*** the `Lane` which can *move*

#### `Traffic diagnostics screen`

* as a `Traffic diagnostics screen` i want to ***check*** the ***state*** of the `Traffic Controller`
* as a `Traffic diagnostics screen` i want to ***check*** the *number* of `Car`s in a `Lane`

#### `Traffic Light`

* as a `Traffic Light` i want to ***update*** my ***state***
* as a `Traffic Light` ***state*** holder i want to ***generate*** my `Mesh`

#### `Intersection`

* as an `Intersection` i want to ***generate*** the `Intersection` `Mesh`
* as an `Intersection` i want to ***generate*** the `Lane` objects

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

---

## Sequence diagrams

* mermaid chart [[sequence diagrams syntax reference]](https://mermaid.js.org/syntax/sequenceDiagram.html)
* will probably need to redo after we fully confirm the things with a proper domain model

<!-- * stub stuffs:
```mermaid
sequenceDiagram
    participant SCENE as Scene
    participant SUN as Sun
    participant CLOUDS as Clouds
    participant MOON as Moon
    participant TRAFFICCONTROLLER as Traffic Controller
    participant TRAFFICLIGHT as Traffic Light
    participant INTERSECTION as Intersection
    participant DIAGNOSTICSSCREEN as Diagnostic Screen
    participant LANE as Lane
    participant SKYDAY as Sky day
    participant SKYNIGHT as Sky night
    participant CAR as Car
    participant WHEEL as Wheel
    participant CARLIGHTS as Car Lights
    participant MESH as Mesh
    participant TERRAIN as Terrain
    participant BUILDING as Building
``` -->

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

* todo
```mermaid
sequenceDiagram
    autonumber
    %% -------------------------------------------------
    participant SCENE as Scene
    participant LANE as Lane
    participant CAR as Car
    participant CARLIGHTS as Car Lights
    participant WHEEL as Wheel
    %% ...
    %% -------------------------------------------------
    note over SCENE,WHEEL: . . . 
    %% -------------------------------------------------
    critical Initialise
    note left of SCENE: creater calls<br>scene.init()
    activate SCENE
    %% ...
    deactivate SCENE
    note left of SCENE: returns control<br>to creator
    end
    %% -------------------------------------------------
    note over SCENE,WHEEL: . . . 
    %% -------------------------------------------------
    loop Draw
    note left of SCENE: creator calls<br>scene.draw()
    activate SCENE
    %% ...
    deactivate SCENE
    note left of SCENE: returns control<br>to creator
    end
    %% -------------------------------------------------
    note over SCENE,WHEEL: . . . 
    %% -------------------------------------------------
    loop Update lane state
    note left of CAR: thread calls<br>car.update()
    activate CAR
    %% ...
    deactivate CAR
    note left of CAR: returns control<br>to thread
    end
    %% -------------------------------------------------
    note over SCENE,WHEEL: . . . 
    %% -------------------------------------------------
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

