#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int seed = 42323;

mt19937 rng(seed);

int32_t main()
{
    ofstream fout("test5.txt");

    int n = 2000000;
    fout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        fout << (rng() % 2 == 0 ? 1 : -1) * ((int)rng() % 1000000) << " " << (rng() % 2 == 0 ? 1 : -1) * ((int)rng() % 1000000) << "\n";
    }

    return 0;
}