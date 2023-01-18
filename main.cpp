#include "header.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

//Backend methods
template<typename T=Entry>
bool isDuplicateObject(std::string name, std::map<int, T>* list) {
	for (auto it = list->begin(); it != list->end(); ++it) {
		if (it->second.getName() == name)
			return true;
	}

	return false;
}

template<typename T=Entry>
void addNewObject(std::map<int, T>* list, std::string name, int id) {
    T newObject(name, id);

	if (!list->empty()) {
		std::cout << "List is not empty" << std::endl;
		if (isDuplicateObject(newObject.getName(), list)) 
			std::cout << "Duplicate entry, not allowed!" << std::endl;
		else {
			list->emplace(newObject.getId(), newObject);
			std::cout << "New videogame added" << std::endl;
		}
	}	
	else {
		std::cout << "List is empty, we create list" << std::endl;
		list->emplace(newObject.getId(), newObject);
	}
}

template<typename T=Entry>
void deleteObjectFromList(int id, std::map<int, T>* list) {
	if (list->empty()) {
		std::cout << "There are no objects in the list" << std::endl;
		return;
	}

	if (list->find(id) == list->end())
		std::cout << "You cannot delete a non existent object" << std::endl;
	else {
		list->erase(id);
		std::cout << "Object deleted correctly!" << std::endl;
	}
}
// THIS IS THE PROBLEM THAT NEEDS TO BE IMPROVED
template <typename T=Entry>
T* getObjectFromList(int id, std::map<int, T>* list) {
	if (list->empty()) {
		std::cout << "There are no objects in the list" << std::endl;
		return nullptr;
	}

	auto object = list->find(id);
	if (object == list->end()){
		std::cout << "You cannot find a non existent object" << std::endl;
		return nullptr;
	} else {
		std::cout << "This is your object" << std::endl;
		return &object->second;
	}
}

void getSortedVideogamesFromName(std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no object in the list" << std::endl;
		return;
	}

	std::vector<std::pair<int, Videogame>> vec;

	for (auto it = videogameList->begin(); it != videogameList->end(); ++it)
		vec.push_back(std::make_pair(it->first, it->second));

	std::sort(vec.begin(), vec.end(), [](std::pair<int, Videogame>& item1, std::pair<int, Videogame>& item2) {
		return item1.second.getName() < item2.second.getName();
	});

	for (auto& it : vec)
		it.second.print();
}

 void getSortedVideogamesFromStudio(std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no object in the list" << std::endl;
		return;
	}

	std::vector<std::pair<int, Videogame>> vec;

	for (auto it = videogameList->begin(); it != videogameList->end(); ++it)
		vec.push_back(std::make_pair(it->first, it->second));

	std::sort(vec.begin(), vec.end(), [](std::pair<int, Videogame>& item1, std::pair<int, Videogame>& item2) {
		return item1.second.getStudio() < item2.second.getStudio();
	});

	for (auto& it : vec)
		it.second.print();
}

void getSortedVideogamesFromTimePlayed(std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no object in the list" << std::endl;
		return;
	}

	std::vector<std::pair<int, Videogame>> vec;

	for (auto it = videogameList->begin(); it != videogameList->end(); ++it)
		vec.push_back(std::make_pair(it->first, it->second));

	std::sort(vec.begin(), vec.end(), [](std::pair<int, Videogame>& item1, std::pair<int, Videogame>& item2) {
		return item1.second.getTimePlayed() < item2.second.getTimePlayed();
	});

	for (auto& it : vec)
		it.second.print();
}

void getSortedVideogamesFromGenre(std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no object in the list" << std::endl;
		return;
	}

	std::vector<std::pair<int, Videogame>> vec;

	for (auto it = videogameList->begin(); it != videogameList->end(); ++it)
		vec.push_back(std::make_pair(it->first, it->second));

	std::sort(vec.begin(), vec.end(), [](std::pair<int, Videogame>& item1, std::pair<int, Videogame>& item2) {
		return item1.second.getGenre() < item2.second.getGenre();
	});

	for (auto& it : vec)
		it.second.print();
}

void addTimePlayedToVideogame(int id, float tp, std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no object in the list" << std::endl;
		return;
	}

	auto videogame = videogameList->find(id);
	if (videogame == videogameList->end())
		std::cout << "This videogame doesn't exist" << std::endl;
	else {
		videogame->second.addTimePlayed(tp);
		std::cout << "Time played has been added correctly!" << std::endl;
	}
}

void addNewAchievement(int id, std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no object in the list" << std::endl;
		return;
	}
	
	std::string achievementName;
	std::cout << "Enter achievement name: ";
    std::getline(std::cin, achievementName);

	auto videogame = videogameList->find(id);

	if (videogame == videogameList->end())
		std::cout << "The videogame doesn't exist" << std::endl;
	else {
		videogame->second.addAchievements(achievementName);
	}
}

//Frontend methods
int menu() {
	int choice = -1;
	while (choice == -1) {
		std::cout << "\n1) Manage Videogames\n"
			"2) Manage Users\n"
			"3) Exit\n"
			"Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cout << "That's not a number bro... :(" << std::endl;
			break;
		}
		if (!(1 <= choice && choice <= 3)) {
			std::cout << "Invalid choice, try again." << std::endl;
			choice = -1;
		}
	}
	return choice;
}

