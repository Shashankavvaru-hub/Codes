#include <bits/stdc++.h>
using namespace std;
class ST{
    vector<int>seg,lazy;
    public:
        ST(int n){
            seg.resize(4*n);
            lazy.resize(4*n);
        }
    public:
        void build(int ind,int low,int high,vector<int>&arr){
            if(low==high){
                seg[ind]=arr[low];
                return;
            }
            int mid=(low+high)>>1;
            build(2*ind+1,low,mid,arr);
            build(2*ind+2,mid+1,high,arr);
            seg[ind]=seg[2*ind+1] + seg[2*ind+2];
        }
    public:
        void update(int ind,int low,int high,int l,int r,int val){
            
            // apply pending lazy if any
            if(lazy[ind]!=0){
                seg[ind]+=(high-low+1)*lazy[ind];
                if(low!=high){
                    lazy[2*ind+1]+=lazy[ind];
                    lazy[2*ind+2]+=lazy[ind];
                }
                lazy[ind]=0;
            }
            
            //no overlap
            if(low>r || high<l) return;
            
            //complete overlap
            if(low>=l && high<=r){
                seg[ind]+=(high-low+1)*val;
                if(low!=high){
                    lazy[2*ind+1]+=val;
                    lazy[2*ind+2]+=val;
                }
                return;
            }
            
            //partial overlap
            int mid=(low+high)>>1;
            update(2*ind+1,low,mid,l,r,val);
            update(2*ind+2,mid+1,high,l,r,val);
            seg[ind]=seg[2*ind+1] + seg[2*ind+2];
        }
    public:
        int query(int ind,int low,int high,int l,int r){
            
            // apply pending lazy if any
            if(lazy[ind]!=0){
                seg[ind]+=(high-low+1)*lazy[ind];
                if(low!=high){
                    lazy[2*ind+1]+=lazy[ind];
                    lazy[2*ind+2]+=lazy[ind];
                }
                lazy[ind]=0;
            }
            
            //no overlap
            if(high<l || low>r) return 0;
            
            //complete overlap
            if(low>=l && high<=r) return seg[ind];
            
            //partial overlap
            int mid=(low+high)>>1;
            int left=query(2*ind + 1,low,mid,l,r);
            int right=query(2*ind+2,mid+1,high,l,r);
            return left+right;
        }
};
int main() {
    
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<int> arr= {1, 2, 3, 4, 5}; 
    int n=(int)arr.size();

    ST st(n);
    st.build(0,0,n-1,arr);

    // add 10 to range [1, 3]
    st.update(0,0,n - 1,1,3,10);

    // query sum
    cout << "Sum [0,4] = " << st.query(0,0,n-1,0,4) << '\n'; // expect 45
    cout << "Sum [1,3] = " << st.query(0,0,n-1,1,3) << '\n'; // expect 39

    return 0;
}
