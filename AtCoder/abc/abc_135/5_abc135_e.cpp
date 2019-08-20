// 5_abc135_e
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int k, x, y;
    cin >> k;
    cin >> x >> y;

    int d = abs(x) + abs(y);
    if(k % 2 == 0 && (d % k) % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    int nx = 0;
    int ny = 0;
    int dx = 0;
    int dy = 0;

    if(d % k != 0){
        int m = d % k;
        if(k % 2 == 0){
            dx = k - m / 2;
            dy = m / 2;
        }else{
            if(m % 2 == 1){
                dx = (k - m) / 2;
                dy = (k + m) / 2;
            }else{
                dx = (k + m) / 2;
                dy = (k - m) / 2;
            }
        }
    }
    if(x > 0){
        nx = -dx;
    }else{
        nx = dx;
    }
    if(y > 0) ny = dy;
    else ny = -dy;

    ll s = (abs(x - nx) + abs(y - ny)) / k;
    cout << s << endl;
    if(nx != 0 || ny != 0){
        cout << nx << " " << ny << endl;
    }

    int residue;
    if(x - nx > 0){
        while(x - nx > k){
            cout << k << " " << 0 << endl;
            nx += k;
        }
        cout << x - nx << " ";
        residue = k - (x - nx);
    }else{
        while(nx - x > k){
            cout << -k << " " << 0 << endl;
            nx -= k;
        }
        cout << nx - x << " ";
        residue = k - (nx - x);
    }

    if(y - ny > 0){
        cout << residue << endl;
        ny += residue;
        while(y - ny > 0){
            cout << 0 << " " << k << endl;
            ny += k;
        }
    }else{
        cout << -residue << endl;
        ny -= residue;
        while(ny - y > k){
            cout << 0 << " " << -k << endl;
            ny -= k;
        }
    }


    return 0;
}
