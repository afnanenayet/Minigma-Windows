#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include "globalvars.h"
#include "decode.h"

using namespace std;

//global variables (now redundant, moved to globalvars.h)

void decoder(std::string coded) {
	int c_position;
	for (unsigned int n = 0; n < coded.length(); n++) { //replace elements from standard array to decode
		c_position = index_of(c_cipher, c_cipher + array_length, coded.at(n));
		cout << c_standard[c_position];
	}
}

int decode_main() {
	//setting up the cipher
	int c_runs = 0;
	string uncoded_message;
	string coded_message;
	int user_seed;
	string c_password;
	bool user_quit = false;
	int quitorno; //allow user to quit
	bool valid_input = false;

	cout << "DECODER" << endl;

	while (user_quit == false)
	{
		std::copy(c_standard, c_standard + array_length, c_cipher);
		std::cout << "Type in your password." << endl;
		if (c_runs > 0) //idk why but this trick allows program to take input
		{
			cin.ignore(1000, '\n');
		}
		else {
			std::getline(cin, c_password);
		}
		std::getline(cin, c_password);
		user_seed = 11111;
		for (unsigned int i = 0; i < c_password.size(); i++) { //sets up cipher/srand seed
			user_seed += c_password[i];
			user_seed = user_seed * (i + 100);
		}
		std::srand(user_seed);
		std::random_shuffle(c_cipher, c_cipher + array_length);
		std::cout << endl;
		std::cout << "Type in your message to be decoded." << endl;
		std::getline(cin, coded_message);
		std::cout << endl;
		decoder(coded_message);
		c_password.erase(c_password.begin(), c_password.end()); //reset password jic user wants to decode again
		std::cout << endl;
		std::cout << "1: decode again" << endl;
		std::cout << "2: return to menu" << endl;
		//menu hierarchy
		do
		{
			cin >> quitorno;
			std::cout << endl;
			//will go back to main menu depending on user input or will repeat
			if (quitorno == 1) { 
				user_quit = false;
				cin.clear();
				valid_input = true;

			}

			else if (quitorno == 2) {
				user_quit = true;
				valid_input = true;
			}

			else {
				std::cout << endl << "You didn't type in 1 or 2." << endl;
				valid_input = false;
				std::cout << "Please type in a valid input." << endl;
			}

		} while (valid_input == false); //loop jic user types invalid input 
		c_runs++; //only here for the cin.ignore workaround
	}
	return 0;
}
