# DOCS 03 : Designables

---
---

## Doc links

Documentation page links:
* [**[readme]**](./readme.md#doc-links)
* [**[docs 00 : overview]**](./docs_00_overview.md#doc-links)
* [**[docs 01 : conceptual]**](./docs_01_conceptual.md#doc-links)
* [**[docs 02 : requirements]**](./docs_02_requirements.md#doc-links)
* [***[docs 03 : designables]***](./docs_03_designables.md#doc-links)
    * [**[docs 03 : designables : experiments 01 : render texture experimenting]**](./docs_03_designables_experiments_01.md#doc-links)
    * [**[docs 03 : designables : suppliments 01 : design pattern diagrams]**](./docs_03_designables_suppliment_01.md#doc-links)
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
* [***[OpenGL documentation]***](#opengl-documentation)
    * [*[OpenGL documentation : pipeline [draft 01]]*](#opengl-documentation--pipeline-draft-01)
    * [*[OpenGL documentation : pipeline [draft 02]]*](#opengl-documentation--pipeline-draft-02)
* [***[Library documentation]***](#library-documentation)
    * [*[Library references : Github repos]*](#library-references--github-repos)
    * [*[Library references : GLFW]*](#library-references--glfw)
    * [*[Library references : GLAD]*](#library-references--glad)
    * [*[Library references : GLM]*](#library-references--glm)
    * [*[Library references : template repo structure [draft 01]]*](#library-references--template-repo-structure-draft-01)
* [***[General references]***](#general-references)
    * [*[General references : Markdown badges]*](#general-references--markdown-badges)

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

## OpenGL documentation

* [openglbook](https://openglbook.com/)
    * lots of graphics and details
* [docs.gl](https://docs.gl/)
* [khronos wiki](https://www.khronos.org/opengl/wiki/Main_Page)
    * [khronos getting started](https://www.khronos.org/opengl/wiki/Getting_Started)
    * [khronos page for the rendering pipeline](https://www.khronos.org/opengl/wiki/Rendering_Pipeline_Overview)
* [this github pages page seems useful](https://kenny-designs.github.io/zim-websites/opengl/Shaders_and_the_Rendering_Pipeline.html)
* something to note is the [opengl pipeline documentation](https://www.opengl.org/img/uploads/pipeline/pipeline_004.pdf)
    * especially page 7 what da henk
* [core specification document ogl4.1](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf)
    * has block diagram of the data [pg17](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf#page=34)
    * primitives and vertices [pg20](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf#page=37)
    * tessellation details [pg112](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf#page=120)
    * geometry shaders [pg127](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf#page=144)
    * rasterisation [pg156](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf#page=173)
    * per fragment operations [pg253](https://registry.khronos.org/OpenGL/specs/gl/glspec41.core.pdf#page=270)
* [GLSL shader language documentation](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.10.pdf)
    * preprocessor [pg14](https://registry.khronos.org/OpenGL/specs/gl/GLSLangSpec.4.10.pdf#page=14)
    * literally has the grammar at the end omg
* [opengl reference cards](https://www.khronos.org/files/opengl41-quick-reference-card.pdf)


### OpenGL documentation : pipeline [draft 01]

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

### OpenGL documentation : pipeline [draft 02]

[***[back to Contents]***](#contents)

```mermaid
flowchart TB
    VERTEXDATA[["Vertex Data[]"]]
    VERTEXSHADER{{Vertex Shader}}
    GEOMETRYSHADER{{Geometry Shader}}
    SHAPEASSEMBLY(Shape Assembly)
    RASTERISATION(Rasterisation)
    FRAGMENTSHADER{{Fragment Shader}}
    TESTSANDBLENDING(Tests and Blending)
    OUTPUTDISPLAY[[Output Display]]
    
    VERTEXDATA --> VERTEXSHADER --> GEOMETRYSHADER --> SHAPEASSEMBLY --> RASTERISATION --> FRAGMENTSHADER --> TESTSANDBLENDING --> OUTPUTDISPLAY
    
```

---

## Library documentation

### Library references : Github repos

[***[back to Contents]***](#contents)

* [![GLAD1 GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLAD1)](https://github.com/Dav1dde/glad/tree/master)
    * GLAD [doesnt include vulkan?]
* [![GLAD2 GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLAD2)](https://github.com/Dav1dde/glad)
    * text heavy documentation in wiki sub section
    * as per the github readme, it's "pretty stable" and suggested to use now

* [![GLFW GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLFW)](https://github.com/glfw/glfw)
    * has links to extensive documentation with graphics

* [![GLM GITHUB REPO](https://img.shields.io/badge/GITHUB-100000?style=for-the-badge&logo=github&logoColor=white&label=GLM)](https://github.com/g-truc/glm)
    * has information on the cmake building
    * documentation is very text / code heavy
    * documentation uses doxygen

### Library references : GLAD

[***[back to Contents]***](#contents)

* [[main documentation for using GLAD with C]](https://github.com/Dav1dde/glad/wiki/C)
* [[documentation for building with CMAKE]](https://github.com/Dav1dde/glad/wiki/C#cmake)

| version | generator link | github repo | wiki / documentation |
| ------- | -------------- | ----------- | -------------------- |
| GLAD 1  | [generator](https://glad.dav1d.de/) | [repo](https://github.com/Dav1dde/glad/tree/master) | [repo readme](https://github.com/Dav1dde/glad/tree/master?tab=readme-ov-file#glad) |
| GLAD 2  | [generator](https://gen.glad.sh/) | [repo](https://github.com/Dav1dde/glad) | [github repo wiki](https://github.com/Dav1dde/glad/wiki/C) |



### Library references : GLFW

[***[back to Contents]***](#contents)

* [notes about `glfwCreateWindow` on MacOS X 10.7 and later](https://www.glfw.org/docs/latest/compat_guide.html#compat_osx)
* [[GLFW quick guide]](https://www.glfw.org/docs/latest/quick_guide.html)
* [[GLFW intro to API]](https://www.glfw.org/docs/latest/intro_guide.html)
    * [[GLFW window guide]](https://www.glfw.org/docs/latest/window_guide.html)
    * [[GLFW context guide]](https://www.glfw.org/docs/latest/context_guide.html)
    * [[GLFW monitor guide]](https://www.glfw.org/docs/latest/monitor_guide.html)
    * [[GLFW input guide]](https://www.glfw.org/docs/latest/input_guide.html)
    * [[GLFW compile guide]](https://www.glfw.org/docs/latest/compile_guide.html)
    * [[GLFW build guide]](https://www.glfw.org/docs/latest/build_guide.html)
        * [cmake building and linking from source](https://www.glfw.org/docs/latest/build_guide.html#build_link_cmake_source)

### Library references : GLM 

[***[back to Contents]***](#contents)

* [[GLM API documentation link]](http://glm.g-truc.net/0.9.9/api/modules.html)
* [[manual link on github]](https://github.com/g-truc/glm/blob/master/manual.md)
    * [depenencies](https://github.com/g-truc/glm/blob/master/manual.md#section1_4)
        * according to the above link, it doesnt depend on anything
    * [finding GLM with CMAKE](https://github.com/g-truc/glm/blob/master/manual.md#section1_5)
* repo readme references:
    * [[cmake building and installing]](https://github.com/g-truc/glm?tab=readme-ov-file#build-and-install)
    * [[cmake using `FetchContent`]](https://github.com/g-truc/glm?tab=readme-ov-file#cmake-using-fetchcontent)


### Library references : template repo structure [draft 01]

[***[back to Contents]***](#contents)

* template will end up not being used very much as we need to remake the shader handling code
* also need to mess with vertex/frame buffer stuff

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
