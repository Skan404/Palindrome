#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string DecToBin(int n, int k) {
	string res;
	for (int i = 1 << k - 1; i > 0; i >>= 1)
	{
		res += (n & i) ? '1' : '0';
	}
	return res;
}

string Reverse(int l, int k)
{
	string liczba = DecToBin(l, k);

	string a = liczba;

	reverse(a.begin(), a.end());
	liczba = liczba + a;
	return liczba;
}

void f(int a, int n)
{
	if (a >= 0)
	{
		if (n % 2 == 0) {
			cout << Reverse(a, n / 2);
		}
		else
		{
			string s = Reverse(a, n / 2);
			s.insert(s.begin() + (n / 2), '1');
			cout << s;
			s[n / 2] = '0';
			cout << s;
		}
		f(a - 1, n);
	}
	return;
}

int main()
{
	int n;
	for (int i = 0; i < 50; i++)
	{
		cin >> n;
		int pom1 = pow(2, n / 2) - 1;
		f(pom1, n);
		cout << endl;
	}
	
	return 0;
}

