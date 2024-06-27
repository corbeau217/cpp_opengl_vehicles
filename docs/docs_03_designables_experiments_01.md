# DOCS 02 : requirements : SUPPLIMENT 01 : DEADLOCKS

---
---

## Doc links

Documentation page links:
* [**[readme]**](./readme.md#doc-links)
* [**[docs 00 : overview]**](./docs_00_overview.md#doc-links)
* [**[docs 01 : conceptual]**](./docs_01_conceptual.md#doc-links)
* [**[docs 02 : requirements]**](./docs_02_requirements.md#doc-links)
* [**[docs 03 : designables]**](./docs_03_designables.md#doc-links)
    * [***[docs 03 : designables : render texture experimenting]***](./docs_03_designables_experiments_01.md#doc-links)
* [**[docs 04 : developments]**](./docs_04_developments.md#doc-links)

---

## About

* first majore experiment was to get render textures working

---

## details and changes from base template

* this required a restructuring of the shader code to accomodate for seperating out the shaders correctly
* also required some playing around with frame buffers and textures
* as well as decoupling the vertex attributes from the triangle object
* majority of this is reflect in the [opengl_rendertexture](https://github.com/corbeau217/opengl_rendertexture) project

---