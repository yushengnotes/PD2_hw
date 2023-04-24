/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式insertSort()用來對vector做排序(Insertion sort)
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>
#include "Employee.h"
using namespace std;

// 呼叫用來對vector做time formatting的副程式
void tmFormat(vector<Employee> &emp);
// 呼叫用來對vector做time formatting的副程式，將秒轉為年月日
void timeFormat(vector<Employee> &emp);


// 比較id大小 
bool compareId(const Employee &a, const Employee &b) {
    return a.getId() < b.getId();
}

// 比較ftime大小 
bool compareFtime(const Employee &a, const Employee &b) {
    if (a.getId() == b.getId()) {
        return a.getFtime() < b.getFtime();
    }
    return a.getId() < b.getId();
}

void sortEmployees(vector<Employee> &v) {

    // 用以排序employees的id，並以quick sort來實作
    sort(v.begin(), v.end(), compareId);
    // cout << "Sorting id success" << endl;

    // 列印出物件emp的成員變數
    // for (int i = 0; i < v.size(); ++i) {
    //     cout << v.at(i).getId() << ',' << v.at(i).getSignType() << ',' << v.at(i).getTime() << endl;
    // }

    tmFormat(v); // 呼叫用來對vector做time formatting的副程式

    // 用以排序employees的ftime，並以quick sort來實作
    sort(v.begin(), v.end(), compareFtime);
    // cout << "Sorting time success" << endl;
    // 呼叫用來對vector做time formatting的副程式，將秒轉為年月日
    timeFormat(v); 
}

