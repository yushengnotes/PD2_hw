/*  鄒雨笙 F64081070 程式設計二 第7次作業 2023/6/21

*/

#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void findKeyWord(const vector< pair<int, double> > &nums, const unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int,double> > > &keyWord) {

    bool flag = false;
    vector< pair<int,double> > keyWords;

    for (const auto& key : numCorpus) {
        for(const auto& num : nums) {
            for(const auto& value : key.second) {
                if(value == num.first) {
                    flag = true;
                    break;
                }
            }
            if (flag == true) {
                keyWords.push_back(num);
            }
            flag = false;
        }
        keyWord.insert({key.first, keyWords});
        keyWords.clear();
    }
    
}
