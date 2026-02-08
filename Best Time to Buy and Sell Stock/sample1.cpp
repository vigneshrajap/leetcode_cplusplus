#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int max_profit(std::vector<int>& prices) {
    int bestBuy = prices[0];
    int bestProfit = 0;

    for (int i = 1; i < prices.size(); i++) {
        bestProfit = std::max(bestProfit, prices[i] - bestBuy);
        bestBuy = std::min(bestBuy, prices[i]);
    }

    return bestProfit;
}

template<typename T>
std::vector<T> get_words() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream ss{line};
    ss >> std::boolalpha;
    std::vector<T> v;
    std::copy(std::istream_iterator<T>{ss}, std::istream_iterator<T>{}, std::back_inserter(v));
    return v;
}

int main() {
    std::vector<int> prices = get_words<int>();
    int res = max_profit(prices);
    std::cout << res << '\n';
}
