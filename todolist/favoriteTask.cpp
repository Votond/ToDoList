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

// Функция для добавления задачи в избранное
void favoriteTask()
{
	int id;

	// Ввод пользователем номера задачи для добавления в избранные
	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы хотите сделать избранной: ";
	cin >> id;

	// Изменение отметки о избранности задачи
	try
	{
		tasks[id].favorite = true;
	}
	catch (const std::exception& ex)
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Задачи под введённым номером не существует" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	// Информация о изменении избранности задачи
	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " отмечена как избранная" << endl;
	SetConsoleTextAttribute(hand, White);
}

// Функция для удаления задачи из избранных
void favoriteTask(string action)
{
	int id;

	// Проверка поступивший в функцию строки на корректность
	if (action == "unelect")
	{
		// Ввод номера задачи для удаления из избранных
		SetConsoleTextAttribute(hand, White);
		cout << "Введите номер задачи, которую вы хотите убрать из избранных: ";
		cin >> id;

		// Удаление задачи из избранных
		try
		{
			tasks[id].favorite = false;
		}
		catch (const std::exception& ex)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "Задачи под введённым номером не существует" << endl;
			SetConsoleTextAttribute(hand, White);
		}

		// Информация о изменении избранности задачи
		SetConsoleTextAttribute(hand, LightGreen);
		cout << "Задача под номером " << id << " убрана из избранных" << endl;
		SetConsoleTextAttribute(hand, White);
	}
}