/*  鄒雨笙 F64081070 程式設計二 第7次作業 2023/6/21

*/

#include <map> 
#include <iostream> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
#include <algorithm>
using namespace std;

void findKeyWord(vector< pair<int, pair<double, double> > > &nums, unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int,pair<double, double> > > > &keyWord) {

    double i = 0;
    double tf;
    bool flag = false;
    vector< pair<int, pair<double, double> > > keyWords;

    for (auto& key : numCorpus) {
        for(auto& num : nums) {
            for(auto& value : key.second) {
                if(value == num.first) {
                    i++;
                    flag = true;
                }
            }
            tf = i / ((key.second).size()-1);
            num.second.second = num.second.first * tf;
            if (flag == true) {
                keyWords.push_back(num);
            }
            flag = false;
            i = 0;
        }
        // 依據second double即new_tf*idf來排序
        sort(keyWords.begin(), keyWords.end(),
    [](const pair<int, pair<double, double>>& a, const pair<int, pair<double, double>>& b) {
            return a.second.second > b.second.second;
            }
        );

        keyWord.insert({key.first, keyWords});
        keyWords.clear();
    }
    
}
