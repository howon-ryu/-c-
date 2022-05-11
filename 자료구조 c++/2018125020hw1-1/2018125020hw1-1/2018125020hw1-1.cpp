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
	cout << main_str << "님" << ' ';
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
	cout << year << "년" << month << "월" << day << "일";
}

void Date::showBirthDay()
{
	cout << year << "년" << month << "월" << day << "일생" << " ";
}

void Date::currentAge()
{
	cout << " 현재" << " " << year - bd-1  << "세입니다.";
}

int main()

{
	int i = 0;
	char input1[100];
	cout << "환영합니다!학과명, 학번, 이름, 생년월일(yyyy / mm / dd)을 입력하세요 >";



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