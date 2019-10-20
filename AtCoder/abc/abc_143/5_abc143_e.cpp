// 5_abc143_e
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
#define MOD (1000000007)
typedef long long ll;

int n, m, l;
vector<vector<ll>> dist;
vector<vector<ll>> g;

void warshall_floyd(){//globalでN * N距離行列 distが存在する前提
    rep(k, n){
        rep(i, n){
            rep(j, n){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }
}

void warshall_floyd_g(){//globalでN * N距離行列 distが存在する前提
    rep(k, n){
        rep(i, n){
            rep(j, n){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
                g[j][i] = g[i][j];
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m >> l;
    dist.resize(n, vector<ll> (n));
    g.resize(n, vector<ll> (n));
    rep(i ,n){
        rep(j, n){
            dist[i][j] = INF;
            g[i][j] = INF;
        }
    }

    rep(k, m){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
    }
    warshall_floyd();

    rep(i, n){
        rep(j, n){
            if(dist[i][j] <= l) g[i][j] = 1;
        }
    }

    warshall_floyd_g();

    int q;
    cin >> q;
    rep(i, q){
        int s, t;
        cin >> s >> t;
        s--; t--;

        if(g[s][t] < INF) cout << g[s][t] - 1 << endl;
        else cout << -1 << endl;
    }

    return 0;
}
