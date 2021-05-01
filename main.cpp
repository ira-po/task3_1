#include <iostream>
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

int newYear() {
    // add validation if year1 < year2
    int day, month, year1, year2;
    day = 01;
    month = 01;
    char c;
    string d[7] = { "Недiля", "Понедiлок", "Вiвторок", "Середа", "Четвер", "П'ятниця", "Субота" };
    cout << "Введiть початковий рiк: ";
    cin >> year1;
    cout << "Введiть кiнцевий рiк: ";
    cin >> year2;
    for (int i = year1; i < year2; i++) {
        cout << d[Date1(day, month, i + 1)] << endl;
    }

    system("pause");
    return 0;
}

int dayOfWeek() {
    int day, month, year;
    char k;
    string l[7] = { "Неділя", "Понеділок", "Вівторок", "Середа", "Четвер", "П'ятниця", "Субота" };
    cout << "Введіть дату вашого народження (через пробіл):";
    cin >> day >> k >> month >> k >> year;
    cout << l[Date2(day, month, year)] << endl;

    system("pause");
    return 0;
}

int dayOfWeekFrom() {
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

int checkLeapYearsBetween(int y1, int y2) {
    int leap = y1;
    int count = 0;
    while (leap < y2) {
        if (leap % 4 == 0 && leap % 100 != 0 || leap % 400 == 0) {
            count++;
        }

        leap++;
    }
    return count;
}

// problem somewhere here
int calculateDaysFor(int m1, int months_count) {
    int months [12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int days = 0;
    cout << m1 << endl;
    cout << months_count << endl;
    for (int i = m1-1; i <= (months_count); i++) {
        int k = i;
        if (i > 11) {
            k = 0;
        }
        days = days + months[k];
    }
    cout << days << endl;

    return days;
}

int daysBetweenDates() {
    int d1, m1, y1, d2, m2, y2, k, leap_years_count, y_diff_in_months, m_diff_in_days;
    int output = 0;

    cout << "Введiть початкову дату (через пробiл) : ";
    cin >> d1 >> m1 >> y1;
    cout << "Введiть кiнцеву дату (через пробiл) : ";
    cin >> d2 >> m2 >> y2;

    // validate date1 < date2 !!!

    // debug section
    // cout << d1 << endl;
    // cout << m1 << endl;
    // cout << y1 << endl;
    // cout << d2 << endl;
    // cout << m2 << endl;
    // cout << y2 << endl;

    leap_years_count = checkLeapYearsBetween(y1, y2);

    int y_diff = y2 - y1;
    y_diff_in_months = y_diff * 12;

    int m_diff = (m2 - m1) + y_diff_in_months;
    m_diff_in_days = calculateDaysFor(m1, m_diff);

    int d_diff = d2 - d1;
    output = d_diff + leap_years_count + m_diff_in_days;

    cout << "Кiлькiсть днiв якi пройшли вiд дати1 до дати2: " << output << endl;
    return 0;
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
		if (t == 1){
			return daysBetweenDates();
		} else if (t == 2) {
			return newYear();
		} else if (t == 3) {
			cout  << "Немає програми" << endl;
		} else if (t == 4) {
			return dayOfWeek();
		} else if (t == 5) {
    		return dayOfWeekFrom();
		} else if (t == 6) {
		  cout << "Немає програми" << endl;
		} else if (t == 7) {
			break;
		}

		cin >> t;
	}
}

