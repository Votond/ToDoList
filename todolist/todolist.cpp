#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
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
// Edit title, desc, complete status - done
// Delete task - done
// Save to file - done
// Load from file - done
// Favorites - done
// Loop - done
// Multifiles

void start();

// done
class Task {
public:
	string title;
	string date;
	string description;
	bool completed = false;
	bool favorite = false;

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
void tasksToConsole(string type)
{
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
	cout << "Задача под номером " << id << " отмечена как выполненная" << endl;
	SetConsoleTextAttribute(hand, White);
}

// done
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

// done
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

// done
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

// done
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

// done
void start()
{
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
		cout << " для просмотра всех задач" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"c\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для просмотра завершенных задач" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"unc\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для просмотра незавершенных задач" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"f\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для просмотра избранных задач" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"comp\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для выполнения задачи" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"elect\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для добавление задачи в избранное" << endl;

		cout << "Введите ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"unelect\"";
		SetConsoleTextAttribute(hand, White);
		cout << " для удаления задачи из избранных" << endl;

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
	else if (input == "unc")
	{
		tasksToConsole("uncomp");
	}
	else if (input == "c")
	{
		tasksToConsole("comp");
	}
	else if (input == "f")
	{
		tasksToConsole("fav");
	}
	else if (input == "comp")
	{
		completeTask();
	}
	else if (input == "elect")
	{
		favoriteTask();
	}
	else if (input == "unelect")
	{
		favoriteTask("unelect");
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
