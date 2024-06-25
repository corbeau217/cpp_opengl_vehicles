# DOCS 03 : Designs and details

---
---

## Doc links

Documentation page links:
* [**[readme]**](./readme.md#doc-links)
* [**[docs 00 : overview]**](./docs_00_overview.md#doc-links)
* [**[docs 01 : conceptual]**](./docs_01_conceptual.md#doc-links)
    * [**[docs 01 : conceptual : old conceptual documentation]**](./docs_01_conceptual_suppliment_01.md#doc-links)
* [**[docs 02 : requirements]**](./docs_02_requirements.md#doc-links)
    * [**[docs 02 : requirements : deadlock suppliment]**](./docs_02_requirements_suppliment_01.md#doc-links)
* [***[docs 03 : designables]***](./docs_03_designables.md#doc-links)
* [**[docs 04 : developments]**](./docs_04_developments.md#doc-links)

---

## About

* much detail will happen
* will include the full uml hopefully

---

## Contents

* [***[Pre-Design stage checklist]***]()
* [***[Project render flow]***](#project-render-flow)
    * [*[Project render flow [draft 01]]*](#project-render-flow-draft-01)
* [***[Model diagrams]***](#model-diagrams)
* [***[Library documentation]***](#library-documentation)
    * [*[Graphics pipeline [draft 01]]*](#graphics-pipeline-draft-01)
    * [*[Base code flow [draft 01]]*](#base-code-flow-draft-01)
* [***[References]***](#references)

---

## Pre-design stage checklist

* [x] - `PDDR_01` - ~~Required fields~~
    * *~~Required data held by our objects~~*
* [x] - `PDDR_02` - ~~suggested design patterns for actors/objects~~
    * *~~proposed design patterns~~*
* [x] - `PDDR_03` - ~~listing deadlock avoidance methods~~
    * *~~a list of the deadlock avoidance methods that work for our system~~*
* [ ] - `PDDR_04` - **simple architectural diagrams for our system**
    * *to show how the actors/object connect to each other and make sure we're not doing spooky design choices sooner rather than later*
* [x] - `PDDR_05` - ~~reorganise documentation~~
    * *~~putting things in the correct documentation files~~*
* [x] - `PDDR_06` - ~~requirement dependency map~~
    * *~~mapped out requirement dependencies~~*
* [x] - `PDDR_07` - ~~importance of requirements~~
    * *~~importance of each requirement~~*
* [ ] - `PDDR_08` - **risk mapping**
    * *risk assessment for work required for a thing to function (and how likely to get it working first try) in relation to importance*
* [x] - `PDDR_09` - ~~checklist table for all the requirements~~
    * *~~somewhere having a checklist for our requirements so we can tick off what's complete~~*
* [ ] - `PDDR_10` - **concept diagrams of models in documentation**
    * *adding the various model concept diagram drafts to the documentation*
* [ ] - `PDDR_11` - **...**
    * *...*

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

---

## Library documentation

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

## references

### Design patterns

[***[back to Contents]***](#contents)

* [Refactoring guru design patterns catalogue](https://refactoring.guru/design-patterns/catalog)

### Graphics pipeline stuffs

[***[back to Contents]***](#contents)

* [khronos page for the rendering pipeline](https://www.khronos.org/opengl/wiki/Rendering_Pipeline_Overview)
* [this github pages page seems useful](https://kenny-designs.github.io/zim-websites/opengl/Shaders_and_the_Rendering_Pipeline.html)