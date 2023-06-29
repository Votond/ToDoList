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
	// Добавление поддержки русского языка
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Вывод заголовка "ToDo List"
	SetConsoleTextAttribute(hand, White);
	cout << "------------------===";
	SetConsoleTextAttribute(hand, Cyan);
	cout << " ToDo List ";
	SetConsoleTextAttribute(hand, White);
	cout << "===------------------" << endl;
	
	// Старт приложения
	start();

	return 0;
}
