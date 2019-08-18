// 1_agc023_a
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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> s(n);
    rep(i, n){
        cin >> a[i];
    }
    s[0] = a[0];
    for(int i = 1; i < n; i++){
        s[i] = s[i - 1] + a[i];
    }

    ll ans = 0;
    // a[i] -> a[j]の和が0 <=> s[j] - s[i - 1] = 0;
    // i = 0のときは? -> s[j] = 0
    // sをソートしてあげて，このようなiとjのくみはソートで行ける

    sort(s.begin(), s.end());

    ll cnt = 1;
    int tmp = s[0];
    if(s[0] == 0) ans++;
    for(int i = 1; i < n; i++){
        if(s[i] == 0) ans++;

        if(s[i] == tmp) cnt++;
        else{
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            tmp = s[i];
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;
    return 0;
}
