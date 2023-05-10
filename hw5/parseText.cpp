/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/11

    此副程式parseCSV()用來讀取csv檔案，並將檔案中的資料存入
    vector<Employee>中
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cassert>
using namespace std;

void parseText(char* &corpus, char* &query, map<int, vector<string> > &c, map<int, vector<string> > &q) { 
    // 宣告一個ifstream型別的物件infile
    ifstream infile;
    // 開啟當前目錄下名為corpus的檔案
    infile.open(corpus);
    if (!infile) {
        cerr << "error: unable to open the input file: " << corpus << endl;
    }

    string line, field;
    
    // 將檔案中的資料存入map<int, vector<string> > corpus
    while (getline(infile, line)) {
    istringstream ss(line);
    vector<string> fields;
    string token;
    for(char& c : line){
        if(c == ' ' || c == '"' || c == ','){
            if (!token.empty()) {
                fields.push_back(token);
                token.clear();
            }
        }
        else{
            token += c;
        }
    }
    // Push the last token if it's not empty
    if (!token.empty()){
        fields.push_back(token);
    }
    int key = stoi(fields[0]);
    c.insert({key, fields});
    }

    
    infile.close();    
    for (auto it = c.begin(); it != c.end(); ++it) {
        cout << "Key: " << it->first << ", Value: ";
        for (const auto& str : it->second) {
            cout << str << " ";
        }
        cout << "\n";
    }

    cout << "Read txt file success" << endl;
}


