#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    vector<string> words; // 儲存以此節點結尾的所有單詞
};

class Trie {
public:
    Trie() : root(new TrieNode()) {}

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->words.push_back(word);
    }

    vector<string> findDoublets(const string& word) {
        vector<string> doublets;
        findDoubletsHelper(word, 0, root, 0, doublets);
        return doublets;
    }

private:
    TrieNode* root;

    void findDoubletsHelper(const string& word, int index, TrieNode* node, int changes, vector<string>& doublets) {
        if (changes > 1) return; // 超過一個字母不同，直接返回

        if (index == word.size()) {
            if (changes == 1) { // 僅當有且只有一個不同字母時，加入雙字組
                doublets.insert(doublets.end(), node->words.begin(), node->words.end());
            }
            return;
        }

        // 遍歷所有子節點
        for (const auto& [c, child] : node->children) {
            findDoubletsHelper(word, index + 1, child, changes + (c != word[index]), doublets);
        }
    }
};

// 單向 BFS 尋找最短路徑
vector<string> bfsShortestPath(const string& start, const string& end, 
                               const unordered_map<string, vector<string>>& graph) {
    queue<vector<string>> q;  // 每個節點存當前路徑
    unordered_set<string> visited;  // 記錄訪問過的單詞
    q.push({start});
    visited.insert(start);

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();
        string current = path.back();

        if (current == end) return path; // 到達終點

        for (const string& neighbor : graph.at(current)) {
            if (!visited.count(neighbor)) {
                visited.insert(neighbor);
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }

    return {}; // 無解
}

int main() {
    vector<string> dictionary;
    unordered_map<string, vector<string>> graph;
    string word;

    // 讀取字典
    while (getline(cin, word) && !word.empty()) {
        dictionary.push_back(word);
    }

    // 建立 Trie 並構建圖
    Trie trie;
    for (const string& word : dictionary) {
        trie.insert(word);
    }

    for (const string& word : dictionary) {
        graph[word] = trie.findDoublets(word);
    }

    // 處理單詞對
    string line;
    bool firstCase = true;
    while (getline(cin, line) && !line.empty()) {
        if (!firstCase) cout << "\n";
        firstCase = false;

        stringstream ss(line);
        string start, end;
        ss >> start >> end;

        if (!graph.count(start) || !graph.count(end)) {
            cout << "No solution.\n";
            continue;
        }

        vector<string> path = bfsShortestPath(start, end, graph);
        if (path.empty()) {
            cout << "No solution.\n";
        } else {
            for (const string& p : path) cout << p << "\n";
        }
    }

    return 0;
}
