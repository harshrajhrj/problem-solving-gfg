#include <bits/stdc++.h>

#define FOR(x, to) for (x = 0; x < (to); x++)
#define FORI(x, to) for (x; x < (to); x++)
#define FORR(x, arr) for (auto &x : arr)
#define ALL(a) (a.begin(), a.end())
#define mem(a, n) memset(a, n, sizeof(a))

using std::cout, std::endl;
using std::unordered_map;
using std::vector;

typedef vector<int> vi;
typedef vector<vi> vii;

int findParent(vi &parent, int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent, parent[x]);
}

void unionSets(vi &parent, int x, int y)
{
    int px = findParent(parent, x);
    int py = findParent(parent, y);

    if (px != py)
        parent[px] = py;
}

vii getComponents(int V, vii &edges)
{
    vi parent(V);

    int i;
    FOR(i, V)
    {
        parent[i] = i;
    }

    // Union sets using edge list
    for (auto &edge : edges)
    {
        unionSets(parent, edge[0], edge[1]);
    }

    // Applying path compression
    FOR(i, V)
    {
        parent[i] = findParent(parent, i);
    }

    // Grouping nodes by their parents
    unordered_map<int, vi> group;

    FOR(i, V)
    {
        group[parent[i]].push_back(i);
        // cout << parent[i] << " " << i << endl;
    }

    // Collecting nodes by group
    vii res;
    for (auto &key : group)
    {
        res.push_back(key.second);
    }

    return res;
}

int main()
{
    int V = 5;

    // Edge list as vector of vectors
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {3, 4}};

    // Find connected components using DSU
    vector<vector<int>> res = getComponents(V, edges);

    for (const auto &comp : res)
    {
        for (int node : comp)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}