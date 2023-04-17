/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11
    
    此表頭檔用以宣告Employee類別的定義式，定義介面但不實作，
    實作將置於Employee.cpp
*/
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

class Employee {
    public:
        // 建構式
        Employee(int id, std::string &signType, std::string &time):
            id(id), signType(signType), time(time) {}
        // 成員函式
        int getId() const { return id; }
        std::string getSignType() const { return signType; }
        std::string getTime() const { return time; }
        int getFtime() const { return ftime; }
        void setFtime(int ftime);

    private:
        int id;
        std::string signType;
        std::string time; // unformatted time
        int ftime; // formatted time
};

#endif
