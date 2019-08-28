// 3_arc005_c
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
vector<vector<int>> c;
vector<vector<ll>> d;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> h >> w;
    c.resize(h, vector<int> (w));
    d.resize(h, vector<ll> (w));
    int sx, sy, gx, gy;
    rep(i, h){
        rep(j, w){
            char ch;
            cin >> ch;
            int tmp = 0;
            if(ch == '#') tmp = 1;

            c[i][j] = tmp;
            d[i][j] = INF;
            if(ch == 's'){
                sx = i; sy = j;
                d[sx][sy] = 0;
            }else if(ch == 'g'){
                gx = i; gy = j;
            }
        }
    }

    priority_queue<pair<ll, pair<int, int>>, vector<pair<ll, pair<int, int>>>, greater<pair<ll, pair<int, int>>>> q;
    q.push(make_pair(0, make_pair(sx, sy)));

    while(!q.empty()){
        auto nd = q.top();
        ll dst = nd.first;
        int x = nd.second.first; int y = nd.second.second;
        q.pop();

        if(x > 0){
            if(d[x - 1][y] > d[x][y] + c[x - 1][y]){
                d[x - 1][y] = d[x][y] + c[x - 1][y];
                q.push(make_pair(d[x - 1][y], make_pair(x - 1, y)));
            }
        }
        if(x < h - 1){
            if(d[x + 1][y] > d[x][y] + c[x + 1][y]){
                d[x + 1][y] = d[x][y] + c[x + 1][y];
                q.push(make_pair(d[x + 1][y], make_pair(x + 1, y)));
            }
        }
        if(y > 0){
            if(d[x][y - 1] > d[x][y] + c[x][y - 1]){
                d[x][y - 1] = d[x][y] + c[x][y - 1];
                q.push(make_pair(d[x][y - 1], make_pair(x, y - 1)));
            }
        }
        if(y < w - 1){
            if(d[x][y + 1] > d[x][y] + c[x][y + 1]){
                d[x][y + 1] = d[x][y] + c[x][y + 1];
                q.push(make_pair(d[x][y + 1], make_pair(x, y + 1)));
            }
        }
    }

    if(d[gx][gy] < 3){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    return 0;
}
