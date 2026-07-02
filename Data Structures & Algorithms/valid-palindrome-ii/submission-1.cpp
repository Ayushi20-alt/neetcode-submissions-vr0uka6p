class Solution {
public:
    bool isPalindrome(int i, int j, string s){
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.size()-1;

        while(left < right){
            if(s[left] == s[right]){
                left++;
                right--;
            }else{
                return isPalindrome(left+1, right, s) || isPalindrome(left, right-1, s);
            }
        }

        return true;
    }
};