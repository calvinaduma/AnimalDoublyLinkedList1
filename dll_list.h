/* 	Calvin Aduma | caduma
	CPSC 1020 | Fall 2020
	C. Kittlestad
	10/10/20
	Project 1
*/

#ifndef DLL_LIST_H
#define DLL_LIST_H

#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


typedef struct animal {
	string aType;
	string aName;
	struct animal *prev;
	struct animal *next;
} animal_t;


typedef struct list {
	animal_t *head;
	animal_t *tail;
	int size;
} list_t;


int printMenu( );  
list_t *newList( );
void listInit( list_t *list, ifstream &inFile  );
void initializeFromFile( list_t *list, ifstream &inFile  );
animal_t *newAnimal( ifstream &inFile );
void addToFront( list_t *list );
void addToRear( list_t *list );
void deleteAnimal( list_t *list, string animalName );
void searchByType( list_t *list );
void searchByName( list_t *list );
int isEmpty( list_t *list );
int size( list_t *list );
void printList ( list_t *list );


#endif /* DLL_LIST_H */
