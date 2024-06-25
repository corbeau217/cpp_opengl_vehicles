# DOCS 02 : requirements : SUPPLIMENT 01 : DEADLOCKS

---
---

## Doc links

Documentation page links:
* [**[readme]**](./readme.md#doc-links)
* [**[docs 00 : overview]**](./docs_00_overview.md#doc-links)
* [**[docs 01 : conceptual]**](./docs_01_conceptual.md#doc-links)
    * [**[docs 01 : conceptual : old conceptual documentation]**](./docs_01_conceptual_suppliment_01.md#doc-links)
* [**[docs 02 : requirements]**](./docs_02_requirements.md#doc-links)
    * [***[docs 02 : requirements : deadlock suppliment]***](./docs_02_requirements_suppliment_01.md#doc-links)
* [**[docs 03 : designables]**](./docs_03_designables.md#doc-links)
* [**[docs 04 : developments]**](./docs_04_developments.md#doc-links)

---

## About

* this file is a supliment to the requirements document with details about deadlocks and deadlock avoidance

---

## Deadlock conditions

* a deadlock situation on a resource can arise only if all of the following conditions occur simultaneously in a system:
    1. **Mutual exclusion**
        1. at least one resource must be held in a non-shareable mode
            * we are assuming that one resource could have multiple instances
            * that is, only one process at a time can use the resource
            * otherwise, the processes would not be prevented from using the resource when necessary.
        2. only one process can use the at any given instant of time
    2. **Hold and wait** *or* **Resource holding**:
        1. a process currently holding at least one resource and requesting additional resources which are held by other processes
    3. **No preemption**:
        1. a resource can be released only voluntarily by the process holding it
    4. **Circular wait**:
        1. each process must be waiting for a resource which is being held by another process, which in turn is waiting for the first process to release the resource.

---

## Deadlock correction

1. **Process termination**:
    * one or more processes involved in the deadlock may be aborted.
    * one could choose to abort all competing processes involved in the deadlock.
    * this ensures that deadlock is resolved with certainty and speed.
    * but the expense is high as partial computations will be lost.
    * or, one could choose to abort one process at a time until the deadlock is resolved.
    * this approach has a high overhead because after each abort an algorithm must determine whether the system is still in deadlock
    * several factors must be considered while choosing a candidate for termination, such as priority and age of the process
2. **Resource preemption**:
    * resources allocated to various processes may be successively preempted and allocated to other processes until the deadlock is broken.

* not advisable to do deadlock correction and instead go for prevention and avoidance
* this is due to the fact it's very painful to detect without room for doubt

---

## Deadlock prevention

* just to work against one of the 4 requirements of deadlock

1. **Mutual exclusion**:
    * removing means that no process will have exclusive access to a resource.
    * this proves impossible for resources that cannot be `spooled`.
    * but even with spooled resources, the deadlock could still occur
    * algorithms that avoid mutual exclusion are called `non-blocking synchronization` algorithms
2. **Hold and wait**: 
    * may be removed by requiring processes to request all the resources they will need before starting up (or before embarking upon a particular set of operations)
        * this advance knowledge is frequently difficult to satisfy and, in any case, is an inefficient use of resources.
    * another way is to require processes to request resources only when it has none
        * first, they must release all their currently held resources before requesting all the resources they will need from scratch.
        * this too is often impractical.
        * it is so because resources may be allocated and remain unused for long periods.
        * also, a process requiring a popular resource may have to wait indefinitely, as such a resource may always be allocated to some process, resulting in `resource starvation`
            * these algorithms, such as `serialised tokens`, are known as `all-or-none` algorithms
3. **No preemption**: 
    * may also be difficult or impossible to avoid as a process has to be able to have a resource for a certain amount of time, or the processing outcome may be inconsistent or `thrashing` may occur.
    * however, the inability to enforce preemption may interfere with a `priority` algorithm.
    * preemption of a "locked out" resource generally implies a `rollback`, and is to be avoided since it is very costly in overhead.
    * algorithms that allow preemptions include `lock-free and wait-free algorithms` and `optimistic concurrency control`.
    * if a process holding some resources and requests for some another resource(s) that cannot be immediately allocated to it, the condition may be removed by releasing all the currently being held resources of that process.
4. **Circular wait**: 
    * approaches that avoid circular waits include disabling interrupts during critical sections and using a hierachy to determine a `partial ordering` of resources.
    * if no obvious hierachy exists, even the memory address of resources has been used to determine ordering and resources are requested in the increasing order of the enumeration.
    * `Dijkstra's solution` can also be used


---