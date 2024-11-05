#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "task.h"

void loadTasks(std::vector<Task>& tasks) {
    std::ifstream file("tasks.txt");
    std::string line;
    while (std::getline(file, line)) {
        tasks.push_back(Task(line));
    }
}

void saveTasks(const std::vector<Task>& tasks) {
    std::ofstream file("tasks.txt");
    for (const auto& task : tasks) {
        file << task.getDescription() << std::endl;
    }
}

void displayTasks(const std::vector<Task>& tasks) {
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].getDescription() << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;
    loadTasks(tasks);

    while (true) {
        std::cout << "Task Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::cout << "Enter task description: ";
            std::string description;
            std::getline(std::cin, description);
            tasks.push_back(Task(description));
            saveTasks(tasks);
        } else if (choice == 2) {
            displayTasks(tasks);
        } else if (choice == 3) {
            std::cout << "Enter task number to delete: ";
            int taskNum;
            std::cin >> taskNum;
            if (taskNum > 0 && taskNum <= tasks.size()) {
                tasks.erase(tasks.begin() + taskNum - 1);
                saveTasks(tasks);
            } else {
                std::cout << "Invalid task number." << std::endl;
            }
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
