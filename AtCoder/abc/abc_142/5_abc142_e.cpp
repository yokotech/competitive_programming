// 5_abc142_e
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
#define MOD (1000000007)
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);
    vector<vector<int>> c(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        c[i].resize(b[i]);
        rep(j, b[i]){
            cin >> c[i][j];
            c[i][j]--;
        }
    }

    vector<int> dp(1 << n);
    rep(i, 1 << n){
        dp[i] = INF;
    }
    dp[0] = 0;

    rep(i, m){
        int state = 0;
        rep(j, b[i]){
            state |= 1 << c[i][j];
        }

        rep(j, 1 << n){
            dp[j | state] = min(dp[j | state], dp[j] + a[i]);
        }
    }

    int ans = dp[(1 << n) - 1];
    if(ans == INF) cout << - 1 << endl;
    else cout << ans << endl;

    return 0;
}
