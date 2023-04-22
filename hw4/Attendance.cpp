/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

*/
#include <iostream>
#include "Attendance.h"
#include "Record.h"
using namespace std;

void Attendance::setRecord(int conWorkday, std::string &startDay, std::string &endDay) {
    Record record(conWorkday, startDay, endDay);
    conDayRecord.push_back(record);
}

void Attendance::printRecord() {
    for (size_t i = 0; i < conDayRecord.size(); i++) {
        cout << conDayRecord[i].getConWorkday() << "," << conDayRecord[i].getStartDay() << "," << conDayRecord[i].getEndDay() << endl;
    }

}

