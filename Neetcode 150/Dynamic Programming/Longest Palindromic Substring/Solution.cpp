#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    // 09/30/2022 Longest Palindromic Substring (Medium)
    string longestPalindrome(string s) {
        string result = ""; // creating empty string to store our result
        int longestLength = 0; // keeps track of our result's longest length
        
        // we expand from the "center" of the string to find if its a palindrome
        // we call each index i our "center"
        for (int i = 0; i < s.length(); i++) {
            // for odd length strings, we can start at the same place 
            int left = i, right = i;
            
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                
                if (right - left + 1 > longestLength) { // if our current length is larger than our longestLength
                    // redefine longest length and then get our current longest length
                    longestLength = right - left + 1;
                    result = s.substr(left, right + 1);
                }
                left--;
                right++;
            }
            
            
            // for even length strings, we have to increment one pointer because
            // we'd go out of bounds
            left = i;
            right = i + 1;
            
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                
                if (right - left + 1 > longestLength) {
                    longestLength = right - left + 1;
                    result = s.substr(left, right + 1);
                }
                left--;
                right++;
            }
        }
        
        // Time Complexity: O(n^2), as for every time when we consider expanding a palindrome from it's "middle", to find if it's a palindrome
        // it can take O(N) time so the complexity is O(n^2)
        // Space Complexity: O(1), no extra space needed
        return result;
    }
    
};