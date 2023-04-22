/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式tmFormat()用來對vector做time formatting
*/

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Attendance.h"
#include "Record.h"
using namespace std;

// 用來將日期轉為秒，再轉為想要的日期格式
string timeFormatting(string &date) {
    // 將日期轉為秒
    tm time_struct = {};
    istringstream ss(date);
    ss >> get_time(&time_struct, "%Y-%m-%d");
    time_t time_value = mktime(&time_struct);

    // 將秒轉為格式化後的日期
    tm *time_struct_ptr = localtime(&time_value);
    char formatted_time[20];
    strftime(formatted_time, sizeof(formatted_time), "%Y%m%d", time_struct_ptr);
    return string(formatted_time);
}

// 宣告用來Time formatting results的副程式
void formatResults(vector<Attendance> &v) {
    for (int i = 0; i < v.size(); ++i) {
        string startDay, endDay; // 未格式化的日期變數
        string startDate, endDate; // 已格式化的日期變數
        string date1, date2;
        startDay = (v[i].getRecord())[0].getStartDay();
        endDay = (v[i].getRecord())[0].getEndDay();

        istringstream ss1(startDay);
        istringstream ss2(endDay);
        // 將字串分割成日期和時間兩部份，並將日期存於date1, date2中
        getline(ss1, date1, ' ');
        getline(ss2, date2, ' ');
        startDate = timeFormatting(date1);
        endDate = timeFormatting(date2);

        // 匯入最後results要使用的格式
        (v[i].getRecord())[0].setFormatRecord(startDate, endDate);
        }
    cout << "Formatting results success!!!" << endl;
}
