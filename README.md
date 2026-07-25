# Todo App C++

Aplicație CLI (linie de comandă) pentru gestionarea task-urilor, scrisă în C++.

## Funcționalități

- Adăugare, editare, ștergere task-uri
- Marcare task-uri ca rezolvate
- Afișare task-uri: toate, sortate după prioritate, status, sau alfabetic
- Filtrare task-uri după prioritate sau status
- Ștergere în masă a task-urilor rezolvate
- Statistici (total, rezolvate, nerezolvate)
- Salvare automată în fișier text

## Tehnologii

- C++17
- Compilator: g++ (MinGW, via MSYS2)

## Structură proiect

- `task.h` — struct-ul `Task` (datele unui task)
- `todo_manager.h` / `todo_manager.cpp` — clasa `TodoManager` (logica aplicației)
- `main.cpp` — interfața CLI

## Compilare și rulare

```bash
g++ -std=c++17 main.cpp todo_manager.cpp -o todo
./todo
```

## Ce am învățat

Acest proiect a fost primul meu contact serios cu:
- `std::vector` și manipularea lui
- Programare orientată pe obiecte (clase, încapsulare)
- Citire/scriere fișiere (`ifstream`/`ofstream`)
- `stringstream` pentru parsare
- Lambda-uri și `std::sort`
- Git: branch-uri, merge, workflow complet

## Status

Proiect finalizat — parte din pregătirea mea pentru Facultatea de Automatică și Calculatoare, UPB.