#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
//the declarations above are used in every file, must be consolidated into 1 header
#include "encode.h"
#include "globalvars.h"
std::string encoding_string;
using namespace std;
void encoder(std::string coded) {
	int c_position;
	ofstream filemessage;
	filemessage.open("codedmessage.txt");
	for (unsigned int n = 0; n < coded.length(); n++) { //replace elements from standard array to decode
		
		c_position = index_of(c_standard, c_standard + array_length, coded.at(n));
		//encoding_string.at(n) = c_cipher[c_position];
		cout << c_cipher[c_position];
		filemessage << c_cipher[c_position];

	}
	filemessage.close();

}


int encode_main() {
	//setting up the cipher
	int c_runs = 0;
	string uncoded_message;
	string coded_message;
	int user_seed;
	string c_password;
	bool user_quit = false;
	int quitorno; //allow user to quit
	bool valid_input = false;
	cout << "ENCODER" << endl;
	while (user_quit == false)
	{
		std::cout << "Type in your password (remember this)." << endl;
		if (c_runs > 0)
		{
			cin.ignore(1000, '\n');
		}
		else {
			std::getline(cin, c_password);
		}
		std::getline(cin, c_password);
		user_seed = 11111;
		for (unsigned int i = 0; i < c_password.size(); i++) {
			user_seed += c_password[i];
			user_seed = user_seed * (i + 100);
		}
		std::srand(user_seed);
		std::random_shuffle(c_cipher, c_cipher + array_length);
		std::cout << endl;
		std::cout << "Type in your message to be encoded.(alphabetical only)" << endl;
		std::getline(cin, uncoded_message);
		std::cout << endl;
		encoder(uncoded_message);
		c_password.erase(c_password.begin(), c_password.end());
		std::copy(c_standard, c_standard + array_length, c_cipher);
		std::cout << endl;
		std::cout << "1: repeat encoder" << endl << "2: return to main menu" << endl; //menu hierarchy
		do
		{
			cin >> quitorno;
			std::cout << endl;
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
		} while (valid_input == false);
		c_runs++;
	}
	std::cout << endl;
	std::cout << "If you want to copy/pastable version of your message " << endl << "search for codedmessage.txt on your computer." << endl;
	return 0;
}
