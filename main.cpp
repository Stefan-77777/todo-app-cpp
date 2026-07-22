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

int main() {
    TodoManager manager("tasks.txt");
    std::string comanda;

    std::cout << "Todo App - comenzi: list, add, done, del, quit" << std::endl;

    while(true) {
        std::cout << "> ";
        std::cin >>comanda;

        if(comanda == "list") {
            printTasks(manager.getAll());

        } else if (comanda == "add") {
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

        } else if (comanda == "done") {
            int id;
            std::cout << "ID task: ";
            std::cin >> id;
            manager.completeTask(id);
            std::cout << "Task marcat ca finalizat." << std::endl;

        } else if (comanda == "del") {
            int id;
            std::cout << "ID task: ";
            std::cin >> id;
            manager.deleteTask(id);
            std::cout << "Task sters." << std::endl;

        } else if (comanda == "quit") {
            break;

        } else {
            std::cout << "Comanda necunoscuta." << std::endl;
        }
    }

    return 0;
}