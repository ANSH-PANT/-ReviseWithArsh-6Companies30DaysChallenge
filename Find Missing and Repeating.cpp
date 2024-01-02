        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto i:arr){
            mp[i]++;
        }
        for(auto i:mp){
            int x=i.second;
            if(x!=1){
                int y=i.first;
                ans.push_back(y);
                break;
            }
        }
        
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
