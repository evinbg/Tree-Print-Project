#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "node.h"

void printMenu(); // prints the main menu
int checkInput(int options, std::string text); // checks if the user's input is valid
void doAction(int action); // does the action of the user input
void insertFromFile(); // reads and inserts the nodes from the file
void enterRange(); // gets the input for the range from the user

Node* root; // keeps track of the root of the BST

int main() {
	bool keepGoing = true;
	int action;

	insertFromFile();

	while (keepGoing == true) { // loop to keep the application running
		printMenu();
		action = checkInput(2, "Enter an option: ");
		doAction(action);
	}

	return 0;
}

void printMenu() {
	std::cout << "[Tree Print]" << std::endl;
	std::cout << "1: Enter range" << std::endl;
	std::cout << "2: Print entire tree in order" << std::endl;
	std::cout << "0: Exit" << std::endl;
}

int checkInput(int options, std::string text) {
	bool keepGoing = true;
	bool intCheck;
	int num;
	std::string strInput;

	while (keepGoing == true) { // loops until valid input is given
		std::cout << text;
		std::getline(std::cin, strInput);
		intCheck = true;

		for (int i = 0; i < strInput.length(); i++) { // checks if the input is an integer
			if (std::isdigit(strInput[i]) == false) {
				std::cout << "You must enter an integer" << std::endl;
				intCheck = false;
				break;
			}
		}

		if (intCheck == true) {
			num = std::stoi(strInput);
			if (num > options && options != 0) { // checks if the integer input is within the given range, no limit if options = 0
				std::cout << "You must enter an option within the range 0 - " << options << std::endl;
			}
			else {
				keepGoing = false;
			}
		}
	}

	return num;
}

void doAction(int action) {

	switch (action) {
	case (1):
		enterRange();
		std::cout << std::endl;
		break;

	case (2):
		root->inOrder(root);
		std::cout << std::endl;
		break;

	case (0):
		exit(1);
		break;

	default:
		std::cout << "Something went wrong..." << std::endl;
		break;
	}
}

void insertFromFile() {
	std::ifstream inputFile;
	inputFile.open("input.txt");

	if (!inputFile) { // checks if the file exists in the directory
		std::cout << "input.txt file not found. Check if the file is in the project's directory" << std::endl << std::endl;
		exit(2);
	}

	bool rootCheck = false;
	std::string str;

	while (std::getline(inputFile, str, ' ')) { // reads each node from file
		int num = stoi(str); // converting string to integer

		if (rootCheck == false) { // special case for first number (root)
			root = new Node(num);
			rootCheck = true;
			continue;
		}

		Node* newNode = root->insert(root, num); // inserting the new num into the BST
	}

	std::cout << std::endl;
}

void enterRange() {
	int k1 = checkInput(0, "Enter the lower limit for k1: ");
	int k2 = checkInput(0, "Enter the upper limit for k2: ");

	if (k1 > k2) {
		std::cout << "You must have k1 less than or equal to k2" << std::endl;
		return;
	}

	root->printRange(root, k1, k2);
}
