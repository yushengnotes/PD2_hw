/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此表頭檔用以宣告Attendance類別的定義式，定義介面但不實作，
    實作將置於Attendance.cpp
*/

#include <string>
#include "Record.h"

void Record::setFormatRecord(std::string &startDate, std::string &endDate) {
    startDay = startDate;
    endDay = endDate;

}
