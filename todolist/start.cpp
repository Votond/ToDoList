#include <iostream>
#include <vector>
#include <time.h>
#include <windows.h>
#include <string>
#include <fstream>

#include "ConsoleColors.h"
#include "completeTask.h"
#include "createTask.h"
#include "deleteTask.h"
#include "editTask.h"
#include "favoriteTask.h"
#include "loadTasks.h"
#include "saveTasks.h"
#include "Task.h"
#include "vec.h"
#include "taskForm.h"
#include "tasksToConsole.h"
using namespace std;

void start()
{
	string input;

	{
		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"new\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� �������� ����� ������" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"view\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ��������� ���� �����" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"c\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ��������� ����������� �����" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"unc\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ��������� ������������� �����" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"f\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ��������� ��������� �����" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"comp\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ���������� ������" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"elect\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ���������� ������ � ���������" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"unelect\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� �������� ������ �� ���������" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"del\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� �������� ������" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"edit\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� �������������� ������" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"save\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ���������� ����� � ����" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"load\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� �������� ����� �� �����" << endl;

		cout << "������� ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << "\"exit\"";
		SetConsoleTextAttribute(hand, White);
		cout << " ��� ������" << endl;
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
		cout << "������������ ����" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	start();
}