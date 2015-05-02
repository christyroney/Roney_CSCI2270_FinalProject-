#include "HashTable.h"
#include <iostream>                   
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

//This function is the constructor that sets the elements of the hashtable to NULL
HashTable::HashTable()
{
	hashTable = new Movie*[10];
	for(int i = 0; i < 10; i++)
	{
		hashTable[i] = NULL;
	}
}


//This is a function that prints out the menu for the user to follow with the following options.  
void HashTable::displayMenu()
{


    cout << "==BOOKS THAT BECAME MOVIES=="<<endl;
    cout << "======Main Menu======" << endl;
    cout << "1. Display Books" << endl;
    cout << "2. Delete book" << endl;
    cout << "3. Find book" << endl;
    cout << "4. Insert book" << endl;
    cout << "5. Add rankings" <<endl;
    cout << "6. Display Best Overall Ratings" <<endl;
    cout << "7. Display Character Rankings" <<endl;
    cout << "8. Display Book Rankings"<<endl;
    cout << "9. Display Movie Rankings" <<endl;
    cout << "10. Quit" << endl;
    return;
}

/*
Function prototype:
void HashTable::insertMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and inserts the movie alphabetically into the hashtable which is an array of linked lists. Handles cases where movie needs to be inserted as the first index, before the first index, after the first index, in the middle of two movie nodes, or as the last node in the liked list.  

Example:
HashTable ht;
ht.insertMovie("The Hunger Games")

Precondition: Unused locations in hashtable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.  The hashtable is an array of linked lists.
Post condition: Movie node inserted based into an index of the array based on its hashsum. Pointers updated to connect the linked list with the inserted movie node. 
*/       
void HashTable::insertMovie(string theTitle)
{
	int index = hashSum(theTitle);

	Movie * foundMovie = new Movie(theTitle);
	foundMovie->favChar = "none";
	foundMovie->bookRank = -1;
	foundMovie->movieRank = -1;
	foundMovie->charRank = -1;
	foundMovie->totalRank = -1;
	foundMovie->next = NULL;
	//if the array is empty at the spot, just insert movie            
	if(hashTable[index] == NULL)
	{
		hashTable[index] = foundMovie;
		foundMovie->next = NULL;
	}
	//else if there already movies at that spot
	else
	{
		Movie * temp = hashTable[index];
		//if movie title should go at head of linked list
		if(strcmp((foundMovie->title).c_str(), (temp->title).c_str()) < 0 )
		{ 
			hashTable[index] = foundMovie;
			foundMovie->next = temp;
		}
		else 
		{
			Movie * prev = hashTable[index];
			if(prev->next == NULL)
			{
				prev->next = foundMovie;
			}
			while(strcmp((foundMovie->title).c_str(), (prev->title).c_str()) > 0 && (prev->next != NULL) ) 
			{	
				if(	foundMovie->title < prev->next->title)
				{
					Movie * after = prev->next;
					prev->next = foundMovie;
					foundMovie->next = after;
					return;
				}
				else
				{
					prev = prev->next;
					if(prev->next == NULL)
					{
						prev->next = foundMovie;
						foundMovie->next = NULL;
						return;
					}
						
				}
					
				}
				
			}
			
			
		}
			
	}

