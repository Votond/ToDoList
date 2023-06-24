#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <string>
#include <fstream>

#include "ConsoleColors.h"
#include "Task.h"
#include "vec.h"
#include "taskForm.h"
using namespace std;

// Функция для вывода всех задач
void tasksToConsole()
{
	// Вывод всех задач
	if (tasks.size() == 0)
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Задачи отсутствуют" << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else
	{
		for (int i = 0; i < tasks.size(); i++)
		{
			taskForm(tasks[i], i);
		}
	}
}

// Переопределение функции для вывода определенных задач
void tasksToConsole(string type)
{
	// Вывод только выполенных задач
	if (type == "comp")
	{
		if (tasks.size() == 0)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "Задачи отсутствуют" << endl;
			SetConsoleTextAttribute(hand, White);
		}
		else
		{
			for (int i = 0; i < tasks.size(); i++)
			{
				if (tasks[i].completed == true)
				{
					taskForm(tasks[i], i);
				}
			}
		}
	}
	// Вывод только невыполненных задач
	else if (type == "uncomp")
	{
		if (tasks.size() == 0)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "Задачи отсутствуют" << endl;
			SetConsoleTextAttribute(hand, White);
		}
		else
		{
			for (int i = 0; i < tasks.size(); i++)
			{
				if (tasks[i].completed == false)
				{
					taskForm(tasks[i], i);
				}

			}
		}
	}
	// Вывод только избранных задач
	else if (type == "fav")
	{
		if (tasks.size() == 0)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "Задачи отсутствуют" << endl;
			SetConsoleTextAttribute(hand, White);
		}
		else
		{
			for (int i = 0; i < tasks.size(); i++)
			{
				if (tasks[i].favorite == true)
				{
					taskForm(tasks[i], i);
				}

			}
		}
	}
}