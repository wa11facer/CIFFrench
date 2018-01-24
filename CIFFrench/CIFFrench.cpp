// CIFFrench.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <string>
#include <locale>

using namespace std;

map<int, string> DICT {
	{0, "z\u00E8ro"},
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
		{ 100, "cent" },
		{ 1000, "mille" },
		{ 1000000, "million" },
	};

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
			cout << "number";
		} else if (sir == "stop") {
			stop = 1;
		} else {
			cout << "cuvinte";
		}
	}
	return 0;
}

