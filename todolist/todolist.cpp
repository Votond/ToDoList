#include <iostream>
#include <vector>
#include <windows.h>

#include "ConsoleColors.h"
#include "start.h"
#include "Task.h"
using namespace std;
HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);
vector<Task> tasks;

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SetConsoleTextAttribute(hand, White);
	cout << "-----===";
	SetConsoleTextAttribute(hand, Cyan);
	cout << " ToDo List ";
	SetConsoleTextAttribute(hand, White);
	cout << "===-----" << endl;

	start();

	return 0;
}
