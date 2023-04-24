/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式insertSort()用來對vector做排序(Insertion sort)
*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Attendance.h"
#include "Record.h"
using namespace std;

time_t startDayFormat(const string &time);

// 將attendances中的startDay的年月日轉為秒
time_t startDayFormat(const string &time) {
    tm time_struct = {};
    istringstream ss(time);
    ss >> get_time(&time_struct, "%Y-%m-%d %H:%M");
    time_t time_value = mktime(&time_struct);
    return time_value; 
    // cout << "time formatted, convert to seconds" << endl;
}

// 比較conWorkday大小 
bool compareDay(const Record &a, const Record &b) {
    return a.getConWorkday() > b.getConWorkday();
}

// 比較startDay大小 
bool compareStartDay(const Record &a, const Record &b) {
    if (a.getConWorkday() == b.getConWorkday()) {
        return a.getStartDay() > b.getStartDay();
    }
    return a.getConWorkday() > b.getConWorkday();
}

void sortAttendances(vector<Attendance> &v) {

    // 用以排序conDayRecord，並以quick sort來實作
    for (size_t i = 0; i < v.size(); ++i) {
        sort(v[i].getRecord().begin(), v[i].getRecord().end(), compareDay);
    }
    // cout << "Sorting conWorkDay success" << endl;

    // 用以排序startDay，並以quick sort來實作
    for (size_t i = 0; i < v.size(); ++i) {
        sort(v[i].getRecord().begin(), v[i].getRecord().end(), compareStartDay);
    }
    // cout << "Sorting startDay success" << endl;
}


