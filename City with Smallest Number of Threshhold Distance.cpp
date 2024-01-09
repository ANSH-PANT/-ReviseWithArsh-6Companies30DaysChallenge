class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) {
                    dist[i][j] = 0;
                    continue;
                }
                dist[i][j] = 10001;
            }
        }

        for(auto it : edges){
            dist[it[0]][it[1]] = dist[it[1]][it[0]] = it[2];
        }

        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }            
        }
        int ans = -1, minSum = INT_MAX;
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                if (dist[i][j] <= distanceThreshold) {
                    sum++;
                }
            }

            if(sum <= distanceThreshold){
                minSum = min(sum, minSum);
                cout<<minSum<<" ";
                if(minSum == sum){
                    ans = i;
                }
            }
        }
        return ans;
    }
};
