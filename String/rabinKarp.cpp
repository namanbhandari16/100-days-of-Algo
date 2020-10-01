#include<bits/stdc++.h>
using namespace std;

#define d 256

void answer(string& pattern, string& text, int q)
{
	int m = pattern.size();
	int n = text.size();
	int i, j;
	int hashPattern = 0;
	int hashText = 0;
	int h = 1;

	// The value of h would be pow(d,m-1)%q
	for (i = 0; i < m - 1; i++)
	{
		h = (h * d) % q;
	}

	// Calc hash value of pattern and first window of text
	for (i = 0; i < m; i++)
	{
		hashPattern = (d * hashPattern + pattern[i]) % q;
		hashText = (d * hashText + text[i]) % q;
	}

	for (i = 0; i <= n - m; i++)
	{
		if (hashText == hashPattern)
		{
			for (j = 0; j < m; j++)
			{
				if (text[i + j] != pattern[j])
					break;
			}

			if (j == m)
			{
				cout << "Pattern matched at index:" << i << endl;
			}
		}

		// Calculate hash value for next window of text
		if (i < n - m)
		{
			hashText = (d * (hashText - h * text[i]) + text[i + m]) % q;
			// We might get -ve value of t

			if (hashText < 0)
			{
				hashText = hashText + q;
			}

		}

	}


}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// freopen("input.txt", "r", stdin);
	// freopen("error.txt", "w", stderr);
	// freopen("output.txt", "w", stdout);

	string pattern;
	string text;
	getline(cin, pattern);
	getline(cin, text);
	int q = 101;
	answer(pattern, text, q);
	return 0;
}
