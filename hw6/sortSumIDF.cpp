/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs
#include <algorithm> 

using namespace std;

void sortSumIDF(map<int, map<int, double> > &storeSumIDF, map<int, vector< pair<int, double > > > &sortedSumIDF) {
    for (const auto& kv : storeSumIDF) {
        // Convert map to vector
        vector< std::pair<int, double> > vec(kv.second.begin(), kv.second.end());

        // Sort the vector in ascending order by int and descending order by double
        sort(vec.begin(), vec.end(), [](const std::pair<int, double>& a, const std::pair<int, double>& b) {
            // If the double values are not equal, compare them
            if (a.second != b.second)
                return a.second > b.second;

            // If the double values are equal, compare the int values
            return a.first < b.first;
        });

        // Insert the sorted vector into sortedSumIDF
        sortedSumIDF.insert({kv.first, vec});
    }
}
