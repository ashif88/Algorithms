/**
 * author: Ashif Akhtar
 **/
#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long m = 1000000007)
{
    a %= m;
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main()
{
    return 0;
}