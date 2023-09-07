#include "Task.h"
#include <iostream>
#include <string.h>
using namespace std;

int main(){
    char input;
    std::string taskDescription;
    std::string loadTaskName;
    std::string saveTaskName;
    std::vector<Task> tasks;

    std::cout << "To-Do List" << std::endl;
    std::cout << "Would you like to create a new to-do list? (y/n)" << std::endl;
    std::cin >> input;
    
    if(input == 'y'){
    }else if(input == 'n'){
        std::cout << "Which tasks would you like to load? "<< std::endl;
        std::cin >> loadTaskName;
        tasks = loadTask(loadTaskName);
    }else{
        std::cout << "I see you don't want to make a new To-Do list or check the old one. Have a great day." << std::endl;
        return 0;
    }

    while(true){
        std::cout << "What would you like to do? For all the commands please enter h." << std::endl;
        std::cin >> input;
        if(input == 'h'){
            std::cout << "a - add task" << std::endl;
            std::cout << "c - mark tasks completed" << std::endl;
            std::cout << "d - delete task" << std::endl;
            std::cout << "l - list tasks" << std::endl;
            std::cout << "q - quit" << std::endl;  
            std::cout << "s - save task" << std::endl;  
        }else if(input == 'q'){
            std::cout << "Thank you for using To-Do list." << std::endl;
            return 0;
        }else if(input == 'a'){
            cin.ignore();
            std::cout << "Please enter task description: "; getline(cin, taskDescription);
            Task tempTask;
            tempTask.description = taskDescription;
            tempTask.completed = false;
            tasks.push_back(tempTask);
        }else if(input == 'l'){
            for(long unsigned int i = 0; i<tasks.size(); i++){
                std::string boolean;
                if(tasks[i].completed == 0){
                    boolean = "false";
                }else if(tasks[i].completed == 1){
                    boolean = "true";
                }
                std::cout << tasks[i].description <<" | "<< boolean << std::endl;
            }
        }else if(input == 's'){
            cin.ignore();
            std::cout << "What would you like to save the to-do list as? "; getline(cin, saveTaskName);
            saveTasks(tasks, saveTaskName);
        }

        // std::cout << "To-Do List" << std::endl;
    }
        
    return 0;
}