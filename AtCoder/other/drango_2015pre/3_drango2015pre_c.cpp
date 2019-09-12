// 3_drango2015pre_c
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

vector<double> dp;
vector<vector<double>> ncr;

void calc_ncr(int k){

    for(int n = 1; n <= k; n++){
        ncr[n][0] = 1;
        ncr[n][1] = n;
        for(int r = 2; r <= n; r++){
            ncr[n][r] = ncr[n][r - 1] / r * (n - r + 1);
        }
    }
}

int hantei(int g, int c, int p){
    char ch;
    if((g == 0 && c == 0) || (c == 0 && p == 0) || (p == 0 && g == 0)){
        return g + c + p;
    }

    if(g == c && c == p){
        // pattern 2-3
        return g + c + p;
    }

    // g, c, pいずれも1人以上
    if(g != 0 && c != 0 && p != 0){
        if((g < c && g < p) || (c < g && c < p) || (p < g && p < c)){
            // pattern2-1
            if(g == min({g, c, p})) return g;
            else if(c == min({g, c, p})) return c;
            else return p;
        }

        if((g < p && c < p)){
            return g;
        }else if((c < g && p < g)){
            return c;
        }else{
            return p;
        }
    }

    if(g == 0){
        if(c <= p) return c;
        else return p;
    }
    if(c == 0){
        if(p <= g) return p;
        else return g;
    }
    if(p == 0){
        if(g <= c) return g;
        else return c;
    }
}

double dfs(int n){
    if(dp[n] >= 0) return dp[n];

    double expect = 0.0;

    double p_aiko = pow(1.0 / 3.0, n) * 3;
    if(n % 3 == 0){
        double tmp = pow(1.0 / 3.0, n);
        tmp *= ncr[n][n / 3] * ncr[2 * n / 3][n / 3];
        p_aiko += tmp;
    }

    for(int g = 0; g <= n; g++){
        for(int c = 0; c <= n - g; c++){
            int p = n - g - c;

            double p_gcp = pow(1.0 / 3.0, n) * ncr[n][g] * ncr[n - g][c];

            int a = hantei(g, c, p);
            if(a == n) continue;

            expect += p_gcp * (dfs(a) + 1);
        }
    }
    expect = (expect + p_aiko) / (1.0 - p_aiko);
    dp[n] = expect;
    return expect;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    dp.resize(n + 1);
    ncr.resize(n + 1, vector<double> (n + 1));
    rep(i, n + 1){
        dp[i] = -1;
    }
    calc_ncr(n);


    dp[0] = 0;
    dp[1] = 0;

    cout << setprecision(15) << dfs(n) << endl;

    return 0;
}
