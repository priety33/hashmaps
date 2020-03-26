/*
Two strings are called k-anagrams if following two conditions are true.

    Both have same number of characters.
    Two strings can become anagram by changing at most k characters in a string.

*/

bool areKAnagrams(string str1, string str2, int k)
  {
    if(str1.length()!=str2.length()) return false;
    int m[26]={0};
    int n=0;
    for(int i=0;i<str1.length();i++) m[str1[i]-'a']++;
    for(int i=0;i<str2.length();i++)
    {
        if(m[str2[i]-'a']>0) m[str2[i]-'a']--;
        else n++;
        if(n>k) return false;
    }
    return true;
  }
