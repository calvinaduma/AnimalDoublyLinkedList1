/*  Calvin Aduma | caduma
    CPSC 1020 | Fall 2020
    C. Kittlestad
    10/10/20
    Project 1
*/

#include "dll_list.h"

int main(int agrc, char** argv){
	string filename = argv[1], animalName;
	ifstream readfile (filename);
	int choice, loop;
	loop = 1;
	list_t listPtr;
	listPtr->head = NULL;
	listPtr->tail = NULL;
	listPtr->size = 0;	
	cout << isEmpty(listPtr) << endl;
	while (loop) {
		choice = printMenu();
		switch (choice) {
			case 1:
				initializeFromFile(&listPtr, readfile);
				cout << isEmpty(&listPtr) << endl;
				break;
			case 2:
				addToFront(&listPtr);
				break;
			case 3:
				addToRear(&listPtr);
				break;
			case 4:
				cout << "Enter the name of the animal you want to delete:\t";
				cin >> animalName;
				cout << endl << endl;
				deleteAnimal(&listPtr, animalName);
				break;
			case 5:
				searchByType(&listPtr);
				break;
			case 6:
				searchByName(&listPtr);
				break;
			case 7:
				cout << "There are " << size(&listPtr) << " animals.\n\n";
				break;
			case 8:
				printList(&listPtr);
				break;
			case 9:
				loop = 0;
		}
	}
	return 0;  
}
