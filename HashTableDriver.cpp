//Author: Christy Roney


#include "HashTable.h"
#include <iostream>                   
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char* argv[])
{

	HashTable * movies = new HashTable();
	
	string line;
	string filename = argv[1];
	ifstream in;
	in.open(filename); //opening the file
	if(in.is_open())
	{

		while(getline(in,line))
		{
			string movieTitle = line;
			movies->insertMovie(movieTitle);
			
		}
	}
	in.close(); //close
	bool quit = false;
	
	string command;
	
	while(quit != true)
	{
		
		movies->displayMenu();
		getline(cin, command);
		switch(atoi(command.c_str()))
		{
			case 1: //Display the books
			{
				movies->printInventory();
				break;
			}
			case 2: //Delete movie
			{
				cout<<"Enter title:"<<endl;
				string titleofMovie;
				getline(cin, titleofMovie);
				if(movies->doesBookExist(titleofMovie) == true)
				{
					movies->deleteMovie(titleofMovie);
				}
				else
					cout<<"Sorry, that book does not exist on this list."<<endl;
				break;
			}
			case 3: //Find movie
			{
				cout<<"Enter title:"<<endl;
				string titleofMovie;
				getline(cin, titleofMovie);
				movies->findMovie(titleofMovie);
				break;
			}
			case 4: //Insert a book
			{
				cout<<"Enter title:"<<endl;
				string titleofMovie;
				getline(cin, titleofMovie);
				if(titleofMovie != " ")
				{
					movies->insertMovie(titleofMovie);
				}
				else
					cout<<"Sorry, you entered a space."<<endl;
				break;
			}
			case 5:
			{
				//declare strings to read in from the command
				string titleofMovie;
				string character;
				string mRating;
				string bRating;
				string charRating;
				cout<<"Enter book title:"<<endl;
				getline(cin, titleofMovie);
				//cout<<"If you wish to not add a ranking to one of the categories, enter '-1'" <<endl;
				if(movies->doesBookExist(titleofMovie) == true)
				{
					cout<<"Who was your favorite character?"<<endl;
					getline(cin, character);
					cout<<"How awesome was this character? Rate (1-10)."<<endl;
					getline(cin, charRating);
					cout<<"Enter rating for the book (1-10)."<<endl;
					getline(cin, bRating);
					cout<<"Enter rating for the movie (1-10)."<<endl;
					getline(cin, mRating);
					if(movies->isRankingValid(charRating)== true && movies->isRankingValid(bRating)== true && movies->isRankingValid(mRating)== true )
					{
						int intmRating = stoi(mRating);
						int intcharRating = stoi(charRating);
						int intbRating = stoi(bRating);
						movies->addBestCharacter(titleofMovie, character, intbRating, intmRating, intcharRating);
					}
					else
						cout<<"Sorry, you must enter ratings (1-10)."<<endl;
				}
				else
					cout<<"Book does not exist"<<endl;
				break;
			}
			case 6:
			{
				
				movies->printBestOverallRatings();
				break;
			}
			case 7:
			{
				movies->printBestCharacters();
				break;
			}
			case 8:
			{
				movies->printBestBooks();
				break;
			}
			case 9:
			{
				movies->printBestMovies();
				break;
			}
			case 10:
			{
				cout<<"Goodbye!"<<endl;
				quit = true;
				break;
			}
			default:
			{
                cout << "Invalid Input" << endl;
                cin.clear();
                cin.ignore(10000,'\n');
                break; 
			}
		}
	}
	return 0;
}
