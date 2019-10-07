#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
void build(int node ,int l,int r,ll a[],ll tree[])
 {
     if(l==r)
     tree[node]=a[l];
     else {
     int mid=(l+r)/2;
     build(2*node,l,mid,a,tree);
     build(2*node+1,mid+1,r,a,tree);
     if(tree[2*node]<tree[2*node+1])
     tree[node]=tree[2*node];
     else 
      tree[node]=tree[2*node+1];
     }
     
 }

void update(int node,int l,int r,int inx,int val,long long a[],long long  tree[])
 {
    if(l==r)
    
    {   a[inx]=val;
        tree[node]=val;
        
        
    }
    else 
    {
        
     int mid=(l+r)/2;
     if(inx<=mid && inx>=l)
     update(2*node,l,mid,inx,val,a,tree);
     else 
     update(2*node+1,mid+1,r,inx,val,a,tree);
     if(tree[2*node]<tree[2*node+1])
     tree[node]=tree[2*node];
     else 
      tree[node]=tree[2*node+1];
     }
        
        

    }
     
 
int query(int node ,int l,int r,int x,int y,long long tree[])
 { 
     
   if(x>r || y<l)return 0;
   if(x<=l && r<=y)return tree[node]; 
   
       
       int mid=(l+r)/2,p1,p2;
       p1=query(2*node,l,mid,x,y,tree);
       p2=query(2*node+1,mid+1,r,x,y,tree);
       if(p1<p2)
       return p1;
       else return p2;
     
     
     
     
     
 }



int main()
 {
     long long n,q,x,y;
     cin>>n>>q;
     long long a[n+1];
     long long  tree[200005]={0};
     for(int i=1;i<=n;i++){
         cin>>a[i];}
     
     build(1,1,n,a,tree);
    
     char c;
     
     while(q--)
      {
          
         cin>>c>>x>>y;
         if(c=='u')
         {   //cout<<"hrr";
             update(1,1,n,x,y,a,tree);
         }
         else {
             int d=query(1,1,n,x,y,tree);
		cout<<d<<"\n";
         }
          
   
      }   
     
 }
