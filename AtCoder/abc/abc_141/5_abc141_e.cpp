// 5_abc141_e
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

vector<int> z_algorithm(string s){
    int n = s.length();
    int l = 0, r = 0;
    vector<int> z(n);

    z[0] = n;
    for(int i = 1; i < n; i++){
        if(i > r){
            l = r = i;
            while(r < n && s[r - l] == s[r]) r++;
            z[i] = r - l;
            r--;
        }else{
            int k = i - l;
            if(z[k] < r - i + 1){
                z[i] = z[k];
            }else{
                l = i;
                while(r < n && s[r - l] == s[r]) r++;
                z[i] = r - l;
                r--;
            }
        }
    }

    return z;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    rep(i, n){
        string t = s.substr(i, n - i);
        vector<int> z = z_algorithm(t);
        for(int j = 1; j < n - i; j++){
            if(z[j] > j) z[j] = j;
            ans = max(z[j], ans);
        }
    }
    cout << ans << endl;
    return 0;
}
