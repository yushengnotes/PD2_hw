/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <string>
#include "TrieNode.h"

using namespace std;

void processSearchState(vector<bool> &searchState);

bool search(TrieNode* root, string word);

inline void processSearchState(vector<bool> &searchState) {
    bool allTrue = true;
    for (const auto& it : searchState) {
        if (!it) {
            allTrue = false;
            break;
        }
    }
    searchState.clear();
    searchState.push_back(allTrue);
}

void searchCorpus(map<int,  TrieNode*> &corpusTrie, map<int, vector<string> > &query, map<int,  map<int, vector<bool> > > &results) {


    // To check if the query is working
    cout << "Size of query: " << query.size() << endl;
    for (const auto& item : query) {
        cout << "Key: " << item.first << ", Values: ";
        for (const auto& str : item.second) {
            cout << str << " ";
        }
        cout << endl;
    }

    for (auto it_q = query.begin(); it_q != query.end(); ++it_q) {
        map<int, vector<bool> > searchMap;

        // A checkpoint
        cout << "Query: " << it_q->first << endl;
        for (auto it_c = corpusTrie.begin(); it_c != corpusTrie.end(); ++it_c) {
            // A checkpoint
            cout << "Corpus: " << it_c->first << " ";
            vector<bool> searchState;
            for (const auto& str : it_q->second) {
                searchState.push_back(search(it_c->second, str));
                // To check if the searching process is working
                cout << "Search word: " << str << " ";
                cout << search(it_c->second, str) << " ";
            }
            // To process the 'searchState' vector
            // processSearchState(searchState);
            // To check if the processSearchState() is working
            for (const auto& it : searchState) {
                cout << it << " ";
            }
            cout << endl;
            searchMap.insert({it_c->first, searchState});
        }
        results.insert({it_q->first, searchMap});
        searchMap.clear();
    }
}


