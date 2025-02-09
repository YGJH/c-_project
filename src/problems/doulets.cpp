#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#pragma G++ optimize(3)
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
// link : https://vjudge.net/problem/UVA-10150
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

// 檢查是否為雙字組
bool isDoublet(const string& a, const string& b) {
    if (a.size() != b.size()) return false;
    int diffCount = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) ++diffCount;
        if (diffCount > 1) return false;
    }
    return diffCount == 1;
}

// 基於哈希分組構建雙字組的圖
unordered_map<string, vector<string>> buildGraph(const vector<string>& words) {
    unordered_map<string, vector<string>> graph;
    for (const string& word : words) {
        graph[word] = {};  // 初始化節點
    }

    // 建立邊：兩個單詞如果是雙字組，則互相連接
    for (size_t i = 0; i < words.size(); ++i) {
        for (size_t j = i + 1; j < words.size(); ++j) {
            if (isDoublet(words[i], words[j])) {
                graph[words[i]].push_back(words[j]);
                graph[words[j]].push_back(words[i]);
            }
        }
    }
    return graph;
}

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

        // 如果到達目標單詞，返回路徑
        if (current == end) return path;

        // 遍歷所有相鄰的雙字組單詞
        for (const string& neighbor : graph.at(current)) {
            if (visited.count(neighbor) == 0) {
                visited.insert(neighbor);
                vector<string> newPath = path;
                newPath.push_back(neighbor);
                q.push(newPath);
            }
        }
    }

    return {};  // 無解
}

int main() {
    vector<string> dictionary;
    unordered_map<string, vector<string>> graph;
    string word;

    // 讀取字典
    while (getline(cin, word) && !word.empty()) {
        dictionary.push_back(word);
    }
    graph = buildGraph(dictionary);

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
