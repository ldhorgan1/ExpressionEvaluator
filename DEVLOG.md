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
- Tested with 3 4 + and confirmed it was detected as POSTFIX.
- Result was still 0 because evalPostfix() is not implemented yet.

## 2026-03-27
- Implemented evalPostfix() in main.cpp.
- Used ArrayStack<double> to evaluate postfix expressions.
- Tested with 3 4 + and 3 4 2 * +.
- Confirmed postfix expressions now return the correct result.

## 2026-03-28
- Implemented infixToPostfix().
- Converted infix expressions to postfix using a stack.
- Tested with 3 + 4 * 2 and ( 3 + 4 ) * 2.
- Verified results match expected output.

## 2026-03-30
- Finished implementing infixToPostfix() and fixed parentheses handling.
- Fixed infix validation to reject invalid cases like 3 ( 4 + 5 ) and ( ).
- Removed extra brace in main() that caused issues.
- Cleaned up postfix output formatting.
- Tested postfix, infix, and invalid expressions to confirm it was correct.
