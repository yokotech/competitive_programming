// 5_abc139_e
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
    int n;
    cin >> n;

    int sum_game = 0;
    vector<queue<int>> a(n);

    rep(i, n){
        queue<int> que;
        rep(j, n - 1){
            int b;
            cin >> b;
            b--;
            que.push(b);
        }
        a[i] = que;
    }

    ll ans = 1;
    queue<int> q;
    queue<int> p;
    set<int> visited;

    for(int i = 0; i < n - 1; i++){
        auto itr = visited.find(i);
        if(itr != visited.end()){
            continue;
        }
        int x = a[i].front();
        if (visited.find(x) == visited.end()) {
            int y = a[x].front();
            if (y  == i) {
                a[i].pop();
                a[x].pop();
                q.push(i);
                q.push(x);
                visited.insert(i);
                visited.insert(x);
                sum_game++;
            }
        }
    }


    int flag = 1;
    while(flag){// ここの条件変える！
        flag = 0;
        if(ans % 2 == 1){
            int tmp = q.size();
            set<int> v;
            while(!q.empty()){
                int x = q.front();
                q.pop();
                auto itr = v.find(x);
                if(itr != v.end()) continue;

                if(a[x].empty()) continue;
                int y = a[x].front();
                if(a[y].empty()) continue;
                itr = v.find(y);
                if(a[y].front() == x && itr == v.end()){
                    flag = 1;
                    a[y].pop();
                    a[x].pop();
                    p.push(y);
                    p.push(x);
                    v.insert(y);
                    v.insert(x);
                    sum_game++;
                }
            }
        }else{
            set<int> v;
            while(!p.empty()){
                int tmp = p.size();
                int x = p.front();
                p.pop();
                auto itr = v.find(x);
                if(itr != v.end()) continue;

                int y = a[x].front();
                if(a[x].empty()) continue;
                if(a[y].empty()) continue;
                itr = v.find(y);
                if(a[y].front() == x && itr == v.end()){
                    flag = 1;
                    a[y].pop();
                    a[x].pop();
                    q.push(y);
                    q.push(x);
                    v.insert(y);
                    v.insert(x);
                    sum_game++;
                }
            }
        }
        ans++;
    }

    if(sum_game == n * (n - 1) / 2){
        cout << ans - 1 << endl;
    }else{
        cout << -1 << endl;
    }


    return 0;
}
