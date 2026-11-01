# Memory management

This page collects background reading for memory-management decisions in
Sycthe, especially around arenas and the lifetime of allocated data. These
links are references, not a specification for the project or a description of
implemented behavior.

## Topics to understand

Before choosing an allocation strategy, consider:

- **Allocation patterns:** how long allocations need to live and whether they
  are released individually or together.
- **Arena ownership:** which component owns an arena, who may use its
  allocations, and when the arena can be reset or destroyed.
- **Lifetimes:** whether values can outlive the memory they refer to,
  particularly when data is shared across compiler or runtime phases.
- **Failure handling:** how allocation failures are reported and handled.
- **Cleanup:** how resources other than memory are released when arena-backed
  data is discarded.

## Reading list

### Arena allocation and allocation strategies

- [Memory Allocation Strategies: Arena Allocators](https://www.gingerbill.org/article/2019/02/08/memory-allocation-strategies-002/)
  — an introduction to arena allocation as one allocation strategy.
- [How to Actually Use Arenas and Program in C](https://alonsozamorano.me/how-to-actually-use-arenas-and-program-in-c/)
  — practical discussion of using arenas in C.
- [Untangling Lifetimes: The Arena Allocator](https://www.dgtlgrove.com/p/untangling-lifetimes-the-arena-allocator)
  — connects arena allocation with reasoning about lifetimes.

### Lifetimes and implementation examples

- [Memory Lifetimes](https://jasongorman.uk/writing/memory-lifetimes/)
  — background on memory lifetime concepts.
- [ccgargantua/arena-allocator](https://github.com/ccgargantua/arena-allocator)
  — an arena-allocator implementation to inspect.
- [tsoding/arena](https://github.com/tsoding/arena)
  — another arena-allocation implementation example.

## Applying this to Sycthe

Use these resources to inform future decisions about allocation ownership and
the lifetime of data such as tokens, syntax trees, and runtime values. Compare
designs against the project's actual needs before adopting one; examples from
other projects are not automatically suitable for Sycthe.
