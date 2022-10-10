#include <iostream>
#include <fstream>

void print_menu() {
	std::cout << std::endl << "f). Find the index(es) where a number is stored" << std::endl;
	std::cout << "m). Modify a number stored at a given index" << std::endl;
	std::cout << "a). Add a number to the end of the library" << std::endl;
	std::cout << "d). Deletes a number stored at a given index" << std::endl;
	std::cout << "q). Quit program" << std::endl;
	std::cout << "Please enter a command: " << std::endl;
}

void expand_arr(int*& arr, int& size) {
	//makes a new array of doubled size and copies all values from the current array
	std::cout << "expanding allocated memory to fit more values, please wait a moment..." << std::endl;
	int* dbl = new int[size * 2];
	for (int i = 0; i < size; i++) {
		dbl[i] = arr[i];
	}
	delete[] arr;
	arr = dbl;
	size *= 2;
}

void add_val(int*& arr, int val, unsigned int index) {
	//adds a value to the array
	if (val < 0) {
		throw "Bad Input Error: Cannot store negative intergers";
	}
	std::cout << "adding " << val << " to index " << index << std::endl;
	arr[index] = val;
}

void arr_find(int*& arr, int val, int size) {
	//searches for all occurences of a given value
	//if none are found, displays appropriate message
	bool found = false;
	for (int i = 0; i < size; ++i) {
		if (arr[i] == val) {
			std::cout << "One occerence of " << val << " is at index " << i << std::endl;
			found = true;
		}
	}
	if (!found) {
		std::cout << val << " is not in the number library" << std::endl;
	}
}

void arr_mod(int*& arr, unsigned int index, int val) {
	//replaces value at given array index with new given value
	if (val < 0) {
		throw "Bad Input Error: Cannot store negative integers";
	}
	std::cout << arr[index] << " has been replaced with " << val << std::endl;
	arr[index] = val;
}

void del_val(int*& arr, int size, int cur_index, unsigned int del_index) {
	//deletes value in place in array by creating new array of equivalent size and copies all values except value at given index
	//corrects for the numbers that shift back one index using if-else ladder
	int* del_arr = new int[size];
	bool shift = false;
	for (int i = 0; i < cur_index; i++) {
		if (i == del_index) {
			shift = true;
			std::cout << arr[del_index] << " has been deleted" << std::endl;
		}
		else if (!shift) {
			del_arr[i] = arr[i];
		}
		else {
			del_arr[i - 1] = arr[i];
		}
	}
	delete[] arr;
	arr = del_arr;
}