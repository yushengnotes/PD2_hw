/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11
    
    此表頭檔用以宣告Attendance類別的定義式，定義介面但不實作，
    實作將置於Attendance.cpp
*/
#ifndef ATTENDANCE_H
#define ATTENDANCE_H
#include <string>
#include <vector>
#include "Record.h"

class Attendance {
    public:
        // 建構式
        Attendance(int id): id(id) {}

        // 成員函式
        int getId() const { return id; }
        void setRecord(int conWorkday, std::string &startDay, std::string &endDay);
        void getRecord();

    private:
        int id;
        std::vector<Record> conDayRecord;
};

#endif
