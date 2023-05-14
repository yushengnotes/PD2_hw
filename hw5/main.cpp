/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include "TrieNode.h"
using namespace std;

// 宣告用來開啟corpus.txt檔案的副程式
void parseCorpus(char* &corpus, map<int, vector<string> > &c);
// 宣告用來開啟query.txt檔案的副程式
void parseQuery(char* &query, map<int, vector<string> > &q);
// 宣告用來創建corpusTrie的副程式
void buildCorpusTrie(map<int, vector<string> > &corpus, map<int,  TrieNode*> &corpusTrie);
// 宣告用來印出corpusTrie的副程式
void printTrie(TrieNode* root, string str = "");
// 宣告用來search corpus的副程式
void searchCorpus(map<int,  TrieNode*> &corpusTrie, map<int, vector<string> > &query, map<int,  map<int, vector<bool> > > &results);
// 宣告用來整理results的副程式
void setResults(map<int, map<int, vector<bool> > > &results, vector<int> &processedResults);

int main(int argc, char *argv[]) {
    // 宣告用以儲存原始的txt檔corpus資料的vector
    map<int, vector<string> > corpus; 
    // 宣告用以儲存原始的txt檔query資料的vector
    map<int, vector<string> > query; 
    // 宣告用來儲存Trie的map
    map<int, TrieNode*> corpusTrie; 
    // 宣告用來儲存未經整理過的每行搜尋結果的map
    map<int, map<int, vector<bool> > > results;

    // 呼叫用來讀取corpus.txt檔案的副程式
    parseCorpus(argv[1], corpus); 
    // 呼叫用來讀取query.txt檔案的副程式
    parseQuery(argv[2], query); 

    // 呼叫用來創建corpusTrie的副程式
    buildCorpusTrie(corpus, corpusTrie);

    // check the words stored in the Trie
    for (auto it = corpusTrie.begin(); it != corpusTrie.end(); ++it) {
        cout << "Printing Trie for index " << it->first << ":" << endl;
        printTrie(it->second);
    }

    // 呼叫用來search corpus的副程式
    searchCorpus(corpusTrie, query, results);

    // 呼叫用來整理results的副程式
    // setResults(results, processedResults);
    
    // 以下函式未定義
    // printResults(processedResults);

    return 0;
}
