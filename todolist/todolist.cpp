#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <string>
#include <fstream>
#include "ConsoleColors.h"
using namespace std;
HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

// ToDo List
//
// Task: - done
// - Title
// - Date of complete
// - Description
// - Complete mark
//
// Create task - done
// Edit name, desc, complete status
// Delete task
// Save to file
// Load from file
// Loop

void start();

// done
class Task {
public:
	string title;
	string date;
	string description;
	bool completed = false;

	Task(string title, string date, string description)
	{
		this->title = title;
		this->date = date;
		this->description = description;
	}

	Task() = default;
};

vector<Task> tasks;

// done
void taskForm(Task task, int id)
{
	string temp = task.title;
	int size = temp.size() + 24;

	SetConsoleTextAttribute(hand, White);
	cout << "----------- ";
	SetConsoleTextAttribute(hand, Yellow);
	cout << task.title;
	SetConsoleTextAttribute(hand, White);
	cout << " -----------" << endl;

	cout << "Дата: ";
	SetConsoleTextAttribute(hand, LightPurple);
	cout << task.date << endl;

	SetConsoleTextAttribute(hand, White);
	cout << "Номер: ";
	SetConsoleTextAttribute(hand, Gray);
	cout << id << endl;

	SetConsoleTextAttribute(hand, White);
	cout << "Описание: ";
	SetConsoleTextAttribute(hand, Cyan);
	cout << task.description << endl;

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

	SetConsoleTextAttribute(hand, White);
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << endl;
}

// done
void tasksToConsole()
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
			taskForm(tasks[i], i);
		}
	}
}

// done
void createTask() {
	string title;
	string description;
	string date;
	Task task;
	SYSTEMTIME st;
	

	GetLocalTime(&st);
	task.date = to_string(st.wDay) + "." + to_string(st.wMonth) + "." + to_string(st.wYear) + "   " + to_string(st.wHour) + ":" + to_string(st.wMinute);

	cout << "Введите название задачи: ";
	cin.ignore();
	getline(cin, task.title);

	cout << "Введите описание задачи: ";
	getline(cin, task.description);

	tasks.push_back(task);

	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача создана" << endl;
	SetConsoleTextAttribute(hand, White);
}

// done
void deleteTask()
{
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи для удаления: ";

	cin >> id;

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
	
	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " удалена" << endl;
	SetConsoleTextAttribute(hand, White);
}

// done
void completeTask()
{
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы выполнили: ";
	cin >> id;

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

	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача под номером " << id << " отмечена, как выполненная" << endl;
	SetConsoleTextAttribute(hand, White);
}

void saveTasks()
{

}

void loadTasks()
{

}

// done
void editTask()
{
	string input;
	string title;
	string description;
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы хотите изменить: ";
	cin >> id;

	cout << "Введите \"title\" для изменения названия\nВведите \"desc\" для изменения описания" << endl;
	cin >> input;

	if (input == "title")
	{
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

		SetConsoleTextAttribute(hand, White);
		cout << "Введите новое название задачи: " << endl;
		cin.ignore();
		getline(cin, tasks[id].title);

		cout << "Новое название задачи: ";
		SetConsoleTextAttribute(hand, Yellow);
		cout << tasks[id].title << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else if (input == "desc")
	{
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

		SetConsoleTextAttribute(hand, White);
		cout << "Введите новое описание задачи: " << endl;
		cin.ignore();
		getline(cin, tasks[id].description);

		cout << "Новое описание задачи: ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << tasks[id].description << endl;
		SetConsoleTextAttribute(hand, White);
	}
}

void start() {
	string input;
	
	{
		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"new\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для создания новой задачи" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"view\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для просмотра задач" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"comp\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для выполнения задачи" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"del\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для удаления задачи" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"edit\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для редактирования задачи" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"save\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для сохранения задач в файл" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"load\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для загрузки задач из файла" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"exit\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для выхода" << endl;
	}

	cin >> input;

	if (input == "new")
	{
		createTask();
	}
	else if (input == "view")
	{
		tasksToConsole();
	}
	else if (input == "comp")
	{
		completeTask();
	}
	else if (input == "del")
	{
		deleteTask();
	}
	else if (input == "edit")
	{
		editTask();
	}
	else if (input == "save")
	{
		saveTasks();
	}
	else if (input == "load")
	{
		loadTasks();
	}
	else if (input == "exit")
	{
		return;
	}
	else
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "Некорректный ввод" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	start();
}

// done
int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SetConsoleTextAttribute(hand, White);
	cout << "-----===";
	SetConsoleTextAttribute(hand, Cyan);
	cout << " ToDo List ";
	SetConsoleTextAttribute(hand, White);
	cout << "===-----" << endl;

	start();

	return 0;
}
