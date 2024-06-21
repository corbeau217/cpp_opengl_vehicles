# DOCS 03 : Designs and details

---
---


## About

* [***click here to return to [overview]***](./docs_00_overview.md#docs-03--detailed-designs-etc)

* much detail will happen
* will include the full uml hopefully

---

## Contents

* [***[The Graphics Pipeline]***](#the-graphics-pipeline)
    * [*[Graphics pipeline [draft 01]]*](#graphics-pipeline-draft-01)
* [***[Project render flow]***](#project-render-flow)
    * [*[Project render flow [draft 01]]*](#project-render-flow-draft-01)
* [***[Base code flow]***](#base-code-flow)
    * [*[Base code flow [draft 01]]*](#base-code-flow-draft-01)
* [***[Design pattern ideas for Concepts]***](#design-pattern-ideas-for-concepts)
    * [Design pattern ideas : Shaders](#design-pattern-ideas--shaders)
    * [Design pattern ideas : Mesh](#design-pattern-ideas--mesh)
    * [Design pattern ideas : Traffic controller](#design-pattern-ideas--traffic-controller)
    * [Design pattern ideas : Cars](#design-pattern-ideas--cars)
    * [Design pattern ideas : Traffic light](#design-pattern-ideas--traffic-light)
* [***[Experimentation details]***](#experimentation-details)
* [***[References]***](#references)

---

## The Graphics Pipeline

### Graphics pipeline [draft 01]

[***[back to Contents]***](#contents)

* minimalist diagram to illustrate the pipeline process

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

## Base code flow

### base code flow [draft 01]

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

## Design pattern ideas for concepts

### Design pattern ideas : Shaders

[***[back to Contents]***](#contents)

* [facade pattern](https://refactoring.guru/design-patterns/facade)

### Design pattern ideas : Mesh

[***[back to Contents]***](#contents)

* [facade pattern](https://refactoring.guru/design-patterns/facade) possibly

### Design pattern ideas : Traffic controller

[***[back to Contents]***](#contents)

* almost certainly [mediator pattern](https://refactoring.guru/design-patterns/mediator)

### Design pattern ideas : Cars

[***[back to Contents]***](#contents)

* [strategy pattern](https://refactoring.guru/design-patterns/strategy) for behaviour and travel desire
* [adapter pattern](https://refactoring.guru/design-patterns/adapter) for the different cars?
* [observer pattern](https://refactoring.guru/design-patterns/observer) for looking at the light from car or next car

### Design pattern ideas : Traffic light

[***[back to Contents]***](#contents)

* likely also [mediator pattern](https://refactoring.guru/design-patterns/mediator) with lanes
* [state pattern](https://refactoring.guru/design-patterns/state) for the state of the lights
* [command pattern](https://refactoring.guru/design-patterns/command) for handling the changes from controllers?
* [adapter pattern](https://refactoring.guru/design-patterns/adapter) for between the command/state and the multi/single light array itself?
* [observer pattern](https://refactoring.guru/design-patterns/observer) for looking at the light from car

---

## Experimentation details

### Misc

[***[back to Contents]***](#contents)

* `20/06/2024` - another project reminded us of the power of getting things to work with 1 instance before moving onto working with multiple.

### Render textures

[***[back to Contents]***](#contents)

* `19/06/2024` - managed to get render buffers to work in another repo, but still need to experiment more with vertex attributes

---

## references

### Design patterns

[***[back to Contents]***](#contents)

* [Refactoring guru design patterns catalogue](https://refactoring.guru/design-patterns/catalog)

### Graphics pipeline stuffs

[***[back to Contents]***](#contents)

* [khronos page for the rendering pipeline](https://www.khronos.org/opengl/wiki/Rendering_Pipeline_Overview)
* [this github pages page seems useful](https://kenny-designs.github.io/zim-websites/opengl/Shaders_and_the_Rendering_Pipeline.html)