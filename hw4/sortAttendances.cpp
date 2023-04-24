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

void sortAttendances(vector<Attendance> &v) {
    int insertDay, moveItem;

    // 用以排序conDayRecord，並以insertion sort來實作
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t next = 1; next < v[i].getRecord().size(); ++next) {
            insertDay = (v[i].getRecord())[next].getConWorkday();
            Record insert = (v[i].getRecord())[next];
            moveItem = next;
            while (moveItem > 0 && (v[i].getRecord())[moveItem-1].getConWorkday() < insertDay) {
                (v[i].getRecord())[moveItem] = (v[i].getRecord())[moveItem-1];
                --moveItem;
            }
            (v[i].getRecord())[moveItem] = insert;
        }
    }
    // cout << "Sorting conWorkDay success" << endl;

    // 用以排序startDay，並以insertion sort來實作
    for (size_t i = 0; i < v.size(); ++i) {
        for (size_t next = 1; next < v[i].getRecord().size(); ++next) {
            insertDay = startDayFormat((v[i].getRecord())[next].getStartDay());
            Record insert = (v[i].getRecord())[next];
            moveItem = next;
            while (moveItem > 0 && startDayFormat((v[i].getRecord())[moveItem-1].getStartDay()) < insertDay && v[i].getRecord()[moveItem-1].getConWorkday() == v[i].getRecord()[moveItem].getConWorkday()) {
                (v[i].getRecord())[moveItem] = (v[i].getRecord())[moveItem-1];
                --moveItem;
            }
            (v[i].getRecord())[moveItem] = insert;
        }
    }
    cout << "Sorting startDay success" << endl;
}


