#include <iostream>
using namespace std;

// Объявление класса Task
class Task {
public:
	// Объялвение полей класса
	string title;
	string date;
	string description;
	// Объявление и инициализация полей класса
	bool completed = false;
	bool favorite = false;

	// Конструктор класса
	Task(string title, string date, string description)
	{
		this->title = title;
		this->date = date;
		this->description = description;
	}

	// Конструктор по умолчанию
	Task() = default;
};