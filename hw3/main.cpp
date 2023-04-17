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
using namespace std;

// 宣告用來開啟csv檔案的副程式
void parseCSV(char* &filename, vector<Employee> &employees); 
// 宣告用來排序vector的副程式
void insertSort(vector<Employee> &v);

int main(int argc, char *argv[]) {
    vector<Employee> employees;
    parseCSV(argv[1], employees); // 呼叫用來開啟csv檔案的副程式
    insertSort(employees); // 呼叫用來排序vector的副程式

    for (int i = 0; i < employees.size(); ++i) {
        cout << employees[i].getId() << ',' << employees[i].getSignType() << ',' << employees[i].getFtime() << endl;
    }
    return 0;
}



