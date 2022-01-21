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
	int d, m, n; cin >> d >> m >> n;
	
	vector<int> v(n);
	for(auto& i : v) cin >> i;
	
	// add our targeted city's distance to the stations we have
	v.emplace_back(d);
	
	int curr = 0, cnt = 0;
	bool noWay = false;
	
	for(int i = 0; i < n; i++){
		
		/* if a distance between two stations is larger than the distance the full-tank car
		 * can go, then there's no way to reach our goal
		 */
		
		if(v[i + 1] - v[i] > m){
			noWay = true;
			break;
		}
		// if we can't reach the next station, then we better fuel the car here
		
		if(v[i + 1] - curr > m){
			curr = v[i];
			cnt++;
		}
	}
	
	cout << (noWay ? -1 : cnt);
}

int main(){
	solve();
	cout << nl;
}
