#include "task.h"

Task::Task(const std::string& description) : description(description) {}

std::string Task::getDescription() const {
    return description;
}
