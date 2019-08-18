// 1_agc037_a
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

    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        cout << n << endl;
        return 0;
    }else if(n == 2){
        if(s[0] == s[1]) cout << 1 << endl;
        else cout << 2 << endl;
        return 0;
    }

    vector<ll> dp1(n);
    vector<ll> dp2(n);
    dp1[0] = 1;
    if(s[0] == s[1]) dp1[1] = -INF;
    else dp1[1] = 2;
    dp2[0] = -INF;
    dp2[1] = 1;


    for(int i = 2; i < n; i++){
        if(s[i] != s[i - 1]){
            dp1[i] = max(dp1[i - 1], dp2[i - 1]) + 1;
        }else{
            dp1[i] = dp2[i - 1] + 1;
        }

        if(i == 2){
            dp2[i] = dp1[i - 2] + 1;
            continue;
        }
        if(s.substr(i - 3, 2) != s.substr(i - 1, 2)){
            dp2[i] = max(dp1[i - 2], dp2[i - 2]) + 1;
        }else{
            dp2[i] = dp1[i - 2] + 1;
        }
    }

    cout << max(dp1[n - 1], dp2[n - 1]) << endl;
    return 0;
}
