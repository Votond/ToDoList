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
	// Объявление файлового потока file для записи
	ofstream file;

	// Открытие или создание файла для записи
	file.open("tasks.txt");

	// Проверка на открытие файла
	if (file.is_open())
	{
		// Внос всех полей всех объектов вектора с задачами
		for (int i = 0; i < tasks.size(); i++)
		{
			file << tasks[i].title << endl;
			file << tasks[i].date << endl;
			file << tasks[i].description << endl;

			// 2 конструкции для вноса в файл булевых полей
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

		// Информация об успешном сохранении задач в файл
		SetConsoleTextAttribute(hand, LightGreen);
		cout << "Все задачи успешно сохранены" << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else
	{
		// Информация об ошибке при сохранении задач в файл
		SetConsoleTextAttribute(hand, Red);
		cout << "Произошла ошибка при записи в файл" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	// Закрытие файла
	file.close();
}