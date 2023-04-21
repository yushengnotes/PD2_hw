/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11

    此為副程式calConWorkDay()，用來計算連續工作天數

*/

#include <iostream>
#include <vector>
#include <sstream>
#include "Employee.h"
#include "Attendance.h"
using namespace std;

bool compareDay(const string &time, const string &time_next);
bool compareYearMonth(const string &time, const string &time_next);
    
void calConWorkday(vector<Employee> &employees, vector<Attendance> &attendances) {
    int i = 0, j = 0;
    int id;
    int day = 0;
    string startDay;
    string endDay;
    while (i < employees.size()) {
        while (employees[i].getId() == employees[i+1].getId()) {
            // 年月日是否相同
            if (compareYearMonth(employees[i].getFormatTime(), employees[i+1].getFormatTime())){
                i++;
                j++;
            } 
            // 年月同，日差一天
            else if (compareDay(employees[i].getFormatTime(), employees[i+1].getFormatTime())){
                i++;
                day++;
            } 
            else {
                startDay = employees[i-day-j].getFormatTime();
                endDay = employees[i].getFormatTime();
                id = employees[i].getId();
                day = day + 1;
                for (int i = 0; i < attendances.size(); i++) {
                    if (id == attendances[i].getId()) {
                        attendances[i].setRecord(day, startDay, endDay);
                        break;
                    }
                }
                day = 0;
                j = 0;
                i++;
            }
        }
        startDay = employees[i-day-j].getFormatTime();
        endDay = employees[i].getFormatTime();
        id = employees[i].getId();
        day = day + 1;
        for (int i = 0; i < attendances.size(); i++) {
            if (id == attendances[i].getId()) {
                attendances[i].setRecord(day, startDay, endDay);
                break;
            }
        }
        day = 0;
        i++;
        j = 0;
    }
}

