// 5_abc130_e
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    vector<int> t(m);
    rep(i, n){
        cin >> s[i];
    }
    rep(i, m){
        cin >> t[i];
    }

    if(n == 1){
        ll cnt = 0;
        rep(i, m){
            if(s[0] == t[i]){
                cnt++;
            }
        }
        cout << cnt << endl;
        return 0;
    }
    if(m == 1){
        ll cnt = 0;
        rep(i, n){
            if(s[i] == t[0]){
                cnt++;
            }
        }
        cout << cnt << endl;
        return 0;
    }

    vector<vector<ll>> dp(n, vector<ll> (m));
    if(s[0] == t[0]) dp[0][0] = 2;
    else dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        if(s[i] == t[0]) dp[i][0] = dp[i - 1][0] + 1;
        else dp[i][0] = dp[i - 1][0];
    }
    for(int j = 1; j < m; j++){
        if(s[0] == t[j]) dp[0][j] = dp[0][j - 1] + 1;
        else dp[0][j] = dp[0][j - 1];
    }

    vector<vector<int>> al(n);
    rep(i, n){
        rep(j, m){
            if(s[i] == t[j]) al[i].push_back(j);
        }
    }

    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j] = dp[i - 1][j];
            rep(k, al[i].size()){
                int l = al[i][k];
                if(l == 0){
                    dp[i][j] = (dp[i][j] + 1) % MOD;
                    continue;
                }
                if(l > j) break;
                dp[i][j] = (dp[i][j] + dp[i - 1][l - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;

    return 0;
}
