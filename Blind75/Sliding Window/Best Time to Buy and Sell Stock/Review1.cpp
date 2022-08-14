#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        // using sliding window with two pointers to keep track of days 
        // we're comparing and calculating profit for
        
        int maxProfit = 0; // variable to keep track of our maxProfit
        int left = 0, right = 0; // left and right pointers
        
        while (right < prices.size()) { // until we reach the end of the array
            
            if (prices[left] < prices[right]) { // if we make a profit, compare current profit and our maxProfit
                maxProfit = max(maxProfit, prices[right] - prices[left]);
                right++; // increment our right pointer to calculate possible profit for the next day
            } else {
                left = right; // if price on our buy (left) day is >= than the price of the right day, we make our left pointer = right
                // as we've found the newest lowest price to buy the stock
                right++; // incrment right pointer to begin comparison of next possible profit on the next day
            }
            
        }
    
        return maxProfit;
        // Time Complexity: O(N), need to pass through array only once
        // Space Complexity: O(1), no extra space needed
    }
};