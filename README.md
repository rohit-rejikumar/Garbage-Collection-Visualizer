# Garbage Collection Visualizer

A beginner-friendly, interactive C++ project that demonstrates how **Reference Counting Garbage Collection** works in memory management.

## About the Project

Garbage Collection is a memory management technique used by programming languages to identify and clean up objects that are no longer being used.

This project demonstrates the Reference Counting algorithm through a console-based visualizer. Users can create and remove references between objects, view their reference counts, and simulate garbage collection.

## Features

- Display the current memory status.
- Add references between memory objects.
- Remove existing references.
- Track reference counts dynamically.
- Identify and collect objects with zero references.
- Display collected objects.
- Interactive menu-driven interface.

## Algorithm Used: Reference Counting

Reference Counting is a garbage collection technique in which every object maintains a counter representing the number of references pointing to it.

### How It Works

1. Each object maintains a reference count.
2. When a new reference is created, the destination object's count increases.
3. When a reference is removed, the destination object's count decreases.
4. If an object's reference count becomes zero, it becomes eligible for garbage collection.
5. The garbage collector marks that object as collected and updates the counts of objects it references.

### Example

Initial object relationships:

```text
A → B → C

D    E    F
```

- Object A has a root reference.
- Object A references B.
- Object B references C.
- Objects D, E and F initially have no references.

When an object becomes eligible for collection, the program marks it as collected.

## Technologies Used

- Programming Language: C++
- Concepts: Data Structures, Memory Management, Reference Counting
- Header Files: iostream, vector
- IDE: Visual Studio Code
- Version Control: Git and GitHub

## Project Structure

```text
Garbage-Collection-Visualizer/
│
├── main.cpp
├── README.md
├── LICENSE
└── .gitignore
```

## How to Run

### Requirements

- C++ compiler (G++)
- Visual Studio Code (recommended)

### Compile

```bash
g++ main.cpp -o garbage
```

### Run on Windows PowerShell

```powershell
.\garbage.exe
```

### Run on Linux

```bash
./garbage
```

## Available Operations

| Option | Operation |
|---|---|
| 1 | Display Memory |
| 2 | Add Reference |
| 3 | Remove Reference |
| 4 | Run Garbage Collection |
| 5 | Exit |

## Limitations

- Basic Reference Counting cannot automatically collect unreachable objects involved in circular references.
- This project simulates memory collection by marking objects as collected rather than actually freeing their C++ memory.
- It is an educational demonstration, not a production-level garbage collector.

## Learning Outcomes

Through this project, we learn:

- How garbage collection works.
- How reference counting manages memory.
- How objects reference one another.
- How memory leaks can occur due to circular references.
- How C++ vectors and structures can be used to simulate memory management.

## License

This project is licensed under the MIT License.