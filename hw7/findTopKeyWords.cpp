/*  鄒雨笙 F64081070 程式設計二 第7次作業 2023/6/21

*/

#include <iostream> 
#include <map> 
#include <unordered_map> 
#include <vector> 
#include <utility> // for using pairs
using namespace std;

void findKeyWord(vector< pair<int, pair<double, double> > > &nums, unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int, pair<double, double> > > > &keyWord); 

void findTopKeyWords(unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int, pair<double, double> > > > &storeIDF, unordered_map <int, map<int, vector< pair<int, pair<double, double> > > > > &storeKeyWord) {

    map <int, vector< pair<int, pair<double, double> > > > keyWord;

    for (auto& key : storeIDF) {
        findKeyWord(key.second, numCorpus, keyWord);
        storeKeyWord.insert({key.first, keyWord});
        keyWord.clear();
    }

    // Checkpoint for storeKeyWord
    // first double是idf、second double是new_tf*idf
    // for(const auto & outer_pair : storeKeyWord) {
    // int outer_key = outer_pair.first;
    // cout << "Outer Key: " << outer_key << endl;
    //
    // for(const auto & inner_pair : outer_pair.second) {
    //     int inner_key = inner_pair.first;
    //     cout << "\tInner Key: " << inner_key << endl;
    //
    //     for(const auto & vector_element : inner_pair.second) {
    //         int vector_key = vector_element.first;
    //         cout << "\t\tVector Key: " << vector_key << endl;
    //
    //         double first_double = vector_element.second.first;
    //         double second_double = vector_element.second.second;
    //         cout << "\t\tFirst Double: " << first_double << ", Second Double: " << second_double << endl;
    //     }
    // }
    // }


}
