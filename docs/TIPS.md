# Development tips

## Researching lexer and parser concepts

When researching online (for example, with Google), use specific search
phrases that combine the compiler component with the concept you want to learn
about. Add terms such as `compiler`, `C`, or the name of a language when that
helps narrow the results.

For lexer research, try searches such as:

- `compiler lexer peek and next functions`
- `C lexer track source position`
- `lexer tokenize multiline comments`
- `C lexer token length pointer subtraction start current`
- `Crafting Interpreters scanner start current token length`
- `lexer token store source pointer and length or copy lexeme`
- `C lexer token span source offsets`

For parser research, try:

- `recursive descent parser expressions in C`
- `parser operator precedence compiler`
- `parser error recovery techniques`

When deciding whether the lexer needs to store a token's length, research how
lexers represent token spans. If the lexer keeps pointers to the token's start
and end, the byte length can often be calculated from those pointers; storing
it separately may still be useful if later stages need the span after those
pointers are no longer available.

For UTF-8 and hexadecimal-number research, try:

- `UTF-8 encoding Unicode code points bytes`
- `C validate UTF-8 input`
- `UTF-8 byte length versus character count`
- `C pointer difference UTF-8 string byte length code points`
- `compiler hexadecimal integer literal syntax`
- `C lexer parse hexadecimal literals`

UTF-8 support and hexadecimal literals are areas of interest for Sycthe; these
queries are starting points for research, not a finalized design or implemented
language feature. In particular, pointer differences in UTF-8 text count bytes,
not Unicode code points; choose deliberately which kind of length the lexer
and token representation need.

These searches are for learning about design and implementation approaches;
they are not instructions to search the repository. Treat external examples as
references, and adapt ideas to Sycthe's evolving design.

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

## Investigating the build

When figuring out how to build the project, explore both build approaches:

- [`nob.h`](https://github.com/tsoding/nob.h) is a header-only C library for
  writing build recipes in C.
- [GNU Make](https://www.gnu.org/software/make/manual/) is the reference manual
  for Makefiles. The repository currently has an empty `src/Makefile`.

No `nob.h` build file is present yet. If build instructions are added, document
the required compiler, commands, and expected output here or in the project
README.
