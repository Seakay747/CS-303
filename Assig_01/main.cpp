#include <iostream>
#include <fstream>
#include "funcs.h"

int main() {

	//instantiating variables that will allow the library of numbers to both grow and enter the 100 values from our input file
	//25 was chose arbitrarily, almost exclusivley to test the function for dynamic growth
	unsigned int index = 0;
	int temp_int;
	int size = 25;
	int* num_lib = new int[size];

	//pulls in the values from the input file
	std::ifstream fin("input.txt");
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
		std::cout << "input.txt failed to open" << std::endl;
	}

	//variable that will be used with functions the user calls
	bool loop = true;
	char command;
	unsigned int temp_index;

	while (loop) {
		//prints menu the displays command options to the user
		print_menu();
		std::cin >> command;
		//runs appropriate function given user specified command
		switch (tolower(command)) {
			case 'f':
				std::cout << "Enter the number you want to find: ";
				std::cin >> temp_int;
				arr_find(num_lib, temp_int, index);
				break;
			case 'm':
				std::cout << "Enter the index of the number you want to modify: ";
				try {
					std::cin >> temp_index;
					if (!std::cin.good()) {
						throw std::invalid_argument("Bad Input Error: The input recieved for the index must be a non-negative interger");
					}
					/*while (temp_index >= index) {
						std::cout << "The index you have entered is out of bounds, please enter an index that is less than " << index << ": ";
						std::cin >> temp_index;
					}*/
					if (temp_index >= index) {
						throw "Out of Bounds Error: The index input entered was outside of the array";
					}
					std::cout << "Enter the number you want to replace " << num_lib[temp_index] << " with: ";
					std::cin >> temp_int;
					if (!std::cin.good()) {
						throw std::invalid_argument("Bad Input Error: The input recieved for the new value must be a non-negative integer");
					}
					arr_mod(num_lib, temp_index, temp_int);
				}
				catch (std::invalid_argument& ex) {
					std::cerr << ex.what() << std::endl;
					std::cin.clear();
					while (std::cin.get() != '\n') {
						continue;
					}
				}
				catch (const char* what) {
					std::cerr << what << std::endl;
					std::cin.clear();
					while (std::cin.get() != '\n') {
						continue;
					}
				}
				break;
			case 'a':
				std::cout << "Enter the number you want to add to the library: ";
				try {
					std::cin >> temp_int;
					if (!std::cin.good()) {
						throw std::invalid_argument("Bad Input Error: The input recieved must be a non-negative integer");
					}
					if (index >= size) {
						expand_arr(num_lib, size);
					}
					add_val(num_lib, temp_int, index);
					index++;
				}
				catch (std::invalid_argument& ex) {
					std::cerr << ex.what() << std::endl;
					std::cin.clear();
					while (std::cin.get() != '\n') {
						continue;
					}
				}
				catch (const char* what) {
					std::cerr << what << std::endl;
					std::cin.clear();
					while (std::cin.get() != '\n') {
						continue;
					}
				}
				break;
			case 'd':
				std::cout << "Enter the index of the number you want to delete: ";
				std::cin >> temp_index;
				while (temp_index >= index) {
					std::cout << "The index you have entered is out of bounds, please enter an index that is less than " << index << ": ";
					std::cin >> temp_index;
				}
				del_val(num_lib, size, index, temp_index);
				index--;
				break;
			case 'q':
				loop = false;
				break;
			default:
				std::cout << "The command you have entered is invalid, please enter a valid command from the list of options" << std::endl;
				break;
		}
	}
	
	return 0;
}