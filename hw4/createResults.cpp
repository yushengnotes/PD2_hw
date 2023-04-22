/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此為副程式createResults()，用來創建results

*/

#include <iostream>
#include <vector>
#include "Attendance.h"
using namespace std;

void createResults(vector<Attendance> &attendances, vector<Attendance> &results) {
    int conWorkDay;
    string startDay, endDay;
    for (size_t i = 0; i < attendances.size(); i++) {
        conWorkDay = (attendances[i].getRecord())[0].getConWorkday();
        startDay = (attendances[i].getRecord())[0].getStartDay();
        endDay = (attendances[i].getRecord())[0].getEndDay();
        results[i].setRecord(conWorkDay, startDay, endDay);
    }
    // cout << "Create results success!!!" << endl;
}


