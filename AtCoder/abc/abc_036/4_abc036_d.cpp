// 4_abc036_d
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

int n;
vector<vector<int>> g;
vector<ll> b;
vector<ll> w;
vector<int> deg;

void func(int nd, int p){
    if(nd != 1 && deg[nd] == 1){
        return;
    }

    rep(i, g[nd].size()){
        int next = g[nd][i];
        if(next == p) continue;

        func(next, nd);
        b[nd] = b[nd] * w[next] % MOD;
        w[nd] = w[nd] * (w[next] + b[next]) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    g.resize(n + 1);
    b.resize(n + 1);
    w.resize(n + 1);
    deg.resize(n + 1);
    rep1(i, n){
        deg[i] = 0;
        b[i] = 1;
        w[i] = 1;
    }
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        deg[a]++; deg[b]++;
    }

    func(1, -1);
    cout << (b[1] + w[1]) % MOD << endl;

    return 0;
}
