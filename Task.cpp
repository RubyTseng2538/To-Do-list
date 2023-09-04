#include <string>
#include <vector>
#include "Task.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

void saveTask(const std::vector<Task>& tasks, const std::string& file){
    std::ofstream ostream(file);
    ostream << tasks.size();

    for(const Task& task : tasks){
        std::string description = task.description;
        std::replace(description.begin(), description.end(), ' ', '_');

        ostream <<'\n'<<description <<' ' << task.completed;
    }
}

std::vector<Task> loadTask(const std::string& file){
    if(!std::filesystem::exists(file)){
        return std::vector<Task>();
    }
    std::vector<Task> tasks;
    std::ifstream(file);

    int n;
    istream >> n;

    for(int i = 0; i< n; i++){
        std::string description;
        bool completed;

        istream >> description >> done;
        std::replace(description.begin(), description.end(), '_', ' ');
        tasks.push_back(Task{ description, completed });
    }

    return tasks;
}