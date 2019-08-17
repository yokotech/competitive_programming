// 1_agc034_a
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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;

    string s;
    cin >> s;
    int flag = 1;

    for(int i = a; i < c; i++){
        if(s[i] == '#' && s[i + 1] == '#'){
            flag = 0;
            break;
        }
    }
    for(int i = b; i < d; i++){
        if(s[i] == '#' && s[i + 1] == '#'){
            flag = 0;
            break;
        }
    }

    if(c > d){
        int tmp = 0;
        for(int i = b; i <= d ; i++){
            if(s[i - 1] == '.' && s[i] == '.' && s[i + 1] == '.'){
                tmp = 1;
                break;
            }
        }
        if(tmp == 0) flag = 0;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
