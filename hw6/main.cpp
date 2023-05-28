/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此為主程式main，其會呼叫parseCorpus(), parseQuery()副程式以
    讀取.txt檔案，並呼叫數個副程式，最後將結果列印到主控台(console)
    
*/

#include <iostream>
#include <map>
#include <vector>
#include <utility> // for using pairs 
#include <unordered_map>
using namespace std;

// 宣告用來開啟corpus.txt檔案的副程式
void parseCorpus(char* &corpus, map<int, vector<string> > &c);
// 宣告用來開啟query.txt檔案的副程式
void parseQuery(char* &query, map<int, vector<string> > &q);
// 宣告用來將string轉換成int的副程式
void stringToNum(map<int, vector<string> > &corpus, map<int, vector<int> > &numCorpus);
// 宣告用來計算各個query word的IDF(Inverse Document Frequency)的副程式
void calculateIDF(map<int, vector<int> > &numQuery, map<int, vector<int> > &numCorpus, map <int, vector< pair<int,double> > > &storeIDF);
// 宣告用來計算每列query其有search到的corpus列其IDF和的副程式
void calculateSumIDF(map<int, vector<int> > &numCorpus, map<int, vector< pair<int, double> > > &storeIDF, map <int, map<int, double> > &storeSumIDF);
// 宣告用來sort storeSumIDF的副程式
void sortSumIDF(map<int, map<int, double> > &storeSumIDF, map<int, vector< pair<int, double > > > &sortedSumIDF);

int main(int argc, char *argv[]) {
    
    // 以下為宣告變數之用 -------------------------

    // 宣告用以儲存corpus資料
    map<int, vector<string> > corpus; 
    // 宣告用以儲存query資料
    map<int, vector<string> > query; 
    // 宣告用以儲存轉換成數字的corpus資料
    map<int, vector<int> > numCorpus; 
    // 宣告用以儲存轉換成數字的query資料
    map<int, vector<int> > numQuery; 

    // 宣告用以儲存各個query word IDF的map
    map<int, vector< pair<int,double> > > storeIDF;
    // 宣告用以儲存各個query word sum of IDF的map
    map<int, map<int, double> > storeSumIDF; 
    // 宣告用來儲存sorted storeSumIDF的map
    map<int, vector< pair<int, double > > > sortedSumIDF;

    // 以下為呼叫函式之用 -------------------------

    // 呼叫用來讀取corpus.txt檔案的副程式
    parseCorpus(argv[1], corpus); 
    // 呼叫用來讀取query.txt檔案的副程式
    parseQuery(argv[2], query); 

    // 呼叫用來將string轉換成int的副程式
    stringToNum(corpus, numCorpus);
    // 呼叫用來將string轉換成int的副程式
    stringToNum(query, numQuery);
    // A checkpoint for numCorpus
    // for (const auto& kv : numCorpus) {
    //     cout << "Key: " << kv.first << "\nValues: ";
    //     for (const auto& val : kv.second) {
    //         std::cout << val << " ";
    //     }
    //     cout << "\n";
    // }
    // A checkpoint for numQuery
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

    // 呼叫用來計算每列query其有search到的corpus列其IDF和的副程式
    calculateSumIDF(numCorpus, storeIDF, storeSumIDF);
    // A checkpoint for storeSumIDF
    // cout << "Sum of IDF:" << endl;
    // for (const auto& outerPair : storeSumIDF) {
    //     cout << "Key: " << outerPair.first << ", Value: { ";
    //
    //     for (const auto& innerPair : outerPair.second) {
    //         cout << "{" << innerPair.first << "," << innerPair.second << "} ";
    //     }
    //
    //     cout << "}\n";
    // }
    // cout << endl;

    // 呼叫用來sort storeSumIDF的副程式
    sortSumIDF(storeSumIDF, sortedSumIDF);
    // A checkpoint for sortedSumIDF
    // cout << "Sorted Sum of IDF:" << endl;
    // for (const auto& kv : sortedSumIDF) {
    //     cout << "Key: " << kv.first << ", Values: ";
    //     for (const auto& pair : kv.second) {
    //         cout << "(" << pair.first << ", " << pair.second << ") ";
    //     }
    //     cout << "\n";
    // }
    // cout << endl;

    // Print the result
    // cout << "Result:" << endl;
    for (const auto& kv : sortedSumIDF) {
        int count = 0;
        for (auto pair = kv.second.begin(); pair != kv.second.end(); ++pair) {
            if (count >= 3) break; // Stop printing after 3 keys

            // If the second value is 0, print -1 and skip the first value
            if (pair->second == 0) {
                cout << "-1";
            } else {
                cout << pair->first;
            }

            // Print space only if it's not the last element
            if (next(pair) != kv.second.end() && count < 2) {
                cout << " ";
            }
            ++count;
        }
        cout << "\n";
    }

    return 0;
}
