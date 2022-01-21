#include<bits/stdc++.h>
using namespace std;

#define nl '\n'

int main(){
	int n; cin >> n;
	vector<int> v(n);
	
	for(auto& i : v) cin >> i;
	
	int maxi = 0;
	for(int i = 0; i < n; i++)
		if(v[i] > v[maxi]) maxi = i;
		
	int secondMaxi = not(maxi > 0);
	for(int i = 0; i < n; i++){
		if(i == maxi) continue;
		if(v[i] > v[secondMaxi]) secondMaxi = i;
	}
	cout << 1ll * v[maxi] * v[secondMaxi] << nl;
}
