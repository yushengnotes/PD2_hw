/*  鄒雨笙 F64081070 程式設計二 第6次作業 2023/5/29

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// Function to process the word
string processWord(string word) {
    word.erase(remove(word.begin(), word.end(), '('), word.end());
    word.erase(remove(word.begin(), word.end(), ')'), word.end());
    word.erase(remove(word.begin(), word.end(), '?'), word.end());
    word.erase(remove(word.begin(), word.end(), '.'), word.end());
    word.erase(remove(word.begin(), word.end(), '['), word.end());
    word.erase(remove(word.begin(), word.end(), ']'), word.end());
    word.erase(remove(word.begin(), word.end(), '-'), word.end());
    word.erase(remove(word.begin(), word.end(), '+'), word.end());
    word.erase(remove(word.begin(), word.end(), '&'), word.end());
    word.erase(remove(word.begin(), word.end(), ';'), word.end());
    word.erase(remove(word.begin(), word.end(), ':'), word.end());
    word.erase(remove(word.begin(), word.end(), '!'), word.end());
    word.erase(remove(word.begin(), word.end(), '\''), word.end());
    word.erase(remove(word.begin(), word.end(), '/'), word.end());
    word.erase(remove(word.begin(), word.end(), ','), word.end());
    word.erase(remove(word.begin(), word.end(), '/'), word.end());
    word.erase(remove(word.begin(), word.end(), '\\'), word.end());
    word.erase(remove(word.begin(), word.end(), '"'), word.end());
    const string target = "®";
    size_t pos = string::npos;
    // Loop while we can still find the target string
    while((pos = word.find(target)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target.length());
    }
    const string target2 = "“";
    // Loop while we can still find the target string
    while((pos = word.find(target2)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target2.length());
    }
    const string target3 = "”";
    // Loop while we can still find the target string
    while((pos = word.find(target3)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target3.length());
    }
    const string target4 = "∞";
    // Loop while we can still find the target string
    while((pos = word.find(target4)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target3.length());
    }
    
    word.erase(remove_if(word.begin(), word.end(), ::isdigit), word.end());
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    return word;
}

void parseCorpus(char* &corpus, unordered_map<int, vector<string> > &c) { 
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
            if(c == ' '){
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

