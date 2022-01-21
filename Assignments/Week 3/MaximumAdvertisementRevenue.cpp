#include<bits/stdc++.h>
using namespace std;

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ll long long
#define ull unsigned long long
#define MOD 1000000007ll
#define PI 3.14159265
#define ceil(a, b) ((a / b) + (a % b ? 1 : 0))
#define imin INT_MIN
#define imax INT_MAX
#define nl '\n'
#define modulo(a, b, mod) ((((a) % mod) * ((b) % mod)) % mod)

void solve(){
	
	int n; cin >> n;
	vector<ll> a(n), b(n);
	for(auto& i : a) cin >> i;
	for(auto& i : b) cin >> i;
	
	/* the maximum revenue of the advertisements is where we put the maximum paying ad in the
	 * maximum clicks per day slot
	 */
	 
	sort(all(a)), sort(all(b));
	
	ll sum = 0;
	for(int i = 0; i < n; i++) 
		sum += a[i] * b[i];
	
	cout << sum;
}

int main(){
	solve();
	cout << nl;
}
