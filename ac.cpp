#include <bits/stdc++.h>
using namespace std;

static const int INF = INT_MAX;

// 按單詞長度分組：每個長度存一個單詞列表
unordered_map<int, vector<string>> groupWords;
// 每個長度的單詞對應索引（快速查找）
unordered_map<int, unordered_map<string, int>> wordIdx;
// 每個長度單詞的鄰接表：兩個單詞如果只差一個字母則互相連通
unordered_map<int, vector<vector<int>>> adj;

// 對於長度為 len 的單詞群，建構鄰接圖，時間 O(G * L * 26)
void buildAdjForGroup(int len) {
    auto &words = groupWords[len];
    int n = words.size();
    adj[len].resize(n);
    for (int i = 0; i < n; i++) {
        string w = words[i];
        for (int pos = 0; pos < len; pos++) {
            char orig = w[pos];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == orig) continue;
                w[pos] = c;
                if (wordIdx[len].count(w))
                    adj[len][i].push_back(wordIdx[len][w]);
            }
            w[pos] = orig;
        }
    }
}

// 在長度為 len 的單詞群中，用 BFS 求從 start 到 end 的最短路徑（返回索引序列）
vector<int> bfsShortestPath(int len, int start, int end) {
    int n = groupWords[len].size();
    vector<int> dist(n, INF), parent(n, -1);
    vector<bool> visited(n, false);
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    while (!q.empty()){
        int u = q.front();
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        if(u == end) break;
        for(int v : adj[len][u]) {
            if(!visited[v] && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }
    if(!visited[end])
        return {};
    vector<int> path;
    for(int cur = end; cur != -1; cur = parent[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    return path;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 讀取字典：直到遇到空行
    string word;
    while(getline(cin, word) && !word.empty()){
        int len = word.size();
        groupWords[len].push_back(word);
    }
    
    // 為每個長度建立「單詞 -> 索引」的映射
    for(auto &kv : groupWords){
        int len = kv.first;
        auto &words = kv.second;
        for(int i = 0; i < words.size(); i++){
            wordIdx[len][words[i]] = i;
        }
    }
    
    // 為每個長度建立鄰接圖
    for(auto &kv : groupWords){
        int len = kv.first;
        adj[len].clear();
        buildAdjForGroup(len);
    }
    
    // 讀取查詢，每行包含兩個單詞，輸出轉換序列（或 "No solution."）
    bool firstCase = true;
    string startWord, endWord;
    while(cin >> startWord >> endWord){
        if(!firstCase)
            cout << "\n";
        firstCase = false;
        int lenA = startWord.size(), lenB = endWord.size();
        // 若兩單詞長度不同或不在字典中則無解
        if(lenA != lenB || !wordIdx[lenA].count(startWord) || !wordIdx[lenB].count(endWord)){
            cout << "No solution.\n";
            continue;
        }
        int startIdx = wordIdx[lenA][startWord], endIdx = wordIdx[lenA][endWord];
        vector<int> path = bfsShortestPath(lenA, startIdx, endIdx);
        if(path.empty()){
            cout << "No solution.\n";
        } else {
            for(int idx : path)
                cout << groupWords[lenA][idx] << "\n";
        }
    }
    return 0;
}
