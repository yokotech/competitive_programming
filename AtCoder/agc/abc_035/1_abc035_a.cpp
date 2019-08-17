// 1_abc035_a
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
    vector<int> a(n);
    rep(i, n){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    if(a[0] == 0 && a[n - 1] == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(n % 3 != 0){
        cout << "No" << endl;
        return 0;
    }

    unsigned int x, y, z;
    x = a[0];
    y = a[n / 3];
    z = a[2 * n / 3];
    int flag = 0;
    rep(i, n / 3){
        if(a[i] != x) flag = 1;
    }
    for(int i = n / 3; i < 2 * n / 3; i++){
        if(a[i] != y) flag = 1;
    }
    for(int i = 2 * n / 3; i < n; i++){
        if(a[i] != z) flag = 1;
    }

    if((x ^ y) != z) flag = 1;

    if(flag){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
    return 0;
}
