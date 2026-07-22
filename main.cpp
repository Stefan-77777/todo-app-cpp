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

    std::cout << "Todo App - comenzi: list, list-priority, list-alpha, list-done, add, done, del, filter-priority, filter-done, quit" << std::endl;

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
        
        } else if (comanda == "filter-priority") {
            int priority;
            std::cout << "Prioritate (1-3): ";
            std::cin >> priority;
            printTasks(manager.getByPriority(priority));
        
        } else if (comanda == "filter-done") {
            bool done;
            std::cout << "Rezolvate (1) sau nerezolvate (0): ";
            std::cin >> done;
            printTasks(manager.getByDone(done));

        } else if (comanda == "list-priority") {
            printTasks(manager.getAllSortedByPriority());

        } else if (comanda == "list-alpha") {
            printTasks(manager.getAllSortedAlpha());

        } else if (comanda == "list-done") {
            printTasks(manager.getAllSortedByDone());

        } else if (comanda == "quit") {
            break;

        } else {
            std::cout << "Comanda necunoscuta." << std::endl;

        }
    }

    return 0;
}