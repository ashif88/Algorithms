/**
 * author: Ashif Akhtar
 **/
#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
public:
    int n, setsize;
    vector<int> parent, rank;
    UnionFind(int a)
    {
        n = setsize = a;
        parent.resize(n + 1);
        rank.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i, rank[i] = 1;
    }
    int find(int x)
    {
        if (x != parent[x])
            return parent[x] = find(parent[x]);
        return x;
    }
    void merge(int x, int y)
    {
        int xroot = find(x), yroot = find(y);
        if (xroot != yroot)
        {
            if (rank[xroot] >= rank[yroot])
            {
                parent[yroot] = xroot;
                rank[xroot] += rank[yroot];
            }
            else
            {
                parent[xroot] = yroot;
                rank[yroot] += rank[xroot];
            }
            setsize--;
        }
    }
    void reset()
    {
        setsize = n;
        for (int i = 1; i <= n; i++)
            parent[i] = i, rank[i] = 1;
    }
    int size() { return setsize; }
    void print()
    {
        for (int i = 1; i <= n; i++)
            cout << i << " -> " << parent[i] << endl;
    }
};

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}