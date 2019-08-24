// 2_jsc2019q_b
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
    ll n, k;
    cin >> n >> k;

    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }

    vector<ll> d(n);
    vector<ll> e(n);

    rep(i, n){
        ll cnt = 0;
        rep(j, n){
            if(a[i] > a[j]) cnt++;
        }
        d[i] = cnt;

        ll cnt2 = 0;
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]) cnt2++;
        }
        e[i] = cnt2;
    }

    ll ans = 0;
    rep(i, n){
//        ans = (ans + d[i] * k * (k - 1) / 2 + e[i] * k) % MOD;
        ans = (ans + e[i] * k) % MOD;
        ll tmp;
        if(k % 2 == 0){
            tmp = k / 2;
            tmp = tmp * d[i] % MOD;
            tmp = tmp * (k - 1) % MOD;
        }else{
            tmp = (k - 1) / 2;
            tmp = tmp * d[i] % MOD;
            tmp = tmp * k % MOD;
        }
        ans = (ans + tmp) % MOD;
    }
    cout << ans << endl;

    return 0;
}
