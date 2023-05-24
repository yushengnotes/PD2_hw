/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

    此副程式parseCSV()用來讀取csv檔案，並將檔案中的資料存入
    vector<Employee>中
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// Function to process the word
string processWord(string word) {
    word.erase(remove(word.begin(), word.end(), '-'), word.end());
    word.erase(remove(word.begin(), word.end(), '('), word.end());
    word.erase(remove(word.begin(), word.end(), ')'), word.end());
    word.erase(remove_if(word.begin(), word.end(), ::isdigit), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

void parseCorpus(char* &corpus, map<int, vector<string> > &c) { 
    // Declare an ifstream object infile
    ifstream infile;
    // Open the file named corpus in the current directory
    infile.open(corpus);
    if (!infile) {
        cerr << "error: unable to open the input file: " << corpus << endl;
    }

    string line, field;
    
    // Store the data from the file in map<int, vector<string> > corpus
    while (getline(infile, line)) {
        istringstream ss(line);
        vector<string> fields;
        string token;
        bool firstField = true;
        for(char& c : line){
            // Added '&' to delimiters and removed '-'
            if(c == ' ' || c == '"' || c == ',' || c == ';' || c == ':' || c == '&'){
                if (!token.empty()) {
                    // Process the token before adding it to fields
                    if (!firstField) {
                        token = processWord(token);
                    }
                    fields.push_back(token);
                    token.clear();
                }
                firstField = false;
            }
            else{
                token += c;
            }
        }
        // Process and push the last token if it's not empty
        if (!token.empty()){
            if (!firstField) {
                token = processWord(token);
            }
            fields.push_back(token);
        }
        int key = stoi(fields[0]);
        c.insert({key, fields});
    }
    
    infile.close();    
}

