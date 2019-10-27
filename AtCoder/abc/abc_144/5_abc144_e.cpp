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
    rep(i, n){
        cin >> a[i];
        sa += a[i];
    }
    rep(i, n){
        cin >> f[i];
    }
    if(sa <= k){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end(), greater<int>());
    sort(f.begin(), f.end());

    priority_queue< pair<ll, int> > q;
    rep(i, n){
        pair<ll, int> p = make_pair(a[i] * f[i], i);
        q.push(p);
    }

    while(k > 0){
        pair<ll, int> p1, p2;
        p1 = q.top();
        q.pop();
        p2 = q.top();

        ll cost1 = p1.first;
        int i1 = p1.second;
        ll cost2 = p2.first;
        int i2 = p2.second;

        ll moku = cost2 / f[i1];
        if(a[i1] - moku > k){
            a[i1] -= k;
            k = 0;
            q.push(make_pair(a[i1] * f[i1], i1));
        }else if(a[i1] != moku){
            k -= a[i1] - moku;
            a[i1] = moku;
            q.push(make_pair(a[i1] * f[i1], i1));
        }else{
            q.pop();

        }
    }
    cout << q.top().first << endl;
    return 0;
}
