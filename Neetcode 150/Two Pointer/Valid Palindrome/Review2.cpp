#include <iostream>

using namespace std;

class Solution {
public:
    // 08/24/2022 Valid Palindrome (Two Pointers) (Easy) 
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    
    bool isPalindrome(string s) {
        
        int left = 0, right = s.length() - 1; // two pointers
        
        while (left < right) { // once left == right, then we know that we've passed over the whole string
            
            while (!isalnum(s[left]) && left < right) { // we only need alphanumeric charactes, so we iterate until both pointers are on alphanumeric characters
                left++;
            }
            
            while (!isalnum(s[right]) && left < right) {
                right--;
            }
            
            if (tolower(s[left]) != tolower(s[right])) { // convert all uppercase to lower case letters, and if they are not the same, return false
                return false;
            }
            left++;
            right--;
        }
        
        return true; // if we make it through it's a palindrome
    }
};