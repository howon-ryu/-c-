#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int bd=0;

class Date
{
public:
	int year = 0;
	int month = 0;
	int day = 0;
	Date();
	Date(string date);
	void showtodayDate();
	void showBirthDay();
	void currentAge();
};

Date::Date()
{

}


Date::Date(string date)

{
	int index = date.find_first_of(",");
	string main_str = date.substr(0, index);
	cout << main_str << ',';
	date = date.substr(index + 1);

	index = date.find_first_of(",");
	main_str = date.substr(0, index);
	cout << main_str << ',';
	date = date.substr(index + 1);

	index = date.find_first_of(",");
	main_str = date.substr(0, index);
	cout << main_str << "��" << ' ';
	date = date.substr(index + 1);

	index = date.find_first_of("/");
	string sub_str = date.substr(index - 4, 4);
	year = atoi(sub_str.c_str());;
	bd = year;
	date = date.substr(index + 1);

	index = date.find_first_of("/");
	sub_str = date.substr(0, index);
	month = atoi(sub_str.c_str());
	date = date.substr(index + 1);

	index = date.find_first_of("/");
	sub_str = date.substr(0, index);
	day = atoi(sub_str.c_str());

}


void Date::showtodayDate()
{
	cout << year << "��" << month << "��" << day << "��";
}

void Date::showBirthDay()
{
	cout << year << "��" << month << "��" << day << "�ϻ�" << " ";
}

void Date::currentAge()
{
	cout << " ����" << " " << year - bd-1  << "���Դϴ�.";
}

int main()

{
	int i = 0;
	char input1[100];
	cout << "ȯ���մϴ�!�а���, �й�, �̸�, �������(yyyy / mm / dd)�� �Է��ϼ��� >";



	while (1)
	{
		input1[i] = getchar();
		if (input1[i++] == '\n')
		{
			break;
		}
	}




	Date birthday(input1);
	Date* pd;
	pd = new Date;
	time_t t = time(0);
	struct tm* now = localtime(&t);

	pd->year = (now->tm_year + 1900);
	pd->month = (now->tm_mon + 1);
	pd->day = (now->tm_mday);
	pd->showtodayDate();
	pd->currentAge();




	return 0;
}