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
