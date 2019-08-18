// 4_abc084_d
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

vector<bool> eratosthenes(int n){
    // n以下の整数が素数かどうかのbool vector返す
    if(n < 1) cout << "ERROR : eratostenes : n < 1";

    vector<bool> prime(n + 1, true);
    prime[0] = false;
    prime[1] = false;

    if(n < 2) return prime;

    int j = 4;
    while(j <= n){
        prime[j] = false;
        j += 2;
    }

    for(int i = 3; i <= sqrt(n); i += 2){
        if(prime[i]){
            int j = 2 * i;
            while(j <= n){
                prime[j] = false;
                j += i;
            }
        }
    }
    return prime;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    int n = 100000;
    vector<int> s(n + 1);
    vector<bool> prime = eratosthenes(n);

    s[1] = 0;
    for(int i = 3; i <= n; i += 2){
        if(prime[i] && prime[(i + 1) / 2]){
            s[i] = s[i - 2] + 1;
        }else{
            s[i] = s[i - 2];
        }
    }

    rep(i, q){
        int l, r;
        cin >> l >> r;
        if(l == 1){
            cout << s[r] << endl;
            continue;
        }
        cout << s[r] - s[l - 2] << endl;
    }

    return 0;
}
