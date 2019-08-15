ll lcm(ll a, ll b){//型大丈夫か確認する
    return a / __gcd(a, b) * b;
}