// 5_abc132_e
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

int n, m;
int s, t;
vector<vector<int>> g1;// 1回で行けるとこ
vector<vector<int>> g2;
vector<vector<int>> g3;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    g1.resize(n + 1);
    g2.resize(n + 1);
    g3.resize(n + 1);
    rep(i, n){
        int u, v;
        cin >> u >> v;
        g1[u].push_back(v);
    }

    rep1(i, n){
        for(int j = 0; j < g1[i].size(); j++){
            int nd1 = g1[i][j];
            for(int k = 0; k < g1[nd1].size(); k++){
                g2[i].push_back(g1[nd1][k]);
            }
        }
    }



    cin >> s >> t;


    return 0;
}
