# DEVLOG

## 2026-03-24
- Set up the ExpressionEvaluator project folder.
- Initialized Git and connected the project to GitHub.
- Added main.cpp and ArrayStack.h to the repository.
- Made the initial setup commit and pushed to GitHub.

## 2026-03-25
- Implemented tokenizer in main.cpp.
- Added operator precedence helper for +, -, *, and /.
- Tested running the program in CLion and fixed build configuration with CMake.
- Confirmed the executable now runs from the IDE.

## 2026-03-26
- Worked on main.cpp.
- Fixed tokenizer.
- Added precedence() function.
- Implemented isValidPostfix().
- Tested with `3 4 +` and confirmed it was detected as POSTFIX.
- Result was still `0` because evalPostfix() is not implemented yet.

