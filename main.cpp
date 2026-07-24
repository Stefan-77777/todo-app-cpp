#include <iostream>
#include <string>
#include "todo_manager.h"

void printTasks(std::vector<Task> tasks) {
    if(tasks.empty()) {
        std::cout << "Nu exista task-uri." << std::endl;
        return;
    }
    for (int i = 0; i < tasks.size(); i++) {
        std::cout << "[" << tasks[i].id << "] "
                  << (tasks[i].done ? "Done" : "Not done") << " "
                  << "[P" << tasks[i].priority << "] "
                  << tasks[i].title << " - "
                  << tasks[i].description << std::endl;
    }
}

void meniuAfisare(TodoManager &manager) {
    while (true) {
        std::cout << "\n-- Afisare --" << std::endl;
        std::cout << "1. Toate task-urile" << std::endl;
        std::cout << "2. Sortare dupa prioritate" << std::endl;
        std::cout << "3. Sortare dupa status" << std::endl;
        std::cout << "4. Sortare alfabetica" << std::endl;
        std::cout << "0. Inapoi" << std::endl;
        std::cout << "> ";

        int optiune;
        std::cin >> optiune;

        /*if (optiune == 1) {
            printTasks(manager.getAll());
        } else if (optiune == 2) {
            printTasks(manager.getAllSortedByPriority());
        } else if (optiune == 3) {
            printTasks(manager.getAllSortedByDone());
        } else if (optiune == 4) {
            printTasks(manager.getAllSortedAlpha());
        } else if (optiune == 0) {
            return;
        } else {
            std::cout << "Optiune necunoscuta." << std::endl;
        }*/

        switch (optiune) {
            case 1:
                printTasks(manager.getAll());
                break;
            case 2:
                printTasks(manager.getAllSortedByPriority());
                break;
            case 3:
                printTasks(manager.getAllSortedByDone());
                break;
            case 4:
                printTasks(manager.getAllSortedAlpha());
                break;
            case 0:
                return;
            default:
                std::cout << "Optiune necunoscuta." << std::endl;
        }
    }
}

void meniuFiltrare(TodoManager &manager) {
    while (true) {
        std::cout << "\n-- Filtrare --" << std::endl;
        std::cout << "1. Dupa prioritate" << std::endl;
        std::cout << "2. Dupa status" << std::endl;
        std::cout << "0. Inapoi" << std::endl;
        std::cout << "> ";

        int optiune;
        std::cin >> optiune;

        switch (optiune)
        {
        case 1: {
            int priority;
            std::cout << "Prioritate (1-3): ";
            std::cin >> priority;
            printTasks(manager.getByPriority(priority));
            break;
        }
        case 2: {
            bool done;
            std::cout << "Rezolvate (1) sau nerezolvate (0): ";
            std::cin >> done;
            printTasks(manager.getByDone(done));
            break;
        }
        case 0:
            return;
        default:
            std::cout << "Optiune necunoscuta." << std::endl;
        }
    }
}

int main() {
    TodoManager manager("tasks.txt");
    
    while(true) {
        std::cout << "\n=== Todo App ===" << std::endl;
        std::cout << "1. Afisare" << std::endl;
        std::cout << "2. Filtare" << std::endl;
        std::cout << "3. Adauga task" << std::endl;
        std::cout << "4. Marcheaza task-ul ca rezolvat" << std::endl;
        std::cout << "5. Sterge task" << std::endl;
        std::cout << "0. Iesire" << std::endl;
        std::cout << "> ";

        int optiune;
        std::cin >> optiune;

        switch (optiune) {
            case 1:
                meniuAfisare(manager);
                break;
            case 2:
                meniuFiltrare(manager);
                break;
            case 3: {    
                std::string title, description;
                int priority;
                std::cout << "Titlu: ";
                std::cin.ignore();
                std::getline(std::cin, title);
                std::cout << "Descriere: ";
                std::getline(std::cin, description);
                std::cout << "Prioritate (1-3): ";
                std::cin >> priority;
                manager.addTask(title, description, priority);
                std::cout << "Task adaugat." << std::endl;
                break;
            }
            case 4: {
                int id;
                std::cout << "ID task: ";
                std::cin >> id;
                manager.completeTask(id);
                std::cout << "Task marcat ca rezolvat." << std::endl;
                break;
            }
            case 5: {
                int id;
                std::cout << "ID task: ";
                std::cin >> id;
                manager.deleteTask(id);
                std::cout << "Task sters." << std::endl;
                break;
            }
            case 0:
                return 0;
            default:
                std::cout << "Optiune necunoscuta." << std::endl;
        }
    }

    return 0;
}