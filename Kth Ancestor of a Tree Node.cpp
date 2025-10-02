class TreeAncestor {
public:
    vector<vector<int>>sparse;
    TreeAncestor(int n, vector<int>& parent) {
        int m=30;
        sparse.resize(m+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            sparse[0][i]=parent[i];
        }
        for(int i=1;i<=m;i++){
            for(int j=0;j<n;j++){
                int prev=sparse[i-1][j];
                if(prev==-1)continue;
                sparse[i][j]=sparse[i-1][prev];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int ans=node;
        for(int i=0;i<=30;i++){
            if(k&(1<<i)){
                ans=sparse[i][ans];
                if(ans==-1)break;
            }
        }return ans;
    }
};
