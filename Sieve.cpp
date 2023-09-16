/**
 * author: Ashif Akhtar
 **/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int prsize = 1000005;
vector<int> spf(prsize);
void pre()
{
    for (int i = 0; i < prsize; i++)
        spf[i] = i;
    for (ll i = 2; i * i < prsize; ++i)
        if (spf[i] == i)
            for (ll j = i * i; j < prsize; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

signed main()
{
    pre();
    return 0;
}