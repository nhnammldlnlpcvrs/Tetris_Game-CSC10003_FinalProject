# Test Plan - Tettris Game

## 1. Test Scope
- Testing the logic of all Tetris blocks: **I, J, L, O, S, T, Z**
- Testing the **Grid** behavior (initialization, cell setting)
- Testing **block rotation** functionality

## 2. Objective
Ensure that each Tetris block behaves correctly upon:
- Initialization
- Rotation (clockwise)

Ensure the Grid:
- Initializes with the correct size and values
- Correctly stores and retrieves cell values

## 3. Test Type
- **Unit Testing** using [Catch2](https://github.com/catchorg/Catch2)

## 4. Test Tool
- Catch2 v3 (amalgamated single-header version)

## 5. Test Environment
- Operating System: **Windows**
- Build Tool: **CMake >= 3.15**
- Compiler: **C++17-compliant (e.g., MSVC, GCC, Clang)**

## 6. Completion Criteria
- All test cases must pass 100%
- No memory leaks or crashes during tests
- Code follows coding conventions (see `coding_convention.md`)

## 7. Related Files
- `test_block_i.cpp`, `test_block_j.cpp`, ..., `test_rotate.cpp`
- `test_grid.cpp`

### Tester: Nguyen Nam