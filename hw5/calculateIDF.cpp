/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/

#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
#include <cmath> // for using log operation
#include <iostream>
using namespace std;

int searchOccurNum(int num, const unordered_map<int, vector<int> > &numCorpus);

void calculateIDF(unordered_map<int, vector<int> > &numQuery, unordered_map<int, vector<int> > &numCorpus, map <int, vector< pair<int, double> > > &storeIDF) {

    double totalKey = numCorpus.size();
    double occurNum;
    double IDF;
    for (const auto& it : numQuery) {
        vector< pair<int,double> > perQueryIDF;
        pair<int,double> queryIDF;
        for (const auto& num : it.second) {
            // 計算出word在corpus中所出現的次數，各corpus超過1則記為1
            occurNum = searchOccurNum(num, numCorpus);
            // A checkpoint
            // cout << occurNum << endl;
            // cout << totalKey << endl;
            // 計算出IDF
            IDF = log10(totalKey/occurNum); 
            // A checkpoint
            // cout << IDF << endl;
            // 將IDF存入storeIDF中
            queryIDF.first = num;
            queryIDF.second = IDF;
            perQueryIDF.push_back(queryIDF);
        }
        storeIDF.insert({it.first, perQueryIDF});
    }

}
