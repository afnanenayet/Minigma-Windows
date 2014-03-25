//Minigma.cpp : Defines the entry point for the console application.
//
/*This was made by Afnan Enayet, last revised 3/25/2014*/

#include "stdafx.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Minigma v1.0.0\n";
	cout << "Enayet 2014\n";
	char dore; //to choose decode or encode
	char booldef; //quit variable
	bool c_repeat = false;


	do
	{
		cout << "e: encode" << endl << "d: decode" << endl;
		cin >> dore;
		if (dore == 'e') { //goes to encode function
			encode_main();
		}

		else if (dore == 'd') { //goes to decode function
			decode_main();
		}

		else {
			cout << endl << "You did not provide a valid input." << endl; //if user didn't press e or d
			cout << "Please type either 1 (to quit) or 2 (to repeat)." << endl;
			cin >> booldef; //default = false so program will quit
		}

		cout << endl << "q: quit program" << endl << "r: repeat program" << endl;
		cin >> booldef;
		//choose whether to quit or not via 'q' or 'r'
		if (booldef == 'q') {
			c_repeat = false;
		}

		else if (booldef == 'r') {
			c_repeat = true;
		}

		else { //if input wasn't 'q' or 'r'
			cout << endl << "You didn't provide a valid input, program will quit.";
		}
	} while (c_repeat == true); //will repeat until else clause makes it false
}

