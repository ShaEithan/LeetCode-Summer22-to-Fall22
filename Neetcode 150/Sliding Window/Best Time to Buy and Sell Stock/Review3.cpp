#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 08/29/2022 Best Time to Buy and Sell Stock (Easy) Sliding Window
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1, maxProfit = 0;
        
        // sliding window problem
        while (sell < prices.size()) { 
            if (prices[buy] < prices[sell]) { // if there's a profit, then we calculate current profit
                // compare it to our current max profit 
                maxProfit = max(maxProfit, prices[sell] - prices[buy]);
                sell++; // slide our window to the next day
            } else { // if there's no profit, then our current sell day is a better a buy day
                // so we set buy = sell, then increment sell to contiue calculation
                buy = sell; 
                sell++;
            }
        }
    
        return maxProfit;
    }
};
