// 4_abc136_d
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
    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> v;
    int cnd = 0;// now : R
    int cnt = 0;
    int num = -1;
    rep(i, n - 1){
        if(cnd == 0){
            if(s[i] == 'R') cnt++;
            else{
                vector<int> u{i, cnt};
                num++;
                v.push_back(u);
                cnt = 1;
                cnd = 1;
            }
        }else{
            if(s[i] == 'L') cnt++;
            else{
                v[num].push_back(cnt);
                cnt = 1;
                cnd = 0;
            }
        }
    }

    if(cnd == 0){
        vector<int> u{n - 1, cnt, 1};
        v.push_back(u);
    }else{
        v[num].push_back(cnt + 1);
    }

    vector<int> ans(n);
    rep(i, n){
        ans[i] = 0;
    }

    rep(i, v.size()){
        int l_point = v[i][0];
        int r_num = v[i][1];
        int l_num = v[i][2];

        ans[l_point - 1] += r_num / 2 + r_num % 2 + l_num / 2;
        ans[l_point] += l_num / 2 + l_num % 2 + r_num / 2;
    }

    rep(i, n){
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
