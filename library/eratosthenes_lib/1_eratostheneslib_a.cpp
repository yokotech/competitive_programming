// 1_eratostheneslib_a
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

// verify :　目視

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
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

    int n;
    cin >> n;
    vector<bool> prime = eratosthenes(n);

    rep(i, n + 1){
        if(prime[i]) cout << i << endl;
    }
    return 0;
}
