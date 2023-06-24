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

void taskForm(Task task, int id)
{
	// Объявление и инициализация переменных для вывода равных по символам границ формы задачи
	string temp = task.title;
	int size = temp.size() + 24;

	// Вывод названия
	SetConsoleTextAttribute(hand, White);
	cout << "----------- ";
	SetConsoleTextAttribute(hand, Yellow);
	cout << task.title;
	SetConsoleTextAttribute(hand, White);
	cout << " -----------" << endl;

	// Вывод даты содания
	cout << "Дата: ";
	SetConsoleTextAttribute(hand, LightPurple);
	cout << task.date << endl;

	// Вывод номера
	SetConsoleTextAttribute(hand, White);
	cout << "Номер: ";
	SetConsoleTextAttribute(hand, Gray);
	cout << id << endl;

	// Вывод описания
	SetConsoleTextAttribute(hand, White);
	cout << "Описание: ";
	SetConsoleTextAttribute(hand, Cyan);
	cout << task.description << endl;

	// Вывод состояния задачи
	switch (task.completed)
	{
	case true:
		SetConsoleTextAttribute(hand, LightGreen);
		cout << "Задача выполнена" << endl;
		break;

	case false:
		SetConsoleTextAttribute(hand, Red);
		cout << "Задача не выполнена" << endl;
		break;
	}

	// Вывод информации об избранности задачи
	switch (task.favorite)
	{
	case true:
		SetConsoleTextAttribute(hand, Yellow);
		cout << "Задача в избранном" << endl;
		break;

	case false:
		SetConsoleTextAttribute(hand, Gray);
		cout << "Задача не в избранном" << endl;
		break;
	}

	// Вывод нижней границы формы задачи
	SetConsoleTextAttribute(hand, White);
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << endl;
}