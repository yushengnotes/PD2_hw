/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "TrieNode.h"

using namespace std;

// 宣告用來新建node的副程式
TrieNode* getNode(); 
// 宣告用來輸入字串的副程式
void insert(TrieNode* root, string word); 

void buildCorpusTrie(map<int, vector<string> > &corpus, map<int,  TrieNode*> &corpusTrie) {

    for (auto it = corpus.begin(); it != corpus.end(); ++it) {
        TrieNode* root = getNode();
        for (const auto& str : it->second) {
            // cout << str << " ";
            insert(root, str);
        }
        corpusTrie.insert({it->first, root});
    }
}
