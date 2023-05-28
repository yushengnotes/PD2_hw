/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void search(const vector< pair<int, double> > &nums, const map<int, vector<int> > &numCorpus, map<int, vector<double> > &IDF);
void processIDF(map<int, vector<double> > &IDF, map<int, double> &sumIDF);

void calculateSumIDF(map<int, vector<int> > &numCorpus, map<int, vector< pair<int, double> > > &storeIDF, map <int, map<int, double> > &storeSumIDF) {

    map<int, double> sumIDF;
    map<int, vector<double> > IDF;

    for (const auto& pair : storeIDF) {
        search(pair.second, numCorpus, IDF);
        processIDF(IDF, sumIDF);
        storeSumIDF.insert({pair.first, sumIDF});
        IDF.clear();
    }

}
