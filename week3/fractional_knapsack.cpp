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

struct Item
{
    int V{0}, W{0};
    double ratio() const
    {
        return (W > 0) ? double(V) / W : 0;
    };
};

double maxValue(vector<Item> &items, int W)
{
    sort(items.begin(), items.end(), [](const Item &lhs, const Item &rhs)
         { return lhs.ratio() > rhs.ratio(); });

    double ans = 0;
    for (auto &item : items)
    {
        if (W == 0)
            break;
        if (item.W <= W)
        {
            ans += item.V;
            W -= item.W;
        }
        else
        {
            auto fraction = double(W) / item.W;
            ans += fraction * item.V;
            W = 0;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N, W;
    cin >> N >> W;
    vector<Item> items;
    for (int i = 0; i < N; i++)
    {
        int Vi, Wi;
        cin >> Vi >> Wi;
        items.push_back({Vi, Wi});
    }
    auto ans = maxValue(items, W);
    cout << fixed << setprecision(4) << ans << nline;

    return 0;
}