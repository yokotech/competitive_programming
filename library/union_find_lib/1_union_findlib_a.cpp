// 1_union_findlib_a
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

// verify : http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define SZ(x) ((int)(x).size())
#define INF (1e16)
typedef long long ll;

vector<int> parent;
vector<int> node_rank;


int root(int x){
    if(parent[x] == x) return x;
    else return parent[x] = root(parent[x]);
}

void link(int x, int y){
    if(node_rank[x] > node_rank[y]){
        parent[y] = x;
    }else{
        parent[x] = y;
        if(node_rank[x] == node_rank[y]){
            node_rank[y]++;
        }
    }
}

void unite(int x, int y){
    link(root(x), root(y));
}

int same(int x, int y){
    return root(x) == root(y);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;// number of nodes
    int q;// number of query
    cin >> n >> q;

    parent.resize(n);
    node_rank.resize(n);
    rep(i, n){
        parent[i] = i;
        node_rank[i] = 1;
    }

    rep(i, q){
        int com, x, y;
        cin >> com >> x >> y;
        if(com == 0){
            unite(x, y);
        }else{
            cout << same(x, y) << endl;
        }
    }

    return 0;
}
