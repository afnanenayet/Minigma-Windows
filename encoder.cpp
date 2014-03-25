/*#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>*/
//the declarations above are used in every file, have been placed in stdafx.h
#include "encoder.h"
#include "globalvars.h"
#include "stdafx.h"

using namespace std;

//global variables
/*const int array_length = 83;
char c_standard[83] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '_', '[', ']', '{', '}', '<', '>', '?' }; //array to be shuffled based on user password
char c_cipher[array_length] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '_', '[', ']', '{', '}', '<', '>', '?' }; //array to be shuffled based on user password
*/
void transcoder(std::string coded) { //super inefficient way to switch out characters in the arrays
	ofstream filemessage;
	filemessage.open("codedmessage.txt");
	cout << endl << "Coded message is: " << endl;
	for (unsigned int n = 0; n < coded.length(); n++) {
		switch (coded.at(n)) {
		case 'a':
			std::cout << c_cipher[1];
			filemessage << c_cipher[1];
			break;

		case 'b':
			std::cout << c_cipher[2];
			filemessage << c_cipher[2];
			break;

		case 'c':
			std::cout << c_cipher[3];
			filemessage << c_cipher[3];
			break;

		case 'd':
			std::cout << c_cipher[4];
			filemessage << c_cipher[4];
			break;

		case 'e':
			std::cout << c_cipher[5];
			filemessage << c_cipher[5];
			break;

		case 'f':
			std::cout << c_cipher[6];
			filemessage << c_cipher[6];
			break;

		case 'g':
			std::cout << c_cipher[7];
			filemessage << c_cipher[7];
			break;

		case 'h':
			std::cout << c_cipher[8];
			filemessage << c_cipher[8];
			break;

		case 'i':
			std::cout << c_cipher[9];
			filemessage << c_cipher[9];
			break;

		case 'j':
			std::cout << c_cipher[10];
			filemessage << c_cipher[10];
			break;

		case 'k':
			std::cout << c_cipher[11];
			filemessage << c_cipher[11];
			break;

		case 'l':
			std::cout << c_cipher[12];
			filemessage << c_cipher[12];
			break;

		case 'm':
			std::cout << c_cipher[13];
			filemessage << c_cipher[13];
			break;

		case 'n':
			std::cout << c_cipher[14];
			filemessage << c_cipher[14];
			break;

		case 'o':
			std::cout << c_cipher[15];
			filemessage << c_cipher[15];
			break;

		case 'p':
			std::cout << c_cipher[16];
			filemessage << c_cipher[16];
			break;

		case 'q':
			std::cout << c_cipher[17];
			filemessage << c_cipher[17];
			break;

		case 'r':
			std::cout << c_cipher[18];
			filemessage << c_cipher[18];
			break;

		case 's':
			std::cout << c_cipher[19];
			filemessage << c_cipher[19];
			break;

		case 't':
			std::cout << c_cipher[20];
			filemessage << c_cipher[20];
			break;

		case 'u':
			std::cout << c_cipher[21];
			filemessage << c_cipher[21];
			break;

		case 'v':
			std::cout << c_cipher[22];
			filemessage << c_cipher[22];
			break;

		case 'w':
			std::cout << c_cipher[23];
			filemessage << c_cipher[23];
			break;

		case 'x':
			std::cout << c_cipher[24];
			filemessage << c_cipher[24];
			break;

		case 'y':
			std::cout << c_cipher[25];
			filemessage << c_cipher[25];
			break;

		case 'z':
			std::cout << c_cipher[26];
			filemessage << c_cipher[26];
			break;

		case ' ':
			std::cout << c_cipher[27];
			filemessage << c_cipher[27];
			break;

		}
	}
	filemessage.close();
} //should streamline this to two arrays

int encode_main() {
	//setting up the cipher
	int c_runs = 0; //how many times has the loop run?
	string uncoded_message; //raw user input
	string coded_message; //output
	int user_seed; //seed based off of password
	string c_password; //raw input of user password
	bool user_quit = false; //has the user chosen to quit? if true, then quit program
	int quitorno; //allow user to quit
	bool valid_input = false; //is the input valid?

	cout << "ENCODER" << endl; //title

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


		//cout << "DEBUG: user_seed = " << user_seed << endl; //delete this before production
		std::srand(user_seed);

		std::random_shuffle(c_cipher, c_cipher + array_length);
		/*for (int n = 0; n < array_length; n++) { //(debug) to show the array to test is password is working
		std::cout << c_cipher[n];
		}*/
		std::cout << endl;

		std::cout << "Type in your message to be encoded.(alphabetical only)" << endl;
		std::getline(cin, uncoded_message);
		std::cout << endl;
		transcoder(uncoded_message);


		c_password.erase(c_password.begin(), c_password.end()); //do this so the user can run program multiple times w/multiple paswrds
		std::copy(c_standard, c_standard + array_length, c_cipher);
		//cout << endl << "c_password is: "; debug
		/*for (unsigned int n = 0; n < c_password.length(); n++) {
		cout << c_password.at(n); //debug only
		} */


		std::cout << endl;
		std::cout << "1: repeat encoder" << endl << "2: return to main menu" << endl; //menu hierarchy

		do
		{ //quit to main menu
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
