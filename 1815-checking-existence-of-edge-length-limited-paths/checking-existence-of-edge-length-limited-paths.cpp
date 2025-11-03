class DisjointSet {
public: 
    vector<int> rank, parent; 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
      
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
           
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

}; 



class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        DisjointSet dsu(n);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }

        sort(queries.begin(),queries.end(),[](auto &l,auto &r){ return l[2]<r[2];});
        sort(edgeList.begin(),edgeList.end(),[](auto &l,auto &r){return l.back()<r.back();});

        int i=0;
        vector<bool>result(queries.size());
        for(auto query:queries){
            while(i<edgeList.size()&&edgeList[i][2]<query[2]){
                dsu.unionByRank(edgeList[i][0],edgeList[i][1]);
                i++;
            }

            result[query.back()]=dsu.findUPar(query[0])==dsu.findUPar(query[1]);
        }

        return result;
    }
};