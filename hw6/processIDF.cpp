/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs
#include <numeric> 
using namespace std;

void processIDF(map<int, vector<double> > &IDF, map<int, double> &sumIDF) {
    for (const auto& it : IDF) {
        double sum = accumulate(it.second.begin(), it.second.end(), 0.0);
        sumIDF[it.first] = sum;
    }
}
