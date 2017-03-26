// Given a string, find the length of the longest substring without repeating characters.
// Example: Given "pwwkew", the answer is "wke", with the length of 3.
// Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
class Solution {
public:
    int max(int a, int b) {
	    if (a > b)
		    return a;
	    else
		    return b;
    }
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int head = 0, index = 0, maxLen = 0;
        bool exist[256] = {};
        for (int i = 0; i <256; i++)
            exist[i] = false;
        while (index < len){
            if (exist[s[index]]){ //当遇到重复的字符
                 maxLen = max(maxLen, index - head);
                 while (s[head] != s[index]){
                     exist[s[head]] = false;
                     head++;
                 }
                 head++; index++;
             }
             else{
                 exist[s[index]] = true;
                 index++;
             }
         }
         maxLen = max(maxLen, len - head);
         return maxLen;
    }
};
