#ifndef TDO_MANAGER_H
#define TDO_MANAGER_H

#include "task.h"
#include <vector>
#include <string>

class TodoManager {
private:
    std::vector<Task> tasks;
    int nextId;
    std::string filename;

public:
    TodoManager(std::string file);
    void addTask(std::string title, std::string description, int priority);
    void completeTask(int id);
    void deleteTask(int id);
    std::vector<Task> getAll();
    std::vector<Task> getByPriority(int priority);
    std::vector<Task> getByDone(bool done);
    std::vector<Task> getAllSortedByPriority();
    std::vector<Task> getAllSortedAlpha();
    std::vector<Task> getAllSortedByDone();
    void load();
    void save();
};

#endif