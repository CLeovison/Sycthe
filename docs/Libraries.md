# Future standard-library ideas

This page records possible libraries to explore once Sycthe has a working
compiler and a stable approach to packages, APIs, and error handling. These
are ideas only; none of the libraries below is currently specified or
implemented as a Sycthe package.

## Operating-system utilities

An OS library could provide portable access to common operating-system
services, such as environment variables, process information, filesystem
operations, and platform details. Platform-specific functionality may need
separate modules or clearly documented availability.

## Structured logging

A logging library could support log levels, structured fields, and configurable
outputs. Its design should make it possible for applications to choose how
messages are filtered and where they are written.

## HTTP and networking

An HTTP/networking library could provide HTTP client and server functionality,
with a broader networking API considered separately. Potential concerns include
timeouts, cancellation, streaming, and how network errors are represented.

## Design questions

Before implementing these libraries, define:

- how packages are declared, found, and versioned;
- which capabilities belong in the standard library versus external packages;
- how errors and resource cleanup are represented;
- which operating systems and networking use cases are supported.
