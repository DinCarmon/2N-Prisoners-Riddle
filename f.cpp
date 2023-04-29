#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 
#define ll long long
 
#define pii pair<int,int>
#define pll pair<ll,ll>
 
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vpi vector<pii>
#define vpl vector<pll>
#define pb push_back
#define all(v) v.begin(),v.end()
#define fast_io ios_base::sync_with_stdio(0),cin.tie(0);


vector<vector<int>> op;
vector<vector<int>> prisoners_list;
int n;
int pips;
int choices;
vector<set<int>> sen;
vector<vi> fac;
int maxx =0;


int ii=0;


template <class T>
void print(vector<T> a) {
    int n=a.size();
    for(ll i = 0; i < n; ++i) {
        cout <<a[i]<<(i==n-1?"\n":" ");
    }
}
 
ll choose(ll n, ll k){
    ll ans = 1;
    k = max(k, n - k);
    for(ll i = 1; i <= n - k; i++){
        ans *= k + i;
        ans /= i;
    }
    return ans;
}

int hashvec(vi v){
    int ans = 0;
    for(int num : v){
        if(num > 9){
            cout<<"\n\n\nshouldnt happen\n\n\n";
        }
        ans*=10;
        ans+=num;
    }
    return ans;
}

int intersection(vi v1, vi v2){
    // get two lists and returns number of repeated elements
    int ans=0;
    vb count(pips+1,0);
    for(int num:v1){
        count[num] = 1;
    }
    for(int num:v2){
        ans += count[num];
    }
    return ans;
}

int intersection(vector<vi> v, vi v1){
    //gets all former choices and the new choice
    vi ans;
    for(vi v2:v){
        ans.push_back(intersection(v1,v2));
    }
    sort(all(ans));
    return hashvec(ans);
    //done - consider changing to hash instead!
}

void fillfac(vi cur, vb used){
    if(cur.size()==pips){
        fac.pb(cur);
        return;
    }
    for(int i=1;i<=pips;i++){
        if(used[i]) continue;
        used[i] = 1;
        cur.push_back(i);
        fillfac(cur,used);
        used[i] = 0;
        cur.pop_back();
    }
}


void rec(vi ch, int cur){
    if(ch.size() == n){
        op.push_back(ch);
        return;
    }
    if(cur <= pips){
        ch.push_back(cur);
        rec(ch,cur+1);
        ch.pop_back();
        rec(ch,cur+1);
    }
}

void rec2(vector<vi> list){
    if(list.size() == pips){
        if(ii%10==0) cout<<ii<<"\n";
        //this is a final list
        //maybe print or save it
        int count = 0; 
        for(int j=0;j<fac.size()/2;j++){
            bool success = true;
            for(int i=0; i<pips;i++){
                //we are checking the list of prisoner #i+1
                bool managed = false;
                for(int num:list[i]){
                    if(fac[j][num-1]==i+1) managed = true;
                }
                success &= managed;
            }
            if(success) count++;
        }
        // if(count == 5576){
        //     cout<<"\n";
        //     for (vi l:list){
        //         print(l);
        //     }
        //     cout<<"\n";
        //     exit(0);
        // }
        maxx = max(maxx, count);
        // cout<<count<<" / "<<fac.size()<<"\n";
        ii++;
        return;
    }
    int sofar = list.size();
    for(int i = 0; i < choices; i++){
        //this might be this guy's list

        if(sen[sofar].count(intersection(list,op[i])) != 0){
            if(i==2558){
                cout<<"will not add\n";
                print(op[i]);
                cout<<"to list\n";
                for (vi l:list){
                  print(l);
                }   
                cout<<"\n\n";
            }
            continue;
        }
        sen[sofar].insert(intersection(list,op[i]));
        list.push_back(op[i]);
        rec2(list);
        list.pop_back();
    }
}

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    //fast_io

    cin >> n;
    pips = 2 * n;
    choices = choose(pips, n);
    // get all chooses:
    rec({},1);
    // op now contains all choose(2n,n) options

    vb used(pips+1);
    fillfac({},used);
    
    
    prisoners_list.push_back({1,2,3,4,5});
    sen.resize(pips+2);
    
    rec2(prisoners_list);

    cout<<maxx<<" / "<<fac.size()<<"\n";
    cout<<ii<<"\n";

	cin >> n;
    
    return 0;
}