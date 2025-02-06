#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// 全局變量：數組長度 n、分段數 k，數組 a
int n, k;
vector<ll> a;
 
// 令 m = k/2 為偶數段的數量（因 k 為偶數）。
 
// 狀態定義：我們只“決策”偶數段（S2, S4, …, S_{2*m}），
// 假設奇數段我們均採取最小長度 1（這樣留給偶數段最多靈活性）。
// 設 f(seg, pos, cur) 表示：當前處理第 seg 個偶數段（seg從 1 到 m），
// 且目前已經在偶數段串連形成的序列 b 中匹配了 cur 個數字（即 b[1..cur] = 1,2,…,cur），
// 現在可從 a 的下標 pos（1-index）開始選取當前偶數段（必須選非空區間），
// 在剩餘部分至少還能給後續所有段分配所需最少元素的情況下，
// 最終能達到的「成本」（即最先出現 b[i] ≠ i 的位置，下標 i，成本即 i）。
// 如果後續選取均使 b 正好匹配（最後還要附加一個 0，不匹配），則成本 = cur+1。
 
struct State {
    int seg; // 第 seg 個偶數段（1-index，1<=seg<=m）
    int pos; // 當前從 a 的這個位置開始選取
    int cur; // 已匹配（且保證 b[1..cur] = 1,2,…,cur）
};
 
struct StateHash {
    size_t operator()(const State &s) const {
        size_t res = 17;
        res = res * 31 + hash<int>()(s.seg);
        res = res * 31 + hash<int>()(s.pos);
        res = res * 31 + hash<int>()(s.cur);
        return res;
    }
};
 
bool operator==(const State &s1, const State &s2){
    return s1.seg == s2.seg && s1.pos == s2.pos && s1.cur == s2.cur;
}
 
// memo 用於備忘
unordered_map<State, int, StateHash> memo;
 
const int INF = 1e9;
 
// f(seg, pos, cur) 的遞歸函數：
// seg：當前要選取的偶數段的序號（1-index）
// pos：從 a 的該位置開始可以選取當前偶數段（a 下標從1開始）
// cur：目前 b 中已連續匹配的數字個數（即 b[1..cur] = 1,2,…,cur）
// m：偶數段總數（= k/2）， n：數組長度
// 返回從該狀態出發能獲得的最小成本（即 b 的第一個不匹配位置）
int f(int seg, int pos, int cur, int m, int n) {
    // 若已完成所有偶數段，則 b 長度為 cur，
    // 附加 0 之後，自然 b[cur+1] = 0 ≠ (cur+1)，故成本為 cur+1
    if(seg > m) return cur + 1;
    // 為了保證後續每段至少非空，計算從 pos 起至少需要分配的剩餘元素：
    int minRequired;
    if(seg < m)
        // 當前偶數段至少 1 + 後續奇數段（1個） + 每對剩下（偶+奇）各 1 個
        minRequired = 1 + 1 + 2 * (m - seg);
    else 
        minRequired = 1; // 最後一個偶數段只需要 1 個
    if(pos + minRequired - 1 > n) return INF; // 剩餘元素不足
 
    State st {seg, pos, cur};
    if(memo.find(st) != memo.end())
        return memo[st];
 
    int best = INF;
    // 偶數段可取的長度 L 必須滿足：從 pos 至 pos+L-1 分配給本段，並保證剩餘至少 minRequired 個元素
    int L_max = n - pos - (minRequired - 1) + 1; // 保證 pos+L_max-1 = n - (minRequired-1)
    // 試所有可能的 L
    for(int L = 1; L <= L_max; L++){
        int newCost = INF;
        // 模擬當前段取 a[pos ... pos+L-1]，這部分將接在 b 之後
        // 檢查該段中從位置 0 到 L-1（對應 b 中位置 cur+1, cur+2, …, cur+L）
        int t;
        for(t = 0; t < L; t++){
            // 若 a[pos+t-1]（因為 a 為 0-index）不等於 cur+t+1，則在 b 的第 (cur+t+1) 個位置產生不匹配，
            // 成本即 cur+t+1
            if(a[pos + t - 1] != (ll)(cur + t + 1)){
                newCost = cur + t + 1;
                break;
            }
        }
        if(t == L){
            // 如果本段所有元素都“正確匹配”，則更新 cur 為 cur+L
            int newCur = cur + L;
            // 接下來必須“用最短方案”選取後續奇數段：奇數段取 1 個元素
            int newPos = pos + L;
            if(seg < m){
                if(newPos > n) newCost = INF;
                else {
                    newPos++; // 為奇數段選 1 個元素
                    newCost = f(seg + 1, newPos, newCur, m, n);
                }
            } else {
                newCost = newCur + 1;
            }
        }
        best = min(best, newCost);
        // 由於我們希望成本儘可能小（最佳下界是1），若已達1可提前退出
        if(best == 1) break;
    }
 
    memo[st] = best;
    return best;
}
 
// 主函數：讀入多測例，對每個測例嘗試 S1（第一個奇數段）的不同最短選取（因為 S1 不影響 b，但會影響從哪開始選 S2）
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        a.resize(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int m = k / 2;  // 偶數段數量
        int bestAns = INF;
        // S1 為第一個奇數段，至少取1個元素，最多取 n - (k-1) 個（保證剩餘段均非空）
        int S1_min = 1, S1_max = n - (k - 1);
        // 枚舉 S1 可能的最短長度
        for (int L1 = S1_min; L1 <= S1_max; L1++){
            int pos = L1 + 1; // S2（第一個偶數段）從 a[pos] 開始
            memo.clear();
            int cur = 0; // 起初 b 還沒有任何元素
            int candidate = f(1, pos, cur, m, n);
            bestAns = min(bestAns, candidate);
            if(bestAns == 1) break;
        }
        cout << bestAns << "\n";
    }
    return 0;
}
