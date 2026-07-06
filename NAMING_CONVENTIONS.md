# Xenonium / XEM Naming Conventions

This documents the naming conventions already in consistent use across `XEM`,
`Xenonium`, `TestGame`, and `TestXEM`.

## Types (classes, structs, enums)
`PascalCase` - `Vec`, `Mat`, `Game`, `Logger`, `Window`, `InputManager`, `KeyState`.

## Interfaces
Prefixed with `I_` - `I_Renderer`, `I_Sprite`. Used only for abstract
classes with pure virtual methods; concrete classes never get the prefix.

## Functions and methods
`PascalCase`, including single-letter vector accessors (`X()`, `Y()`, `R()`)
and private implementation helpers (`AdditionImpl`, `SquaredLengthImpl`).

## Static member functions
`s_` prefix + `PascalCase` - `s_FramebufferSizeCallback`, `s_KeyCallback`,
`s_CursorPosCallback`, `s_MouseButtonCallback`. Used specifically to mark
GLFW-style static callback functions in `Window`.

## Member variables
- **Private members**: `m_` + `camelCase` - `m_initialized`, `m_frametime`,
  `m_keyboardKeys`.
- **Public data members on POD-style structs**: no prefix - `Vec::components`,
  `Mat::entries`, `GameData::deltaTime`, `Game::fps`. The rule is: if it's
  encapsulated private state, prefix it; if it's public data the type exists
  to expose, don't.

## Parameters and local variables
`camelCase` - `deltaTime`, `lastTime`, `windowTitle`, `elapsedTime`.

## Enumerators
`ALL_CAPS` - `LoggerLevel::FATAL`, `KeyState::PRESSED`.

## Macros
`ALL_CAPS_WITH_UNDERSCORES` - `XENONIUM_API`. (Note: `__XENONIUM_ENTRY_POINT`
and `__XENONIUM_DLL` use a leading double-underscore, which is technically a
reserved identifier in C++ - reserved for the compiler/standard library
everywhere, in any scope. Extremely common in practice, but worth knowing;
a single leading underscore, e.g. `_XENONIUM_ENTRY_POINT`, would be the more
technically-correct alternative if you ever want to tighten this up.)

## Namespaces
- `xem` / `xem_impl` - lowercase, library-style (mirrors `std`, matches how
  a reusable math library is typically named).
- `Xenonium` - `PascalCase`, engine-style.

These differ by project on purpose (XEM is meant to be a standalone,
reusable library; Xenonium is the engine that consumes it) - not a
conflict, just two conventions for two different kinds of code.

## Template parameters
Short, conventional: `T` (scalar type), `N`/`M` (dimensions), `Args`
(parameter packs), `Is` (index sequences).

## Files
`PascalCase` matching the primary type inside - `Vec.hpp`, `Window.cpp`,
`InputManager.hpp`. Umbrella/acronym headers stay all-caps to match the
acronym itself - `XEM.hpp`, `XEMTEST.hpp`.

## Internal helper naming pattern (XEM specifically)
Compile-time-unrolled operator helpers follow `<Operation>Impl` /
`<Operation>AssignImpl` - e.g. `AdditionImpl`, `SubtractionAssignImpl`.
Worth keeping this pattern for any new `Vec`/`Mat` operations you add.
