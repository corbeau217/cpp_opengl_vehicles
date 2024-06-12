# conceptual stuffs

* using the opengl and C++ for the things
* probably use the stuff:

## discussions posts

---
---
---

### important concepts

---

####  [traffic light control system](https://github.com/corbeau217/cpp_opengl_vehicles/discussions/3)

* the concurrent controller of the traffic
* would need to use semaphores/threads/sockets possibly
    * could use sockets as a way to simulate distributed systems
    * probably could semi grug this and keep it to being a normal concurrent system until later

---

#### [traffic light objects](https://github.com/corbeau217/cpp_opengl_vehicles/discussions/4)

* as the discussion design notes say, we should just treat these as glorified status lights
* can have these as just flat simple squares or changing the road colour until we're at a point that models matter
* discussion has some sketches for models though that could be preliminary/detailed design level

---

#### [car/vehicle objects](https://github.com/corbeau217/cpp_opengl_vehicles/discussions/5)

* these could stay as boxes until later to rush prototype then milestone the vehicle objects
* would need to have a worker that controls each vehicle
* preliminary/detailed suggestion would be to have as a node being shuffled between queues
    * possibly abstract it to be a packet or an "instruction"
    * would need to have some sort of behind the scenes "behavioural pattern" for where they want to turn

---

#### [controller status display object](https://github.com/corbeau217/cpp_opengl_vehicles/discussions/6)

* would be a way for debugging the effects of everything
* could have a circuit diagram style line shader to show what a thing is connected to
    * might be large scope for that
* kinda a board that just says what each thing does
* could just have this as overlay content/ minimap style something, so we dont have to suffer render texture hell
    * later we could make the minimap system of it actually be to a render texture then stick it on a screen

---

#### [road terrain object](https://github.com/corbeau217/cpp_opengl_vehicles/discussions/2)

* very simple each quad is a cell, and the cell that has inlet from more than 2 directions becomes intersection
* could feature creep into heightmap and tunnels etc
* could have this as flat colour to start with
* would also have the options of marked traffic lines later
* should have debug options of the status stuffs for lanes etc
* vertex attributes are chockers with texture mapping
* flat texture for feature creep later
    * have gutters maybe later?
    * tiles for the things
    * render texture is the height map
    * use that for the build tiles if rules allow

---
---
---

### less important concepts

#### [street lights](https://github.com/corbeau217/cpp_opengl_vehicles/discussions/7)
    * possible to grug
    * kinda very later stuff

---

#### gutters

* gutters could be a thing and then later could have rain go into gutters
* keep for the tiling the terrain maybe

---

#### skybox stuff

* stars at night
* sun during day
* clouds maybe
* planes fly over
    * render texture for the planes flying over