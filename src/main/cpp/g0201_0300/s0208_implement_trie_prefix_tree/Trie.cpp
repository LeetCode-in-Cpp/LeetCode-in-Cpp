// #Medium #Top_100_Liked_Questions #Top_Interview_Questions #String #Hash_Table #Design #Trie
// #LeetCode_75_Trie #Level_2_Day_16_Design #Udemy_Trie_and_Heap #Top_Interview_150_Trie
// #Big_O_Time_O(word.length())_or_O(prefix.length())_Space_O(N)
// #2024_05_26_Time_57_ms_(37.76%)_Space_52.1_MB_(16.23%)

#include <string>
#include <vector>

class Trie {
private:
    struct TrieNode {
        std::vector<TrieNode*> children;
        bool isWord;

        TrieNode() : children(26, nullptr), isWord(false) {}
    };

    TrieNode* root;
    bool startWith;

    void insert(const std::string& word, TrieNode* node, int idx) {
        if (idx == word.length()) {
            node->isWord = true;
            return;
        }
        int index = word[idx] - 'a';
        if (node->children[index] == nullptr) {
            node->children[index] = new TrieNode();
        }
        insert(word, node->children[index], idx + 1);
    }

    bool search(const std::string& word, TrieNode* node, int idx) {
        if (idx == word.length()) {
            startWith = true;
            return node->isWord;
        }
        int index = word[idx] - 'a';
        if (node->children[index] == nullptr) {
            startWith = false;
            return false;
        }
        return search(word, node->children[index], idx + 1);
    }

public:
    Trie() : root(new TrieNode()), startWith(false) {}

    void insert(const std::string& word) {
        insert(word, root, 0);
    }

    bool search(const std::string& word) {
        return search(word, root, 0);
    }

    bool startsWith(const std::string& prefix) {
        search(prefix, root, 0);
        return startWith;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
