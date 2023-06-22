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

void saveTasks()
{
	ofstream file;

	file.open("tasks.txt");

	if (file.is_open())
	{
		for (int i = 0; i < tasks.size(); i++)
		{
			file << tasks[i].title << endl;
			file << tasks[i].date << endl;
			file << tasks[i].description << endl;

			if (tasks[i].completed == true)
			{
				file << "true" << endl;
			}
			else
			{
				file << "false" << endl;
			}

			if (tasks[i].favorite == true)
			{
				file << "true" << endl;
			}
			else
			{
				file << "false" << endl;
			}
		}

		SetConsoleTextAttribute(hand, LightGreen);
		cout << "Все задачи успешно сохранены" << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Произошла ошибка при записи в файл" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	file.close();
}