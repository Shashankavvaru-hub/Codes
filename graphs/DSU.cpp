class DSU{
    
    vector<int> parent, size, rank;

    public:
        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1, 1);
            rank.resize(n+1, 0);
            for(int i=0;i<=n;i++){
                parent[i] = i;
            }
        }

        int findUltPar(int node){
            if(parent[node]==node) return node;
            return parent[node] = findUltPar(parent[node]);
        }

        void unionBySize(int u,int v){
            int ult_u = findUltPar(u);
            int ult_v = findUltPar(v);
            if(ult_u == ult_v) return;
            if(size[ult_u] < size[ult_v]){
                parent[ult_u] = ult_v;
                size[ult_v] += size[ult_u];
            }
            else{
                parent[ult_v] = ult_u;
                size[ult_u] += size[ult_v];
            }
        }
        
        void unionByRank(int u, int v){
            int ult_u = findUltPar(u);
            int ult_v = findUltPar(v);
            if(ult_u == ult_v) return;
            if(rank[ult_u]<rank[ult_v]){
                parent[ult_u] = ult_v;
            }
            else if(rank[ult_v]<rank[ult_u]){
                parent[ult_v] = ult_u;
            }
            else{
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }
        }
};