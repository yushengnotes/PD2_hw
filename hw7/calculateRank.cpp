/*  鄒雨笙 F64081070 程式設計二 第7次作業 2023/6/21

*/

#include <iostream> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void calculateRank(unordered_map <int, map<int, vector< pair<int, pair<double, double> > > > > &storeKeyWord, unordered_map <int, vector< pair<int, double> > > &result) {

    for (const auto& outer_key_pair : storeKeyWord) {
        vector< pair<int, double> > inner_result;

        for (const auto& inner_key_pair : outer_key_pair.second) {
            double sum_second_double = 0;
            int counter = 0;

            for (const auto& pair : inner_key_pair.second) {
                sum_second_double += pair.second.second;
                counter++;
                if (counter == 3) {
                    break;
                }
            }
            // Store the summed values in 'inner_result'
            inner_result.push_back({inner_key_pair.first, sum_second_double});
        }

        result[outer_key_pair.first] = inner_result;
    }

    for(const auto& outer_pair : result){
    cout << "Key: " << outer_pair.first << endl;
    for(const auto& inner_pair : outer_pair.second){
        cout << "(" << inner_pair.first << ", " << inner_pair.second << ") ";
    }
    cout << endl;
    }

}


