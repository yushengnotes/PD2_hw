/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map> 
#include <vector> 
#include <utility> // for using pairs 
using namespace std;

int searchOccurNum(int num, const map<int, vector<int> > &numCorpus) {

    int occurNum = 0;
    bool flag = false;
    vector<bool> flags;

    for (const auto& key : numCorpus) {
        for(const auto& value : key.second) {
            if(value == num) {
                flag = true;
            }
        }
        flags.push_back(flag);
        flag = false;
    }
    
    for (const auto& flag : flags) {
        if (flag == true) {
            occurNum++;
        }
    }

    return occurNum;

}
