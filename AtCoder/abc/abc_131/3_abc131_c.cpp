// 3_abc131_c
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
typedef long long ll;

ll gcd(ll x, ll y){
    if(x < y) swap(x, y);

    while(y > 0){
        ll r = x % y;
        x = y;
        y = r;
    }
    return x;
}

ll lcm(ll x, ll y){
    ll z = x * y / gcd(x, y);
    return z;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll n_c, n_d, n_cd;// c, d, cdで割り切れるものの数
    n_c = b / c - a / c;
    if(a % c == 0) n_c++;

    n_d = b / d - a / d;
    if(a % d == 0) n_d++;

    ll e = lcm(c, d);
    n_cd = b / e - a / e;
    if(a % e == 0) n_cd++;

    cout << b - a + 1 - (n_c + n_d - n_cd) << endl;
    return 0;
}