/*
Function prototype:
void HashTable::findMovie(string)

Function description:
This method finds the movie node in the hashtable that has the same name as the input movie name by looping through the movie nodes in the hashtable.  Then, it returns the movie node once its found and also prints that it found the name of that movie node.

Example:
HashTable ht;
ht.findMovie("The Hunger Games")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node found from linked list at its hashsum index and once movie found returns movie node.
*/	
Movie* HashTable::findMovie(string inTitle)
{
	int index = hashSum(inTitle);
	Movie *temp = hashTable[index];
	//Movie *found;
	while(temp != NULL)
	{
		if(temp->title == inTitle)
		{
			cout<<temp->title<<;
			return temp;
		}
			
		temp = temp->next;	
	}	
}
/*
Function prototype:
void HashTable::deleteMovie(string)

Function description:
This method calculates the hashcode for the input movie name, and deletes the movie from the hash table. Handles cases where movie is first, mid, or last node in the chain.

Example:
HashTable ht;
ht.deleteMovie("The Giver")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: movie node deleted from chain and memory freed. Pointers updated to bypass deleted movie.
*/
void HashTable::deleteMovie(string inTitle)
{
	int index = hashSum(inTitle);
	Movie * head = hashTable[index];
	
	if(hashTable[index]->title == inTitle)
	{
		Movie * temp = hashTable[index];
		
		hashTable[index] = temp->next;
		delete temp;
	}
	else
	{
		while(head != NULL)
		{
			if(head->next->title == inTitle)
			{
				Movie * todelete = head->next;
				head->next = head->next->next;
				delete todelete;
				break;
			}
			else
				head = head->next;
		}
	}
	
}
/*
Function prototype:
void HashTable::printInventory()

Function description:
This method first checks to see if the hashtable is empty. If it is, it prints "empty". If not loops through the hashtable (array of linked list) and prints out the movie titles starting at index 0 of the hashtable.

Example:
HashTable ht;
ht.printInventory()

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. There is no input.
Post condition: Movie nodes are printed in order of the hashtable.
*/
void HashTable::printInventory()
{
	int sum = 0;
	bool isEmpty = true;
	for(int i = 0; i < 10; i++)
	{
		if(hashTable[i] != NULL)
			isEmpty = false;
	}
	
	if(isEmpty == false)
	{
	for(int i = 0; i < 10; i++)
	{
		Movie *temp = hashTable[i];
		while(temp != NULL)
		{
			cout<<temp->title<<endl;
			temp = temp->next;
		}
	}
	}
	else
		cout<<"empty"<<endl;
}
/*
Function prototype:
int HashTable::hashSum(string, int);

Function description:
This function calculates the hash code for a string by summing the ascii values of the individual elements of the string and % the sum by the size of the hash table.

Example:
HashTable ht
int hc = ht.hashSum("The Giver")

Pre-conditions: hashLen is integer > 0. inputString is valid ascii string
Post-conditions: returns non-negative integer
*/
int HashTable::hashSum(string theString)
{
	
	int sum = 0;
	for(int i = 0; i < theString.length(); i++)
	{
		sum += theString[i];	
	}
	sum = sum % 10;
	
	return sum;
	
}
/*
Function prototype:
void HashTable::addBestCharacter(string, string, int, int, int)

Function description:
This method calculates the hashcode for the input movie name and sets that movie node's best character, book rating, movie rating, and character rating.  Then, the overall rating is calculated based on those ratings and the movie node's overall rating is set to that.  

Example:
HashTable ht;
ht.addBestCharacter("The Hunger Games", "Catniss", 9, 8, 9)

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title, best character, book rating, movie rating, and character rating.
Post condition: Movie node's favorite character, book rating, movie rating, and character rating are set.  Then, the overall ranking is calculated and set.
*/
void HashTable::addBestCharacter(string inTitle, string bestChar, int bookRating, int movieRating, int charRating)
{
	int index = hashSum(inTitle);
	Movie *temp = hashTable[index];
	Movie * foundBook;
	while(temp != NULL)
	{
		if(temp->title == inTitle)
		{
			foundBook = temp;
			foundBook->favChar = bestChar;
			foundBook->bookRank = bookRating;
			foundBook->movieRank = movieRating;
			foundBook->charRank = charRating;	
		}
			
		temp = temp->next;
	}
	int overallRating = (bookRating + movieRating + charRating)/3;
	foundBook->totalRank = overallRating;
	cout<<"Total rank: "<<foundBook->totalRank<<endl;
		
}

/*
Function prototype:
void HashTable::doesBookExist(string)

Function description:
This method loops calculates the hashcode for the input movie name and loops through the hashtable to find if the movie exists.

Example:
HashTable ht;
ht.doesBookExist("The Hunger Games")

Precondition: Unused locations in hashTable vector are NULL. Movies stored using correctly calculated hash code calculated from movie title. The input string name is movie title.
Post condition: Function returns true if the movie node is in the hashtable and false if the movie is not in the hashtable.
*/
bool HashTable::doesBookExist(string inTitle)
{
	int index = hashSum(inTitle);
	Movie *temp = hashTable[index];
	Movie * foundBook;
	bool found = false;
	while(temp != NULL)
	{
		if(temp->title == inTitle)
		{
			foundBook = temp;
			found = true;
			
		}
			
		temp = temp->next;
		
	}
	return found;
}

/*
Function prototype:
void HashTable::printBestOverallRatings()

Function description:
This method first checks to see if the hashtable is empty. If it is, it prints "empty". If not loops through the hashtable (array of linked list) and prints out the best rankings in order from 10 to 1. It will not print out rankings if the rankings are 0 (or -1). 

Example:
HashTable ht;
ht.printBestOverallRatings()

Precondition: Only prints the movie nodes that conatin an overall rating greater than 0.  This method takes no input.
Post condition: Movie nodes titles with their overall ranking are printed in order (10 to 1).
*/
void HashTable::printBestOverallRatings()
{
	cout<<"THE TOP RATED BOOKS THAT BECAME MOVIES ARE: "<<endl;
	
	int count = 1;
	int sum = 0;
	bool isEmpty = true;
	for(int i = 0; i < 10; i++)
	{
		if(hashTable[i] != NULL)
			isEmpty = false;
	}
	
	if(isEmpty == false)
	{
		for(int j = 10; j > 0; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Movie *temp = hashTable[i];
				while(temp != NULL)
				{
					if(temp->totalRank == j)
					{
						cout<<count<<". "<<temp->title<<": "<<temp->totalRank<<endl;
						count++;
					}
					
					temp = temp->next;
				}
			}
		
		}
	}
	else
		cout<<"empty"<<endl;
	
}

