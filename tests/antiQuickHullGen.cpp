#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

#define int int64_t
#define ld long double

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;
const long double PI = 2 * acos(0);

int seed = 2344;

mt19937 rng(seed);

int32_t main()
{
    ofstream fout("test7.txt");

    int n = 100;
    fout << n << "\n";
    fout << setprecision(15) << 0 << " " << 1000000 << "\n";
    for (int i = 0; i < n - 1; i++)
    {
        fout << setprecision(15) << 1000000 * cos(PI / (pow(2, i))) << " " << 1000000 * sin(PI / (pow(2, i))) << "\n";
    }

    return 0;
}