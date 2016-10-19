/*
208. Implement Trie (Prefix Tree)

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class TrieNode {
    vector<TrieNode*> v_;
public:
    bool terminal = false;
    TrieNode() {}

    TrieNode* get(int i) {
        if (i >= v_.size()) v_.resize(i+1);
        return v_[i];
    }

    TrieNode* set(int i, TrieNode *node) {
        if (i >= v_.size()) v_.resize(i+1);
        return v_[i] = node;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *node = root;
        for (auto c : word) {
            TrieNode *t = node->get(c - 'a');
            if (t) {
                node = t;
            } else {
                node = node->set(c - 'a', new TrieNode());
            }
        }
        node->terminal = true;
    }

    bool search(string word) {
        TrieNode *node = root;
        for (auto c : word) {
            TrieNode *t = node->get(c - 'a');
            if (t) {
                node = t;
            } else {
                return false;
            }
        }
        return node->terminal;
    }

    bool startsWith(string prefix) {
        TrieNode *node = root;
        for (auto c : prefix) {
            TrieNode *t = node->get(c - 'a');
            if (t) {
                node = t;
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
};


int main() {
    Trie t;
    t.insert("foobar");
    t.insert("foofoo");
    assert(!t.search("foo"));
    assert(t.startsWith("foo"));
    assert(t.search("foobar"));
    t.insert("foo");
    assert(t.search("foo"));
    cout << "All done." << endl;
}
