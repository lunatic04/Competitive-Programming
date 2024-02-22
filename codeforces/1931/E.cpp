#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;

typedef  long long int ll;
#define pb push_back
#define FOR(i,n) for(ll i =0; i<n;i++)
#define vi vector<ll>


// const ll inf = 1000000007;
// ll unsigned ing = 1e15;
// ll mod = 998244353;
vector<ll> prim(ll u ){
    vi pf;
    ll h = 2;
    while(h<= sqrt(u)){
        while(u%h==0){
               pf.pb(h);
              u = u/h;
        }
        h++;
    }
    if(u!=1){
        pf.pb(u);
    }
    return pf;
}



ll lp(ll u){
    ll j =2;
    bool ok =0;
    while(j<=sqrt(u)){
        if(u%j==0){
            ok=1;
            break;
        }
        j++;
    }
    if(!ok) return u;
    return j;
}

bool isprime(ll h ){
    ll j =2;
    bool ok =1;
    while(j<=sqrt(h)){
        if(h%j==0){
            ok=0;
            break;
        }
        j++;
    }
    return ok;
}


ll gcd_(ll a , ll b){
    if(b==0) return a;
    return gcd_(b,a%b);
}

ll lcm(ll a, ll b){
    ll ans = (ll)(a*b)/(gcd_(a,b));
    return ans;
}



ll modp(ll h, ll f , ll m){
    if(h==0)return 0;
    if(f==0){
        return 1%m;
    }
    ll u = modp(h,f/2,m);
    u = (ll)(u*u)%m;
    if(f%2!=0){ u = (u*h)%m;}
    return u;
}


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

vector<ll> allf(ll n ,ll m){
    vi ans;
    ll i =2;
    for(i = 2;i<=min((ll)sqrt(n),m);i++){
        if(!n%i){
            ans.pb(i);
            if(i!=n/i && n/i<=m){
                ans.pb(n/i);
            }
        }
    }
    return ans;
}

ll hd(ll c){
    ll u =10;
    ll f =1;
    while(c%u==0){
        f++;
        u = u*10;
    }
    f--;
    return f;
}
bool cmp(const pair<ll,ll> &a , const pair<ll,ll>  &b){
    return a.second>b.second;
   
}
void solve(){

 ll n,m;
 cin>>n>>m;
 vector<pair<ll,ll>> op;
 ll r =0;
 vi nop;
 FOR(i,n){
    ll a;cin>>a;
    ll g = 1+floor((double)(log10(a)));
    if(a%10==0){
        ll c = hd(a);
        op.pb({g-c,c});
    }
    else{
        r+=g;
        nop.pb(a);
    }
 }
 if(r>=m+1){
    cout<<"Sasha\n";
    return;
 }
 sort(op.begin(),op.end(),cmp);
 ll d = op.size();
 ll q =0;
 while(q<d){
    r+=op[q].first;
    q++;
    if(q<d){
        r+= op[q].first;
        r+=op[q].second;
        q++;
    }
 }
 cout<<(r>=m+1 ? "Sasha":"Anna")<<"\n";


 






}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
}
