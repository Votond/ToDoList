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

void editTask()
{
	string input;
	string title;
	string description;
	int id;

	// Ввод номера задачи для изменения
	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы хотите изменить: ";
	cin >> id;

	// Пользователю даётся выбор между изменением названия и описания
	cout << "Введите \"title\" для изменения названия\nВведите \"desc\" для изменения описания" << endl;
	cin >> input;

	// На основе выбора пользователя выполняется условие
	if (input == "title")
	{
		// Вывод текущего названия задачи
		cout << "Текущее название задачи: ";
		SetConsoleTextAttribute(hand, Yellow);

		try
		{
			cout << tasks[id].title << endl;
		}
		catch (const std::exception& ex)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "Задачи под введённым номером не существует" << endl;
			SetConsoleTextAttribute(hand, White);
		}

		// Ввод пользователем нового названия задачи
		SetConsoleTextAttribute(hand, White);
		cout << "Введите новое название задачи: " << endl;
		cin.ignore();
		getline(cin, tasks[id].title);

		// Вывод нового названия задачи
		cout << "Новое название задачи: ";
		SetConsoleTextAttribute(hand, Yellow);
		cout << tasks[id].title << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else if (input == "desc")
	{
		// Вывод текущего описания задачи
		cout << "Текущее описание задачи: ";
		SetConsoleTextAttribute(hand, Cyan);

		try
		{
			cout << tasks[id].description << endl;
		}
		catch (const std::exception& ex)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "Задачи под введённым номером не существует" << endl;
			SetConsoleTextAttribute(hand, White);
		}

		// Ввод пользователем нового описания задачи
		SetConsoleTextAttribute(hand, White);
		cout << "Введите новое описание задачи: " << endl;
		cin.ignore();
		getline(cin, tasks[id].description);

		// Вывод нового описания задачи
		cout << "Новое описание задачи: ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << tasks[id].description << endl;
		SetConsoleTextAttribute(hand, White);
	}
}