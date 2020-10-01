#include<bits/stdc++.h>
using namespace std;

vector<int> computeLpsArray(string pattern, int m)
{
	int len = 0;
	int i = 1;
	std::vector<int> v(m, 0);
	while (i < m)
	{
		if (pattern[i] == pattern[len])
		{
			v[i] = len + 1;
			i++;
			len++;

		}
		else {
			if (len != 0)
			{
				len = v[len - 1];
			}
			else {
				v[i] = 0;
				i++;
			}

		}
	}
	return v;
}


void KMPSearc(string pattern, string text)
{
	int n = text.size();
	int m = pattern.size();
	vector<int>lps = computeLpsArray(pattern, pattern.size());
	int i = 0, j = 0;
	while (i < n)
	{
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else {
			if (j != 0)
			{
				j = lps[j - 1];

			}
			else {
				i++;
			}
		}
		if (j == m)
		{
			cout << i - j << endl;
			j = lps[j - 1];
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

	string pattern, text;

	getline(cin, pattern);
	getline(cin, text);
	cout << pattern << endl;
	cout << text << endl;
	KMPSearc(pattern, text);

	return 0;
}
