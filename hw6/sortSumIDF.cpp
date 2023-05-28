/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void sortSumIDF(map<int, map<int, double> > &storeSumIDF, map<int, vector< pair<int, double > > > &sortedSumIDF) {
    for (const auto& kv : storeSumIDF) {
        // Convert map to vector
        vector< std::pair<int, double> > vec(kv.second.begin(), kv.second.end());

        // Sort the vector in ascending order
        sort(vec.begin(), vec.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
            return a.second > b.second;
        });

        // Insert the sorted vector into sortedSumIDF
        sortedSumIDF.insert({kv.first, vec});
    }
}
