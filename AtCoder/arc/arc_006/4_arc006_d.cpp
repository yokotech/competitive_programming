// 4_arc006_d
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

int h, w;
vector<vector<char>> m;
vector<vector<int>> visited;

void init_visited(){
    rep(i, h){
        rep(j, w){
            visited[i][j] = 0;
        }
    }
}

void dfs_ty(int x, int y){
    visited[x][y] = 1;
    if(x > 0 && visited[x - 1][y] == 0 && m[x - 1][y] == 'o'){
        dfs_ty(x - 1, y);
    }
    if(x < h - 1 && visited[x + 1][y] == 0 && m[x + 1][y] == 'o'){
        dfs_ty(x + 1, y);
    }
    if(y > 0 && visited[x][y - 1] == 0 && m[x][y - 1] == 'o'){
        dfs_ty(x, y - 1);
    }
    if(y < w - 1 && visited[x][y + 1] == 0 && m[x][y + 1] == 'o'){
        dfs_ty(x, y + 1);
    }
}

int tateyoko(){
    int cnt = 0;
    init_visited();
    rep(i, h){
        rep(j, w){
            if(m[i][j] == '.') continue;
            if(!visited[i][j]){
                dfs_ty(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs_naname(int x, int y){
    visited[x][y] = 1;
    if(x > 0 && y > 0 && visited[x - 1][y - 1] == 0 && m[x - 1][y - 1] == 'o'){
        dfs_naname(x - 1, y - 1);
    }
    if(x > 0 && y < w - 1 && visited[x - 1][y + 1] == 0 && m[x - 1][y + 1] == 'o'){
        dfs_naname(x - 1, y + 1);
    }
    if(x < h - 1  && y > 0 && visited[x + 1][y - 1] == 0 && m[x + 1][y - 1] == 'o'){
        dfs_naname(x + 1, y - 1);
    }
    if(x < h - 1 && y < w - 1 && visited[x + 1][y + 1] == 0 && m[x + 1][y + 1] == 'o'){
        dfs_naname(x + 1, y + 1);
    }
}

int naname(){
    int cnt = 0;
    init_visited();
    rep(i, h){
        rep(j, w){
            if(m[i][j] == '.') continue;
            if(!visited[i][j]){
                dfs_naname(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

void dfs_tynaname(int x, int y){
    visited[x][y] = 1;
    if(x > 0 && visited[x - 1][y] == 0 && m[x - 1][y] == 'o'){
        dfs_tynaname(x - 1, y);
    }
    if(x < h - 1 && visited[x + 1][y] == 0 && m[x + 1][y] == 'o'){
        dfs_tynaname(x + 1, y);
    }
    if(y > 0 && visited[x][y - 1] == 0 && m[x][y - 1] == 'o'){
        dfs_tynaname(x, y - 1);
    }
    if(y < w - 1 && visited[x][y + 1] == 0 && m[x][y + 1] == 'o'){
        dfs_tynaname(x, y + 1);
    }

    if(x > 0 && y > 0 && visited[x - 1][y - 1] == 0 && m[x - 1][y - 1] == 'o'){
        dfs_tynaname(x - 1, y - 1);
    }
    if(x > 0 && y < w - 1 && visited[x - 1][y + 1] == 0 && m[x - 1][y + 1] == 'o'){
        dfs_tynaname(x - 1, y + 1);
    }
    if(x < h - 1  && y > 0 && visited[x + 1][y - 1] == 0 && m[x + 1][y - 1] == 'o'){
        dfs_tynaname(x + 1, y - 1);
    }
    if(x < h - 1 && y < w - 1 && visited[x + 1][y + 1] == 0 && m[x + 1][y + 1] == 'o'){
        dfs_tynaname(x + 1, y + 1);
    }
}

int tynaname(){
    int cnt = 0;
    init_visited();
    rep(i, h){
        rep(j, w){
            if(m[i][j] == '.') continue;
            if(!visited[i][j]){
                dfs_tynaname(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    m.resize(h, vector<char> (w));
    visited.resize(h, vector<int> (w));
    rep(i, h){
        rep(j, w){
            cin >> m[i][j];
        }
    }

    int x = tateyoko();
    int y = naname();
    int z = tynaname();

    int a = (-x + -2 * y + 19 * z) / 7;
    int b = (-3 * x + y + 8 * z) / 7;
    int c = (4 * x + y - 20 * z) / 7;

    cout << a << " " << b << " " << c << endl;

    return 0;
}
