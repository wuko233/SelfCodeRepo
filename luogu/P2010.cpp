#include <iostream>

using namespace std;

const int MONTH_DAY[12] = {31, -1, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isYearLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isRecallable(int date) {
    int reverseDate = 0;
    int tempDate = date;
    while (tempDate) {
        reverseDate = reverseDate * 10 + tempDate % 10;
        tempDate /= 10;
    }

    return reverseDate == date;
}

void calculateRecallableDate(int startDate, int endDate, int &cnt) {

    int startYear = startDate / 10000;
    int startMonth = startDate / 100 - startYear * 100;
    int startDay = startDate - startMonth * 100 - startYear * 10000;

    int endYear = endDate / 10000;
    int endMonth = endDate / 100 - endYear * 100;
    int endDay = endDate - endMonth * 100 - endYear * 10000;

    for (int year = startYear; year <= endYear; ++year) {
        for (int month = (year == startYear) ? startMonth : 1;month <= 12; ++month) {
            int daysInMonth = MONTH_DAY[month - 1];
            if (daysInMonth == -1) {
                daysInMonth = isYearLeap(year) ? 29 : 28;
            }
            for (int day = (year == startYear && month == startMonth) ? startDay : 1;
                    day <= daysInMonth; ++day) {
                if (year == endYear && month == endMonth && day == endDay) {
                    int date = year * 10000 + month * 100 + day;
                    if (isRecallable(date)) {
                        cnt++;
                    }
                    return;
                }

                int date = year * 10000 + month * 100 + day;
                if (isRecallable(date)) {
                    cnt++;
                }
            }
        }
    }
}


int main() {
    int startDate;
    cin >> startDate;

    int endDate;
    cin >> endDate;

    int cnt = 0;

    calculateRecallableDate(startDate, endDate, cnt);

    cout << cnt << endl;
}