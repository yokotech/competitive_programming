// 1_agc033_a
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

vector<vector<char>> m;
vector<vector<int>> d;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h, w;
    cin >> h >> w;
    m.resize(h, vector<char>(w));
    d.resize(h, vector<int>(w));

    queue<pair<int, int>> q;

    rep(i, h){
        rep(j, w){
            d[i][j] = -1;
            cin >> m[i][j];
            if(m[i][j] == '#'){
                d[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if(x > 0 && d[x - 1][y] == -1){
            d[x - 1][y] = d[x][y] + 1;
            q.push(make_pair(x - 1, y));
        }
        if(x < h - 1 && d[x + 1][y] == -1){
            d[x + 1][y] = d[x][y] + 1;
            q.push(make_pair(x + 1, y));
        }
        if(y > 0 && d[x][y - 1] == -1) {
            d[x][y - 1] = d[x][y] + 1;
            q.push(make_pair(x, y - 1));
        }
        if(y < w - 1 && d[x][y + 1] == -1){
            d[x][y + 1] = d[x][y] + 1;
            q.push(make_pair(x, y + 1));
        }
    }

    int ans = 0;
    rep(i, h){
        rep(j, w){
            if(d[i][j]> ans) ans = d[i][j];
        }
    }

    cout << ans << endl;
    return 0;
}
