/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此表頭檔用以宣告Attendance類別的定義式，定義介面但不實作，
    實作將置於Attendance.cpp
*/
#ifndef RECORD_H
#define RECORD_H
#include <string>

class Record {
    public:
        // 建構式
        Record(int conWorkday, std::string &startDay, std::string &endDay):
            conWorkday(conWorkday), startDay(startDay), endDay(endDay) {}
        
        // 成員函式
        int getConWorkday() const { return conWorkday; }
        std::string getStartDay() const { return startDay; }
        std::string getEndDay() const { return endDay; }
        // 匯入最後results要使用的格式
        void setFormatRecord(std::string &startDate, std::string &endDate);

    private:
        int conWorkday;
        std::string startDay;
        std::string endDay; 
};

#endif

