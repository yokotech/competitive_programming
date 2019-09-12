// 3_yahoo2017qualc_c
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
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    vector<int> b(n);
    rep(i, n){
        b[i] = 0;
    }
    rep(i, k){
        cin >> a[i];
        a[i]--;
        b[a[i]] = 1;
    }
    vector<string> s(n);
    rep(i, n){
        cin >> s[i];
    }

    string scmp = s[a[0]];
    vector<int> preflen(n);

    rep(i, n){
        int tmp = 0;
        rep(j, min(scmp.size(), s[i].size())){
            if(s[i][j] == scmp[j]) tmp++;
            else break;
        }
        preflen[i] = tmp;
    }

    int commin = 100000;
    int incommax = -1;

    rep(i, n){
        if(b[i]){
            commin = min(preflen[i], commin);
        }else{
            incommax = max(preflen[i], incommax);
        }
    }

    if(commin <= incommax){
        cout << -1 << endl;
    }else{
        if(incommax == -1){
            cout << "" << endl;
        }else{
            cout << s[a[0]].substr(0, incommax + 1);
        }
    }

    return 0;
}
