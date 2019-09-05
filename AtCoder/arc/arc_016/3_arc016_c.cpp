// 3_arc016_c
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
#define INF (1e9)
#define EPS (1e-10)
#define MOD (1000000007)
typedef long long ll;

int n, m;
vector<int> c, cost;
vector<vector<int>> idol;
vector<vector<double>> p;
vector<double> dp;

double dfs(int state){
    if(dp[state] < INF - 100000) return dp[state];

    double retval = INF;

    rep(i, m){
        double ok = 0;
        double e = 0;

        rep(j, c[i]){
            if((state & (1 << idol[i][j])) == 0){
                ok += p[i][j];
            }
        }

        if(ok < EPS) continue;

        rep(j, c[i]){
            if((state & (1 << idol[i][j])) == 0){
                e += dfs(state | (1 << idol[i][j])) * p[i][j] / ok;
            }
        }
        e += cost[i] / ok;
        retval = min(retval, e);
    }
    dp[state] = retval;
    return retval;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    c.resize(m);
    cost.resize(m);
    idol.resize(m);
    p.resize(m);
    dp.resize((1 << n));

    rep(i, m){
        cin >> c[i] >> cost[i];
        rep(j, c[i]){
            int l;
            double q;
            cin >> l >> q;
            l--;
            idol[i].push_back(l);
            p[i].push_back(q / 100.0);
        }
    }

    rep(i, (1 << n)){
        dp[i] = INF;
    }
    dp[(1 << n) - 1] = 0;

    double ans = dfs(0);
    cout << setprecision(15) << ans << endl;
    return 0;
}
