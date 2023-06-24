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

void deleteTask()
{
	int id;

	// Ввод номера задачи для удаления
	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи для удаления: ";

	cin >> id;

	// Удаление задачи
	try
	{
		tasks.erase(tasks.begin() + id);
	}
	catch (const std::exception& ex)
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Задачи под введённым номером не существует" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	// Информация о удалении задачи
	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " удалена" << endl;
	SetConsoleTextAttribute(hand, White);
}