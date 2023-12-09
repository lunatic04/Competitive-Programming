#include <bits/stdc++.h>
using namespace std;

typedef  long long int ll;
#define pb push_back
#define FOR(i,n) for(ll i =0; i<n;i++)
#define vi vector<ll>


// const ll inf = 1000000007;
// ll unsigned ing = 1e15;
// ll mod = 998244353;
// vector<ll> prim(ll u ){
//     vi pf;
//     ll h = 2;
//     while(h<= sqrt(u)){
//         while(u%h==0){
//                pf.pb(h);
//               u = u/h;
//         }
//         h++;
//     }
//     if(u!=1){
//         pf.pb(u);
//     }
//     return pf;
// }



// ll lp(ll u){
//     ll j =2;
//     bool ok =0;
//     while(j<=sqrt(u)){
//         if(u%j==0){
//             ok=1;
//             break;
//         }
//         j++;
//     }
//     if(!ok) return u;
//     return j;
// }

// bool isprime(ll h ){
//     ll j =2;
//     bool ok =1;
//     while(j<=sqrt(h)){
//         if(h%j==0){
//             ok=0;
//             break;
//         }
//         j++;
//     }
//     return ok;
// }


// ll gcd_(ll a , ll b){
//     if(b==0) return a;
//     return gcd_(b,a%b);
// }

// ll lcm(ll a, ll b){
//     ll ans = (ll)(a*b)/(gcd_(a,b));
//     return ans;
// }



// ll modp(ll h, ll f , ll m){
//     if(h==0)return 0;
//     if(f==0){
//         return 1%m;
//     }
//     ll u = modp(h,f/2,m);
//     u = (ll)(u*u)%m;
//     if(f%2!=0){ u = (u*h)%m;}
//     return u;
// }


// bool comp(const pair<ll,ll> a , const pair<ll,ll> b){
//     if(a.first==b.first) return a.second>b.second;
//     return a.first<b.first;
// }

// bool is2(ll n){
//     if(n==1) return 1;
//     if(n%2!=0) return 0;
//     return  is2(n/2);
// }
// ll nd(ll n){
//     ll ans =0;
//     while(n>0){
//         ans++;
//         n = n/10;
//     }
//     return ans;
// }

// ll sd(ll n){
//     ll ans =0;
//     while(n>0){
//         ans += n%10;
//         n = n/10;
//     }
//     return ans;
// }

// ll C = 100000+1;
// vector<vector<ll>> adj(C);
// set<ll> s;
// ll n ;
// void dfs1(ll e1,ll e2 , ll w){
//     if(e1==b) return;
//     s.insert(w);
//     for(auto f : adj[e1]){
//         if(f.first!=e2){
//             dfs1(f.first,e1,w^f.second);
//         }
//     }
// }

// bool dfs2(ll e1 , ll e2 , ll w){
//     if(e1!=b && s.count(w)) return 1;
//     for(auto f : adj[e1]){
//         if(f.first!=e2){
//             if(dfs2(f.first,e1,w^f.second)) return 1;
//         }
//     }
//     return 0;
// }

// ll com(vi a , vi b ){
//     sort(a.begin(),a.end());
//     sort(b.begin(),b.end());
//     ll n = a.size();
//     ll i = n-1;
//     ll j = n-1;
//     while(i>-1 && j>-1){
//         if(b[i]>a[j]){
//             i--;
//             j--;
//         }
//         else{
//             j--;
//         }
//     }
//     return i+1;
// }


void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> op(n);
    FOR(i,n){
        cin>>op[i].first;
       op[i].second = i;
    }
    sort(op.begin(),op.end());
    vi pre(n);
    vector<ll> dat;
    for(ll i =0;i<n;i++){
        if(!i) pre[i] =op[i].first;
        else{
            pre[i] = pre[i-1]+op[i].first;
        }
        dat.push_back(op[i].first);
    }
    vi ans(n);
    ll i =0;
    while(i<n){
        ll in = i;
        while(i<n-1 && op[i].first==op[i+1].first){
            i++;
        }
        ll sum = pre[i];
        ll g = upper_bound(dat.begin(),dat.end(),sum) - dat.begin();
        if(g==n){
            for(ll j = in;j<=i;j++){
                ans[op[j].second] = g-1;
            }
        }
        else{
            sum = pre[g-1];
            while(g<n && sum>=dat[g]){
                g = upper_bound(dat.begin(),dat.end(),sum) - dat.begin();
                if(g==n) break;
                sum = pre[g-1];
            }
            for(ll j = in;j<=i;j++){
                ans[op[j].second] = g-1;
            }

        }

        i++;
    }
    for(ll h :ans){
        cout<<h<<" ";
    }
    cout<<"\n";

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        solve();
}
}