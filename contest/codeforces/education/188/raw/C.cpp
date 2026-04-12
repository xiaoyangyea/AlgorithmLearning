#include<vector>
#include<iostream>
using namespace std;
long long gcd(long long a, long long b) {
    if(b == 0)
        return a;
    return gcd(b, a%b);
}
int main() {
    int t;
    cin>>t;
    while(t --) {
        long long a, b, c, m;
        cin>>a>>b>>c>>m;
        long long   ac = a * c / gcd(a, c),
                    ab = a * b / gcd(a, b),
                    bc = b * c / gcd(b, c),
                    abc = a * (b * c / gcd(b, c)) / (gcd(a, b * c / gcd(b, c)));

        long long   _a1 = m / a - m / ab - m / ac + m / abc,
                    _a2 = m / ab + m / ac - 2 * (m / abc),
                    _a3 = m / abc,
                    _b1 = m / b - m / ab - m / bc + m / abc,
                    _b2 = m / ab + m / bc - 2 * (m / abc),
                    _b3 = m / abc,
                    _c1 = m / c - m / bc - m / ac + m / abc,
                    _c2 = m / bc + m / ac - 2 * (m / abc),
                    _c3 = m / abc;
        // cout<<a<<' '<<ab<<' '<<ac<<' '<<abc<<'\n';
        cout<<6 * _a1 + 3 * _a2 + 2 * _a3 << ' '<<6 * _b1 + 3 * _b2 + 2 * _b3<<' '<<6 * _c1 + 3 * _c2 + 2 * _c3 << '\n';
    }
}