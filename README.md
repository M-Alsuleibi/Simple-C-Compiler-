# Simple-C-Compiler-

### Here is [instructions for creating a simple compiler in C](https://drive.google.com/file/d/1MqXruiM849l0Eix4f5jot6pyy-fcVgOs/view?usp=sharing)
 split into modules like lexer, parser, emitter, symbol, init, error, and main. It explains how to compile and execute the compiler under UNIX.

---

### Global Header File (global.h)

The `global.h` header file contains essential declarations, constants, and function prototypes used throughout the compiler implementation. It includes standard library headers, defines token values, buffer sizes, and structures for symbol table entries. Additionally, it declares functions for lexical analysis, parsing, error handling, and symbol table management.

---
### To compile the seven files (lexer.c, parser.c, emitter.c, symbol.c, init.c, error.c, main.c) in VS Code on Ubuntu OS
1. Create a Header File: If you haven't already, create a `global.h` header file.

2. Install the `build-essential` package.

3. Create a `tasks.json` file in the `.vscode` directory within your project directory. You can use this file to define build tasks.

4. Define a build task that compiles all the source files using the `cc` command. Here's an example `tasks.json` configuration:
```
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build-compiler",
            "type": "shell",
            "command": "cc",
            "args": ["-o", "compiler", "lexer.c", "parser.c", "emitter.c", "symbol.c", "init.c", "error.c", "main.c"],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": {
                "owner": "cpp",
                "fileLocation": ["relative", "${workspaceFolder}"],
                "pattern": {
                    "regexp": "^(.*):(\\d+):(\\d+):\\s+(warning|error):\\s+(.*)$",
                    "file": 1,
                    "line": 2,
                    "column": 3,
                    "severity": 4,
                    "message": 5
                }
            }
        }
    ]
}

```
5. Build the Compiler: 
    - Press `Ctrl + Shift + B` to open the Command Palette in VS Code.
    - Select the `build-compiler` task to compile the files and create the executable `compiler` output file.

6. Run the Compiler:

    - After a successful build, you can run the compiler by executing ./compiler in the terminal within your project directory.
    - Follow the instructions provided in the original document to exercise the compiler with expressions.
    