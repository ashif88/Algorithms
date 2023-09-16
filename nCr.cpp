/**
 * author: Ashif Akhtar
 **/
#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;

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
long long fact[1000001];
long long invfact[1000001];
void prefact()
{
    for (int i = 0; i <= 1000000; i++)
        fact[i] = 1, invfact[i] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        fact[i] = i * fact[i - 1];
        fact[i] %= mod;
        invfact[i] = fact[i];
    }
    for (int i = 2; i <= 1000000; ++i)
    {
        invfact[i] = binpow(invfact[i], mod - 2, mod);
    }
}
long long nCr(long long n, long long r)
{
    return (((fact[n] * invfact[r]) % mod) * invfact[n - r]) % mod;
}

signed main()
{
    prefact();
    return 0;
}