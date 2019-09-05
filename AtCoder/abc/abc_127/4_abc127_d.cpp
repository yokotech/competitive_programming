// 4_abc127_d
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

    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<pair<int, int>> p(m);
    rep(i, m){
        int b, c;
        cin >> b >> c;
        p[i] = make_pair(c, b);
    }
    sort(p.begin(), p.end(), greater<pair<int, int>>());

    int cnt = 0;
    int flag = 0;
    rep(i, m){
        int b = p[i].second;
        int c = p[i].first;
        rep(j, b){
            a[cnt] = max(a[cnt], c);
            cnt++;
            if(cnt == n){
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }

    ll ans = 0;
    rep(i, n){
        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}
