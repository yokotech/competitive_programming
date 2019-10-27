// 5_abc144_e
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
    vector<ll> f(n);
    ll sa = 0;
    ll m = 0;
    rep(i, n){
        cin >> a[i];
        sa += a[i];
    }
    rep(i, n){
        cin >> f[i];
        m = max(m, a[i] * f[i]);
    }

    if(sa <= k){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(f.begin(), f.end());

    ll ans = m;
    ll l = 1;
    ll r = m;
    ll c = (l + r) / 2;
    while(1){
        if(l >= r){
            ll cnt = 0;
            rep(i, n){
                if(a[i] * f[i] <= c) continue;
                else cnt += a[i] - c / f[i];
            }
            if(k >= cnt) ans = min(ans, r);

            break;
        }
        ll cnt = 0;
        rep(i, n){
            if(a[i] * f[i] <= c) continue;
            else cnt += a[i] - c / f[i];
        }
        if(k >= cnt){
            ans = min(ans, c);
            r = c - 1;
            c = (l + r) / 2;
        }else{
            l = c + 1;
            c = (l + r) / 2 ;
        }
    }

    cout << ans << endl;

    return 0;
}
