## Project OOP - Tetris C++ Game

This is an academic project where our team applies **Object-Oriented Programming (OOP)** concepts to design and build a classic **Tetris game** using **C++**.

## Team Members
- Nguyen Nam (IT - University of Science, VNU)

- Khoi Vu (IT - University of Science, VNU) 

## Git Feature Branch Workflow

We use **Feature Branch Workflow** to manage collaborative development efficiently.

### Branch Naming Convention

- `main`: Stable production-ready code
- `feature/<feature-name>`: New feature branches  

  > Example: `feature/hold-mechanic`, `feature/add-menu`

- `bugfix/<description>`: For small fixes  

  > Example: `bugfix/ghost-piece`

- `hotfix/<description>`: Urgent production fixes

### Workflow Steps
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