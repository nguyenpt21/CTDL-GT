
#include <iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;
vector<bool> visited;
map<int, vector<int>> adj_list;
void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        cout << t << " ";
        for (int x : adj_list[t])
        {
            if (!visited[x])
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }
}
void dfs(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int x : adj_list[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
}
int main()
{
    int v, e; cin >> v >> e;
    visited = vector<bool>(v, false);
    for (int i = 0; i < e; i++)
    {
        int x, y; cin >> x >> y;
        adj_list[x].push_back(y);
        adj_list[y].push_back(x);
    }
    cout << "DFS: ";
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            dfs(i);
    }
    visited = vector<bool>(v, false);
    cout << "\nBFS: ";
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            bfs(i);
    }
}

