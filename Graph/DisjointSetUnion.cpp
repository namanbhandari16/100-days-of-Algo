// using rank and path compression

#include<bits/stdc++.h>
using namespace std;

#define ll long long 
struct disnode{
    ll rank=0;
    ll data;
    ll parent;
};
ll findset(disnode djset[],ll v,ll i){
    if(djset[i].parent!=i)
        djset[i].parent=findset(djset,v,djset[i].parent);
    return djset[i].parent;
}
void unionset(disnode djset[],ll v,ll i,ll j)  {
    ll x=findset(djset,v,i);
    ll y=findset(djset,v,j);
    if(djset[x].rank==djset[y].rank){
        djset[y].parent=x;
        djset[x].rank++;
    }
    else{
        if(djset[x].rank>djset[y].rank){
            djset[y].parent=x;
        }
        else{
            djset[x].parent=y;
        }
    }
}
void makeset(disnode djset[],ll v){
    for(int i=0;i<v;i++) djset[i].parent=i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll v; cin>>v;
    disnode djset[v];
    for(int i=0;i<v;i++) djset[i].parent=i;
    ll e; cin>>e;
    while(e--){
        ll x,y;
        cin>>x>>y;
        unionset(djset,v,x,y);
    }
    for(int i=0;i<v;i++){
        cout<<djset[i].rank<<" "<<djset[i].parent<<endl;
    }
    return 0;
}
