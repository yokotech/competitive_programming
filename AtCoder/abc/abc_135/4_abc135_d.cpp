// 4_abc135_d
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
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> residue(n, vector<int>(10));
    rep(j, 10){
        residue[n - 1][j] = j;
    }
    for(int i = n - 2; i >= 0; i--){
        rep(j, 10){
            residue[i][j] = residue[i + 1][j] * 10 % 13;
        }
    }

    vector<vector<ll>> dp(n, vector<ll>(13));
    rep(i, n){
        rep(j, 13){
            dp[i][j] = 0;
        }
    }

    if(s[0] == '?'){
        rep(k, 10){
            dp[0][residue[0][k]]++;
        }
    }else{
        int k = s[0] - '0';
        dp[0][residue[0][k]]++;
    }

    for(int i = 1; i < n; i++){
        if(s[i] == '?'){
            for(int h = 0; h < 10; h++){
                int k = h;
                int l = residue[i][k];
                for(int j = 0; j < 13 - l; j++){
                    dp[i][l + j] += dp[i - 1][j];
                    dp[i][l + j] %= MOD;
                }
                for(int j = 1; j <= l; j++){
                    dp[i][l - j] += dp[i - 1][13 - j];
                    dp[i][l - j] %= MOD;
                }
            }
        }else{
            int k = s[i] - '0';
            int l = residue[i][k];
            for(int j = 0; j < 13 - l; j++){
                dp[i][l + j] = dp[i - 1][j];
            }
            for(int j = 1; j <= l; j++){
                dp[i][l - j] = dp[i - 1][13 - j];
            }
        }
    }

    cout << dp[n - 1][5] << endl;

    return 0;
}
