#include "../header.hpp"
#include <iostream>

bool User::isDuplicateObject(std::string name, std::map<int, Videogame*>* list){
    for (auto it = list->begin(); it != list->end(); ++it) {
        if (it->second->getName() == name)
            return true;
    }

    return false;
}

void User::addVideogame(int id, Videogame* videogame){
    if (!userVideogames.empty()) {
        std::cout << "List is not empty" << std::endl;
        if (isDuplicateObject(videogame->getName(), &userVideogames))
            std::cout << "Duplicate entry, not allowed!" << std::endl;
        else {
            userVideogames.emplace(id, videogame);
            std::cout << "New videogame added" << std::endl;
        }
    }
    else {
        std::cout << "List is empty, we create list" << std::endl;
        userVideogames.emplace(id, videogame);
    }
}

void User::deleteVideogame(int id){
    if (userVideogames.find(id) == userVideogames.end()) {
        std::cout << "User doesn't have the videogame!" << std::endl;
        return;
    } 
    else
        userVideogames.erase(id);
}

void User::print(){
    std::cout << "\n-> User name : " << name << " -> ID: " << id << std::endl;
}

void User::showUsersLibrary(){
    if(userVideogames.empty()){
        std::cout << "There are no objects in the list" << std::endl;
        return;
    }
            
    std::cout << "User videogames: " << std::endl;
    for (auto& it : userVideogames) {
        it.second->print();
    }
}

void User::getVideogameFromList(int id){
    if (userVideogames.empty()) {
        std::cout << "There are no objects in the list" << std::endl;
        return;
    }

    auto videogame = userVideogames.find(id);
    if (videogame == userVideogames.end())
        std::cout << "You cannot deleta a non existent object" << std::endl;
    else {
        std::cout << "This is your object" << std::endl;
        videogame->second->print();
    }
}