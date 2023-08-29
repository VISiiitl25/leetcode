

class DisjointSet{
    vector<int> size,parent;
    public:
    DisjointSet(int n)
    {
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
        }
    }
    int findUPar(int node)
    {
        if(node==parent[node])
        return node;
        return parent[node]=findUPar(parent[node]);
    }
    void  unionBySize(int u,int v)
    {
        int ulp_u=findUPar(u),ulp_v=findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]>=size[ulp_v])
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
    
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
      DisjointSet ds(row.size());
      for(int i=0;i<row.size();i+=2)
      {
          ds.unionBySize(row[i],row[i+1]);
      }
      int cnt=0;
      for(int i=0;i<row.size();i+=2)
      {
          if(ds.findUPar(i)!=ds.findUPar(i+1))
          {
              cnt++;
              ds.unionBySize(ds.findUPar(i),ds.findUPar(i+1));
          }
      }
      return cnt;
    }
};