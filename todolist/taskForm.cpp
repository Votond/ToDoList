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

void taskForm(Task task, int id)
{
	// ���������� � ������������� ���������� ��� ������ ������ �� �������� ������ ����� ������
	string temp = task.title;
	int size = temp.size() + 24;

	// ����� ��������
	SetConsoleTextAttribute(hand, White);
	cout << "----------- ";
	SetConsoleTextAttribute(hand, Yellow);
	cout << task.title;
	SetConsoleTextAttribute(hand, White);
	cout << " -----------" << endl;

	// ����� ���� �������
	cout << "����: ";
	SetConsoleTextAttribute(hand, LightPurple);
	cout << task.date << endl;

	// ����� ������
	SetConsoleTextAttribute(hand, White);
	cout << "�����: ";
	SetConsoleTextAttribute(hand, Gray);
	cout << id << endl;

	// ����� ��������
	SetConsoleTextAttribute(hand, White);
	cout << "��������: ";
	SetConsoleTextAttribute(hand, Cyan);
	cout << task.description << endl;

	// ����� ��������� ������
	switch (task.completed)
	{
	case true:
		SetConsoleTextAttribute(hand, LightGreen);
		cout << "������ ���������" << endl;
		break;

	case false:
		SetConsoleTextAttribute(hand, Red);
		cout << "������ �� ���������" << endl;
		break;
	}

	// ����� ���������� �� ����������� ������
	switch (task.favorite)
	{
	case true:
		SetConsoleTextAttribute(hand, Yellow);
		cout << "������ � ���������" << endl;
		break;

	case false:
		SetConsoleTextAttribute(hand, Gray);
		cout << "������ �� � ���������" << endl;
		break;
	}

	// ����� ������ ������� ����� ������
	SetConsoleTextAttribute(hand, White);
	for (int i = 0; i < size; i++)
	{
		cout << "-";
	}
	cout << endl;
}