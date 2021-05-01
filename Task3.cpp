﻿#include <iostream>
#include <math.h>
#include <string>
using namespace std;


int Date1(int day, int month, int year)
{
	int a, y, m, l;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	l = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
	return l % 7;
}

int Date2(int day, int month, int year)
{
	int a, y, m, r;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	r = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
	return r % 7;
}


long JDay(int year, int month, int day)
{
	if (month <= 2)
	{
		year--;
		month += 12;
	};
	unsigned long J;
	int A = year / 100;
	A = 2 - A + (A / 4);
	J = 1461L * long(year);
	J /= 4L;
	unsigned long K = 306001L * long(month + 1);
	K /= 10000L;
	J += K + day + 1720995L + A;
	return J;
}

void GDate(long JD, int& y, int& m, int& d)
{
	unsigned long A = (JD * 4L - 7468865L) / 146097L;
	A = (JD > 2299160) ? JD + 1 + A - (A / 4L) : JD;
	long B = A + 1524;
	long N = (B * 20L - 2442L) / 7305L;
	long D = (N * 1461L) / 4L;
	long E = (10000L * (B - D)) / 306001L;
	d = int(B - D - ((E * 306001L) / 10000L));
	m = int((E <= 13) ? E - 1 : E - 13);
	y = int(N - ((m > 2) ? 4716 : 4715));
}

