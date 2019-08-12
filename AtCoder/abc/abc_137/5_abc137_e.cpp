// 5_abc137_e
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

int n, m, s, p;
vector<vector<pair<int, int> > > g;
vector<ll> dist;

void bellman_ford(){
    rep(i, n - 1){
        rep1(j, n){
            if(dist[j] == INF) continue;

            rep(k, g[j].size()){
                int next = g[j][k].first;
                if(dist[next] > dist[j] + g[j][k].second){
                    dist[next] = dist[j] + g[j][k].second;
                }
            }
        }
    }

    ll ans = dist[n];

    rep(i, n){
        rep1(j, n){
            if(dist[j] == INF) continue;

            rep(k, g[j].size()){
                int next = g[j][k].first;
                if(dist[j] == -INF){
                    dist[next] = -INF;
                }else{
                    if(dist[next] > dist[j] + g[j][k].second){
                        dist[next] = -INF;
                    }
                }
            }
        }
    }

    if(ans > dist[n]){
        cout << -1 << endl;
    }else{
        if(ans > 0) cout << 0 << endl;
        else cout << -ans << endl;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    s = 1;

    cin >> n >> m >> p;
    g.resize(n + 1);
    dist.resize(n + 1);
    rep(i, m){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back(make_pair(b, -c + p));
    }
    rep1(i, n){
        dist[i] = INF;
    }
    dist[s] = 0;

    bellman_ford();
    return 0;
}