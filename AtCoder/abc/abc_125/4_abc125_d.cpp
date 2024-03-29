// 4_abc125_d
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
    ll s = 0;
    int mi = 1000000000;
    rep(i, n){
        cin >> a[i];
        s += abs(a[i]);
        mi = min(mi, abs(a[i]));
    }

    vector<int> l(n);
    vector<int> r(n);
    if(a[0] >= 0) l[0] = 0;
    else l[0] = 1;

    if(a[n - 1] >= 0) r[n - 1] = 0;
    else r[n- 1] = 1;

    for(int i = 1; i < n; i++){
        if(a[i] >= 0) l[i] = l[i - 1];
        else l[i] = l[i - 1] + 1;
    }

    for(int i = n - 2; i >= 0; i--){
        if(a[i] >= 0) r[i] = r[i + 1];
        else r[i] = r[i + 1] + 1;
    }

    if((r[1] % 2 == 0 && a[0] >= 0) || (r[1] % 2 == 1 && a[0] <= 0)){
        cout << s << endl;
        return 0;
    }
    if((l[n - 2] % 2 == 0 && l[n - 1] >= 0) || (l[n - 1] % 2 == 1 && a[n - 1] <= 0)){
        cout << s << endl;
        return 0;
    }

    for(int i = 1; i <= n - 2; i++){
        int d = l[i - 1] + r[i + 1];
        if((d % 2 == 0 && a[i] >= 0) || (d % 2 == 1 && a[i] <= 0)){
            cout << s << endl;
            return 0;
        }
    }
    cout << s - mi << endl;
    return 0;

    return 0;
}
