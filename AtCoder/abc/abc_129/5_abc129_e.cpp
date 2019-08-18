// 5_abc129_e
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

string l;
int n;
vector<ll> powmod;

ll dfs(int itr){
    if(itr == n - 1){
        if(l[itr] == '1') return 3;
        else return 1;
    }

    if(l[itr] == '1'){
        return (2 * dfs(itr + 1) + powmod[n - itr - 1]) % MOD;
    }else{
        return dfs(itr + 1) % MOD;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> l;
    n = l.length();
    if(n == 1){
        cout << 3 << endl;
        return 0;
    }
    powmod.resize(n + 1);
    powmod[0] = 1;
    for(int i = 1; i <= n; i++){
        powmod[i] = 3 * powmod[i - 1] % MOD;
    }

    ll ans = powmod[n - 1];

    ll ans2 = 2 * dfs(1);

    cout << (ans + ans2) % MOD << endl;

    return 0;
}
