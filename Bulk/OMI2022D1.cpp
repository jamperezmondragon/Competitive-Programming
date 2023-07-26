#include <iostream>
#include <vector>
using namespace std;
using ll = long long int;
int const Mxn = 1e5 + 1;

vector<pair<int, int>> Adj[Mxn], Queries[Mxn];
ll dp[Mxn], dp2[Mxn], Ans[Mxn], psum[Mxn];
int preorder[Mxn],  hijo[Mxn], n, q, cnt = 1;

struct segementri { // segment tree de máximos. 
    vector<ll> segs;
    void init() { segs.assign(Mxn<<1, -2000000000000);}
    void upd(int i, ll val) {
        segs[i += Mxn] = val;
        for (i >>= 1; i; i >>= 1) {
            segs[i] = max(segs[i<<1], segs[i<<1|1]);
        }
    }
    ll query(int l, int r, ll ans = -2000000000000) {
        for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
            if (l&1) ans = max(ans, segs[l++]);
            if (r&1) ans = max(ans, segs[--r]);
        }
        return ans;
    }
} segtree;

void dfs_precalc(int node, int parent, ll W) { // Dfs para calcular los dos hijos con la distancia más larga a una hoja.
    psum[node] = psum[parent] + W;
    dp[node] = 0, dp2[node] = 0;
    preorder[node] = cnt++;

    for (auto [child, w] : Adj[node]) {
        if (child == parent) continue;
        dfs_precalc(child, node, w);
        if (dp[child] + w > dp[node]) {
            dp2[node] = dp[node]; dp[node] = dp[child] + w;
            hijo[node] = child;
        } else if (dp[child] + w > dp2[node]) {
            dp2[node] = dp[child] + w;
        }
    }
}

void dfs_ans(int node, int parent) { // Dfs para calcular la respuesta. 
    for (auto [x, idx] : Queries[node]) {// respondemos todas las queries del tipo, camino más largo en la zona x, que pasa por node.
        if (x != node) Ans[idx] = segtree.query(preorder[x], preorder[node]) + psum[node] + dp[node];
        else Ans[idx] = 0; // si el nodo y la zona son la misma, la respuesta es dp[node] + dp2[node].
        Ans[idx] = max(Ans[idx], dp[node] + dp2[node]);
    }
    segtree.upd(preorder[node], dp[node] - psum[node]); // en cualquier momento, el segmentree tiene los valores de todos los ancestros del nodo que está procesando.
    for (auto [child, x] : Adj[node]) {
        if (child == parent) continue;
        if (child == hijo[node]) segtree.upd(preorder[node], dp2[node] - psum[node]); // si entramos en la rama del camino más largo hacia una hoja, hay que cambiar el valor que habíamos puesto en el segmentree.
        dfs_ans(child, node);
        if (child == hijo[node]) segtree.upd(preorder[node], dp[node] - psum[node]); // cuando salimos de esa rama, regresamos el valor a como estaba anteriormente.
    }
    segtree.upd(preorder[node], -2000000000000); //regresamos el valor al default.
}

int main() {
    scanf("%d %d",&n,&q);
    for (int i = 1, x, y, z; i < n; i++) {
        scanf("%d %d %d",&x,&y,&z);
        Adj[x].push_back({y, z});
        Adj[y].push_back({x, z});
    }
    for (int i = 0, a, b; i < q; i++) {
        scanf("%d %d",&a,&b);
        Queries[a].push_back({b, i});
    }
    psum[1] = 0;
    segtree.init();
    dfs_precalc(1, 1, 0);
    dfs_ans(1, 1);
    for (int i = 0; i < q; i++) {
        printf("%d\n",Ans[i]);
    }
}
