# Development tips

## Searching the codebase

Use specific, direct keywords instead of broad searches. For example, when
investigating lexer behavior, search for terms such as:

- `lexer`
- `peek`
- `advance`
- `skip`
- `position`
- `start`
- `token`
- `type`

Combine related terms when you know what you are looking for, such as `lexer
position` or `token type`. Search results depend on which parts of the
frontend have been implemented; some relevant files may currently be empty or
only contain declarations.

## Useful starting points

- [`src/frontend/token.h`](../src/frontend/token.h) contains the current token
  type declarations.
- `src/frontend/lexer.c` and `src/frontend/lexer.h` are the intended lexer
  files.
- `src/frontend/parser.c` and `src/frontend/parser.h` are the intended parser
  files.
- `src/frontend/semantic.c` and `src/frontend/semantic.h` are the intended
  semantic-analysis files.

Treat declarations and filenames as signposts, not proof that the corresponding
behavior is implemented. Check the source and examples before relying on a
feature.
