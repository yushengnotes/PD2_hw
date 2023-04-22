/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式tmFormat()用來對vector做time formatting
*/

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <vector>
#include "Employee.h"
using namespace std;


// 將年月日轉為秒
void tmFormat(vector<Employee> &emp) {
    for (size_t i = 0; i < emp.size(); i++) {
        string time = emp[i].getTime();
        tm time_struct = {};
        istringstream ss(time);
        ss >> get_time(&time_struct, "%Y%m%d%H%M");
        time_t time_value = mktime(&time_struct);
        emp[i].setFtime(time_value); // 將轉為秒的時間存入emp
    }
    // cout << "time formatted, convert to seconds" << endl;
}


