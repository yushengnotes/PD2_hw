// TrieNode.h
#ifndef TRIENODE_H
#define TRIENODE_H

#include <unordered_map>

struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
};


#endif

