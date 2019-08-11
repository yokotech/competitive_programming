#include<bits/stdc++.h>
/*
g++ -std=c++11 -Wall -g -fsanitize=undefined -D_GLIBCXX_DEBUG library/dijkstra.cpp
SoundHound2018/d.cppに準拠
*/
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define SZ(x) ((int)(x).size())
typedef long long ll;
#define INF (1e16)

int n, m, s, t;

vector<vector<pair<int, ll>>> g;// i番目のノードから出るj番目のedgeの行き先がfirst, コストがsecond
vector<vector<pair<int, ll>>> g2;

vector<ll> dist;
vector<ll> dist2;

void dijkstra(){// 1はじまりのindex
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(make_pair(0, s));// 始点
    vector<int> visited(n + 1);
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }

    while(!q.empty()){
        pair<ll, int> p = q.top();
        q.pop();
        int nd = p.second;//nd番目のノード
        visited[nd] = 1;
        rep(i, g[nd].size()){
            int next = g[nd][i].first;// ndから出るi本目のedgeの行き先
            ll nd_next = g[nd][i].second;// nd <--> next間の距離
            if(visited[next] == 1) continue;

            if(dist[next] > dist[nd] + nd_next){
                dist[next] = dist[nd] + nd_next;
                q.push(make_pair(dist[next], next));
            }
        }
    }
}

void dijkstra2(){// 1はじまりのindex // 終点からのdijkstra
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.push(make_pair(0, t));// 始点
    vector<int> visited(n + 1);
    for(int i = 1; i <= n; i++){
        visited[i] = 0;
    }

    while(!q.empty()){
        pair<ll, int> p = q.top();
        q.pop();
        int nd = p.second;//nd番目のノード
        visited[nd] = 1;
        rep(i, g2[nd].size()){
            int next = g2[nd][i].first;// ndから出るi本目のedgeの行き先
            ll nd_next = g2[nd][i].second;// nd <--> next間の距離
            if(visited[next] == 1) continue;

            if(dist2[next] > dist2[nd] + nd_next){
                dist2[next] = dist2[nd] + nd_next;
                q.push(make_pair(dist2[next], next));
            }
        }
    }
}

int main(){
    cin >> n >> m >> s >> t;
    g.resize(n + 1);
    g2.resize(n + 1);
    dist.resize(n + 1);
    dist2.resize(n + 1);
    for(int i = 1; i <= n; i++){
        dist[i] = INF;
        dist2[i] = INF;
    }
    dist[s] = 0;
    dist2[t] = 0;
    rep(i, m){
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        g[u].push_back(make_pair(v, a));
        g[v].push_back(make_pair(u, a));
        g2[u].push_back(make_pair(v, b));
        g2[v].push_back(make_pair(u, b));
    }
    
    dijkstra();
    dijkstra2();

    vector<ll> ans(n);
    ans[n - 1] = dist[n] + dist2[n];
    for(int i = n - 2; i >= 0; i--){
        if(dist[i + 1] + dist2[i + 1] < ans[i + 1]){
            ans[i] = dist[i + 1] + dist2[i + 1];
        }else{
            ans[i] = ans[i + 1];
        }
    }
    ll tmp = 1e15;
    rep(i, n){
        cout << tmp - ans[i] << "\n";
    }
    return 0;
}