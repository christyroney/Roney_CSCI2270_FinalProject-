#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>

//using namespace std;

struct Movie{
    std::string title;
    std::string favChar;
    int bookRank;
    int movieRank;
    int charRank;
    int totalRank;

    
  
    Movie *next;
    

    Movie(){};

    Movie(std::string in_title)
    {
        title = in_title;
        next = NULL;
        favChar = "";
        bookRank = -1;
        movieRank = -1;
        charRank = -1;
        totalRank = -1;
    }

};

class HashTable
{
    public:
        HashTable();
        void printInOrder();
        void insertMovie(std::string s);
        Movie* findMovie(std::string in_title);
        void deleteMovie(std::string in_title);
        void printInventory();
        int hashSum(std::string str);
        void addBestCharacter(std::string inTitle, std::string bestChar, int bookRating, int movieRating, int charRating);
        bool doesBookExist(std::string title);
        void printBestOverallRatings();
        void printBestCharacters();
        void displayMenu();
        void printBestBooks();
        void printBestMovies();
        bool isRankingValid(std::string rank);
    protected:
    private:
        Movie **hashTable;
};

#endif // HASHTABLE_H
