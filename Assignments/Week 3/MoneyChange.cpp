/*
 * we have an array of coins with values 10, 5, and 1.
 * given a number representing a price, print the minimum number of coins that can
 * represent that price
 * 
 * */

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
	int arr[3] = {10, 5, 1};
	
	/*
	 * we can iterate over our sorted array (descending) 
	 * of coins and take as many coins as we need
	 * 
	 */
	 
	int sum = 0;
	for(auto& i : arr){
		while(n / i){
			sum++, n -= i;
		}
	}
	cout << sum;
}

int main(){
	solve();
	cout << nl;
}
