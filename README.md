# auto-suggest-trie
Build a system that efficiently suggests the top K most frequent words matching a given prefix, similar to how search engines or mobile keyboards suggest completions as you type.


## 🔧 Build & Run Instructions (Manual Setup)

This section explains how to **manually build and run** the project using `g++` on Windows (with MSYS2 or MinGW installed) and Visual Studio Code.

### 📁 Folder Structure

```
auto-suggest-trie/
│
├── include/
│   └── Trie.hpp
│
├── src/
│   └── Trie.cpp
│
├── main.cpp
├── words.csv
├── main.exe (output after build)
└── .vscode/
    └── tasks.json
```

---

### ⚙️ 1. Update `.vscode/tasks.json`

Replace the content with this to use `g++` and correctly include the source/header files:

```json
{
  "version": "2.0.0",
  "tasks": [
    {
      "type": "cppbuild",
      "label": "C/C++: g++.exe build active file",
      "command": "C:\\msys64\\ucrt64\\bin\\g++.exe",
      "args": [
        "-fdiagnostics-color=always",
        "-g",
        "${workspaceFolder}/main.cpp",
        "${workspaceFolder}/src/Trie.cpp",
        "-I",
        "${workspaceFolder}/include",
        "-o",
        "${workspaceFolder}/main.exe"
      ],
      "options": {
        "cwd": "${workspaceFolder}"
      },
      "problemMatcher": [
        "$gcc"
      ],
      "group": {
        "kind": "build",
        "isDefault": true
      },
      "detail": "Build task using g++"
    }
  ]
}
```

---

### 🛠️ 2. Build the Project

Open **VS Code Terminal** and press:

```bash
Ctrl + Shift + B
```

This will compile `main.cpp` and `Trie.cpp`, and create `main.exe` in the project root folder.

✅ If successful, you’ll see `main.exe` appear in your folder.

---

### ▶️ 3. Run the Executable

From the terminal, run the built file:

```bash
./main.exe
```

Or, on Windows:

```bash
main.exe
```

This will execute your program and show suggestions based on the logic inside `main.cpp`.

---

### 📌 Notes

* `words.csv` must exist in the project root and contain a list of words (one per line).
* You can edit `main.cpp` to customize the suggestion logic or change input prompts.
* `main.exe` will be overwritten every time you build.

---

### 🚫 Trouble?

* If `main.exe` is not created, check the build terminal for errors.
* Ensure `g++` path in `tasks.json` matches your MSYS2 or MinGW installation.
* Restart VS Code if changes don’t reflect.
