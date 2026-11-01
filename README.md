# Sycthe

Sycthe is an experimental programming-language project. The repository contains
early C code for language and runtime components alongside notes about the
language's intended syntax and future direction. It is not yet a complete,
usable compiler or interpreter.

> **Project status:** The frontend is unfinished. The token definitions in
> `src/frontend/token.h` describe planned language constructs, but do not by
> themselves mean those constructs can currently be compiled or run. The files
> in `example/` are syntax sketches, not verified programs.

## Language design

The source-file extension is `.syth`. The syntax and feature set are still
evolving; the lists below summarize the current design notes and token
definitions rather than a stable language specification.

### Declared keywords

The token definitions currently include:

`proc`, `if`, `else`, `for`, `range`, `switch`, `case`, `break`, `default`,
`return`, `struct`, `union`, `contract`, `enum`, `const`, `later`, and `when`.

The module-related tokens are `scope` and `access`. Their intended roles are
package and dependency declarations, respectively.

### Declared types and values

The token definitions include the type names `string`, `float`, `int`, `bool`,
`decimal`, and `double`, as well as the boolean values `true` and `false`.

### Declared operators and punctuation

The token definitions include arithmetic operators (`+`, `-`, `*`, `/`, `%`),
assignment (`=`), equality and comparison operators (`==`, `!=`, `<`, `<=`,
`>`, `>=`), logical operators (`&&`, `||`, `!`), and compound assignments
(`+=`, `-=`, `*=`, `/=`, `%=`). Commas, semicolons, parentheses, braces,
brackets, colons, and dots are also represented.

These are token declarations, not a promise that every operator or construct
has working parsing or runtime behavior.

### Syntax sketch

The examples show the intended procedure syntax:

```syth
proc main(x int, y int) {
    return x + y;
}
```

This is illustrative only; the current frontend does not yet provide a
complete way to compile or run it.

## Project layout

| Path | Purpose |
| --- | --- |
| `src/frontend/` | Lexer, parser, semantic-analysis, and token source files |
| `src/ast/` | Abstract syntax tree source files |
| `src/core/` | Foundational C utilities, including arrays, strings, arenas, and UTF-8 |
| `src/runtime/` | Runtime and memory-management source files |
| `example/` | Illustrative `.syth` syntax sketches |
| `docs/` | Working notes and design resources |

`src/main.c` is currently a small C string-utility demonstration, not a Sycthe
language runner.

## Development roadmap

The following items are planned or under exploration:

- String interpolation. Token placeholders are present, but interpolation is
  not implemented end to end.
- UTF-8 support throughout the language and runtime.
- Signals/reactivity, with a focus on frontend application development.
- Behavior-oriented concurrency and a defined concurrency model.
- Multiline comments.
- Exploring a register-based virtual machine.

## Documentation

- [Library notes](docs/Libraries.md)
- [Memory-management references](docs/MemoryManagement.md)
- [Development tips](docs/TIPS.md)

These documents are working notes and may be incomplete.