int videogameManager(){
	int choice = -1;
	while (choice == -1) {
		std::cout << "\n1) Add new videogame\n"
			"2) List videogames by ID\n"
			"3) Search videogame\n"
			"4) List videogames ordered by genre\n"
			"5) List videogames ordered by name\n"
			"6) List videogmaes ordered by time played\n"
			"7) List videogames ordered by studio name\n"
			"8) Add time played\n"
			"9) Add achievements\n"
			"10) Delete videogame from list\n"
			"11) Back\n"
			"12)Exit\n"
			"Enter your choice:";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cout << "That's not a number bro... :(" << std::endl;
			break;
		}

		if (!(1 <= choice && choice <= 13)) {
			std::cout << "\nInvalid choice. Try again!\n";
			choice = -1;
		}
	}
	return choice;
}

int userManager(){
	int choice = -1;
	while (choice == -1) {
		std::cout << "\n1) Add new user\n"
			"2) Show user list\n"
			"3) Buy videogame\n"
			"4) List user videogames\n"
			"5) Search user videogame\n"
			"6) Back\n"
			"7)Exit\n"
			"Enter your choice:";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cout << "That's not a number bro... :(" << std::endl;
			break;
		}

		if (!(1 <= choice && choice <= 7)) {
			std::cout << "\nInvalid choice. Try again!\n";
			choice = -1;
		}
	}
	return choice;
}

void run() {
    std::unique_ptr<User> user;
	std::unique_ptr<Videogame> videogame;
	std::map<int, User> userList;
	std::map<int, Videogame> videogameList;
	int id;
	int userId;
	float tp;
    std::string name;
	std::string sortType;

	int choice = menu();

	if (choice == 3) {
		std::cout << "See ya!" << std::endl;
		return;
	}
	while (choice == 1 && !std::cin.fail()) {
		int videogameAdminChoice = videogameManager();
		switch (videogameAdminChoice) {
			case 1:
                srand((unsigned)time(0));
                id = rand();
                std::cout << "Object id is: " << id << std::endl;
                std::cout << "Enter name:";
                std::cin.get();
                std::getline(std::cin, name);
				addNewObject(&videogameList, name, id);
				break;
			case 2:
				if(videogameList.empty()){
					std::cout << "There are no objects in the list" << std::endl;
					break;
				} else {
					std::cout << "Videogames in the list:" << std::endl;
					for (auto it = videogameList.begin(); it != videogameList.end(); ++it)
						it->second.print();
					break;
				}
			case 3:
				std::cout << "Which videogame are you looking for?";
				std::cin >> id;
				videogame = std::make_unique<Videogame>(getObjectFromList(id, &videogameList));
				videogame->print();
				break;
			case 4:
				getSortedVideogamesFromGenre(&videogameList);
				break;
			case 5:
				getSortedVideogamesFromName(&videogameList);
				break;
			case 6:
				getSortedVideogamesFromTimePlayed(&videogameList);;
				break;
			case 7:
				getSortedVideogamesFromStudio(&videogameList);
				break;
			case 8:
				std::cout << "Which videogame are you looking for?";
				std::cin >> id;
				std::cout << "How much did you play?";
				std::cin >> tp;
				addTimePlayedToVideogame(id, tp, &videogameList);
				break;
			case 9:
				std::cout << "Which videogame are you looking for?";
				std::cin >> id;
				addNewAchievement(id, &videogameList);
				break;
			case 10:
				std::cout << "Which videogame do you want to delete?";
				std::cin >> id;
				deleteObjectFromList(id, &videogameList);
				break;
			case 11:
				run();
				break;
			case 12:
				std::cout << "See ya!" << std::endl;
				return;
			default:
				break;
		}
	}
	while(choice == 2 && !std::cin.fail()){
		int videogameUserChoice = userManager();
		switch (videogameUserChoice) {
			case 1:
                srand((unsigned)time(0));
                id = rand();
                std::cout << "Object id is: " << id << std::endl;
                std::cout << "Enter name:";
                std::cin.get();
                std::getline(std::cin, name);
				addNewObject(&userList, name, id);
				break;
			case 2:
				if(userList.empty()){
					std::cout << "There are no users in the list!" << std::endl;
					break;
				} else {
					std::cout << "Users in the list:" << std::endl;
					for (auto it = userList.begin(); it != userList.end(); ++it)
						it->second.print();
					break;
				}
			case 3:
				std::cout << "Who are you?";
				std::cin >> userId;
				user = std::make_unique<User>(getObjectFromList(userId, &userList));
				if (user->getName() == "" && user->getId() == 0)
					break;
				else {
					std::cout << "Which videogame do you want?";
					std::cin >> id;
					user->addVideogame(id, &videogameList.find(id)->second);
					break;
				}
			case 4:
				std::cout << "Who are you?";
				std::cin >> userId;
				user = std::make_unique<User>(getObjectFromList(userId, &userList));
				if (user->getName() == "" && user->getId() == 0)
					break;
				else {
					std::cout << "These are your videogames: " << std::endl;
					user->showUsersLibrary();
					break;
				}
			case 5:
				std::cout << "Who are you?";
				std::cin >> userId;
				user = std::make_unique<User>(getObjectFromList(userId, &userList));
				std::cout << "Which videogame are you looking for?";
				std::cin >> id;
				if (user == std::unique_ptr<User>{})
					break;
				else {
					user->getVideogameFromList(id);
					break;
				}
			case 6:
				run();
				break;
			case 7:
				std::cout << "See ya!" << std::endl;
				return;
			default:
				break;
		}
	}
}

//Main function
int main()
{
	run();
	return 0;
}
