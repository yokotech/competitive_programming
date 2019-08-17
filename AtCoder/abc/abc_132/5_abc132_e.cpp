// 5_abc132_e
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

int n, m;
int s, t;
vector<vector<int>> g;
vector<int> visited;
vector<int> d;
queue<int> q;

void bfs(int nd, int t, int dist){
    if(t == 3){
        if(visited[nd] == 0){
            visited[nd] = 1;
            d[nd] = dist + 1;
            q.push(nd);
        }
        return;
    }

    rep(i, g[nd].size()){
        int next = g[nd][i];
        bfs(next, t + 1, dist);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    d.resize(n + 1);
    rep1(i, m){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    rep1(i, n){
        visited[i] = 0;
        d[i] = -1;
    }
    cin >> s >> t;

    q.push(s);
    d[s] = 0;

    while(!q.empty()){
        int nd = q.front();
        q.pop();
        bfs(nd, 0, d[nd]);
    }
    cout << d[t] << endl;

    return 0;
}
