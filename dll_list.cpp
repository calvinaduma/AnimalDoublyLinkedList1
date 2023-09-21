/*	Calvin Aduma | caduma
	CPSC 1020 | Fall 2020
	C. Kittlestad
	10/10/20
	Project 1
*/
	
#include "dll_list.h"

// prints the Menu option
// inputs: none
// outputs: an integer from the selected menu
int printMenu () {
	int choice;
	cout << "1.\tinitialize list of animals from file" << endl;
	cout << "2.\tadd additional animal to front of list" << endl;
	cout << "3.\tadd additional animal to end of list" << endl;
	cout << "4.\tdelete animal" << endl;
	cout << "5.\tsearch animals by type\n";
	cout << "6.\tsearch animals by name\n";
	cout << "7.\tshow number of animals in list\n";
	cout << "8.\tprint animals\n";
	cout << "9.\tquit program\n" << endl;
	cout << "- - > ";
	cin >> choice;
	cout << endl;
	return choice;
}
// checks to see if list is empty
// inputs: one of the pointer in the structure list_t
// outputs: 1 if list is empty; 0 if not empty
int isEmpty (list_t *list) {
	if (list->head != NULL) { // checks if head and tail pointer is null for emptiness
		return 0; // if not empty
	} else {
		return 1; // if empty
	}
}
// returns the size of the list
// input: one of the pointers in the structure list_t
// output: returns an int
int size (list_t *list) {
	int i;
	while (list->head != NULL){ //if head pointer is null, list is empty
		i++;
		list->head = list->head->next;
	}
	if (list->head == NULL) {
		i = 0;
	}		
	list->size = i;
	return i;
}
// prints the list of animals created
// input: one of the pointers in the structure list_t
// output: void
void printList (list_t *list) {
	cout << "Animals in list:\n" << endl << endl;
	while (list != NULL) {
		cout << list->head->aType << list->head->aName << endl << endl;
		list->head = list->head->next;
	}
}
// called from intializeFromFile(); call newAnimal() to create and initialize a new animal from the file; then adds it to end of list; increments the list size for each animal added
// input: one of the pointers in the structure list_t and input file pointer
// output: void
void listInit (list_t *list, ifstream &inFile) {
	animal_t *tempAnimal = new animal_t;
	int count = 0;
	while (!inFile.eof()){
		inFile >> tempAnimal->aType >> tempAnimal->aName; // reads and stores input
		tempAnimal->next = NULL; // creates a template to be subbed into the actual list
		tempAnimal->prev = list->tail;
		list->tail = tempAnimal; // tail pointer used because list grows at the end.
		if (count==0){
			list->head=list->tail; // places the head pointer at beginning of list
		}
		count++;
	}
	list->size = count;
	delete tempAnimal; 
}
// calls listInit() sending the input file pointer (the file specified at the command-line)
// input: one of the pointers in the stucture list_t and input file pointer
// output: void
void initializeFromFile (list_t *list, ifstream &inFile) { 
	if (list->size == 0) {
		listInit(list, inFile);
	} else {
		cout << "List is already initialized\n\n";
	}
}
// creates a new animal from user input and adds it to the front of the list
// input: one of the pointers in the structure list_t
// output: void
void addToFront (list_t *list) {
	string type, name;
	animal_t *temporary = new animal_t;
	cout << "Enter animal type:\t";
	cin >> type;
	cout << endl << "\nEnter animal name:\t";
	cin >> name;
	cout << endl << endl;
	temporary->next = list->head; // creation of temp animal struct for new animal to be added to front
	temporary->aType = type;
	temporary->aName = name;
	list->head = temporary; 
	list->size++;
	delete temporary;	
}
// creates a new animal from user input and adds it to the end of the list
// input: one of the pointers in the structure list_t 
// output: void
void addToRear (list_t *list) {
	string type, name;
	animal_t *temporary = new animal_t;
	cout << "Enter animal type:\t";
	cin >> type;
	cout << endl << "\nEnter animal name:\t";
	cin >> name;
	cout << endl << endl;
	temporary->prev = list->tail; // creation of temp animal strict for new animal to be added to rear
	temporary->aType = type;
	temporary->aName = name;
	list->tail = temporary;	
	list->size++;
	delete temporary;
}
// deletes the animal with the aName that matches the parameter animalName; decrements list size; if list is empty, prints message that the list is empty
// input: one of the pointers in the structure list_t
// output: void
void deleteAnimal (list_t *list, string animalName) {
	animal_t *temporary = new animal_t;
	if (isEmpty(list)==0){
		while (list->head != NULL) {
			if (animalName == list->head->aName) { // match
				cout << endl << "\nDeleting animal: " << list->head->aType << " " << list->head->aName << endl << endl;
				temporary = list->head->next; // temp files equals next pointer
				temporary->prev = list->head->prev; // previous files move to temp files
				list->head = temporary; // temp files transfer
			} else {
				list->head = list->head->next;
			}
		} 
	} else {
		cout << "The list is empty" << endl << endl;
	}
}
// searches the list for aType and returns all found, or message that no animals of that type were found
// input: one of the pointers in the structure list_t
// output: void
void searchByType (list_t *list) {
	string type;
	cout << "What is the animal type you are looking for:\t";
	cin >> type;
	cout << endl << endl;
	while (list->head != NULL) {
		if (type == list->head->aType) {
			cout << list->head->aType << " " << list->head->aName << endl;
			list->head = list->head->next;
		} else if (type != list->head->aType && list->head->next == NULL) {
			cout << "No animal of type " << type << " were found\n\n";
		} else {
			list->head = list->head->next;
		}
	}
}
// searches the list for aName and returns all found, or message that no animals of that name were found
// input: one of the pointers in the structure list_t
// output: void
void searchByName (list_t *list) {
	string name;
	int count = 1;
	cout << "What is the animal name you are looking for:\t";
	cin >> name;
	cout << endl << endl;
	while (list->head != NULL) {
		if (name == list->head->aName) {
			cout << list->head->aType << " " << list->head->aName << " is number "<< count << " in the list\n\n";
		} else if (list->head->next == NULL && name != list->head->aName) {
			cout << "No animals of name " << name << " were found \n\n"; 
		} else {
			count++;
		}
	}
}
