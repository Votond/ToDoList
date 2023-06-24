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

void editTask()
{
	string input;
	string title;
	string description;
	int id;

	// ���� ������ ������ ��� ���������
	SetConsoleTextAttribute(hand, White);
	cout << "������� ����� ������, ������� �� ������ ��������: ";
	cin >> id;

	// ������������ ����� ����� ����� ���������� �������� � ��������
	cout << "������� \"title\" ��� ��������� ��������\n������� \"desc\" ��� ��������� ��������" << endl;
	cin >> input;

	// �� ������ ������ ������������ ����������� �������
	if (input == "title")
	{
		// ����� �������� �������� ������
		cout << "������� �������� ������: ";
		SetConsoleTextAttribute(hand, Yellow);

		try
		{
			cout << tasks[id].title << endl;
		}
		catch (const std::exception& ex)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "������ ��� �������� ������� �� ����������" << endl;
			SetConsoleTextAttribute(hand, White);
		}

		// ���� ������������� ������ �������� ������
		SetConsoleTextAttribute(hand, White);
		cout << "������� ����� �������� ������: " << endl;
		cin.ignore();
		getline(cin, tasks[id].title);

		// ����� ������ �������� ������
		cout << "����� �������� ������: ";
		SetConsoleTextAttribute(hand, Yellow);
		cout << tasks[id].title << endl;
		SetConsoleTextAttribute(hand, White);
	}
	else if (input == "desc")
	{
		// ����� �������� �������� ������
		cout << "������� �������� ������: ";
		SetConsoleTextAttribute(hand, Cyan);

		try
		{
			cout << tasks[id].description << endl;
		}
		catch (const std::exception& ex)
		{
			SetConsoleTextAttribute(hand, Red);
			cout << "������ ��� �������� ������� �� ����������" << endl;
			SetConsoleTextAttribute(hand, White);
		}

		// ���� ������������� ������ �������� ������
		SetConsoleTextAttribute(hand, White);
		cout << "������� ����� �������� ������: " << endl;
		cin.ignore();
		getline(cin, tasks[id].description);

		// ����� ������ �������� ������
		cout << "����� �������� ������: ";
		SetConsoleTextAttribute(hand, Cyan);
		cout << tasks[id].description << endl;
		SetConsoleTextAttribute(hand, White);
	}
}