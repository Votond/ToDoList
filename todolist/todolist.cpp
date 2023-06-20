#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <algorithm>
#include <conio.h>
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include "ConsoleColors.h"
using namespace std;
HANDLE hand = GetStdHandle(STD_OUTPUT_HANDLE);

vector<Task> tasks;

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
		cout << "Задача выполнена";
		break;

	case false:
		SetConsoleTextAttribute(hand, Red);
		cout << "Задача не выполнена";
		break;

	default:
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
void toConsole()
{
	for (int i = 0; i < tasks.size(); i++)
	{
		taskForm(tasks[i], i);
	}
}

//done
void createTask() {
	string title;
	string date;
	string description;
	Task task;

	auto now = chrono::system_clock::now();
	time_t end_time = chrono::system_clock::to_time_t(now);
	task.date = ctime(&end_time);

	cout << "Введите название задачи: ";
	cin >> task.title;

	cout << "Введите описание задачи: ";
	cin >> task.description;

	tasks.push_back(task);
}

void deleteTask()
{
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи для удаления: ";
	cin >> id;

	tasks.erase(tasks.begin() + id);

	cout << "Задача под номером " << id << " удалена";
}

void completeTask()
{
	Task temp;
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "Введите номер задачи, которую вы выполнили: ";
	cin >> id;

	try
	{

	}
	catch (const std::exception&)
	{

	}

	tasks[id].completed = true;

	cout << "Задача под номером " << id << " отмечена, как выполненная";

	//temp = tasks[id];
	//temp.completed = true;
	//tasks[id] = temp;
}

void start() {
	string input;

	cout << "-----=== ToDo List ===-----" << endl;
here:
	cout << "Введите \"create\" для создания задачи\nВведите \"view\" для просмотра задач\nВведите \"complete\" для выполнения задачи\nВведите \"delete\" для удаления задачи\nВведите \"save\" для сохранения задач в файл\nВведите \"load\" для загрузки задач из файла" << endl;

	cin >> input;

	if (input == "create")
	{
		createTask();
	}
	else if (input == "view")
	{
		toConsole();
	}
	else if (input == "complete")
	{
		completeTask();
	}
	else if (input == "delete")
	{
		deleteTask();
	}
	else if (input == "save")
	{
		
	}
	else if (input == "load")
	{
		
	}
	else if (input == "view")
	{
		toConsole();
	}
	else
	{
		cout << "Некорректный ввод" << endl;
		goto here;
	}

}

int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	return 0;
}
