#include <iostream>
#include <cstdlib>
#include <map>
#include <vector>

class Entry{
    protected:
        Entry(){};
        std::string name;
        int id;
    public:
        Entry(std::string name, int id) : name(name), id(id) {}
        std::string getName() { return name; }
        int getId() { return id; }
};

class Videogame : public Entry{
	private:
        int maxAchievements;
        float timePlayed;
        std::string genre;
        std::string studio;
        std::vector<std::string> videogameAchievements;
    public:
        Videogame(std::string name, int id);
        std::string getGenre(); 
        std::string getStudio();
        float getTimePlayed();
        void print();
        void addTimePlayed(float tp);
        bool isDuplicate(std::string name);
        void addAchievements(std::string newAchievement);
};

class User : public Entry{
    private:
        std::map<int, Videogame*> userVideogames;
    public:
        User(std::string name, int id) : Entry(name, id) {};
        bool isDuplicateObject(std::string name, std::map<int, Videogame*>* list);
        void addVideogame(int id, Videogame *videogame);
        void deleteVideogame(int id);
        void print();
        void showUsersLibrary();
        void getVideogameFromList(int id);
};

