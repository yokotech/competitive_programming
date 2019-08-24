// 3_abc062_c
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
    ll h, w;
    cin >> h >> w;
    ll ans;
    if(w % 3 == 0 || h % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    ans = min(h, w);

    ll a, b, c;
    for(int i = 1; i <= h - 1; i++){
        a = w * i;
        if(w % 2 == 0){
            b = (h - i) * w / 2;
            c = b;
        }else{
            b = (h - i) * (w / 2 + 1);
            c = (h - i) * (w / 2);
        }
        ll diff = max(abs(b - a), abs(c - b));
        diff = max(diff, abs(a - c));
        if(ans > diff) ans = diff;
    }

    for(int i = 1; i <= w - 1; i++){
        a = h * i;
        if(h % 2 == 0){
            b = (w - i) * h / 2;
            c = b;
        }else{
            b = (w - i) * (h / 2 + 1);
            c = (w - i) * (h / 2);
        }
        ll diff = max(abs(b - a), abs(c - b));
        diff = max(diff, abs(a - c));
        if(ans > diff) ans = diff;
    }

    cout << ans << endl;
    return 0;
}
