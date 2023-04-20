/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11
    
   此副程式tmFormat()用來對vector做time formatting
*/

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include "Employee.h"
using namespace std;

void tmFormat(vector<Employee> &emp) {
    for (int i = 0; i < emp.size(); i++) {
        string time = emp[i].getTime();
        tm time_struct = {};
        istringstream ss(time);
        ss >> get_time(&time_struct, "%Y%m%d%H%M");
        time_t time_value = mktime(&time_struct);
        emp[i].setFtime(time_value); // 將轉為秒的時間存入emp
    }
    cout << "Time formatted, convert to seconds" << endl;
}
