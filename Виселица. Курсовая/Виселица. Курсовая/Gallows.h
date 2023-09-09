#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <ctime>

using namespace std;

class Gallows {
	enum {light=1,hard=2};
	const char* worlduser = "Ответ.txt"; // путь где содержаться слова
	char user;
	int stop, size;
	char arr[25];
	char arr1[25];
public:
	void Print(); 
	char Help(char world[]);
	void Interface(char world[],char str[]);
	char NoHelp(char world[]);

};

