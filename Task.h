#include <string>
#include <vector>

struct Task{
    std::string description;
    bool completed;
};

void saveTasks(const std::vector<Task>&, const std::string& file);
std::vector<Task> loadTask(const std::string& file);