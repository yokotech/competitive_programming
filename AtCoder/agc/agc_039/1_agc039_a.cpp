// 1_agc039_a
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
    ll k;
    cin >> s;
    cin >> k;
    ll n = s.length();
    ll cnt = 0;

    rep(i, n - 1){
        if(s[i] != s[i + 1]) break;

        if(i == n - 2){
            cout << (k * n) / 2 << endl;
            return 0;
        }
    }

    rep(i, n - 1){
        if(s[i] == s[i + 1]){
            cnt++;
            i++;
        }
    }

    ll ans = k * cnt;
    if(s[0] == s[n - 1]){
        ll a, b;
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]) continue;
            else{
                a = i + 1;
                break;
            }
        }
        for(int i = n - 1; i > 0; i--){
            if(s[i] == s[i - 1]) continue;
            else{
                b = n - i;
                break;
            }
        }

        cout << ans - (k - 1) * (a / 2 + b / 2 - (a + b) / 2) << endl;
    }else{
        cout << ans << endl;
    }


    return 0;
}
