#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {}

    int ping(int t) {
        // 1. Add the new request to the end of the queue
        requests.push(t);

        // 2. Remove all timestamps that are outside the [t-3000, t] range
        // Since t is strictly increasing, these will always be at the front
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // 3. The size of the queue is now exactly the number of recent calls
        return requests.size();
    }
};