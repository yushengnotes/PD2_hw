/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include "TrieNode.h"
using namespace std;

// 宣告用來開啟corpus.txt檔案的副程式
void parseCorpus(char* &corpus, map<int, vector<string> > &c);
// 宣告用來開啟query.txt檔案的副程式
void parseQuery(char* &query, map<int, vector<string> > &q);
// 宣告用來將string轉換成int的副程式
void stringToNum(map<int, vector<string> > &corpus, map<int, vector<int> > &numCorpus);
// 宣告用來計算各個query word的IDF(Inverse Document Frequency)的副程式
void calculateIDF();
// 宣告用來search corpus的副程式
void searchCorpus(map<int,  TrieNode*> &corpusTrie, map<int, vector<string> > &query, map<int,  map<int, vector<bool> > > &results);
// 宣告用來整理results的副程式
void setResults(map<int, map<int, vector<bool> > > &results, map<int, vector<int> > &processedResults);
// 宣告用來印出processedResults的副程式
void printResults(map<int, vector<int> > &processedResults);

int main(int argc, char *argv[]) {
    // 以下為宣告變數之用 -------------------------

    // 宣告用以儲存corpus資料
    map<int, vector<string> > corpus; 
    // 宣告用以儲存query資料
    map<int, vector<string> > query; 
    // 宣告用以儲存轉換成數字的corpus資料
    map<int, vector<int> > numCorpus; 
    // 宣告用以儲存轉換成數字的query資料
    map<int, vector<int> > numQuery; 

    // 宣告用來儲存未經整理過的每行搜尋結果的map
    map<int, map<int, vector<bool> > > results;
    // 宣告用來儲存經整理過的每行搜尋結果的map
    map<int, vector<int> > processedResults; 

    // 以下為呼叫函式之用 -------------------------

    // 呼叫用來讀取corpus.txt檔案的副程式
    parseCorpus(argv[1], corpus); 
    // 呼叫用來讀取query.txt檔案的副程式
    parseQuery(argv[2], query); 

    // 呼叫用來將string轉換成int的副程式
    stringToNum(corpus, numCorpus);
    // 呼叫用來將string轉換成int的副程式
    stringToNum(query, numQuery);

    // A checkpoint for numCorpus
    for (const auto& kv : numCorpus) {
        cout << "Key: " << kv.first << "\nValues: ";
        for (const auto& val : kv.second) {
            std::cout << val << " ";
        }
        cout << "\n";
    }
    // A checkpoint for numQuery
    for (const auto& kv : numQuery) {
        cout << "Key: " << kv.first << "\nValues: ";
        for (const auto& val : kv.second) {
            std::cout << val << " ";
        }
        cout << "\n";
    }

    // 呼叫用來search corpus的副程式
    // searchCorpus(corpusTrie, query, results);

    // 呼叫用來整理results的副程式
    // setResults(results, processedResults);
    // 呼叫用來印出processedResults的副程式
    // printResults(processedResults);

    return 0;
}
