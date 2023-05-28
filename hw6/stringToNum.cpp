/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

inline int convertToNum(const string &word) {
    int sum = 0;
    for (char c : word) {
        sum += static_cast<int>(c);
    }
    return sum;
}

void stringToNum(map<int, vector<string> > &corpus, map<int, vector<int> > &numCorpus) {
    for (auto it = corpus.begin(); it != corpus.end(); ++it) {
        vector<int> numVec; 
        for (const auto& str : it->second) {
            int num = convertToNum(str);
            numVec.push_back(num); 
        }
        numCorpus[it->first] = numVec; 
    }
}
