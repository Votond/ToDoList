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

void loadTasks()
{
	ifstream file;
	string line;
	Task task;
	vector<string> lines;
	int counter = 0;

	file.open("tasks.txt");

	if (file.is_open())
	{
		while (getline(file, line))
		{
			lines.push_back(line);
		}

		SetConsoleTextAttribute(hand, LightGreen);
		cout << "Все задачи успешно загружены" << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Произошла ошибка при чтении файла" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	for (int i = 0; i < lines.size() / 5; i++)
	{
		task.title = lines[counter];
		task.date = lines[counter + 1];
		task.description = lines[counter + 2];

		if (lines[counter + 3] == "true")
		{
			task.completed = true;
		}
		else if (lines[counter + 3] == "false")
		{
			task.completed = false;
		}

		if (lines[counter + 4] == "true")
		{
			task.favorite = true;
		}
		else if (lines[counter + 4] == "false")
		{
			task.favorite = false;
		}

		counter += 5;

		tasks.push_back(task);
	}

	file.close();
}