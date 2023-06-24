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

	// Ввод номера задачи
	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы выполнили: ";
	cin >> id;

	// Изменение отметки о выполненности задачи
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

	// Если задача отмечена, то выводится информация об этом
	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " отмечена как выполненная" << endl;
	SetConsoleTextAttribute(hand, White);
}