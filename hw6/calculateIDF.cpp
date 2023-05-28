/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs
#include <cmath> // for using log operation
#include <iostream>
using namespace std;

int searchOccurNum(int num, const map<int, vector<int> > &numCorpus);

void calculateIDF(map<int, vector<int> > &numQuery, map<int, vector<int> > &numCorpus, map <int, vector< pair<int, double> > > &storeIDF) {

    double totalKey = numQuery.size();
    double occurNum;
    double IDF;
    for (const auto& it : numQuery) {
        vector< pair<int,double> > perQueryIDF;
        pair<int,double> queryIDF;
        for (const auto& num : it.second) {
            // 計算出word在corpus中所出現的次數，各corpus超過1則記為1
            occurNum = searchOccurNum(num, numCorpus);
            // A checkpoint
            cout << occurNum << endl;
            // 計算出IDF
            IDF = log10(occurNum/totalKey); 
            // A checkpoint
            cout << IDF << endl;
            // 將IDF存入storeIDF中
            queryIDF.first = num;
            queryIDF.second = IDF;
            perQueryIDF.push_back(queryIDF);
        }
        storeIDF.insert({it.first, perQueryIDF});
    }

}
