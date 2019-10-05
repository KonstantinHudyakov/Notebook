struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
    }
};

void insert(TrieNode *root, string s) {
    TrieNode *cur = root;
    for(auto &ch : s) {
        TrieNode *node = cur->children[ch];
        if(!node) {
            node = new TrieNode();
            cur->children[ch] = node;
        }
        cur = node;
    }
    cur->isEndOfWord = true;
}

bool contains(TrieNode *root, string s) {
    TrieNode *cur = root;
    for(auto &ch : s) {
        TrieNode *node = cur->children[ch];
        if(!node) {
            return false;
        }
        cur = node;
    }
    return cur->isEndOfWord;
}