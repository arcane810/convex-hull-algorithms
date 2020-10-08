#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const long double PI = 3.14159265;

int seed = 2344;

mt19937 rng(seed);

int32_t main()
{
    ofstream fout("test6.txt");

    int n = 1000;
    fout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        fout << setprecision(15) << (100 + (rng() % 2 == 0 ? 1 : -1) * ((int)rng() % 1000) * 0.00001) * sin(i * 1.0 / n * 2 * PI) << " " << (100 + (rng() % 2 == 0 ? 1 : -1) * ((int)rng() % 1000) * 0.00001) * cos(i * 1.0 / n * 2 * PI) << "\n";
    }

    return 0;
}