#include <bits/stdc++.h>
using namespace std;

bool is_k_palin(string s, int k);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int k;
        cin >> k;

        cout << is_k_palin(s, k) << endl;
    }
    return 0;
}
int lps(string a, string b)
{
    int n = a.length();
    int t[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            t[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                t[i][j] = t[i - 1][j - 1] + 1;
            else
                t[i][j] = max(t[i - 1][j], t[i][j - 1]);
        }
    }
    return t[n][n];
}
bool is_k_palin(string s, int k)
{
    string r = s;
    reverse(r.begin(), r.end());
    int c = lps(s, r);
    // cout<<c<<endl;
    if ((s.length() - c) <= k)
        return true;
    return false;
}