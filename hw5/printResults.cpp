/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

void printResults(map<int, vector<int> > &processedResults) {
    for(const auto &pair : processedResults) {
        // A checkpoint
        // cout << "Key: " << pair.first << ", Values: ";
        if (pair.second.empty()) {
            cout << "-1";
        } else {
            for(size_t i = 0; i < pair.second.size(); ++i) {
                cout << pair.second[i];
                if(i != pair.second.size() - 1) // if not the last element
                    cout << " ";
            }
        }
        cout << endl;
    }
}
