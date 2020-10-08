#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int32_t main()
{
    ofstream fout("test2.txt");

    int n = 50000;
    fout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        fout << i - 25000 << " " << i * i - 25000 << "\n";
    }

    return 0;
}