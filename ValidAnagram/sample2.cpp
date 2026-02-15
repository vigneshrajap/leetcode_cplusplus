bool isAnagram(string a, string b) {
    if (a.size() != b.size()) return false;

    unordered_map<char, int> count;

    for (char c : a) count[c]++;
    for (char c : b) {
        if (--count[c] < 0) return false;
    }

    return true;
}