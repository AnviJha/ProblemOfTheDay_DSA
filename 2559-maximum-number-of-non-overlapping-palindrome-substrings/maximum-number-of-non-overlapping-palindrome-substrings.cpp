class Solution {
public:
    bool pal(const string& s, int i, int j) {
        while (i < j) {
            if (s[i++] != s[j--]) return false;
        }
        return true;
    }

    // [b] solve(i, j) = max non-overlapping palindromic pieces (length >= k)
    //     achievable, considering the window s[i..j] as the "current candidate"
    int solve(const string& s, int k, int i, int j, vector<vector<int>>& t) {
        int n = s.size();
        if (i >= n || j >= n) 
            return 0;
            
        if (t[i][j] != -1) 
            return t[i][j];

        if (pal(s, i, j)) {
            // [c] this window IS a palindrome (length j-i+1 >= k) — three choices:
            int growWindow  = solve(s, k, i, j + 1, t);           // keep growing this window, don't commit yet
            int takeIt      = 1 + solve(s, k, j + 1, j + k, t);   // commit to this piece, start a fresh window of length k after it
            int slideWindow = solve(s, k, i + 1, j + 1, t);       // don't take it, just slide the whole window forward

            return t[i][j] = max({growWindow, takeIt, slideWindow});
        }

        // [d] this window is NOT a palindrome — only two choices: grow it, or slide it
        int slideWindow = solve(s, k, i + 1, j + 1, t);
        int growWindow  = solve(s, k, i, j + 1, t);
        return t[i][j] = max(slideWindow, growWindow);
    }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        if (k == 1) return n; // every single character is trivially a palindrome of length 1

        vector<vector<int>> t(n, vector<int>(n, -1));
        return solve(s, k, 0, k - 1, t);
    }
};