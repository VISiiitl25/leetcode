class Solution
{
    public:
        class DisjointSet
        {
            vector<int> rank, parent;
            public:
                DisjointSet(int n)
                {
                    rank.resize(n + 1, 0);
                    parent.resize(n + 1);
                    for (int i = 0; i <= n; i++)
                    {
                        parent[i] = i;
                    }
                }

            int findUPar(int node)
            {
                if (node == parent[node])
                    return node;
                return parent[node] = findUPar(parent[node]);
            }

            void unionByRank(int u, int v)
            {
                int ulp_u = findUPar(u);
                int ulp_v = findUPar(v);
                if (ulp_u == ulp_v) return;
                if (rank[ulp_u] < rank[ulp_v])
                {
                    parent[ulp_u] = ulp_v;
                }
                else if (rank[ulp_v] < rank[ulp_u])
                {
                    parent[ulp_v] = ulp_u;
                }
                else
                {
                    parent[ulp_v] = ulp_u;
                    rank[ulp_u]++;
                }
            }
        };
    vector<int> sieve(int n)
    {
        vector<int> smallestPrime(n + 1, 0);
        for (int i = 2; i <= n; i++)
        {
            if (smallestPrime[i] == 0)
            {
                for (int j = i; j <= n; j += i)
                {
                    if (smallestPrime[j] == 0)
                    {
                        smallestPrime[j] = i;
                    }
                }
            }
        }
        return smallestPrime;
    }
    bool canTraverseAllPairs(vector<int> &nums)
    {
        DisjointSet ds(100004);

        vector<int> smallestPrime = sieve(100004);

        int n = nums.size();
        if(n==1)return true;
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            int x = nums[i];
            if (x == 1) return false;
            while (temp > 1)
            {
                ds.unionByRank(x, smallestPrime[temp]);
                temp /= smallestPrime[temp];
            }
        }
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            st.insert(ds.findUPar(nums[i]));
        }

        return st.size() == 1;
    }
};