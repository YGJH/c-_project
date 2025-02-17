#include <bits/stdc++.h>
using namespace std;

// We store words in groups by their length.
// For each length `len`, we have:
//   1. A vector of all words of length `len`.
//   2. A map<string,int> for quick word->index lookup in that group.
//   3. An adjacency list that links each index to neighbors differing by 1 character.

static const int INF = INT_MAX;

// For each group (by length), we store these:
unordered_map<int, vector<string>> groupWords;          // length -> vector of words
unordered_map<int, unordered_map<string,int>> wordIdx;  // length -> (word -> index)
unordered_map<int, vector<vector<int>>> adj;            // length -> adjacency list

// Build adjacency for words of a specific length group.
// O(G * L * 26) where G is #words in that group, L is word length.
void buildAdjForGroup(int len) {
    auto &words = groupWords[len];
    int n = (int)words.size();
    adj[len].resize(n);

    // For each word, try replacing each character with [a..z].
    // If the replaced word exists in the dictionary, add an edge.
    for (int i = 0; i < n; i++) {
        string w = words[i];
        for (int pos = 0; pos < len; pos++) {
            char orig = w[pos];
            for (char c = 'a'; c <= 'z'; c++) {
                if (c == orig) continue;
                w[pos] = c;
                // Check if w is in dictionary (same length).
                if (wordIdx[len].count(w)) {
                    int neighbor = wordIdx[len][w];
                    adj[len][i].push_back(neighbor);
                }
            }
            w[pos] = orig; // revert
        }
    }
}

// BFS to find the shortest path in the group of a certain length.
// Returns the path from `start` to `end` index. If no path, returns empty vector.
vector<int> bfsShortestPath(int len, int start, int end) {
    int n = (int)groupWords[len].size();
    vector<int> dist(n, INF), fa(n, -1);
    vector<bool> visited(n, false);

    queue<int>q;
    dist[start] = 0;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = true;
        if (u == end) break; // found the end word

        for (int v : adj[len][u]) {
            if (!visited[v] && dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                fa[v] = u;
                q.push(v);
            }
        }
    }

    if (!visited[end]) {
        // No path found
        return {};
    }

    // Reconstruct path
    vector<int> path;
    for (int cur = end; cur != -1; cur = fa[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 1) Read dictionary until blank line
    while(true) {
        string word;
        if(!std::getline(cin, word)) break;       // no more input
        if(word.empty()) break;                  // blank line -> dictionary ends
        int len = (int)word.size();
        groupWords[len].push_back(word);
    }

    // 2) For each length group, build (word -> index) map
    for (auto &kv : groupWords) {
        int len = kv.first;
        auto &words = kv.second;
        // Build map from word -> index
        for (int i = 0; i < (int)words.size(); i++) {
            wordIdx[len][words[i]] = i;
        }
    }

    // 3) Build adjacency for each length group
    for (auto &kv : groupWords) {
        int len = kv.first;
        // prepare adjacency vector
        adj[len].clear();
        buildAdjForGroup(len);
    }

    // 4) Read queries until EOF
    bool firstOutput = true;
    while(true) {
        string startWord, endWord;
        if(!(cin >> startWord >> endWord)) break; // no more queries
        // Print a blank line before each case except the first
        if(!firstOutput) cout << '\n';
        firstOutput = false;

        // If not in dictionary or lengths differ -> no solution
        int lenA = (int)startWord.size();
        int lenB = (int)endWord.size();
        if (lenA != lenB ||
            !wordIdx[lenA].count(startWord) ||
            !wordIdx[lenB].count(endWord)) {
            cout << "No solution.\n";
            continue;
        }

        // BFS in the group for this length
        int startIdx = wordIdx[lenA][startWord];
        int endIdx   = wordIdx[lenB][endWord];
        vector<int> path = bfsShortestPath(lenA, startIdx, endIdx);

        if (path.empty()) {
            cout << "No solution.\n";
        } else {
            // Print the actual words in the path
            auto &words = groupWords[lenA];
            for (int idx : path) {
                cout << words[idx] << '\n';
            }
        }
    }
    return 0;
}
