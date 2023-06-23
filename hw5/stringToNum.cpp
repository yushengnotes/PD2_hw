/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "MurmurHash3.h" 

using namespace std;

uint32_t convertToNum(const string &word, uint32_t seed = 0) {
    uint32_t hashValue;
    MurmurHash3_x86_32(word.data(), word.size(), seed, &hashValue);
    return hashValue;
}

void stringToNum(unordered_map<int, vector<string> > &corpus, unordered_map<int, vector<int> > &numCorpus) {
    for (auto it = corpus.begin(); it != corpus.end(); ++it) {
        vector<int> numVec; 
        for (const auto& str : it->second) {
            int num = convertToNum(str);
            numVec.push_back(num); 
        }
        numCorpus[it->first] = numVec; 
    }
}
