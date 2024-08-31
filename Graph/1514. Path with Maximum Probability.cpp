class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        map<int, vector<pair<int, double>>> adj;
        vector<double> result(n, 0);

        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});

        }

        priority_queue< pair<double, int> > pq;

        pq.push({1.0, start_node});
        result [start_node] = 1;
        
        while(!pq.empty()){

            int currNode = pq.top().second;
            double currProb = pq.top().first;
            pq.pop();

            for( auto &temp : adj[currNode]){
                
                int adjNode = temp.first;
                double adjProb = temp.second;

                if(result[adjNode] < currProb * adjProb){
                    result[adjNode] = currProb * adjProb;
                    pq.push({currProb * adjProb, adjNode});
                }


            }
        }

        return result[end_node];

    }
};