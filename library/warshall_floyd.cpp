// 参照渡しで書き直したほうが良いのかも
void warshall_floyd(){//globalでN * N距離行列 distが存在する前提
    rep(k, N){
        rep(i, N){
            rep(j, N){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                dist[j][i] = dist[i][j];
            }
        }
    }
    return;
}