
// problem link: https://atcoder.jp/contests/abc118/tasks/abc118_d?lang=en
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("inline")
#pragma GCC optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#pragma G++ optimize(3)
#pragma G++ optimize("fast-math")
#pragma G++ optimize("Ofast")
#pragma G++ optimize("inline")
#pragma G++ optimize("-bmi -bmi2 -popcnt -abm -lzcnt -tbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm -mmmx -msse -msse2 -msse3 -mssse3 -msse4.1 -msse4.2 -mavx -mavx2 -mfma -mbmi -mbmi2 -mpopcnt -mabm -mlzcnt -mtbm")
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool w = 0; char c ;
template<typename T>
inline void re(T &a) {
c = getchar();a = 0; while(c < '0' || c > '9') w|=(c=='-') , c=getchar();
while(c >= '0' && c <= '9') a = (a<<1) + (a<<3) + (c&15) , c = getchar();
if(w) a=-a;
return ;}
char st[30] ; int kkkk = 0;
template<typename T>
inline void wr(T a) {
if(a==0) { putchar('0') ; return ;}
if(a<0)putchar('-') , a=-a;
while(a) { st[kkkk++] = a % 10 + '0' , a/=10;}
while(kkkk) { putchar(st[--kkkk]);}
return ;}
int main(){
    int V, M;
    re(V); re(M);
    vector<int> availableDigits(M);
    for (int i = 0; i < M; i++){
        // cin >> availableDigits[i];
        re(availableDigits[i]);
    }
    
    // 標準火柴棒成本對應（1~9）
    int costMapping[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    
    // dp[v] 表示用 v 根火柴棒能拼出的最大位數；不可拼出時用 -1000000 表示
    const int MINF = -1000000;
    vector<int> dp(V+1, MINF);
    dp[0] = 0;
    for (int v = 0; v <= V; v++){
        if(dp[v] < 0) continue;
        for (int &d : availableDigits) {
            int cost = costMapping[d];
            if(v + cost <= V){
                dp[v + cost] = max(dp[v + cost], dp[v] + 1);
            }
        }
    }
    
    int maxDigits = dp[V];
    // if(maxDigits <= 0){
    //     // cout << 0 << "\n";
    //     putchar('0');
    //     return 0;
    // }
    
    // 為了貪心選位，將可用數字降序排序
    sort(availableDigits.begin(), availableDigits.end(), greater<int>());
    
    string ans;
    int remaining = V;
    // 從最高位到最低位選出每一位的數字
    for (int i = 0; i < maxDigits; i++){
        // 對每一位，依降序檢查候選數字
        for (int &d : availableDigits) {
            int cost = costMapping[d];
            if(remaining < cost) continue;
            // 如果選擇 d 之後，剩下的火柴棒能剛好拼出剩餘位數，即 dp[remaining - cost] == dp[remaining] - 1
            if(dp[remaining - cost] == dp[remaining] - 1){
                // ans.push_back('0' + d);
                putchar('0'+d);
                remaining -= cost;
                break;
            }
        }
    }
    
    // cout << ans << "\n";
    return 0;
}
