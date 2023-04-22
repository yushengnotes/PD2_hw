/*  鄒雨笙 F64081070 程式設計二 第4次作業 2023/4/26

    此副程式parseCSV()用來讀取csv檔案，並將檔案中的資料存入
    vector<Employee>中
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include "Employee.h"
using namespace std;

void parseCSV(char* &filename, vector<Employee> &employees) {
    // 宣告一個ifstream型別的物件infile
    ifstream infile;
    // 開啟當前目錄下名為filename的檔案
    infile.open(filename);
    if (!infile) {
        cerr << "error: unable to open the input file: " << filename << endl;
    }

    string line, field;
    
    // 將檔案中的資料存入vector<Employee> employees
    while (getline(infile, line)) {
        istringstream ss(line); // 將ss綁定至讀取行
        vector<string> fields;
        // 將每一行的單字取出
        while (getline(ss, field, ',')) { 
            fields.push_back(field);
        }
        int id = stoi(fields[0]);
        string signType = fields[1];
        string time = fields[2];
        // 建立物件emp
        Employee emp(id, signType, time);
        employees.push_back(emp);
    }
    

    
    // cout << "Read csv file success" << endl;

}


