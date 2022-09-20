#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    // 08/20/2022 Best Time to Buy and Sell Stock (Easy) Sliding Window 
    int maxProfit(vector<int>& prices) {
        
        if (prices.empty()) { // if there's nothing in the prices array, then there's no profit to be made so return 0
            return 0;
        }
        
        // intialize our windowsize and maxprofit
        int buyDay = 0, sellDay = 0, maxProfit = 0;
        
        
        while (sellDay < prices.size()) {
            
            // if we can make profit (price on buy day is less than sell day), then
            // we calculate current max profit and then increment our sellDay pointer
             if (prices[buyDay] < prices[sellDay]) {
                maxProfit = max(maxProfit, prices[sellDay] - prices[buyDay]); 
                sellDay++;
             } else { // if there can't be a profit, then we make our buy day our current sellday as 
                 // our current Sell day is the best time to buy
                buyDay = sellDay;
                sellDay++;
             }
        }
        
        // Time Complexity: O(N), need to pass over array only once
        // Space Complexity: O(1)
        return maxProfit;
    }
};