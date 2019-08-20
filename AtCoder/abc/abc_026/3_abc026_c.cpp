// 3_abc026_c
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

int n;
vector<vector<int>> g;

int dfs(int nd){
    if(g[nd].size() == 0){
        return 1;
    }

    int mi = dfs(g[nd][0]);
    int ma = dfs(g[nd][0]);
    for(int i = 1; i < g[nd].size(); i++){
        int a = dfs(g[nd][i]);
        if(a < mi) mi = a;
        if(a > ma) ma = a;
    }
    return mi + ma + 1;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    for(int i = 1; i < n; i++){
        int b;
        cin >> b;
        b--;
        g[b].push_back(i);
    }
    int ans = dfs(0);

    cout << ans << endl;
    return 0;
}
