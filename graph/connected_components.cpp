#include <bits/stdc++.h>
using namespace std;

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

typedef vector<int> vi;
typedef vector<vi> vii;

vii buildGraph(int V, vii &edges)
{
    vii adj(V);
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

void dfs(int u, vii &adj, vi &vis, vi &component)
{
    vis[u] = 1;

    component.push_back(u);

    for (int neighbor : adj[u])
    {
        if (!vis[neighbor])
        {
            dfs(neighbor, adj, vis, component);
        }
    }
}

vii getComponents(int V, vii &edges)
{
    vii adj = buildGraph(V, edges);
    vi visited(V, 0);

    vii res;

    int i;
    FOR(i, V)
    {
        if (!visited[i])
        {
            vi component;
            dfs(i, adj, visited, component);

            res.push_back(component);
        }
    }

    return res;
}