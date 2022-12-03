#include <iostream>
#include <queue>
#include <string>
#include <iterator>
#include <map>

//prints each item of queue by printing front, moving front to back, and popping front
void print_queue(std::queue<int>& q) {
	std::cout << "printing queue..." << std::endl;
	unsigned int qsize = q.size();
	for (unsigned int i = 0; i < qsize; i++) {
		std::cout << q.front() << ", ";
		q.push(q.front());
		q.pop();
	}
	std::cout << std::endl << "queue printed!" << std::endl << std::endl;
}

//moves front to back
void move_to_rear(std::queue<int>& q) {
	std::cout << "moving front to rear..." << std::endl;
	q.push(q.front());
	q.pop();
	std::cout << "entry moved!" << std::endl << std::endl;
}


//calls itself untilt the string is shorter than 2, then returns true if and only if each character on each end of the word was equivalent up until that point
bool is_pali(std::string word, int size) {
	if (word.size() < 2) {
		return true;
	}
	else {
		if (tolower(word.front()) == tolower(word.back())) {
			std::string new_word = word.substr(1, word.size() - 2);
			return is_pali(new_word, new_word.size());
		}
		else {
			return false;
		}
	}
}


//prints each obj in map
void print_map(std::map<std::string, std::string>& m) {
	std::map<std::string, std::string>::iterator itr = m.begin();
	for (itr; itr != m.end(); itr++) {
		std::cout << itr->first << "\t" << itr->second << std::endl;
	}
	std::cout << std::endl;
}

//returns the capital given a state
void get_capital(std::map<std::string, std::string>& m) {
	std::string user_state;
	std::cout << "Enter the name of the state: ";
	std::cin >> user_state;
	std::cout << std::endl;
	std::cout << m[user_state] << std::endl;
}