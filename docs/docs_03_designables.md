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
    * [**[docs 02 : requirements : model design drafts suppliment]**](./docs_02_requirements_suppliment_02.md#doc-links)
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