/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此為副程式createAttend()，用來創建attendances

*/

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Attendance.h"
using namespace std;

void createAttend(vector<Employee> &employees, vector<Attendance> &attendances) {
    int i = 0;
    while (i < employees.size()) {
        int id;
        id = employees[i].getId();
        while (employees[i].getId() == employees[i+1].getId()) {
            i++;
        }
        // 建立物件atd
        Attendance atd(id);
        attendances.push_back(atd);
        i++;
    }

    cout << "Create attendances success!!!" << endl;
    for (int i = 0; i < attendances.size(); ++i) {
        cout << attendances[i].getId()  << endl;
    }
}
