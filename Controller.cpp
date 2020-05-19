#include "Controller.h"
#include "RepositoryMovie.h"
#include "Movie.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>

Controller::Controller() {}

int Controller::Validate_int()
{
	//functie de verificare int

	int num;

	while (!(cin >> num))
	{
		cout << "Error, enter a number:";
		cin.clear();
		cin.ignore(123, '\n');
	}

	return num;
}


int Controller::Validate_Year()
{
	//functie de verificare an
	
	int num = 0;

	while (!(cin >> num && num >= 1878 && num <= 2020))
	{
		cout << "Error, enter a number between 1878 and 2020:";
		cin.clear();
		cin.ignore(123, '\n');
	}

	return num;
}


