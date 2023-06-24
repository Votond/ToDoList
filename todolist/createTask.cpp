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
	// Объявление объекта структуры SYSTEMTIME
	SYSTEMTIME st;

	// Получение и запись даты и времени в поле объекта
	GetLocalTime(&st);
	task.date = to_string(st.wDay) + "." + to_string(st.wMonth) + "." + to_string(st.wYear) + "   " + to_string(st.wHour) + ":" + to_string(st.wMinute);

	// Ввод названия и описания задачи
	cout << "Введите название задачи: ";
	cin.ignore();
	getline(cin, task.title);

	cout << "Введите описание задачи: ";
	getline(cin, task.description);

	// Добавление задачи в вектор
	tasks.push_back(task);

	// Информация о создании задачи
	SetConsoleTextAttribute(hand, LightGreen);
	cout << "Задача создана" << endl;
	SetConsoleTextAttribute(hand, White);
}