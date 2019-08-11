// 3_abc137_c
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<char>> s(n, vector<char>(10));
    vector<string> s2(n);
    rep(i, n){
        rep(j, 10){
            cin >> s[i][j];
        }
        sort(s[i].begin(), s[i].end());
        string tmp(s[i].begin(), s[i].end());
        s2[i] = tmp;
    }
    sort(s2.begin(), s2.end());
    ll ans = 0;
    string cmp = s2[0];
    ll cnt = 1;
    for(int i = 1; i < n; i++){
        if(cmp == s2[i]) cnt++;
        else{
            ans += cnt * (cnt - 1) / 2;
            cnt = 1;
            cmp = s2[i];
        }
    }
    ans += cnt * (cnt - 1) / 2;
    cout << ans << endl;

    return 0;
}
