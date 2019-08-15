#include<bits/stdc++.h>
/*
g++ -std=c++11 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG other_contests/codefes2017qualb/c.cpp
*/
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

vector<vector<int>> g;
vector<int> color;// 0: not visited, -1: white, 1: black

bool is_bipartite(int k){// 連結であることを前提とする
    bool rev = true;
    rep(i, g[k].size()){
        if(color[g[k][i]] == 0){// unvisited
            color[g[k][i]] = -color[k];
            if(!is_bipartite(g[k][i])){
                return false;
            }
        }else{
            if(color[g[k][i]] == color[k]){
                return false;
            }
        }
    }
    return rev;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);//おまじないでcin, cout早くする
    ll n, m;
    cin >> n >> m;
    g.resize(n);
    color.resize(n);
    rep(i, n){
        color[i] = 0;
    }
    rep(i, m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    color[0] = 1;
    bool bi = is_bipartite(0);

    return 0;
}