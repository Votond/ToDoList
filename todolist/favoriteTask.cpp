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

void favoriteTask()
{
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы хотите сделать избранной: ";
	cin >> id;

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

	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " отмечена как избранная" << endl;
	SetConsoleTextAttribute(hand, White);
}

void favoriteTask(string action)
{
	int id;

	if (action == "unelect")
	{
		SetConsoleTextAttribute(hand, White);
		cout << "Введите номер задачи, которую вы хотите убрать из избранных: ";
		cin >> id;

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

		SetConsoleTextAttribute(hand, LightGreen);
		cout << "Задача под номером " << id << " убрана из избранных" << endl;
		SetConsoleTextAttribute(hand, White);
	}
}