public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int ans=0;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)v.push_back({end[i],start[i]});
        sort(v.begin(),v.end());
        int last=-1;
        for(int i=0;i<n;i++){
            if(v[i].second>last){
                ans++;
                last=v[i].first;
            }
        }
        return ans;
    }
