#include "../header.hpp"
#include <iostream>

//Class videogame methods
Videogame::Videogame(std::string name, int id) : Entry(name, id){
    std::cout << "Genre of the videogame:";
    std::getline(std::cin, genre);
                
    std::cout << "Videogame's studio:";
	std::getline(std::cin, studio);

    timePlayed = 0;

	maxAchievements = rand()%20;
};

std::string Videogame::getGenre(){ return genre; }

std::string Videogame::getStudio(){ return studio;}

float Videogame::getTimePlayed(){ return timePlayed;}

void Videogame::print(){
    	std::cout << "\n-> Videogame name : " << name << " -> ID: " << id << std::endl;
		std::cout << "-> Genre: " << genre << " -> Studio: " << studio << "-> Time played: " << timePlayed << std::endl;

		if (videogameAchievements.empty())
			std::cout << "No achievements have been added yet" << std::endl;
		else {
			for (auto& it : videogameAchievements)
				std::cout << "Videogame achievment: " << it << std::endl;
		}
}

void Videogame::addTimePlayed(float tp) {
    timePlayed = tp;
}

bool Videogame::isDuplicate(std::string name) {
    for (auto &it : videogameAchievements) {
        if (it == name)
            return true;
    }
    return false;
}

void Videogame::addAchievements(std::string newAchievement) {
	if (videogameAchievements.size() <= maxAchievements) {
		if (!videogameAchievements.empty()) {
			std::cout << "Achievements List is not empty" << std::endl;
			if (isDuplicate(newAchievement))
				std::cout << "Duplicated achievement" << std::endl;
			else {
				std::cout << "Adding new achievement" << std::endl;
				videogameAchievements.push_back(newAchievement);
			}
		}
		else {
			std::cout << "There's no new achievements, adding new one" << std::endl;
			videogameAchievements.push_back(newAchievement);
		}
	}
	else
		std::cout << "All achievements have been unlocked" << std::endl;
}