/*  鄒雨笙 F64081070 程式設計二 第7次作業 2023/6/21

*/

#include <iostream> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void findKeyWord(const vector< pair<int, double> > &nums, const unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int,double> > > &keyWord); 

void findTop3IDFword(const unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int, double> > > &storeIDF, map <int, map<int, double> > &storeTop3IDF) {

    map<int, vector< pair<int,double> > > keyWord;
    map <int, map<int, vector< pair<int,double> > > > storeKeyWord;

    for (const auto& key : storeIDF) {
        findKeyWord(key.second, numCorpus, keyWord);
        storeKeyWord.insert({key.first, keyWord});
        keyWord.clear();
    }
    for (const auto & outerMapElement : storeKeyWord) {
    int outerKey = outerMapElement.first;
    std::cout << "Outer Key: " << outerKey << std::endl;

    for (const auto & innerMapElement : outerMapElement.second) {
        int innerKey = innerMapElement.first;
        std::cout << "    Inner Key: " << innerKey << std::endl;

            for (const auto & vectorElement : innerMapElement.second) {
                int pairFirst = vectorElement.first;
                double pairSecond = vectorElement.second;

                std::cout << "        Pair: (" << pairFirst << ", " << pairSecond << ")" << std::endl;
            }
        }
    }

}
