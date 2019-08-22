// 2_arc001_b
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
    int a, b;
    cin >> a >> b;

    if(a > b) swap(a, b);

    int ans = 0;
    while(b - a >= 10){
        a += 10;
        ans++;
    }

    if(b - a == 9){
        cout << ans + 2 << endl;
    }else if(b - a == 8){
        cout << ans + 3 << endl;
    }else if(b - a == 7){
        cout << ans + 3 << endl;
    }else if(b - a == 6){
        cout << ans + 2 << endl;
    }else if(b - a == 5){
        cout << ans + 1 << endl;
    }else if(b - a == 4){
        cout << ans + 2 << endl;
    }else if(b - a == 3){
        cout << ans + 3 << endl;
    }else if(b - a == 2){
        cout << ans + 2 << endl;
    }else if(b - a == 1){
        cout << ans + 1 << endl;
    }else{
        cout << ans << endl;
    }


    return 0;
}
