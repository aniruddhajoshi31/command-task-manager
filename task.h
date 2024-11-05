#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
public:
    Task(const std::string& description);
    std::string getDescription() const;

private:
    std::string description;
};

#endif // TASK_H
