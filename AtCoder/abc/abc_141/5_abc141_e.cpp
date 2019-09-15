// 5_abc141_e
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

vector<pair<string, int>> tmp;


//string func(string t){
//    string alpha = "abcdefghijklmnopqrstuvwxyz";
//    int l = t.length();
//    int flag = 1;
//    rep(i, l){
//        if(t[i] != 'z'){
//            flag = 0;
//            break;
//        }
//    }
//    if(flag){
//        return t + 'a';
//    }
//
//    if(t[l - 1] != 'z'){
//        int a = t[l - 1] - 'a';
//        t[l - 1] = alpha[a + 1];
//        return t;
//    }else{
//        return func(t.substr(0, l - 1));
//    }
//}

bool func2(string a, string b){
    // aがbを接頭辞に含まなかったらtrue
    int na = a.length();
    int nb = b.length();
    if(na < nb){
        return true;
    }

    if(a.substr(0, nb) == b){
        return false;
    }else{
        return true;
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    tmp.resize(n);

    rep1(i, n){
        string t = s.substr(n - i, i);
        tmp[i - 1] = make_pair(t, n - i);
    }
    sort(tmp.begin(), tmp.end());

    vector<string> suf_s(n);
    vector<int> suf_i(n);
    rep(i, n){
        suf_s[i] = tmp[i].first;
        suf_i[i] = tmp[i].second;
    }

    int len = 0;
    for(int l = 1; l <= n / 2; l++){
        int flag = 0;
        for(int i = 0; i <= n - 2 * l; i++){
            // s.substr(i, l)を検索してi + lより先に出てくるやつがいたら更新
            string t = s.substr(i, l);
            auto itr = lower_bound(suf_s.begin(), suf_s.end(), t);
            if(itr != suf_s.end()){
                int k = distance(suf_s.begin(), itr);
                for(int j = k; j < n; j++){
                    // suf_s[k]がtを含まなかったらbreak
                    if(func2(suf_s[k], t)) break;

                    if(suf_i[k] >= i + l){
                        len = l;
                        flag = 1;
                        break;
                    }
                }
            }
            if(flag) break;
        }
        if(flag == 0) break;
    }
    cout << len << endl;


    return 0;
}
