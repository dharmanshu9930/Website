#include<bits/stdc++.h>
using namespace std;
#define int          long long
#define endl         "\n"
#define pb           push_back
#define all(v)       v.begin(),v.end()
#define ff           first
#define ss           second

string sumBig(string a, string b)
{
    if (a.length() > b.length())
        swap(a, b);
    string str = "";
    int n1 = a.length(), n2 = b.length();
 
    int diff = n2 - n1;
    int carry = 0;
    for (int i = n1 - 1; i >= 0; i--) {
        int sum
            = ((a[i] - '0')
               + (b[i + diff] - '0') + carry);
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = n2 - n1 - 1; i >= 0; i--) {
 
        int sum = ((b[i] - '0') + carry);
 
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
        str.push_back(carry + '0');
    reverse(str.begin(), str.end());
 
    return str;
}
string complement10(string v)
{
    string complement = "";
    for (int i = 0; i < v.size(); i++) {
        complement += '9' - v[i] + '0';
    }
    complement = sumBig(complement, "1");
    return complement;
}
string sumnum(string a, string b)
{
    if (a.length() < b.length())
        swap(a, b);
    int l1 = a.length(), l2 = b.length();
 
    int diffLen = l1 - l2;
 
    for (int i = 0; i < diffLen; i++) {
 
        b = "0" + b;
    }
 
    string c = sumBig(a, complement10(b));
 
    if (c.length() > a.length()) {
        string::iterator it;
        it = c.begin();
        c.erase(it);
 
        while (*it == '0')
            c.erase(it);
 
        return c;
    }
 
    else {
        return complement10(c);
    }
}


string longDivision(string number, int divisor)
{
    string ans;
    int idx = 0;
    int temp = number[idx] - '0';
    while (temp < divisor)
        temp = temp * 10 + (number[++idx] - '0');
    while (number.size() > idx) {
        ans += (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + number[++idx] - '0';
    }
 
    if (ans.length() == 0)
        return "0";
 
    return ans;
}
 
void solve()
{
   string s1,s2;
   cin>>s1>>s2;
   int n1=s1.size(),n2=s2.size();
   string ans;
   ans=sumnum(s1,s2);
    int sum=0,sum1=0;
    for(int i=0;i<n1;i++)
    {
        sum+=(s1[i]-48);
    }
    for(int i=0;i<n2;i++)
    {
        sum1+=(s2[i]-48);
    }
    int x1,x2;
    x1=sum%3;
    x2=sum1%3;
    if(x1>0)
    x1=3-x1;
    int y=x1-x2;
    string str1;
    str1+=(y+48);
    string res=sumnum(ans,str1);
    string finalans=longDivision(res,3);
    if(sum1%3==0)
    {
        string str2="1";
        finalans=sumBig(finalans,str2);
    }
    cout<<finalans;

}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<endl;
    }

    return 0;
}