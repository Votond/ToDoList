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