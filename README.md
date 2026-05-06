Sudoku Generator & Solver 🎲🧩
Repository Description

A C++ based Sudoku Generator and Solver that creates random Sudoku puzzles and solves them using the Backtracking Algorithm.
The project demonstrates concepts of Object-Oriented Programming (OOP), recursion, random puzzle generation, and constraint validation in a clean console-based implementation.

The program:

Generates a valid 9×9 Sudoku board
Randomly removes cells to create a playable puzzle
Solves the puzzle automatically using recursion and backtracking
Prints both generated and solved Sudoku boards in the console
Key Features 🚀
✅ Random Sudoku puzzle generation
✅ Sudoku solver using backtracking
✅ 3×3 subgrid validation
✅ Row and column safety checks
✅ Object-Oriented design using C++ classes
✅ Console-based interface
✅ Recursive solving logic
Technologies Used 💻
Language: C++
Concepts:
OOP
Recursion
Backtracking
Arrays
Randomization
Algorithm Used 🧠

The solver uses the Backtracking Algorithm:

Find an empty cell (*)
Try numbers 1–9
Check if placement is safe
Recursively solve remaining board
Backtrack if a conflict occurs

This guarantees a valid Sudoku solution if one exists.
