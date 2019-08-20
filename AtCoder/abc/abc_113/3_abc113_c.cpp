// 3_abc113_c
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

void print_num(int x){
    if(x >= 100000){
        // do nothing
    }else if(x >= 10000) cout << "0";
    else if(x >= 1000) cout << "00";
    else if(x >= 100) cout << "000";
    else if(x >= 10) cout << "0000";
    else cout << "00000";

    cout << x;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<pair<int,int>, int>> v(m);
    rep(i, m){
        int p, y;
        cin >> p >> y;
        v[i].first = make_pair(p, y);
        v[i].second = i + 1;
    }
    sort(v.begin(), v.end());

    v[0].first.second = 1;
    for(int i = 1; i < m; i++){
        if(v[i].first.first == v[i - 1].first.first){
            v[i].first.second = v[i - 1].first.second + 1;
        }else{
            v[i].first.second = 1;
        }
    }

    vector<pair<int, pair<int, int>>> tmp(m);
    rep(i, m){
        tmp[i].first = v[i].second;
        tmp[i].second = v[i].first;
    }
    sort(tmp.begin(), tmp.end());

    rep(i, m){
        int p = tmp[i].second.first;
        int y = tmp[i].second.second;
        print_num(p);
        print_num(y);
        cout << endl;
    }

    return 0;
}
