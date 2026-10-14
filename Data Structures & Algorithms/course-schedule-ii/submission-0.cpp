class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& p) {
        
        // 1. make adjacency matrix 
        vector<vector<int>> adjls(numCourses); 

        for(auto &it : p) { 

            int u = it[0] ; int v = it[1]  ;
            adjls[u].push_back(v);
        }

        // 2. make indegree vector
        vector<int> indegree(numCourses) ;

        for(int i=0; i<numCourses; i++ ){
            for(auto &it : adjls[i]) {
                indegree[it] ++ ;
            }
        }

        // 3. store all 0 indegree nodes into the queue
        queue<int> q ;
        for(int i=0; i<indegree.size(); i++ ){
            if(indegree[i] == 0 ) q.push(i) ;
        }

        // 4. main logic
        vector<int> topo ; 

        while(!q.empty () ) {

            topo.push_back(q.front() ) ;
            int node = q.front() ; q.pop();

            for(auto &it : adjls[node] ) {

                indegree[it] --; 
                if(indegree[it] == 0 ) q.push(it ) ;
            }
        } 

        if(topo.size() < numCourses) return {} ;
        reverse(topo.begin(), topo.end() ) ;
        return topo ; 


        
    }
};