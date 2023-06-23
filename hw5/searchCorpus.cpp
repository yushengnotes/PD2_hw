/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;

inline bool search(vector<int> &values, int num) {
    bool flag = false;
    for (auto value : values) {
        if (value == num) {
            flag = true;
            break;
        }
    } 
    return flag;
}

void searchCorpus(unordered_map<int, vector<int> > &numCorpus, unordered_map<int, vector<int> > &numQuery, map<int, map<int, vector<bool> > > &result) {

    map<int, vector<bool> > searchMap;

    for (auto nums : numQuery) {
        for (auto key : numCorpus) {
            vector<bool> searchState;

            for (const auto& num : nums.second) {
                searchState.push_back(search(key.second, num));
            }
            searchMap.insert({key.first, searchState});
        }
        result.insert({nums.first, searchMap});
        searchMap.clear();
    }
}

