/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

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
