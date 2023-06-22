#include <iostream>
using namespace std;

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