// 3_abc111_c
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
    int k = 100000;
    int n;
    cin >> n;
    vector<pair<int, int>> u(k + 1);
    vector<pair<int, int>> v(k + 1);

    rep(i, k + 1){
        v[i] = make_pair(0, i);
        u[i] = make_pair(0, i);
    }
    rep(i, n){
        int a;
        cin >> a;
        if(i % 2 == 0){
            u[a].first++;
        }else{
            v[a].first++;
        }
    }

    sort(u.begin(), u.end(), greater<pair<int, int>>());
    sort(v.begin(), v.end(), greater<pair<int, int>>());

    if(u[0].second != v[0].second){
        cout << n - u[0].first - v[0].first << endl;
    }else{
        int ans = max(u[0].first + v[1].first, u[1].first + v[0].first);
        cout << n - ans << endl;
    }

    return 0;
}
