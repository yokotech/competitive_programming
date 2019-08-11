#include<bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

typedef struct node_{
    vector<int> pre;// 前のノード
    vector<int> nx;// 次のノード
    int nprev;// 入次数
    int nnext;// 出次数
    // int depth;// 深さ
    // int parent;// 親
    int visited;// 0に初期化必要
}* node;

vector<node> g;
vector<int> l;// ここに

void visit(int n){
    if(g[n] -> visited == 0){
        g[n] -> visited = 1;
        rep(i, g[n] -> nnext){
            visit(g[n] -> nx[i]);
        }
        l.push_back(n);
    }
}

void topological_sort(){
    int a = g.size();
    rep(i, a){
        g[i]->visited = 0;
    }
    rep(i, a){
        visit(i);
    }
}