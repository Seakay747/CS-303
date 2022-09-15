#include <iostream>
#include <fstream>
#include "funcs.h"

using namespace std;

int main() {

	//instantiating variables that will allow the library of numbers to both grow and enter the 100 values from our input file
	//25 was chose arbitrarily, almost exclusivley to test the function for dynamic growth
	unsigned int index = 0;
	int temp_int;
	int size = 25;
	int* num_lib = new int[size];

	//pulls in the values from the input file
	ifstream fin("input.txt");
	if (fin.is_open()) {
		while (fin >> temp_int) {
			//if the current index goes past the amount of space we have allocated, the array is expanded to fit more values
			if (index >= size) {
				expand_arr(num_lib, size);
			}
			add_val(num_lib, temp_int, index);
			index++;
		}
	}
	else {
		cout << "input.txt failed to open" << endl;
	}

	//variable that will be used with functions the user calls
	bool loop = true;
	char command;
	unsigned int temp_index;

	while (loop) {
		//prints menu the displays command options to the user
		print_menu();
		cin >> command;
		//runs appropriate function given user specified command
		switch (tolower(command)) {
			case 'f':
				cout << "Enter the number you want to find: ";
				cin >> temp_int;
				arr_find(num_lib, temp_int, index);
				break;
			case 'm':
				cout << "Enter the index of the number you want to modify: ";
				cin >> temp_index;
				while (temp_index >= index) {
					cout << "The index you have entered is out of bounds, please enter an index that is less than " << index << ": ";
					cin >> temp_index;
				}
				cout << "Enter the number you want to replace " << num_lib[temp_index] << " with: ";
				cin >> temp_int;
				arr_mod(num_lib, temp_index, temp_int);
				break;
			case 'a':
				cout << "Enter the number you want to add to the library: ";
				cin >> temp_int;
				if (index >= size) {
					expand_arr(num_lib, size);
				}
				add_val(num_lib, temp_int, index);
				index++;
				break;
			case 'd':
				cout << "Enter the index of the number you want to delete: ";
				cin >> temp_index;
				while (temp_index >= index) {
					cout << "The index you have entered is out of bounds, please enter an index that is less than " << index << ": ";
					cin >> temp_index;
				}
				del_val(num_lib, size, index, temp_index);
				index--;
				break;
			case 'q':
				loop = false;
				break;
			default:
				cout << "The command you have entered is invalid, please enter a valid command from the list of options" << endl;
				break;
		}
	}
	
	return 0;
}