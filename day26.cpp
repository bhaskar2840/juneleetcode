class Solution {
public:

bool dfs(unordered_map<int, vector<int>> &m, int node, vector<int> visited, int parent)
{
    if(find(visited.begin(),visited.end(),node)!=visited.end())
        return true;
    visited.push_back(node);
      //  cout<<node<<" "<<visited.size()<<endl;
        for(int v: m[node]){
            if(v==parent)
                continue;
            if(dfs(m,v,visited,node)){
                return true;
            }
        }
    
    return false;
}

vector<int> findRedundantConnection(vector<vector<int>>& A)
    {
        int n = A.size();
        vector<int> visited;
        
        unordered_map<int, vector<int>> m;
        
        for(int i=0;i<n;i++)
        {
            int f = A[i][0];
            int s = A[i][1];
            
            m[f].push_back(s);
            m[s].push_back(f);             
          //  cout<<"***** "<<f<<" *****\n";
            if(dfs(m,f,visited,-1))         
            {
              return {f,s};
            }
            visited.clear();
        }
        
        return {};
    }
};
