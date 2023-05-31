/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/

#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void search(const vector< pair<int, double> > &nums, const unordered_map<int, vector<int> > &numCorpus, map<int, vector<double> > &IDF);
void processIDF(map<int, vector<double> > &IDF, map<int, double> &sumIDF);

void calculateSumIDF(unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int, double> > > &storeIDF, map <int, map<int, double> > &storeSumIDF) {

    map<int, double> sumIDF;
    map<int, vector<double> > IDF;

    for (const auto& pair : storeIDF) {
        search(pair.second, numCorpus, IDF);
        processIDF(IDF, sumIDF);
        storeSumIDF.insert({pair.first, sumIDF});
        IDF.clear();
    }

}
