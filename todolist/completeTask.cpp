#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <string>
#include <fstream>

#include "ConsoleColors.h"
#include "Task.h"
#include "vec.h"
using namespace std;

void completeTask()
{
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы выполнили: ";
	cin >> id;

	try
	{
		tasks[id].completed = true;
	}
	catch (const std::exception& ex)
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Задачи под введённым номером не существует" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " отмечена как выполненная" << endl;
	SetConsoleTextAttribute(hand, White);
}