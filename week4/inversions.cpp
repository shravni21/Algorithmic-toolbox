#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/*

                   ___           !!!         |               ___          _   _        .      .
  `  _ ,  '       .|||.       `  _ _  '      |.===.        .'_#_`.       '\-//`     .  .:::.
 -  (o)o)  -      (o o)      -  (OXO)  -     {}o o{}       |[o o]|        (o o)        :(o o):  .
-ooO'(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo-

*/

#define us unordered_set
#define mod 1000000007
#define sp ' '
#define nline "\n"
#define mp make_pair
#define us unordered_set
#define bpc __builtin_popcount

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) (a * b) / gcd(a, b)

#define all(v) v.begin(), v.end()
#define lb(a, X) lower_bound(all(a), X) - a.begin()
#define ub(a, X) upper_bound(all(a), X) - a.begin()
#define rfor(i, a, b) for (ll i = a; i >= b; i--)
#define sfor(i, a, b) for (ll i = a; i < b; i++)
#define rot(a, x)          \
    for (auto &a : x)      \
    {                      \
        cout << it << " "; \
    }
#define max_ele(a) *max_element(a.begin(), a.end())
#define min_ele(a) *min_element(a.begin(), a.end())
#define take_vector(a) \
    for (auto &x : a)  \
        cin >> x;
#define take_array(a, n)        \
    for (int i = 0; i < n; i++) \
    {                           \
        cin >> a[i];            \
    }
#define ssort(v) sort(v.begin(), v.end())
#define rsort(v) sort(v.begin(), v.end(), greater<>())

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;

ll merge(vector<int> &a, vector<int> &b, int l, int m, int r)
{
    ll inversions = 0;
    ll i = l, j = m, k = l;
    while (i < m && j < r)
    {
        if (a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
            inversions += m - i;
        }
    }
    while (i < m)
    {
        b[k++] = a[i++];
    }
    while (j < r)
    {
        b[k++] = a[i++];
    }
    copy(b.begin() + l, b.begin() + r, a.begin() + l);
    return inversions;
}
ll merge_sort(vector<int> &a, vector<int> &b, int l, int r)
{
    ll inversions = 0;
    if (r <= l + 1)
        return inversions;
    ll m = l + (r - l) / 2;
    inversions += merge_sort(a, b, l, m);
    inversions += merge_sort(a, b, m, r);
    inversions += merge(a, b, l, m, r);
    return inversions;
}
long long getNumberOfInversions(vector<int> &a)
{
    vector<int> b(a.size());
    return merge_sort(a, b, 0, a.size());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << getNumberOfInversions(a) << nline;

    return 0;
}