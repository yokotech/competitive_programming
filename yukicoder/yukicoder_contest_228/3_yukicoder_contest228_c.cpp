// 3_yukicoder_contest228_c
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
    string s;
    cin >> s;

    int ans = 0;
    list<int> l;

    rep(i, n){
        if(s[i] == '3' || s[i] == '5' || s[i] == '7') ans++;
        else l.push_back(s[i] - '0');
    }

    int cnt1 = 0;
    int cnt9 = 0;

    for(auto itr = l.begin(); itr != l.end(); ++itr){
        int x = *itr;
        if(x == 1){
            cnt1++;
        }else{
            cnt9++;
            if(cnt1 > 0){
                cnt1--;
                cnt9--;
                ans++;
            }
        }
    }

    if(cnt1 % 2 == 0){
        ans += cnt1 / 2;
    }else{
        ans += cnt1 / 2;
        if(cnt9 > 1 && l.back() == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}
