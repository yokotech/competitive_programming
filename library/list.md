# Library一覧
- Eratosthenesの篩
- gcd
- is_prime
- union_find
- Warshall_Floyd
- LIS(最長増加部分列)

## 既存のものの説明

## 作りたいLibrary
- Dijkstra
- Bellman-Ford
- nPr mod k
- トポロジカルソート
- 二部グラフ判定
- 二部マッチング
- 最大フロー・最小カット
- Kruscal法
- Prim法

以下古いやつ
# Library一覧
- [Library一覧](#library%E4%B8%80%E8%A6%A7)
  - [既存のLibrary](#%E6%97%A2%E5%AD%98%E3%81%AElibrary)
    - [is_prime.cpp : 素数判定](#isprimecpp--%E7%B4%A0%E6%95%B0%E5%88%A4%E5%AE%9A)
    - [lcm.cpp : 最小公倍数](#lcmcpp--%E6%9C%80%E5%B0%8F%E5%85%AC%E5%80%8D%E6%95%B0)
    - [warshall_floyd.cpp : Warshall-Floyd法](#warshallfloydcpp--warshall-floyd%E6%B3%95)
    - [dijkstra.cpp : Dijkstra法](#dijkstracpp--dijkstra%E6%B3%95)
    - [kruskal.cpp : Kruskal法](#kruskalcpp--kruskal%E6%B3%95)
    - [bellman_ford.cpp : Bellman-Ford法](#bellmanfordcpp--bellman-ford%E6%B3%95)
    - [union_find_tree.cpp : Union-Find木](#unionfindtreecpp--union-find%E6%9C%A8)
    - [Eratosthenesの篩](#eratosthenes%E3%81%AE%E7%AF%A9)
    - [nprmodk](#nprmodk)
    - [topological_sort](#topologicalsort)
    - [is_bipartite](#isbipartite)
  - [作ったほうが良さそうなLibrary](#%E4%BD%9C%E3%81%A3%E3%81%9F%E3%81%BB%E3%81%86%E3%81%8C%E8%89%AF%E3%81%95%E3%81%9D%E3%81%86%E3%81%AAlibrary)
    - [Prim法](#prim%E6%B3%95)
    - [二部マッチング](#%E4%BA%8C%E9%83%A8%E3%83%9E%E3%83%83%E3%83%81%E3%83%B3%E3%82%B0)
    - [最大フロー，最小カット](#%E6%9C%80%E5%A4%A7%E3%83%95%E3%83%AD%E3%83%BC%E6%9C%80%E5%B0%8F%E3%82%AB%E3%83%83%E3%83%88)
## 既存のLibrary
### is_prime.cpp : 素数判定

### lcm.cpp : 最小公倍数

### warshall_floyd.cpp : Warshall-Floyd法
任意の2点間の最小距離を求める．O(V^3)

### dijkstra.cpp : Dijkstra法
SoundHound2018でverify．少し遅いがTLEしたらvectorを通常の配列に変えれば良いと思う．
O((E + V)logV)

### kruskal.cpp : Kruskal法
AOJ grl2_aでverify.
ソートがボトルネックでO(ElogE)．
最小全域木の重み出力するようにしてる．

### bellman_ford.cpp : Bellman-Ford法
AOJ grl1_bでverify．
O(V^2)
負閉路検出で"NEGATIVE CYCLE"，非検出で全頂点の始点からの距離出力．

### union_find_tree.cpp : Union-Find木

### Eratosthenesの篩
n以下の素数全部vectorに入れて返す 
O(nloglogn)

### nprmodk
nCr mod kを計算する．
COMinitがO(n)でこれがボトルネック．COM(n, r)はO(1)

### topological_sort
nodeのvectorで表現した有向グラフ(自分の前の点もnodeからわかる)をトポロジカルソートして，逆順に`vector<int> l`に入れるやつ．
日経コン2019のdで使った．

### is_bipartite
二部グラフ判定．「連結な無向グラフ」を前提として二部グラフかどうかを変数biに入れる．
要するにDFSなのでO(V + E)

## 作ったほうが良さそうなLibrary

### Prim法

### 二部マッチング

### 最大フロー，最小カット
