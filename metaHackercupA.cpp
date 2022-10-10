#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[1001];
void dsx() {
  cin >> n >> k;
  int ans=k*2;
  for(int i=1;i<=n;++i)
    cin >> a[i];
  if(ans<n) {
    puts("NO");
    return;
  }
  map<int,int> m;
  for(int i=1;i<=n;++i) {
    m[a[i]]++;
    if(m[a[i]]==3) {
      puts("NO");
      return;
    }
  }
  puts("YES");
}
signed main() {
  int T;
  cin >> T;
  for(int i=1;i<=T;++i) {
    cout << "Case #" << i << ": ";
    dsx();
  }
}
