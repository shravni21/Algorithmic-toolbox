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

void partition(vector<int> &v, int l, int h, int &i, int &j)
{
    if (h - l <= 1)
    {
        if (v[h] < v[l])
            swap(v[h], v[l]);
        i = l,
        j = h;
        return;
    }
    int m = l;
    int pivot = v[h];
    while (m <= h)
    {
        if (v[m] < pivot)
            swap(v[l++], v[m++]);
        else if (v[m] == pivot)
            m++;
        else if (v[m] > pivot)
            swap(v[m], v[h--]);
    }
    i = l - 1;
    j = m;
}
void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;

    int i, j;
    partition(arr, low, high, i, j);
    quickSort(arr, low, i);
    quickSort(arr, j, high);
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
    quickSort(a, 0, n - 1);
    for (int i : a)
    {
        cout << i << " ";
    }
    cout << nline;

    return 0;
}