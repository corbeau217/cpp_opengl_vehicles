# DOCS 03 : Designables : suppliments 01 : design pattern diagrams

---
---

## Doc links

Documentation page links:
* [**[readme]**](./readme.md#doc-links)
* [**[docs 00 : overview]**](./docs_00_overview.md#doc-links)
* [**[docs 01 : conceptual]**](./docs_01_conceptual.md#doc-links)
* [**[docs 02 : requirements]**](./docs_02_requirements.md#doc-links)
* [**[docs 03 : designables]**](./docs_03_designables.md#doc-links)
    * [**[docs 03 : designables : experiments 01 : render texture experimenting]**](./docs_03_designables_experiments_01.md#doc-links)
    * [**[docs 03 : designables : suppliments 01 : design pattern diagrams]**](./docs_03_designables_suppliment_01.md#doc-links)
* [**[docs 04 : developments]**](./docs_04_developments.md#doc-links)

---

## About

* this is for the details about the design patterns we suggested

---

## Contents

* [[Design patterns : adapter pattern]](#design-patterns--adapter-pattern)
* [[Design patterns : command pattern]](#design-patterns--command-pattern)
* [[Design patterns : facade pattern]](#design-patterns--facade-pattern)
* [[Design patterns : mediator pattern]](#design-patterns--mediator-pattern)
* [[Design patterns : observer pattern]](#design-patterns--observer-pattern)
* [[Design patterns : singleton pattern]](#design-patterns--singleton-pattern)
* [[Design patterns : state pattern]](#design-patterns--state-pattern)
* [[Design patterns : strategy pattern]](#design-patterns--strategy-pattern)

---

## Design patterns

[[Refactoring guru design patterns catalogue]](https://refactoring.guru/design-patterns/catalog)

### Design patterns : adapter pattern

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

### Design patterns : command pattern

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

### Design patterns : facade pattern

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

### Design patterns : mediator pattern

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

### Design patterns : observer pattern

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

### Design patterns : singleton pattern

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

### Design patterns : state pattern

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

### Design patterns : strategy pattern

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

