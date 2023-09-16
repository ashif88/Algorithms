/**
 * author: Ashif Akhtar
 **/
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> manacher(string &s)
{
    int n = s.length();
    vector<int> d1(n);
    int l = 0, r = -1;
    for (int i = 0; i < n; ++i)
    {
        int k = (i > r ? 0 : min(d1[l + r - i], r - i));
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
            ++k;
        d1[i] = k--;
        if (i + k > r)
            l = i - k, r = i + k;
    }
    vector<int> d2(n);
    l = 0, r = -1;
    for (int i = 0; i < n; ++i)
    {
        int k = (i > r ? 0 : min(d2[l + r - i + 1], r - i + 1)) + 1;
        while (i + k - 1 < n && i - k >= 0 && s[i + k - 1] == s[i - k])
            ++k;
        d2[i] = --k;
        if (i + k - 1 > r)
            l = i - k, r = i + k - 1;
    }
    // 2*o-1-> i-(o-1)    &    2*e-> i-e
    return {d1, d2};
}

signed main()
{
    return 0;
}