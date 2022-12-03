#include <iostream>
#include "funcs.h"
#include <queue>
#include <string>
#include <iterator>
#include <map>

int main() {
	
	/*
	Write a new queue function called move_to_rear that moves the element
	currently at the front of the queue to the rear of the queue. The element that was
	second in line will be the new front element. Do these using functions push, front,
	and pop.
	*/
	
	std::queue<int> qints;
	for (unsigned int i = 0; i < 10; i++) {
		qints.push(i);
	}
	print_queue(qints);
	move_to_rear(qints);
	print_queue(qints);

	/*
	As discussed in Chapter 5, a palindrome is a word that reads the same left to
	right as right to left. Write a recursive function that determines whether its argument
	string is a palindrome.
	*/


	//setting up palindromes and non-palindromes to test
	std::string word1 = "mom";
	std::string word2 = "pallindrome";
	std::string word3 = "RACEcar";
	std::string word4 = "fish are friends";
	std::string word5 = "Madam Eve madam";

	//testing using recursive func
	if (is_pali(word1, word1.size())) {
		std::cout << word1 << " is a palindrome!" << std::endl;
	}
	else {
		std::cout << word1 << " is NOT a palindrome :(" << std::endl;
	}

	if (is_pali(word2, word2.size())) {
		std::cout << word2 << " is a palindrome!" << std::endl;
	}
	else {
		std::cout << word2 << " is NOT a palindrome :(" << std::endl;
	}

	if (is_pali(word3, word3.size())) {
		std::cout << word3 << " is a palindrome!" << std::endl;
	}
	else {
		std::cout << word3 << " is NOT a palindrome :(" << std::endl;
	}

	if (is_pali(word4, word4.size())) {
		std::cout << word4 << " is a palindrome!" << std::endl;
	}
	else {
		std::cout << word4 << " is NOT a palindrome :(" << std::endl;
	}

	if (is_pali(word5, word5.size())) {
		std::cout << word5 << " is a palindrome!" << std::endl << std::endl;
	}
	else {
		std::cout << word5 << " is NOT a palindrome :(" << std::endl << std::endl;
	}

	/*
	Declare the map container stateDataMap to store pairs of the form
	(stateName, capitalName), where stateName and capitalName are variables of type
	string:
	• Write C++ statements that add the following pairs to stateDataMap: (Nebraska,
	Lincoln), (New York, Albany), (Ohio, Columbus), (California, Sacramento),
	(Massachusetts, Boston), and (Texas, Austin).
	• Write a C++ method that outputs the data stored in stateDataMap.
	• Write a C++ statement that changes the capital of California to Los Angeles
	• Write a C++ method that outputs the capitalName using the stateName which will
	be entered by the user.
	*/

	//Declare the map container stateDataMap
	std::map<std::string, std::string> stateDataMap;
	//add the following pairs to stateDataMap
	stateDataMap.insert(std::pair<std::string, std::string>("Nebraska", "Lincoln"));
	stateDataMap.insert(std::pair<std::string, std::string>("New York", "Albany"));
	stateDataMap.insert(std::pair<std::string, std::string>("Ohio", "Columbus"));
	stateDataMap.insert(std::pair<std::string, std::string>("California", "Sacramento"));
	stateDataMap.insert(std::pair<std::string, std::string>("Massachusetts", "Boston"));
	stateDataMap.insert(std::pair<std::string, std::string>("Texas", "Austin"));

	//Write a C++ method that outputs the data stored in stateDataMap.
	print_map(stateDataMap);

	//statement that changes
	stateDataMap["New York"] = "Los Angeles";

	//outputs the capital name given a state name
	get_capital(stateDataMap);

	return 0;
}