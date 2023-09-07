#include <string>
#include <vector>
#include "Task.h"
#include <filesystem>
#include <fstream>
#include <algorithm>

void saveTasks(const std::vector<Task>& tasks, const std::string& fileName){
    std::ofstream ostream(fileName);
    ostream << tasks.size();

    for(const Task& task : tasks){
        std::string description = task.description;
        std::replace(description.begin(), description.end(), ' ', '_');

        ostream <<'\n'<<description <<' ' << task.completed;
    }
}

std::vector<Task> loadTask(const std::string& fileName){
    if(!std::filesystem::exists(fileName)){
        return std::vector<Task>();
    }
    std::vector<Task> tasks;
    std::ifstream istream(fileName);

    int n;
    istream >> n;

    for(int i = 0; i< n; i++){
        std::string description;
        bool completed;

        istream >> description >> completed;
        std::replace(description.begin(), description.end(), '_', ' ');
        tasks.push_back(Task{ description, completed });
    }

    return tasks;
}