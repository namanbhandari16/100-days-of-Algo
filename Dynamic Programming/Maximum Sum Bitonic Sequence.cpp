#include <bits/stdc++.h>
using namespace std;
#define loop(x, n) for (int x = 0; x < n; ++x)
typedef long long int ll;
int main()
{
    //code
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n], b[n], c[n];
        loop(i, n)
        {
            cin >> a[i];
            b[i] = a[i];
            c[i] = a[i];
        }
        //maximum sum increasing subsequence
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[i] > a[j] && b[i] < b[j] + a[i])
                    b[i] = b[j] + a[i];
            }
        }
        //maximum sum decreasing subsequence
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = n - 1; j > i; j--)
            {
                if (a[j] < a[i] && a[i] + c[j] > c[i])
                    c[i] = c[j] + a[i];
            }
        }
        int maxx = 0;
        for (int i = 0; i < n; i++)
            maxx = max(maxx, c[i] + b[i] - a[i]);
        cout << maxx << endl;
    }
    return 0;
}