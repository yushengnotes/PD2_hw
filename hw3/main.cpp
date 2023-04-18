/*  鄒雨笙 F64081070 程式設計二 第3次作業 2023/4/11

    此為主程式main，其會呼叫parseCSV()副程式以讀取csv檔案，並呼叫
    overLoadingdays()副程式對vector計算overLoadingdays，再呼叫
    signForgetdays()副程式對vector計算signForgetdays()，最後呼叫
    printOut()副程式將每個員工的id, overLoadingdays, signForgetdays
    列印到主控台(console)
*/

#include <iostream>
#include <vector>
#include "Employee.h"
#include "Attendance.h"
using namespace std;

// 宣告用來開啟csv檔案的副程式
void parseCSV(char* &filename, vector<Employee> &employees); 
// 宣告用來排序vector的副程式
void insertSort(vector<Employee> &v);

int main(int argc, char *argv[]) {
    // 宣告用以儲存原始的csv檔employee資料的vector
    vector<Employee> employees; 
    // 宣告用以儲存整理過的employee資料，並以id為物件以Attendance為類別
    // 的vector．未寫
    vector<Attendance> attendances; 

    parseCSV(argv[1], employees); // 呼叫用來開啟csv檔案的副程式
    insertSort(employees); // 呼叫用來排序vector的副程式

    // 以下還未寫

    // 呼叫用來創建attendances的副程式
    createAttend(employees, attendances);
    // 呼叫用來計算連續工作天並找出開始與結束日期的副程式
    calConWorkday(employees, attendances);
    selectSort(attendances); // 呼叫用來排序attendances的副程式
    // 列印出前三名最長連續工作天的員工，每行格式為
    // 例: 1023, 100, 20230102, 20230310
    printOut(attendances); 

    for (int i = 0; i < employees.size(); ++i) {
        cout << employees[i].getId() << ',' << employees[i].getSignType() << ',' << employees[i].getFtime() << endl;
    }
    return 0;
}



