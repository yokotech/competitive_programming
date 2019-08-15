#include<bits/stdc++.h>
/*
g++ -std=c++11 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG 
http://drken1215.hatenablog.com/entry/2018/06/08/210000
*/
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

const int MAX = 510000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
    // 前処理
    COMinit();

    // 計算例
    cout << COM(100000, 50000) << endl;
}