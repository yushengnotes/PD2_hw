/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <vector>

void processSearchMap(map<int, vector<bool> > &searchMap) {

    for (auto it = searchMap.begin(); it != searchMap.end(); ++it) {
        for (const auto& str : it->second) {

        if (it == false) {
            searchState.clean();
            searchState.push_back(false);
            break;
        }
    }
}
