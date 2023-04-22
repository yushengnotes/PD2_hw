/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式insertSort()用來對vector做排序(Insertion sort)
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Employee.h"
using namespace std;

// 呼叫用來對vector做time formatting的副程式
void tmFormat(vector<Employee> &emp);
// 呼叫用來對vector做time formatting的副程式，將秒轉為年月日
void timeFormat(vector<Employee> &emp);

void sortEmployees(vector<Employee> &v) {
    int insertId, insertTm, moveItem;

    // 用以排序employees的id，並以insertion sort來實作
    for (size_t next = 1; next < v.size(); ++next) {
        insertId = v.at(next).getId();
        Employee insert = v.at(next);
        moveItem = next;
        while (moveItem > 0 && (v.at(moveItem-1).getId() > insertId)) {
            v.at(moveItem) = v.at(moveItem-1);
            --moveItem;
        }
        v.at(moveItem) = insert;
    }
    // cout << "Sorting id success" << endl;

    // 列印出物件emp的成員變數
    // for (int i = 0; i < v.size(); ++i) {
    //     cout << v.at(i).getId() << ',' << v.at(i).getSignType() << ',' << v.at(i).getTime() << endl;
    // }

    tmFormat(v); // 呼叫用來對vector做time formatting的副程式

    // 用以排序employees的ftime，並以insertion sort來實作
    for (size_t next = 1; next < v.size(); ++next) {
        insertTm = v.at(next).getFtime();
        Employee insert = v.at(next);
        moveItem = next;
        while (moveItem > 0 && (v.at(moveItem-1).getFtime() > insertTm) && (v.at(moveItem-1).getId() == v.at(moveItem).getId())) {
            v.at(moveItem) = v.at(moveItem-1);
            --moveItem;
        }
        v.at(moveItem) = insert;
    }
    // cout << "Sorting time success" << endl;
    // 呼叫用來對vector做time formatting的副程式，將秒轉為年月日
    timeFormat(v); 
}