int main()
{
	setlocale(LC_ALL, "ukr");
	cout << "Для того щоб знайти скiльки днiв пройшло вiд першої дати натиснiть 1" << endl;
	cout << "Знайти на якi днi тижня припаде новий рiк на промiжку вiд year1 до year2 натиснiть 2" << endl;
	cout << "Знайти скiльки п'ятниць 13 було(буде) в заданому роцi year2 натиснiть 3" << endl;
	cout << "Знайти в який день тижня ви народилися натиснiть 4" << endl;
	cout << "Визначити який день тижня та яка дата була k днiв тому вiд дати 2, натиснiть 5" << endl;
	cout << "Знайти першу п'ятницю 13 яка буде пiсля заданої дати 2, назвiть 6" << endl;
	cout << "Завершити програму - 7" << endl;
	int t = 0;
	cin >> t;
	while (t != 7)
	{
		if (t == 1)
		{
			int a, b, c, d, e, f, x, y = 0;
			int leap, k;
			int month1 = 31,
				month2 = 28,
				month3 = 31,
				month4 = 30,
				month5 = 31,
				month6 = 30,
				month7 = 31,
				month8 = 31,
				month9 = 30,
				month10 = 31,
				month11 = 30,
				month12 = 31;

			cout << "Введiть початкову дату (через пробiл) : ";
			cin >> a >> b >> c;
			cout << "Введiть кiнцеву дату (через пробiл) : ";
			cin >> d >> e >> f;


			leap = c;
			k = 0;
			while (leap <= f)
			{

				if (leap % 4 == 0 && leap % 100 != 0 || leap % 400 == 0)
				{
					k = k + 1;
				}

				leap++;

			}


			if (b == 1) { x = a; }
			else if (b == 2) { x = month1 + a; }
			else if (b == 3) { x = month1 + month2 + a; }
			else if (b == 4) { x = month1 + month2 + month3 + a; }
			else if (b == 5) { x = month1 + month2 + month3 + month4 + a; }
			else if (b == 6) { x = month1 + month2 + month3 + month4 + month5 + a; }
			else if (b == 7) { x = month1 + month2 + month3 + month4 + month5 + month6 + a; }
			else if (b == 8) { x = month1 + month2 + month3 + month4 + month5 + month6 + month7 + a; }
			else if (b == 9) { x = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + a; }
			else if (b == 10) { x = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + month9 + a; }
			else if (b == 11) { x = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + month9 + month10 + a; }
			else if (b == 12) { x = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + month9 + month10 + month11 + a; }

			if (e == 1) { y = d; }
			else if (e == 2) { y = month1 + d; }
			else if (e == 3) { y = month1 + month2 + d; }
			else if (e == 4) { y = month1 + month2 + month3 + d; }
			else if (e == 5) { y = month1 + month2 + month3 + month4 + d; }
			else if (e == 6) { y = month1 + month2 + month3 + month4 + month5 + d; }
			else if (e == 7) { y = month1 + month2 + month3 + month4 + month5 + month6 + d; }
			else if (e == 8) { y = month1 + month2 + month3 + month4 + month5 + month6 + month7 + d; }
			else if (e == 9) { y = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + d; }
			else if (e == 10) { y = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + month9 + d; }
			else if (e == 11) { y = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + month9 + month10 + d; }
			else if (e == 12) { y = month1 + month2 + month3 + month4 + month5 + month6 + month7 + month8 + month9 + month10 + month11 + d; }
			if ((c % 4 == 0 && leap % 100 != 0 || leap % 400 == 0) && b > 2) { k = k - 1; }
			if ((f % 4 == 0 && leap % 100 != 0 || leap % 400 == 0) && d <= 29 && e < 3) { k = k - 1; }

			if (c == f)
			{
				cout << "Кiлькiсть днiв якi пройшли вiд дати1 до дати2: " << (y - x) + k << endl;
			}
			else
				cout << "Кiлькiсть днiв якi пройшли вiд дати1 до дати2:" << (f - c) * 365 + ((y - x) + k) << endl;
			cout << k;
			return 0;
		}
		else if (t == 2)
		{
			int day, month, year1, year2;
			day = 01;
			month = 01;
			char c;
			string d[7] = { "Недiля", "Понедiлок", "Вiвторок", "Середа", "Четвер", "П'ятниця", "Субота" };
			cout << "Введiть початковий рiк: ";
			cin >> year1;
			cout << "Введiть кiнцевий рiк: ";
			cin >> year2;
			for (int i = year1; i < year2; i++)
			{
				cout << d[Date1(day, month, i + 1)] << endl;
			}

			system("pause");
			return 0;
		}
		else if (t == 3)
		{
			cout  << "Немає програми" << endl;
		}
		else if (t == 4)
		{
			int day, month, year;
			char k;
			string l[7] = { "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота" };
			cout << "Введіть дату вашого народження (через пробіл):";
			cin >> day >> k >> month >> k >> year;
			cout << l[Date2(day, month, year)] << endl;

			system("pause");
			return 0;
		}
		else if (t == 5)
		{
		char C;
		int day, month, year;
		cout << "Введіть дату(через пробіл): ";
		cin >> day >> C >> month >> C >> year;
		cout << "Ваша дата: " << day << "." << month << "." << year << endl;
		long jd = JDay(year, month, day);
		int m;
		cout << "На скільки днів Ви хочете повернутись назад?" << endl;
		cin >> m;

		if (m > 0)
		{
			cout << "Дата через " << m << " днів: ";
			GDate(jd - m - 2, year, month, day);
			cout << day << "." << month << "." << year << endl;
			string S[7] = { "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота" };
			cout << S[Date2(day, month, year)] << endl;
		}

		system("pause");

		return 0;
		}
		else if (t == 6)
		{
		cout << "Немає програми" << endl;
		}
		else if (t == 7)
		{
			break;
		}
		cin >> t;
	}
}
[Переслано від Настя]
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int Date(int day, int month, int year)
{
	int a, y, m, R;
	a = (14 - month) / 12;
	y = year - a;
	m = month + 12 * a - 2;
	R = 7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
	return R % 7;
}

int main()
{
	int intyear, count = 0;
	char C;
	string S[7] = { "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота" };
	//cout << S[5];
	cout << "Введіть рік:";
	cin >> intyear;

	if (S[5] == S[Date(13, 01, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 02, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 03, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 04, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 05, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 06, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 07, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 8, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 9, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 10, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 11, intyear)])
	{
		count++;
	}
	if (S[5] == S[Date(13, 12, intyear)])
	{
		count++;
	}


	cout << "Кількість пятниць 13-те у " << intyear << " році: " << count;

	return 0;
}