/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <string>
#include "TrieNode.h"
using namespace std;

void printTrie(TrieNode* root, string str = "") {
    if (root->isEndOfWord) {
        cout << str << endl;
    }
    for (auto it = root->children.begin(); it != root->children.end(); ++it) {
        printTrie(it->second, str + it->first);
    }
}
