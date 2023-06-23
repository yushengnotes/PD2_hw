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

std::string replaceSubstring(std::string str, const std::string& from, const std::string& to) {
    size_t startPos = 0;
    while((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

// Function to process the word
string processWord(string word) {
    word.erase(remove(word.begin(), word.end(), '('), word.end());
    word.erase(remove(word.begin(), word.end(), ')'), word.end());
    word.erase(remove(word.begin(), word.end(), '?'), word.end());
    word.erase(remove(word.begin(), word.end(), '.'), word.end());
    word.erase(remove(word.begin(), word.end(), '['), word.end());
    word.erase(remove(word.begin(), word.end(), ']'), word.end());
    word.erase(remove(word.begin(), word.end(), '{'), word.end());
    word.erase(remove(word.begin(), word.end(), '}'), word.end());
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
    word.erase(remove(word.begin(), word.end(), '*'), word.end());
    word.erase(remove(word.begin(), word.end(), '`'), word.end());
    word.erase(remove(word.begin(), word.end(), '#'), word.end());
    word.erase(remove(word.begin(), word.end(), '|'), word.end());
    word = replaceSubstring(word, "G⃗", "g");
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
        word.erase(pos, target4.length());
    }
    const string target5 = "µ";
    // Loop while we can still find the target string
    while((pos = word.find(target5)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target5.length());
    }
    const string target6 = "3-µ";
    // Loop while we can still find the target string
    while((pos = word.find(target6)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target6.length());
    }
    const string target7 = "μ";
    // Loop while we can still find the target string
    while((pos = word.find(target7)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target7.length());
    }
    const string target8 = "α";
    // Loop while we can still find the target string
    while((pos = word.find(target8)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target8.length());
    }
    const string target9 = "≤";
    // Loop while we can still find the target string
    while((pos = word.find(target9)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target9.length());
    }
    const string target10 = "θ";
    // Loop while we can still find the target string
    while((pos = word.find(target10)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target10.length());
    }
    const string target11 = "∂";
    // Loop while we can still find the target string
    while((pos = word.find(target11)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target11.length());
    }
    const string target12 = "−";
    // Loop while we can still find the target string
    while((pos = word.find(target12)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target12.length());
    }
    const string target13 = "";
    // Loop while we can still find the target string
    while((pos = word.find(target13)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target13.length());
    }
    const string target14 = "√";
    // Loop while we can still find the target string
    while((pos = word.find(target14)) != string::npos){
        // Remove the target string from the source string
        word.erase(pos, target14.length());
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
