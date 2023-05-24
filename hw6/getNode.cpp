/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/
#include "TrieNode.h"

TrieNode* getNode() {
    TrieNode* node = new TrieNode;
    node->isEndOfWord = false;
    return node;
}