/*
Function prototype:
void HashTable::printBestCharacters()

Function description:
This method first checks to see if the hashtable is empty. If it is, it prints "empty". If not loops through the hashtable (array of linked list) and prints out the best ranked characters in order from 10 to 1. It will not print out rankings if the rankings are 0 (or -1). 

Example:
HashTable ht;
ht.printBestCharacters()

Precondition: Only prints the movie nodes that conatin an overall rating greater than 0.  This method takes no input.
Post condition: Movie nodes titles with their favorite character ratings are printed in order (10 to 1).
*/
void HashTable::printBestCharacters()
{
		cout<<"THE TOP RATED CHARACTERS ARE: "<<endl;
	
	int count = 1;
	int sum = 0;
	bool isEmpty = true;
	for(int i = 0; i < 10; i++)
	{
		if(hashTable[i] != NULL)
			isEmpty = false;
	}
	
	if(isEmpty == false)
	{
		for(int j = 10; j > 0; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Movie *temp = hashTable[i];
				while(temp != NULL)
				{
					if(temp->charRank == j)
					{
						cout<<count<<". "<<temp->favChar<<"--"<<temp->title<<": "<<temp->charRank<<endl;
						count++;
					}
					
					temp = temp->next;
				}
			}
		
		}
	}
	else
		cout<<"empty"<<endl;
}

/*
Function prototype:
void HashTable::printBestBooks()

Function description:
This method first checks to see if the hashtable is empty. If it is, it prints "empty". If not loops through the hashtable (array of linked list) and prints out the book rankings in order from 10 to 1. It will not print out rankings if the rankings are 0 (or -1). 

Example:
HashTable ht;
ht.printBestBooks()

Precondition: Only prints the movie nodes that conatin a book rating greater than 0.  This method takes no input.
Post condition: Movie node titles with their book rating are printed in order (10 to 1).
*/
void HashTable::printBestBooks()
{
		cout<<"THE TOP RATED BOOKS ARE: "<<endl;
	
	int count = 1;
	int sum = 0;
	bool isEmpty = true;
	for(int i = 0; i < 10; i++)
	{
		if(hashTable[i] != NULL)
			isEmpty = false;
	}
	
	if(isEmpty == false)
	{
		for(int j = 10; j > 0; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Movie *temp = hashTable[i];
				while(temp != NULL)
				{
					if(temp->bookRank == j)
					{
						cout<<count<<". "<<temp->title<<": "<<temp->bookRank<<endl;
						count++;
					}
					
					temp = temp->next;
				}
			}
		
		}
	}
	else
		cout<<"empty"<<endl;
}

/*
Function prototype:
void HashTable::printBestMovies()

Function description:
This method first checks to see if the hashtable is empty. If it is, it prints "empty". If not loops through the hashtable (array of linked list) and prints out the movie rankings in order from 10 to 1. It will not print out rankings if the rankings are 0 (or -1). 

Example:
HashTable ht;
ht.printBestMovies()

Precondition: Only prints the movie nodes that conatin a book rating greater than 0.  This method takes no input.
Post condition: Movie node titles with their book rating are printed in order (10 to 1).
*/
void HashTable::printBestMovies()
{
			cout<<"THE TOP RATED MOVIES ARE: "<<endl;
	
	int count = 1;
	int sum = 0;
	bool isEmpty = true;
	for(int i = 0; i < 10; i++)
	{
		if(hashTable[i] != NULL)
			isEmpty = false;
	}
	
	if(isEmpty == false)
	{
		for(int j = 10; j > 0; j--)
		{
			for(int i = 0; i < 10; i++)
			{
				Movie *temp = hashTable[i];
				while(temp != NULL)
				{
					if(temp->movieRank == j)
					{
						cout<<count<<". "<<temp->title<<": "<<temp->movieRank<<endl;
						count++;
					}
					
					temp = temp->next;
				}
			}
		
		}
	}
	else
		cout<<"empty"<<endl;	
}

//This function returns true if the ranking is valid (between 1-10)
//Not one of the main functions
bool HashTable::isRankingValid(string ranking)
{
	if(ranking == "1" || ranking == "2" || ranking == "3" ||
	ranking == "4" || ranking == "5" || ranking == "6" ||
	ranking == "7" || ranking == "8" || ranking == "9" || ranking == "10")
		return true;
	
	return false;
	
}
