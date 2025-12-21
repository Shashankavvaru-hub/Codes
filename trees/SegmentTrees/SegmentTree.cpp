#include<bits/stdc++.h>
using namespace std;
class SGTree{
    vector<int>seg;
    public:
        SGTree(int n) {
		    seg.resize(4 * n + 1);
	    }
        void build(int ind,int low,int high,vector<int>&arr){
            if(low==high){
                seg[ind]=arr[low];
                return;
            }
            int mid = (low+high) >> 1;
            build(2*ind + 1 , low,mid,arr);
            build(2*ind + 2 , mid+1,high, arr);
            seg[ind]=min(seg[2*ind +1],seg[2*ind+2]);
        }
        int query(int ind,int low, int high, int L, int R){
            //complete overlap
            if(low>=L && high<=R) return seg[ind];
            //No overlap
            if(R<low || L>high) return INT_MAX;
            //partial overlap
            int mid = ( low + high ) >> 1;
            int left = query(2*ind + 1,low , mid , L,R);
            int right = query(2*ind + 2,mid+1 , high , L,R);
            return min(left,right);   
        }
        void update(int ind,int low,int high , int i , int val){
            if(low==high){
                seg[ind]=val;
                return;
            }
            int mid=(low+high)/2;
            if(i<=mid) update(2*ind + 1 , low, mid,i,val);
            else update(2*ind + 2, mid+1 , high,i , val);
            seg[ind]=min(seg[2*ind +1],seg[2*ind+2]);
        }
};