#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

int seed = 45;

mt19937 rng(45);

int32_t main()
{
    ofstream fout("test3.txt");

    int n = 100;
    fout << n << "\n";
    for (int i = 0; i < 100; i++)
    {
        fout << rng() % 1000 << " " << rng() % 1000 << "\n";
    }

    return 0;
}