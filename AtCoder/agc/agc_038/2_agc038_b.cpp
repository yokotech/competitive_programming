// 2_agc038_b
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

    int n, k;
    cin >> n >> k;


    vector<int> p(n);
    rep(i, n){
        cin >> p[i];
    }

    if(n == k){
        cout << 1 << endl;
        return 0;
    }    if(n == k){
        cout << 1 << endl;
        return 0;
    }

    // 各区間での最小最大を記録
    vector<int> mi(n - k);
    vector<int> ma(n - k);

    priority_queue<int> qma;
    priority_queue<int, vector<int>, greater<int>> qmi;
    set<int> s;

    rep(i, k + 1){
        s.insert(p[i]);
        qma.push(p[i]);
        qmi.push(p[i]);
    }
    mi[0] = qmi.top();
    ma[0] = qma.top();


    for(int i = 1; i <= n - k - 1; i++){
        s.erase(p[i - 1]);
        s.insert(p[k + i]);
        qma.push(p[k + i]);
        qmi.push(p[k + i]);
        while(1){
            int a = qmi.top();
            if(s.count(a)){
                mi[i] = a;
                break;
            }else{
                qmi.pop();
            }
        }
        while(1){
            int a = qma.top();
            if(s.count(a)){
                ma[i] = a;
                break;
            }else{
                qma.pop();
            }
        }
    }

    int cnt = 0;
    vector<int> hoge(n);
    rep(i, n){
        hoge[i] = 0;
    }
    rep(i, n - k){
        if(mi[i] == p[i] && ma[i] == p[i + k]){
            cnt++;
            hoge[i + 1] = 1;
        }
    }

    int l = 1;
    int now = p[0];
    int ptr = -1;

    for(int i = 1; i < n; i++){
        if(p[i] > now){
            l++;
            if(l == k){
                ptr = i;
                break;
            }
        }else{
            l = 1;
        }
        now = p[i];
    }
    if(ptr == -1 || ptr + 1 >= n){
        cout << n - k + 1 - cnt << endl;
        return 0;
    }

    now = p[ptr + 1];
    l = 1;
    for(int i = ptr + 2; i < n; i++){
        if(p[i] > now){
            l++;
            if(l == k){
                l = k - 1;
                cnt++;
                hoge[i - k + 1] = 1;
            }
        }else{
            l = 1;
        }
        now = p[i];
    }
//    cout << n - k + 1 - cnt << endl;

    int ans = n - k + 1;
    rep(i, n){
        if(hoge[i]) ans--;
    }
    cout << ans << endl;
    return 0;
}
