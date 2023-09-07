#pragma once
#include <string>
#include <vector>

struct Task{
    std::string description;
    bool completed;
};

void saveTasks(const std::vector<Task>&, const std::string& fileName);
std::vector<Task> loadTask(const std::string& fileName);