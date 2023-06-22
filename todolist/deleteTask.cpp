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

void deleteTask()
{
	int id;

	SetConsoleTextAttribute(hand, White);
	cout << "������� ����� ������ ��� ��������: ";

	cin >> id;

	try
	{
		tasks.erase(tasks.begin() + id);
	}
	catch (const std::exception& ex)
	{
		SetConsoleTextAttribute(hand, Red);
		cout << "������ ��� �������� ������� �� ����������" << endl;
		SetConsoleTextAttribute(hand, White);
	}

	SetConsoleTextAttribute(hand, LightGreen);
	cout << "������ ��� ������� " << id << " �������" << endl;
	SetConsoleTextAttribute(hand, White);
}