// 1_abc138_a
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

    string s, t;
    cin >> s >> t;
    int ns = s.length();
    int nt = t.length();
    vector<bool> used_in_s(26);
    vector<bool> used_in_t(26);

    rep(i, 26){
        used_in_s[i] = false;
        used_in_t[i] = false;
    }

    rep(i, ns){
        used_in_s[s[i] - 'a'] = true;
    }
    rep(j, nt){
        used_in_t[t[j] - 'a'] = true;
    }
    rep(i, 26){
        if(used_in_t[i] && (!used_in_s[i])){
            cout << -1 << endl;
            return 0;
        }
    }

    vector<vector<int>> itr_s(26);
    rep(i, ns){
        int ch = s[i] - 'a';
        itr_s[ch].push_back(i);
    }

    ll ans = 1;
    int ch = t[0] - 'a';
    int now = itr_s[ch][0];

    for(int i = 1; i < nt; i++){
        ch = t[i] - 'a';
        auto it = upper_bound(itr_s[ch].begin(), itr_s[ch].end(), now);
        if(it == itr_s[ch].end()){
            now = itr_s[ch][0];
            ans++;
        }else{
            now = *it;
        }
    }

    ans = (ans - 1) * ns;
    ans += now + 1;

    cout << ans << endl;

    return 0;
}
