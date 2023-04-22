/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此為副程式compareDay()，用來判斷年月相同但日是否差一天

*/

#include <sstream>
#include <string>
using namespace std;

bool compareDay(const string &time, const string &time_next) {
    string date1, date2;
    string year1, month1, day1, year2, month2, day2;
    int yr1, m1, d1, yr2, m2, d2;
    istringstream ss1(time);
    istringstream ss2(time_next);
    // 將字串分割成日期和時間兩部份，並將日期存於date1, date2中
    getline(ss1, date1, ' ');
    getline(ss2, date2, ' ');
    // 將字串變數date1, date2中的字串繼續分割
    istringstream ss3(date1);
    istringstream ss4(date2);
    getline(ss3, year1, '-');
    getline(ss3, month1, '-');
    getline(ss3, day1, '-');
    getline(ss4, year2, '-');
    getline(ss4, month2, '-');
    getline(ss4, day2, '-');
    // 將字串變數轉換為整數變數
    yr1 = stoi(year1);
    yr2 = stoi(year2);
    m1 = stoi(month1);
    m2 = stoi(month2);
    d1 = stoi(day1);
    d2 = stoi(day2);
    if (yr1 == yr2 && m1 == m2 && (d2 - d1) == 1) {
        return true;
    }
    else {
        return false;
    }
}
