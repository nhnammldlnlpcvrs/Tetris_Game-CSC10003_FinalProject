# Project OOP - Tetris C++ Game

This is an academic project where our team applies **Object-Oriented Programming (OOP)** concepts to design and build a classic **Tetris game** using **C++**.

# Team Members
- Nguyen Nam (IT - University of Science, VNU)

- Khoi Vu (IT - University of Science, VNU) 

- Trong Khang (IT - University of Science, VNU)

# Git Feature Branch Workflow

We use **Feature Branch Workflow** to manage collaborative development efficiently.

## Branch Naming Convention

- `main`: Stable production-ready code
- `feature/<feature-name>`: New feature branches  

  > Example: `feature/hold-mechanic`, `feature/add-menu`

- `bugfix/<description>`: For small fixes  

  > Example: `bugfix/ghost-piece`

- `hotfix/<description>`: Urgent production fixes

## Workflow Steps
1. **Start a Feature**
```bash
git checkout main
git pull origin main
git checkout -b feature/your-feature-name
```
2. **Work on the Feature**
```bash
git add .
git commit -m "feat: short and clear message"
```
3. **Push and Create Pull Request**
```bash
git push -u origin feature/your-feature-name
```
4. **Merge after Review**
- Squash & merge recommended

- Delete feature branch after merge
5. **Clean up**
```bash
git branch -d feature/your-feature-name
git push origin --delete feature/your-feature-name
```
# Project Structure
```bash
./
│── assets/ # Assets (fonts, sounds, textures)
│── build/ # Build output (ignored by Git)
│── cmake-build/ # CMake build directory
│── docs/ # Documentation (Doxygen, reports, diagrams)
│── images/ # Illustrative images (not game assets)
│── raylib/ # Raylib library (if bundled with project)
│
│── resource/ # Refactored source (OOP + design patterns)
│ ├── App/
│ ├── Controller/
│ ├── Core/
│ ├── ...
│ 
│
│── source/ # Original/demo source code
│
│── x64/Debug/ # Visual Studio debug build output
│── .gitignore
│── CMakeLists.txt
│── Makefile
│── Doxyfile
│── README.md
│── rules_of_code.md # Coding rules and conventions
│── source.sln # Visual Studio solution
```


# How to Compile and Run
Run Tetris (Raylib) using Docker and Docker Compose. Works on Windows, Linux, and macOS.
```bash
git clone https://github.com/nhnammldlnlpcvrs/CSC10003_FinalProject.git
```
## Prerequisites
- Docker & Docker Compose installed

- Windows only: Install X server (e.g., VcXsrv)

## Linux/macOS
```bash
xhost +local:docker

docker-compose up --build
```

## Windows
Launch VcXsrv (Multiple Windows, No Client, Disable Access Control)

Run
```bash 
docker-compose up --build
```
**Notes**

- Binary uses static Raylib, no extra libraries needed.

- Best score can be persisted by mounting a volume for best_score.txt.

## (Optional) Run without Docker
Install the *raylib* library
1. **MacOS:** 

- Install Homebrew

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
- Install raylib

```bash
brew install raylib
```

- Check
```bash
pkg-config --modversion raylib
```
2. **Ubuntu / Debian Linux:**
- Update package list
```bash
sudo apt update
```

- Install raylib 
```bash
sudo apt install libraylib-dev
```

- Check
```bash
pkg-config --modversion raylib
```

3. **Windows (MSYS2):**

- Install MSYS2: https://www.msys2.org/

- Open MSYS2 MinGW 64-bit shell.

- Update package database
```bash
pacman -Syu
```

- Install raylib 
```bash
pacman -S mingw-w64-x86_64-raylib
```

- Check
```bash
pkg-config --modversion raylib
```
**Note:** If using Docker, there's no need to manually install raylib, because the Dockerfile has built it statically.

### Build with Makefile
Open a terminal in the project root folder.
```bash
make clean

make

./tetris
```
**⚠️ Make sure you are in the project root directory where Makefile is located.**