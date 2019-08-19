// 5_abc136_e
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

int n, k;
vector<int> a;
vector<int> r;
int s;
int ans;

void func(int d){
    if(d == 1) return;

    rep(i, n){
        r[i] = a[i] % d;
    }
    sort(r.begin(), r.end());
    int its = 0;
    int itt = n - 1;
    int cnt = 0;
    while(its < itt){
        int diff = min(r[its], d - r[itt]);
        r[its] -= diff;
        r[itt] += diff;
        cnt += diff;

        if(r[its] == 0) its++;
        if(r[itt] == d) itt--;
    }
    if(cnt > k) return;

    ans = max(ans, d);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    s = 0;
    ans = 1;
    a.resize(n);
    r.resize(n);
    rep(i, n){
        cin >> a[i];
        s += a[i];
    }

    for(int i = 1; i * i <= s; i++){
        if(s % i) continue;

        func(i);
        func(s / i);
    }

    cout << ans << endl;
    return 0;
}
