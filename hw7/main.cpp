/*  鄒雨笙 F64081070 程式設計二 第7次作業 2023/6/21

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <vector>
#include <string> // for using stoi
#include <utility> // for using pairs 
#include <unordered_map>
using namespace std;

// 宣告用來開啟corpus.txt檔案的副程式
void parseCorpus(char* &corpus, unordered_map<int, vector<string> > &c);
// 宣告用來開啟query.txt檔案的副程式
void parseQuery(char* &query, unordered_map<int, vector<string> > &q);
// 宣告用來將string轉換成int的副程式
void stringToNum(unordered_map<int, vector<string> > &corpus, unordered_map<int, vector<int> > &numCorpus);
// 宣告用來計算各個query word的IDF(Inverse Document Frequency)的副程式
void calculateIDF(unordered_map<int, vector<int> > &numQuery, unordered_map<int, vector<int> > &numCorpus, map <int, vector< pair<int,pair<double, double> > > > &storeIDF);
// 宣告計算每列query其有search到的corpus列其前3個IDF值最高的副程式
void findTopKeyWords(unordered_map<int, vector<int> > &numCorpus, map<int, vector< pair<int, pair<double, double> > > > &storeIDF, map <int, map<int, vector< pair<int, pair<double, double> > > > > &storeKeyWord); 
// 呼叫計算每列query其有search到的corpus列的keyword的副程式
void calculateRank(map <int, map<int, vector< pair<int, pair<double, double> > > > > &storeKeyWord, map <int, map<int, double> > &result); 
// 宣告用來sort storeSumIDF的副程式
void sortSumIDF(map<int, map<int, double> > &storeSumIDF, map<int, vector< pair<int, double > > > &sortedSumIDF);

int main(int argc, char *argv[]) {
    
    // ----------------- 以下為宣告變數之用 -----------------

    // 宣告用以儲存corpus資料
    unordered_map<int, vector<string> > corpus; 
    // 宣告用以儲存query資料
    unordered_map<int, vector<string> > query; 
    // 宣告用以儲存轉換成數字的corpus資料
    unordered_map<int, vector<int> > numCorpus; 
    // 宣告用以儲存轉換成數字的query資料
    unordered_map<int, vector<int> > numQuery; 

    // 宣告用以儲存各個query word IDF的map
    map<int, vector< pair<int, pair<double, double> > > > storeIDF;
    // 宣告用以儲存search到的corpus列的keywords並以降序排列的map
    map <int, map<int, vector< pair<int, pair<double, double> > > > > storeKeyWord;
    // 宣告用以儲存各個corpus列的rank(tf*idf)的map
    map <int, map<int, double> > result;

    // ----------------- 以下為呼叫函式之用 -----------------

    // 呼叫用來讀取corpus.txt檔案的副程式
    parseCorpus(argv[1], corpus); 
    // 呼叫用來讀取query.txt檔案的副程式
    parseQuery(argv[2], query); 

    // for (const auto& kv : corpus) {
    //     std::cout << "Key: " << kv.first << ", Values: ";
    //     for (const auto& str : kv.second) {
    //         std::cout << str << " ";
    //     }
    //     std::cout << "\n";
    // }

    // 呼叫用來將string轉換成int的副程式
    stringToNum(corpus, numCorpus);
    // 呼叫用來將string轉換成int的副程式
    stringToNum(query, numQuery);
    // A checkpoint for numCorpus
    // cout << "A checkpoint for numCorpus" << endl;
    // for (const auto& kv : numCorpus) {
    //     cout << "Key: " << kv.first << "\nValues: ";
    //     for (const auto& val : kv.second) {
    //         std::cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    // // A checkpoint for numQuery
    // cout << "A checkpoint for numQuery" << endl;
    // for (const auto& kv : numQuery) {
    //     cout << "Key: " << kv.first << "\nValues: ";
    //     for (const auto& val : kv.second) {
    //         std::cout << val << " ";
    //     }
    //     cout << "\n";
    // }

    // 呼叫用來計算各個query word的IDF(Inverse Document Frequency)的副程式
    calculateIDF(numQuery, numCorpus, storeIDF);
    // A checkpoint for storeIDF
    // cout << "IDF:" << endl;
    // for (const auto& pair : storeIDF) {
    //     std::cout << "Key: " << pair.first << ", Value: ";
    //     cout << "{ ";
    //     for (const auto& umap : pair.second) {
    //         cout << "(" << umap.first << "," << umap.second << ") ";
    //     }
    //     cout << "} ";
    //
    //     cout << "\n";
    // }
    // cout << endl;

    // 呼叫計算每列query其有search到的corpus列的keyword的副程式
    findTopKeyWords(numCorpus, storeIDF, storeKeyWord); 

    // 以下函式未定義

    // 呼叫算出storeKeyWord的rank的副程式
    calculateRank(storeKeyWord, result);

    // Print the result
    // cout << "Result:" << endl;
    // int stopCount = stoi(argv[3]);
    // for (const auto& kv : sortedSumIDF) {
    //     int count = 0;
    //     for (auto pair = kv.second.begin(); pair != kv.second.end(); ++pair) {
    //         if (count >= stopCount) break; // Stop printing after stopCount keys
    //
            // Print space only if it's not the first element
            // if (count != 0) {
            //     cout << " ";
            // }

            // If the second value is 0, print -1 and skip the first value
    //         if (pair->second == 0) {
    //             cout << "-1";
    //         } else {
    //             cout << pair->first;
    //         }
    //
    //         ++count;
    //     }
    //     cout << "\n";
    // }

    return 0;
}
