// 4_abc134_d
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
    int n;
    cin >> n;
    vector<int> a(n + 1);
    rep1(i, n){
        cin >> a[i];
    }

    if(n == 1){
        if(a[1] == 1){
            cout << 1 << endl;
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
        return 0;
    }

    vector<int> b(n + 1);
    for(int j = n; j > n / 2; j--){
        if(a[j] == 1) b[j] = 1;
        else b[j] = 0;
    }
    for(int i = 2; i <= n; i++){
        for(int j = n / i; j > n / (i + 1); j--){
            int cnt = 0;
            for(int k = 2 * j; k <= n; k += j){
                if(b[k] == 1) cnt++;
            }
            if(a[j] == 0){
                if(cnt % 2 == 0) b[j] = 0;
                else b[j] = 1;
            }else{
                if(cnt % 2 == 0) b[j] = 1;
                else b[j] = 0;
            }
        }
    }
    int m = 0;
    rep1(i, n){
        if(b[i] == 1) m++;
    }

    cout << m << endl;
    rep1(i, n){
        if(b[i] == 1) cout << i << " ";
    }
    cout << endl;

    return 0;
}
