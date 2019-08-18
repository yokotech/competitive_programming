// 4_abc138_d
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

int n, q;
vector<vector<int>> g;
vector<ll> c;
vector<ll> ans;

void dfs(int nd, int parent){
    ans[nd] = c[nd] + ans[parent];
    rep(i, g[nd].size()){
        int next = g[nd][i];
        if(next == parent) continue;

        dfs(next, nd);
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    g.resize(n + 1);
    c.resize(n + 1);
    ans.resize(n + 1);
    ans[0] = 0;
    for(int i = 1; i <= n; i++){
        c[i] = 0;
    }
    rep(i, n - 1){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i, q){
        int p, x;
        cin >> p >> x;
        c[p] += x;
    }

    ans[1] = c[1];
    dfs(1, 0);

    rep1(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
