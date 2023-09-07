#include "Task.h"
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main(){
    char input;
    std::string taskDescription;
    std::string loadTaskName;
    std::string saveTaskName;
    //empty to-do list
    std::vector<Task> tasks;

    //Check to load or make a to do list
    std::cout << "To-Do List" << std::endl;
    std::cout << "Would you like to create a new to-do list? (y/n)" << std::endl;
    std::cin >> input;
    
    //make new to-do list
    if(input == 'y'){
        //don't actually need anything here because one is already made
    }
    //load to-do list
    else if(input == 'n'){
        std::cout << "Which tasks would you like to load? "<< std::endl;
        std::cin >> loadTaskName;
        tasks = loadTask(loadTaskName);
    }
    //invalid command, close to-do list if user input neither y nor n
    else{
        std::cout << "I see you don't want to make a new To-Do list or check the old one. Have a great day." << std::endl;
        return 0;
    }

    //loops to check for user command
    while(true){
        std::cout << "What would you like to do? For all the commands please enter h." << std::endl;
        std::cin >> input;
        //help command, list out all possible command
        if(input == 'h'){
            std::cout << "a - add task" << std::endl;
            std::cout << "c - mark tasks completed" << std::endl;
            std::cout << "d - delete task" << std::endl;
            std::cout << "l - list tasks" << std::endl;
            std::cout << "q - quit" << std::endl;  
            std::cout << "s - save task" << std::endl;  
        }
        //end program
        else if(input == 'q'){
            std::cout << "Thank you for using To-Do list." << std::endl;
            return 0;
        }
        //add new tasks
        else if(input == 'a'){
            cin.ignore();
            std::cout << "Please enter task description: "; getline(cin, taskDescription);
            Task tempTask;
            if(!taskDescription.empty()){
                tempTask.description = taskDescription;
                tempTask.completed = false;
                tasks.push_back(tempTask);
            }else{
                std::cout << "Your input was invalid." << std::endl;
            }
        }
        //list all available task
        else if(input == 'l'){
            for(long unsigned int i = 0; i<tasks.size(); i++){
                std::string boolean;
                if(tasks[i].completed == 0){
                    boolean = "false";
                }else if(tasks[i].completed == 1){
                    boolean = "true";
                }
                std::cout << tasks[i].description <<" | "<< boolean << std::endl;
            }
        }
        //save to-do list
        else if(input == 's'){
            cin.ignore();
            std::cout << "What would you like to save the to-do list as? "; getline(cin, saveTaskName);
            saveTasks(tasks, saveTaskName);
        }
        //mark items on to-do list as complete
        else if(input == 'c'){
            cin.ignore();
            std::cout << "Which task would you like to mark as complete? "; getline(cin, taskDescription);
            for(long unsigned int i = 0; i<tasks.size(); i++){
                if(tasks[i].description == taskDescription){
                    tasks[i].completed = true;
                    std::cout << "You marked " << taskDescription << " as completed." <<std::endl;
                    break;
                }
            }
            // std::cout << "Task " << taskDescription << " was not found."
        }
        //delete items on to-do list
        else if(input == 'd'){
            cin.ignore();
            std::cout << "Which task would you like to delete? "; getline(cin, taskDescription);
            for(long unsigned int i = 0; i<tasks.size(); i++){
                if(tasks[i].description == taskDescription){
                    tasks.erase(tasks.begin()+i);
                    std::cout << "You removed " << taskDescription << "." <<std::endl;
                    break;
                }
            }
            // std::cout << "Task " << taskDescription << " was not found."
        }

        // std::cout << "To-Do List" << std::endl;
    }
        
    return 0;
}