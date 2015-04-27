# Roney_CSCI2270_FinalProject-
Project Summary:
For this project, I am going to create a hashtable (specifically an array of linked lists) of books that became movies (Harry Potter, Lord of the Rings, ect.).  The hashtable will consist of book structs with a title, best character, character rating, book rating, movie rating, and overall rating (scale of 1-10).  The overall ranking will be calculated based on the book, movie, and best character rating.  
At the start of the program, a list of 50 books that became movies will be displayed along with a menu option.  The user will have the option to add different rankings based on what books or movies they have read.  Once the user puts in their rankings, they can select the option to display (in order) the top books, top movies, top characters, and top overall books that became movies.  If the user did not add rankings to any movie, those rankings will not be displayed. 

How to Run: To run this code, download the HashTable.cpp, HashTable.h, and the driver HashTableDriver.cpp.  Also, download the Books.txt file.  To compile the code, compile the code on a linux operating system terminal by typing in "g++ -std=c++11 HashTable.cpp HashTableDriver.cpp".  Then press enter.  Then, to execute the code, type into the terminal "./a.out Books.txt".  If you wish to not use the list of books in Books.txt, you can create your own txt file of books.  Then, a menu will pop up with different options to perform for the book to movie structs.  I would reccommend to add as many ratings to the structs as you can so you can then display the different ratings from the menu.

Dependencies:
This program does not require any dependencies. However, it does require a file to be read in that is a list of books which became movies. The file Books.txt can be used as that file to be read in, yet if you would like to create your own list of books which became movies txt file that is fine.

System Requirements: 
This program has no system requirements.

Group Members:
I worked alone on this project.

Contributors:
Rhonda Hoenigman helped resolve a bug in my code which was causing a seg fault when adding an extra parameter to my movie struct.

Open issues/bugs:
I have not encountered any bugs with my code, yet I am open to requests involving how to display my list of movies that became books in alphabetical order.


