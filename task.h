#ifndef TASK_H
#define TASK_H

#include <string>

struct Task {
    int id;
    bool done;
    int priority;
    std::string title;
    std::string description;
};

#endif // TASK_H