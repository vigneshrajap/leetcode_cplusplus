#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

int max_profit(std::vector<int>& prices) {
    int profit = *std::max_element(prices.begin()+1, prices.end())-prices[0];

    for(int i=2; i < prices.size(); i++){
        int current_profit= *std::max_element(prices.begin()+i, prices.end())-prices[i-1];
        if (current_profit>profit){
            profit = current_profit;            
        }
    }

    if (profit < 0) profit = 0;

    return profit;
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
