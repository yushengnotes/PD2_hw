/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11

    此為副程式createAttend()，用來創建attendances

*/

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Attendance.h"
using namespace std;

void calConWorkday(vector<Employee> &employees, vector<Attendance> &attendances) {
    int i = 0;
    int j = 0;
    int day = 0;
    while (i < employees.size()) {
        while (employees[i].getId() == employees[i+1].getId()) {
            // 年月日是否相同
            if (employees[i].getTm() == employees[i+1].getTm()){
                i++;
                j++;
            } 
            // 年月同，日差一天
            else if (employees[i].getTm() == employees[i+1].getTm()) {
                i++;
                day++;
            }
            else {
                startDay = employees[i-day].getTm();
                endDay = employees[i].getTm();
                id = employees[i].getId();
                for (int i = 0; i < attendances.size(); i++) {
                    if (id == attendances[i].getId()) {
                        attendances[i].setRecord(day, startDay, endDay);
                        break;
                    }
                }
                day = 0;
                i++;
            }
        }
        startDay = employees[i-day-j].getTm();
        endDay = employees[i].getTm();
        id = employees[i].getId();
        for (int i = 0; i < attendances.size(); i++) {
            if (id == attendances[i].getId()) {
                attendances[i].setRecord(day, startDay, endDay);
                break;
            }
        }
        day = 0;
        i++;
    }
}
