// CIFFrench.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <locale>

using namespace std;

map<int, string> DICT {
	    { 0, "zero"},
		{ 1, "un" },
		{ 2, "deux" },
		{ 3, "trois" },
		{ 4, "quatre" },
		{ 5, "cinq" },
		{ 6, "six" },
		{ 7, "sept" },
		{ 8, "huit" },
		{ 9, "neuf" },
		{ 10, "dix" },
		{ 11, "onze" },
		{ 12, "douze" },
		{ 13, "treize" },
		{ 14, "quatorze" },
		{ 15, "quinze" },
		{ 16, "seize" },
		{ 17, "dix-sept" },
		{ 18, "dix-huit" },
		{ 19, "dix-neuf" },
		{ 20, "vingt" },
		{ 30, "trente" },
		{ 40, "quarante" },
		{ 50, "cinquante" },
		{ 60, "soixante" },
		{ 80, "quatre-vingt" },
		{ 100, "cent" },
		{ 1000, "mille" },
		{ 1000000, "million" },
	};

const string INVALID_NUMBER = "Invalid Number!";

bool is_number(string so_called_number) {
	if (so_called_number.empty()) return false;
	for (int i = 0; i < so_called_number.length(); i++) {
		if (!isdigit(so_called_number[i])) {
			return false;
		}
	}
	return true;
}

string convertNumberToWords(string number) {
	string words = "";

	if (number[0] == '-') {
		words += "minus ";
		number.erase(0, 1);
	}

	if (!is_number(number)) {
		return INVALID_NUMBER;
	}
	int actual_number = stoi(number);

	switch (number.length()) {
		case 1:
		case 2:
			if (DICT[actual_number] != "") {
				words += DICT[actual_number];
			}
			else {
				switch (actual_number / 10) {
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 8:
					words += DICT[(actual_number / 10) * 10];
					if (number[1] == '1' && number[0] != '8') {
						words += " et un";
					}
					else if (actual_number == 80) {
						words += "s";
					}
					else {
						words += "-" + DICT[actual_number % 10];
					}
					break;
				case 7:
				case 9:
					words += DICT[(actual_number / 10 - 1) * 10];
					if (actual_number == 71) {
						words += " et ";
					}
					else {
						words += "-";
					}
					
					words += DICT[(actual_number % 10) + 10];
					break;
				default:
					words += "oops, unknown";
				}
			}
			break;
		case 3:
			break;
	}

	return words;
}

int main()
{
	char *locale;
	locale = setlocale(LC_ALL, "");
	int stop = 0;
	string sir;

	while (stop == 0) {
		cout << "\nIntrodu numarul sau cuvintele pe care le doresti convertite. 'stop' pentru iesire." << endl;
		cin >> sir;
		
		if (isdigit(sir[0]) || sir[0] == '-') {
			cout << convertNumberToWords(sir);
		} else if (sir == "stop") {
			stop = 1;
		} else {
			cout << "cuvinte";
		}

	}
	return 0;
}

