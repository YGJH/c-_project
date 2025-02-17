#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define MAXSIZE 25143  // 最大單詞數量

// 判斷兩個單詞是否只差一個字母（僅適用於相同長度的單詞）
bool doublets(const string &a, const string &b) {
    if (a.length() != b.length()) return false;
    int diff = 0;
    for (int i = 0; i < (int)a.length(); i++) {
        if (a[i] != b[i]) {
            diff++;
            if (diff > 1) return false;
        }
    }
    return (diff == 1);
}

// 無解時輸出的函式
void no_solution() {
    cout << "No solution." << "\n";
}

// 全域資料結構
static string points[MAXSIZE];  // 存放字典中的單詞
static vector<int> edges[MAXSIZE];  // 鄰接表：每個單詞可轉換到哪些索引
static int parentT[MAXSIZE];  // BFS 中用來記錄前驅，用以回溯路徑
static bool discovered[MAXSIZE];  // BFS 中記錄是否訪問過
static int n = 0;  // 字典中單詞數量

// 輔助函式：回溯並輸出最短路徑
// 修改後：當 cur == start 時直接輸出起點，確保完整路徑輸出
void find_path_point(string *words, int parent[], int start, int cur) {
    if (cur == start) {
        cout << words[start] << "\n";
        return;
    }
    find_path_point(words, parent, start, parent[cur]);
    cout << words[cur] << "\n";
}

// 執行 BFS 搜尋最短路徑，並建立 parentT 陣列
bool BFS(int start, int end) {
    memset(discovered, false, sizeof(discovered));
    memset(parentT, -1, sizeof(parentT));
    
    queue<int> q;
    discovered[start] = true;
    q.push(start);
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == end)
            return true;
        for (int v : edges[u]) {
            if (!discovered[v]) {
                discovered[v] = true;
                parentT[v] = u;
                q.push(v);
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    // 讀取字典，直到遇到空行為止
    string line;
    while (getline(cin, line) && !line.empty()) {
        points[n++] = line;
    }
    
    // 建立鄰接表：兩個只差一個字母的單詞互相連通
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (doublets(points[i], points[j])) {
                edges[i].push_back(j);
                edges[j].push_back(i);
            }
        }
    }
    
    // 讀取查詢，每行包含一對單詞
    bool firstCase = true;
    while (getline(cin, line)) {
        if(line.size() == 0) continue; // 忽略空行
        istringstream iss(line);
        string s1, s2;
        iss >> s1 >> s2;
        if (s1 == "" || s2 == "") continue;
        
        // 找出字典中對應 s1 與 s2 的索引
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n; i++) {
            if (points[i] == s1) idx1 = i;
            if (points[i] == s2) idx2 = i;
            if (idx1 != -1 && idx2 != -1) break;
        }
        
        // 若找不到或單詞長度不同，輸出無解
        if (idx1 == -1 || idx2 == -1 || s1.size() != s2.size()) {
            if (!firstCase) cout << "\n";
            firstCase = false;
            no_solution();
            continue;
        }
        
        // 執行 BFS 搜尋最短轉換序列
        bool foundPath = BFS(idx1, idx2);
        
        if (!firstCase) cout << "\n";
        firstCase = false;
        if (!foundPath) {
            no_solution();
        } else {
            // 回溯並輸出最短路徑（包含起點）
            find_path_point(points, parentT, idx1, idx2);
        }
    }
    return 0;
}
