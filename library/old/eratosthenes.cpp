#include<bits/stdc++.h>
using namespace std;

vector<int> eratosthenes(int n){// n以下の素数を全てvectorに入れて返す
    if(n < 2){
        vector<int> v(0);
        return v;
    }
    int cnt = 0;
    vector<int> v(n + 1, 1);// flag vector 素数なら1
    v[0] = 0;
    v[1] = 0;
    for(int i = 2; i <= n; i++){
        if(v[i] == 0) continue;// 素数じゃなかったらとばす
        cnt++;
        for(int j = 2; j <= n/i; j++){
            v[i * j] = 0;
        }
    }

    vector<int> ans(cnt);// サイズわかってる状態でvector作ることで高速化?
    int it = 0;
    for(int i = 2; i <= n; i++){
        if(v[i] == 1){
            ans[it] = i;
            it++;
        }
    }
    return ans;
}