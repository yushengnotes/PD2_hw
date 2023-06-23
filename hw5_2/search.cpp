/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <string>
#include <algorithm>
#include "TrieNode.h"

using namespace std;

bool search(TrieNode* root, string word) {
    transform(word.begin(), word.end(), word.begin(),
        [](unsigned char c){ return tolower(c); });
    
    TrieNode* node = root;
    for (char ch : word) {
        if (node->children.count(ch) == 0) {
            return false;
        }
        node = node->children[ch];
    }
    return node->isEndOfWord;
}


