bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> count, freqCount;

    for (int x : arr)
        count[x]++;

    for (auto& p : count)
        if (++freqCount[p.second] > 1)
            return false;

    return true;
}