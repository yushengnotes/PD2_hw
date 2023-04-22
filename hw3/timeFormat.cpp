/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11
    
   此副程式timeFormat()用來對vector做time formatting
*/

#include <iostream>
#include <string>
#include <ctime>
#include "Employee.h"
using namespace std;

// 將秒轉為年月日
string secondsToYearMonthDay(time_t seconds) {
    tm *time_struct = localtime(&seconds);
    char formatted_time[20];
    strftime(formatted_time, sizeof(formatted_time), "%Y-%m-%d %H:%M", time_struct);
    return std::string(formatted_time);
}

// 將轉為年月日的時間存入emp
void timeFormat(vector<Employee> &emp) {
    for (int i = 0; i < emp.size(); i++) {
        string formatTime;
        formatTime = secondsToYearMonthDay(emp[i].getFtime());
        emp[i].setFormatTime(formatTime); 
    }
    cout << "Time formatted, convert back to Y-M-D H:M" << endl;
}

