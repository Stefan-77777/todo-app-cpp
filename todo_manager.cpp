#include "todo_manager.h"
#include <fstream>
#include <sstream>
#include <iostream>

TodoManager::TodoManager(std::string file) {
    filename = file;
    nextId = 1;
    load();
}

void TodoManager::addTask(std::string title, std::string description, int priority) {
    Task t;
    t.id = nextId++;
    t.done = false;
    t.priority = priority;
    t.title = title;
    t.description = description;
    tasks.push_back(t);
    save();
}

void TodoManager::completeTask(int id) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == id) {
            tasks[i].done = true;
            save();
            return;
        }
    }
}

void TodoManager::deleteTask(int id) {
    for (int i = 0; i < tasks.size(); i++) {
        if (tasks[i].id == id) {
            tasks.erase(tasks.begin() + i);
            save();
            return;
        }
    }
}

std::vector<Task> TodoManager::getAll() {
    return tasks;
}

void TodoManager::load() {
    std::ifstream fisier(filename);
    std::string linie;
    while (std::getline(fisier, linie)) {
        std::stringstream ss(linie);
        std::string bucata;
        Task t;
        std::getline(ss, bucata, '|'); t.id = std::stoi(bucata);
        std::getline(ss, bucata, '|'); t.done = std::stoi(bucata);
        std::getline(ss, bucata, '|'); t.priority = std::stoi(bucata);
        std::getline(ss, bucata, '|'); t.title = bucata;
        std::getline(ss, bucata, '|'); t.description = bucata;
        tasks.push_back(t);
        if (t.id >= nextId)
            nextId = t.id + 1;
    }
}

void TodoManager::save() {
    std::ofstream fisier(filename);
    for (int i = 0; i < tasks.size(); i++) {
        fisier << tasks[i].id << "|"
               << tasks[i].done << "|"
                << tasks[i].priority << "|"
                << tasks[i].title << "|"
                << tasks[i].description << std::endl;
    }
}