#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    // 07/26/2022
    bool isPalindrome(string s) {  
        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
        // if character at pointer 1 is not alphanumeric keep iterating until we
        // find a alphanumeric character
        while (i < j && !isalnum(s[i]))
            i++;
        
        // same thing with pointer2 is not alphanumeric keep iterating until we find
        // a alphannumeric character
        while (i < j && !isalnum(s[j]))
            j--;

        // compare characters and if they don't match return false
        if (tolower(s[i]) != tolower(s[j]))
         return false;
        }
        
        // if we make it after one pass over the string, then it's a palindrome
        return true;
    }
    // Time Complexity: O(N), need only one pass at worst, if we find that the string
    // is a palindrome
    // Space Complexity: O(1), no extra space needed
};