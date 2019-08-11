#include<bits/stdc++.h>
/*
g++ -std=c++11 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG aoj/grl_2_a.cpp
aoj/grl_2_aにてverify
*/
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

vector<int> parent;// それぞれのnodeのparent，main内でresize必要
vector<int> tree_rank;// それぞれのnodeの属する木のtree_rank

void init(int n){// 初期化．全てのnodeで親を自分自身に，tree_rankを0にする．nもらわなくてもv.size()でいける
    rep(i, n){
        parent[i] = i;
        tree_rank[i] = 0;
    }
}

int root(int x){// node xのrootを返す．parent[x] = root(parent[x])で親をrootにつなぎ替える
    return x == parent[x] ? x : parent[x] = root(parent[x]);
}

bool same(int x, int y){// 同じ木に属するかどうか判定する
    return root(x) == root(y);
}

void unite(int x, int y){// xの属する木とyの属する木を連結する．rankができるだけ低くなるように処理を行う
    x = root(x);
    y = root(y);

    if(tree_rank[x] < tree_rank[y]){
        parent[x] = y;
    }else{
        parent[y] = x;
        if(tree_rank[x] == tree_rank[y]) tree_rank[x]++;
    }
}

vector<pair<int, pair<int, int> > > edges;

void kruskal(){
    int v, e;
    cin >> v >> e;
    edges.resize(e);
    parent.resize(v);
    tree_rank.resize(v);
    init(v);

    rep(i, e){
        int s, t, w;
        cin >> s >> t >> w;
        edges[i] = make_pair(w, make_pair(s, t));
    }
    sort(edges.begin(), edges.end());

    ll ans = 0;// 最小全域木の重みの合計
    rep(i, e){
        int s = edges[i].second.first;
        int t = edges[i].second.second;
        int w = edges[i].first;

        if(same(s, t)) continue;

        unite(s, t);
        ans += w;
    }
    cout << ans << "\n";
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);//おまじないでcin, cout早くする
    kruskal();
    return 0;
}