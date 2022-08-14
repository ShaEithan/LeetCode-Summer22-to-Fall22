#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    // 07/29/2022 Best Time to Buy and Sell Stock

    // Time Complexity: O(N), need to do only one pass of the array
    // Space Complexity: O(1)
    int maxProfit(vector<int>& prices) {
        
        // we want to buy low, so we can sell high later
        
        // windowStart is the day we are buying, want this to be as low as possible
        int windowStart = 0;
        int maxProfit = 0;
        
        // loop to iterate over one pass of the array
        for (int windowEnd = 1; windowEnd < prices.size(); windowEnd++) {
            
            // if our buy day is lower than our current sell day, then we calculate
            // profit and then find the maxProfit
            if (prices[windowStart] < prices[windowEnd]) {
                int profit = prices[windowEnd] - prices[windowStart];
                maxProfit = max(maxProfit, prices[windowEnd] - prices[windowStart]);
            } else {
                // if our buy date is greater than or equal to our sell date,
                // make our buy date = the sell date as we've found our current lowest price to use
                // and save time iterating
                windowStart = windowEnd;
            }
        }
        
        return maxProfit;
    }
};