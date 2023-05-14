/*  鄒雨笙 F64081070 程式設計二 第5次作業 2023/5/15

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <map>
#include <vector>

void setResults(map<int, map<int, vector<bool> > > &results, vector<int> &processedResults) {

    for (auto it = results.begin(); it != results.end(); ++it) {
        for (auto it_map = (it->second).begin(); it_map != (it->second).end(); ++it_map) {
            for (auto it_vec = it_map.begin(); it_vec != it_map.end(); ++it_vec) {

        cout << "Printing Trie for index " << it->first << ":" << endl;
        printTrie(it->second);
    }


}
