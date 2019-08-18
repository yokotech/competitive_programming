// 1_vol5_a
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
// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
#define MOD (1000000007)
typedef long long ll;

void proc(int n, int k){
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }
    vector<ll> s(n);
    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = s[i - 1] + a[i];
    }
    ll ans = s[k - 1];
    for(int i = k; i < n; i++){
        if(ans < s[i] - s[i - k]) ans = s[i] - s[i - k];
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    while(cin >> n){
        cin >> k;
        proc(n, k);
    }
    return 0;
}
