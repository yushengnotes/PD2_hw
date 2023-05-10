/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCSV()副程式以讀取csv檔案，並呼叫
    數個副程式，最後輸出前三個連續工作天最多的員工id，其開始
    及結束工作日期，列印到主控台(console)
    
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

// 宣告用來開啟txt檔案的副程式
void parseText(char* &corpus, char* &query, map<int, vector<string> > &c, map<int, vector<string> > &q);

int main(int argc, char *argv[]) {
    // 宣告用以儲存原始的txt檔corpus資料的vector
    map<int, vector<string> > corpus; 
    // 宣告用以儲存原始的txt檔query資料的vector
    map<int, vector<string> > query; 

    // 宣告用來儲存每行搜尋結果的vector
    vector<int> results; 

    // 呼叫用來開啟txt檔案的副程式
    parseText(argv[1], argv[2], corpus, query); 
    
    // 以下函式未定義
    // searchWord();
    
    // setResults();

    return 0;
}
