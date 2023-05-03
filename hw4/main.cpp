/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此為主程式main，其會呼叫parseCSV()副程式以讀取csv檔案，並呼叫
    數個副程式，最後輸出前三個連續工作天最多的員工id，其開始
    及結束工作日期，列印到主控台(console)
*/

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Attendance.h"
using namespace std;

// 宣告用來開啟csv檔案的副程式
void parseCSV(char* &filename, vector<Employee> &employees); 
// 宣告用來排序employees的副程式，使用&v是表示傳入的參數是vector
void sortEmployees(vector<Employee> &v);
// 宣告用來創建attendances的副程式
void createAttend(vector<Employee> &employees, vector<Attendance> &attendances);
// 宣告用來計算conWorkday的副程式
void calConWorkday(vector<Employee> &employees, vector<Attendance> &attendances);
// 宣告用來排序attendances的副程式
void sortAttendances(vector<Attendance> &v);
// 宣告用來賦值到results的副程式
void createResults(vector<Attendance> &attendances, vector<Attendance> &results);
// 宣告用來排序results的副程式
void sortResults(vector<Attendance> &v);
// 宣告用來Time formatting results的副程式
void formatResults(vector<Attendance> &v);

int main(int argc, char *argv[]) {
    // 宣告用以儲存原始的csv檔employee資料的vector
    vector<Employee> employees; 
    // 宣告用以儲存整理過的employee資料，並以id為物件以Attendance為類別
    // 的vector
    vector<Attendance> attendances; 
    // 宣告用來儲存每個員工連續工作最多天的那一筆紀錄
    vector<Attendance> results; 

    parseCSV(argv[1], employees); // 呼叫用來開啟csv檔案的副程式
    sortEmployees(employees); // 呼叫用來排序employees的副程式

    // for (int i = 0; i < employees.size(); ++i) {
    //     cout << employees[i].getId() << ',' << employees[i].getSignType() << ',' << employees[i].getFormatTime() << endl;
    // }

    // 呼叫用來創建attendances的副程式
    createAttend(employees, attendances);

    // 呼叫用來計算連續工作天並找出開始與結束日期的副程式
    calConWorkday(employees, attendances);

    sortAttendances(attendances); // 呼叫用來排序attendances的副程式

    // for (int i = 0; i < attendances.size(); ++i) {
    //     cout << attendances[i].getId() << ",";
    //     attendances[i].printRecord();
    // }

    // 呼叫用來創建results的副程式，此時results裡的各值的成員變數為空
    createAttend(employees, results);

    // 呼叫用來賦值給results的副程式
    createResults(attendances, results);

    // for (int i = 0; i < results.size(); ++i) {
    //     cout << results[i].getId() << ",";
    //     results[i].printRecord();
    // }

    // 呼叫用來排序results的副程式，conWorkDay越大越往前擺
    sortResults(results);

    // for (int i = 0; i < results.size(); ++i) {
    //     cout << results[i].getId() << ",";
    //     results[i].printRecord();
    // }

    // 呼叫用來Time formatting results的副程式
    formatResults(results);

    // 列印出前三名最長連續工作天的員工的副程式，每行格式為
    // 例: 1023,10,20230102, 20230112
    for (int i = 0; i < 3; ++i) {
        cout << results[i].getId() << ",";
        results[i].printRecord();
    }

    return 0;
}

