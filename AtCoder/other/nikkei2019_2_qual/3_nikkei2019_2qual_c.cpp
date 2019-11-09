// 3_nikkei2019_2qual_c
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

void make_error(){// WAとREの違いでどこで終わってるか見極める
    int a = 1;
    int b = 0;
    int c = a / b;
    cout << c << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> ac(n);
    vector<int> bc(n);
    vector<pair<int, int>> pa(n);
    vector<pair<int, int>> pb(n);
    rep(i, n){
        cin >> a[i];
        ac[i] = a[i];
        pa[i] = make_pair(a[i], i);
    }
    rep(i, n){
        cin >> b[i];
        bc[i] = b[i];
        pb[i] = make_pair(b[i], i);
    }
    sort(ac.begin(), ac.end());
    sort(bc.begin(), bc.end());

    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end());
    rep(i, n){
        pa[i].first = i;
        pb[i].first = i;
        swap(pa[i].first, pa[i].second);
        swap(pb[i].first, pb[i].second);
    }
    sort(pa.begin(), pa.end());
    sort(pb.begin(), pb.end());
    // pa, pbのsecondにa[i], b[i]がsort後にどこに行ったか(p, q)が入ってる

    rep(i, n){
        if(ac[i] > bc[i]){
            cout << "No" << endl;
            return 0;
        }
    }

    vector<int> v(n);
    for(int i = 0; i < n - 1; i++){
        if(ac[i + 1] <= bc[i]) v[i] = 0;
        else v[i] = 1;
    }
    vector<int> s(n);
    s[0] = v[0];
    for(int i = 1; i < n - 1; i++){
        s[i] = s[i - 1] + v[i];
    }

    rep(i, n){
        if(a[i] > b[i]) continue;

        int p = pa[i].second;
        int q = pb[i].second;

        while(p < n - 1){
            if(b[p] == b[p + 1]) p++;
            else break;
        }
        while(q > 0){
            if(a[q] == a[q - 1]) q--;
            else break;
        }

        if(p >= q){
            make_error();
            cout << "Yes" << endl;
            return 0;
        }

        // n - 1でセグフォ出そう
        if(p == 0){
            if(s[0] == 1) continue;
            else{
                if(s[q - 1] == 0){
                    cout << "Yes" << endl;
                    return 0;
                }else{
                    continue;
                }
            }
        }
        if(s[q - 1] - s[p - 1] == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}
