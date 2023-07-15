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

ll get_fibonacci_huge(ll n, ll m)
{
    if (n <= 1)
        return n;

    ll previous = 0;
    ll current = 1;
    ll tmp_previous = 0;

    vector<ll> pisano;
    pisano.push_back(0);
    pisano.push_back(1);

    while (true)
    {
        tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
        if (current == 1 && previous == 0)
        {
            break;
        }
        else
        {
            pisano.push_back(current);
        }
    }

    pisano.pop_back();
    ll index = n % pisano.size();
    return pisano.at(index);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << get_fibonacci_huge(a, b) << '\n';
    return 0;
}
