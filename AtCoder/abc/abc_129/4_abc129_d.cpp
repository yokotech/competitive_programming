// 4_abc129_d
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
    int h, w;
    cin >> h >> w;
    vector<vector<char>> m(h, vector<char>(w));
    rep(i, h){
        rep(j, w){
            cin >> m[i][j];
        }
    }
    vector<vector<int>> vert(h, vector<int>(w));
    vector<vector<int>> horz(h, vector<int>(w));
    rep(i, h){
        rep(j, w){
            vert[i][j] = 0;
            horz[i][j] = 0;
        }
    }

    rep(i, h){
        int s = 0;
        int t = 0;
        int cnt, flag;
        if(m[i][0] == '#'){
            flag = 1;
            cnt = 0;
        }else{
            flag = 0;
            cnt = 1;
        }

        if(w == 1){
            horz[i][0] = cnt;
            continue;
        }

        for(int j = 1; j < w; j++){
            if(flag){
                if(m[i][j] == '#') continue;
                else{
                    flag = 0;
                    s = j;
                    cnt = 1;
                }
            }else{
                if(m[i][j] == '.'){
                    cnt++;
                    if(j == w - 1){
                        t = j;
                        for(int k = s; k <= t; k++){
                            horz[i][k] = cnt;
                        }
                        flag = 1;
                        cnt = 0;
                    }
                }else{
                    t = j;
                    for(int k = s; k <= t; k++){
                        horz[i][k] = cnt;
                    }
                    flag = 1;
                    cnt = 0;
                }
            }
        }
    }

    rep(j, w){
        int s = 0;
        int t = 0;
        int cnt, flag;
        if(m[0][j] == '#'){
            flag = 1;
            cnt = 0;
        }else{
            flag = 0;
            cnt = 1;
        }

        if(h == 1){
            vert[0][j] = cnt;
            continue;
        }

        for(int i = 1; i < h; i++){
            if(flag){
                if(m[i][j] == '#') continue;
                else{
                    flag = 0;
                    s = i;
                    cnt = 1;
                }
            }else{
                if(m[i][j] == '.'){
                    cnt++;
                    if(i == h - 1){
                        t = i;
                        for(int k = s; k <= t; k++){
                            vert[k][j] = cnt;
                        }
                        flag = 1;
                        cnt = 0;
                    }
                }else{
                    t = i;
                    for(int k = s; k <= t; k++){
                        vert[k][j] = cnt;
                    }
                    flag = 1;
                    cnt = 0;
                }
            }
        }
    }

    int ans = 0;
    rep(i, h){
        rep(j, w){
            ans = max(ans, horz[i][j] + vert[i][j] - 1);
        }
    }

    cout << ans << endl;

    return 0;
}
