/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式insertSort()用來對vector做排序(Insertion sort)
*/

#include <iostream>
#include <vector>
#include <string>
#include "Attendance.h"
using namespace std;

void sortResults(vector<Attendance> &v) {
    int insertDay, moveItem;

    // 用以排序results，並以insertion sort來實作
    for (size_t next = 1; next < v.size(); ++next) {
        insertDay = (v[next].getRecord())[0].getConWorkday();
        Attendance insert = v[next];
        moveItem = next;
        while (moveItem > 0 && (v[moveItem-1].getRecord())[0].getConWorkday() < insertDay) {
            v[moveItem] = v[moveItem-1];
            --moveItem;
        }
        v[moveItem] = insert;
    }
    // cout << "Sorting results success" << endl;


}


