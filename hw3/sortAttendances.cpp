/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11
    
   此副程式insertSort()用來對vector做排序(Insertion sort)
*/

#include <iostream>
#include <vector>
#include <string>
#include "Attendance.h"
using namespace std;


void sortAttendances(vector<Attendance> &v) {
    int insertDay, moveItem;

    // 用以排序conDayRecord，並以insertion sort來實作
    for (int i = 0; i < v.size(); ++i) {
        for (int next = 1; next < v[i].getRecord().size(); ++next) {
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
    cout << "Sorting conWorkDay success" << endl;


}

