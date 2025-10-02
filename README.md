# 🌐 Sycthe Keywords Reference

This document lists all reserved keywords in **Sycthe**, a minimal, JIT-friendly programming language designed for explicit control, asynchronous operations, and modular architecture.

---

## 📦 Module System

| Keyword   | Description |
|-----------|-------------|
| `expose`  | Declares the current file's module identity. |
| `access`  | Imports another module for use. All calls must use `module.symbol(...)`. |

---

## 🧱 Types & Contracts

| Keyword     | Description |
|-------------|-------------|
| `struct`    | Defines a composite data type with named fields. |
| `union`     | Declares a tagged union (sum type). |
| `contract`  | Declares a behavior contract (similar to interfaces). |

---

## ⚙️ Function Definitions

| Keyword       | Description |
|---------------|-------------|
| `funct`       | Declares a regular function. Cannot use `await`. |
| `async funct` | Declares an asynchronous function. Only `async funct` can use `await`. |
| `return`      | Returns values from a function. |
| `main`        | Declares the program entry point. |

---

## 🔁 Control Flow

| Keyword     | Description |
|-------------|-------------|
| `if`        | Conditional branching. |
| `else`      | Alternate branch. |
| `for`       | Loop over a range or sequence. |
| `while`     | Loop with a condition. |
| `switch`    | Multi-branch control structure. |
| `case`      | Branch inside a `switch`. |
| `default`   | Fallback case in a `switch`. |
| `break`     | Exit a loop or switch block. |

---

## ⚡ Asynchronous Execution

| Keyword  | Description |
|----------|-------------|
| `await`  | Triggers execution of an `async funct` and unwraps its `(value, error)` result. Only valid inside `async funct`. |

---

## ❗ Error Handling

| Keyword | Description |
|---------|-------------|
| `error` | Built-in error type. All errors must be explicitly handled. |
| `null`  | Represents absence of value or error. |

---

## 📤 Output & Literals

| Keyword  | Description |
|----------|-------------|
| `emit`   | Outputs a value to the console or log. |
| `true`   | Boolean literal for truth. |
| `false`  | Boolean literal for falsehood. |

---

