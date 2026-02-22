class RecentCounter {
public:
    RecentCounter() {}

    vector<int> requests = {};   

    int ping(int t) {
        int min = t-3000;
        int max = t;

        requests.push_back(t);

        int recent_calls = 0;

        for(auto& val:requests){
            if (val>=min && val<=max){
                recent_calls++;
            }
        }

        return recent_calls;
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */