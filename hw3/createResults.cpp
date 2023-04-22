
#include <iostream>
#include <vector>
#include "Attendance.h"
using namespace std;

void createResults(vector<Attendance> &attendances, vector<Attendance> &results) {
    int conWorkDay;
    string startDay, endDay;
    for (int i = 0; i < attendances.size(); i++) {
        conWorkDay = (attendances[i].getRecord())[0].getConWorkday();
        startDay = (attendances[i].getRecord())[0].getStartDay();
        endDay = (attendances[i].getRecord())[0].getEndDay();
        results[i].setRecord(conWorkDay, startDay, endDay);
    }
    cout << "Create results success!!!" << endl;
}
