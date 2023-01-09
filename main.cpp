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

void getVideogameFromList(int id, std::map<int, Videogame>* videogameList) {
	if (videogameList->empty()) {
		std::cout << "There are no objects in the list" << std::endl;
		return;
	}

	auto videogame = videogameList->find(id);
	if (videogame == videogameList->end())
		std::cout << "You cannot deleta a non existent object" << std::endl;
	else {
		std::cout << "This is your object" << std::endl;
		videogame->second.print();
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

User getUser(int userId, std::map<int, User>* userList) {
    User tempUser("", 0);
	if (userList->empty()) {
		std::cout << "User list is empty!" << std::endl;
		return tempUser;
	}

	auto user = userList->find(userId);
	if (user == userList->end()) {
		std::cout << "The item does not exist" << std::endl;
		return tempUser;
	}
	else {
		std::cout << "User found" << std::endl;
        tempUser = user->second;
		return tempUser;
	}
}

//Frontend methods
int menu() {
	int choice = -1;
	while (choice == -1) {
		std::cout << "\n1) Manage Videogames\n"
			"2) Exit\n"
			"Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail()) {
			std::cout << "That's not a number bro... :(" << std::endl;
			break;
		}
		if (!(1 <= choice && choice <= 2)) {
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
			"2) List videogames\n"
			"3) Search videogame\n"
			"4) List videogames ordered by genre\n"
			"5) List videogames ordered by name\n"
			"6) List videogmaes ordered by time played\n"
			"7) List videogames ordered by studio name\n"
			"8) Add time played\n"
			"9) Add achievements\n"
			"10) Delete videogame from list\n"
			"11) Add new user\n"
			"12) Show user list\n"
			"13) Buy videogame\n"
			"14) List user videogames\n"
			"15) Search user videogame\n"
			"16) Back\n"
			"17)Exit\n"
			"Enter your choice:";
		std::cin >> choice;
		if (std::cin.fail()) {
			std::cout << "That's not a number bro... :(" << std::endl;
			break;
		}

		if (!(1 <= choice && choice <= 17)) {
			std::cout << "\nInvalid choice. Try again!\n";
			choice = -1;
		}
	}
	return choice;
}

void run() {
    std::unique_ptr<User> user;
	std::map<int, User> userList;
	std::map<int, Videogame> videogameList;
	int id;
	int userId;
	float tp;
    std::string tempName;

	int choice = menu();

	if (choice == 2) {
		std::cout << "See ya!" << std::endl;
		return;
	}
	while (choice == 1 && !std::cin.fail()) {
		int adminChoice = videogameManager();

		switch (adminChoice) {
			case 1:
                srand((unsigned)time(0));
                id = rand();
                std::cout << "Object id is: " << id << std::endl;
                std::cout << "Enter name:";
                std::cin.get();
                std::getline(std::cin, tempName);
				addNewObject(&videogameList, tempName, id);
				break;
			case 2:
				for (auto it = videogameList.begin(); it != videogameList.end(); ++it)
					it->second.print();
				break;
			case 3:
				std::cout << "Which videogame are you looking for?";
				std::cin >> id;
				getVideogameFromList(id, &videogameList);
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
                srand((unsigned)time(0));
                id = rand();
                std::cout << "Object id is: " << id << std::endl;
                std::cout << "Enter name:";
                std::cin.get();
                std::getline(std::cin, tempName);
				addNewObject(&userList, tempName, id);
				break;
			case 12:
				for (auto it = userList.begin(); it != userList.end(); ++it)
					it->second.print();
				break;
			//Points 14-15 have to be improved
			case 13:
				std::cout << "Who are you?";
				std::cin >> userId;
				user = std::make_unique<User>(getUser(userId, &userList));
				if (user->getName() == "" && user->getId() == 0)
					break;
				else {
					std::cout << "Which videogame do you want?";
					std::cin >> id;
					user->addVideogame(id, videogameList.find(id)->second);
					break;
				}
			case 14:
				std::cout << "Who are you?";
				std::cin >> userId;
				user = std::make_unique<User>(getUser(userId, &userList));
				if (user->getName() == "" && user->getId() == 0)
					break;
				else {
					std::cout << "These are your videogames: " << std::endl;
					user->showUsersLibrary();
					break;
				}
			case 15:
				std::cout << "Who are you?";
				std::cin >> userId;
				user = std::make_unique<User>(getUser(userId, &userList));
				std::cout << "Which videogame are you looking for?";
				std::cin >> id;
				if (user == std::unique_ptr<User>{})
					break;
				else {
					user->getVideogameFromList(id);
					break;
				}
			case 16:
				run();
				break;
			case 17:
				std::cout << "See ya!" << std::endl;
				return;
			default:
				break;
		}
	}
}

int main()
{
	run();
	return 0;
}
