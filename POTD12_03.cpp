class Solution {
  public:
    int minChar(string& s) {
        // Write your code here
        string rev = s;
        reverse(rev.begin(), rev.end());
        string combined = s + "#" + rev;
        int n = combined.length();
        int lps[n] = {0};
        for (int i = 1; i < n; i++) {
            int j = lps[i - 1];
            while (j > 0 && combined[i] != combined[j]) {
                j = lps[j - 1];
            }
            if (combined[i] == combined[j]) {
                j++;
            }
        lps[i] = j;
        }
        return s.length() - lps[n - 1];
    }
};
