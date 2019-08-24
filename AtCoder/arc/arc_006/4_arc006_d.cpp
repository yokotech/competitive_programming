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
int xmin, xmax, ymin, ymax;
int masu;
int a = 0; int b = 0; int c = 0;

void init_visited(){
    rep(i, h){
        rep(j, w){
            visited[i][j] = 0;
        }
    }
}

void dfs_tynaname(int x, int y){
    visited[x][y] = 1;
    masu++;
    if(x < xmin) xmin = x;
    if(x > xmax) xmax = x;
    if(y < ymin) ymin = y;
    if(y > ymax) ymax = y;

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

void tynaname(){
    init_visited();
    rep(i, h){
        rep(j, w){
            if(m[i][j] == '.') continue;
            if(!visited[i][j]){
                masu = 0;
                xmin = i;
                xmax = i;
                ymin = j;
                ymax = j;
                dfs_tynaname(i, j);

                int saizu = (xmax - xmin + 1) / 5;
                int jou = pow(saizu, 2);
                if(masu == 12 * jou) a++;
                else if(masu == 16 * jou) b++;
                else if(masu == 11 * jou) c++;
            }
        }
    }
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

    tynaname();
    cout << a << " " << b << " " << c << endl;
    return 0;
}
