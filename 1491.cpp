//剪枝版
#include <bits/stdc++.h>
using namespace std;

const int N = 15, M = 50;

int n, m;

bool fr[N][N];
bool st[N];
int buf[N];
int idx;

long long ans;

//u:已经有了多少层
void dfs(int u)
{
    if (u == n)
    {           
        if (!fr[buf[n]][buf[1]])
            ans++;

        return;
    }

    for (int i = 2; i <= n; i++)
    {
        if (st[i] || fr[i][buf[idx]])
            continue;

        st[i] = true;
        buf[++idx] = i;
        dfs(u + 1);
        --idx;
        st[i] = false;
    }
}

//围一圈，默认从1号开始
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        fr[a][b] = fr[b][a] = true;
    }

    //给出从1号开始的全排列
    idx = 1;
    buf[1] = 1;
    dfs(1);

    cout << ans;

    return 0;
}
