// 3_abc112_c
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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    int nonzero = -1;
    rep(i, n){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
        if(nonzero == -1 && v[i][2] > 0){
            nonzero = i;
        }
    }

    rep(cx, 101){
        rep(cy, 101){
            int flag = 1;
            int ch = v[nonzero][2] + abs(v[nonzero][0] - cx) + abs(v[nonzero][1] - cy);

            rep(i, n){
                int x = v[i][0];
                int y = v[i][1];
                int h = v[i][2];

                if(h != max(ch - abs(x - cx) - abs(y - cy), 0)){
                    flag = 0;
                    break;
                }
            }

            if(flag){
                cout << cx << " " << cy << " " << ch << endl;
                return 0;
            }
        }
    }
    return 0;
}
