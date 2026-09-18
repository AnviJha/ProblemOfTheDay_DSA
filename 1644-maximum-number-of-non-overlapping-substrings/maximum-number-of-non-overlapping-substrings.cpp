class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for (int i = 0; i < s.size(); i++) {

            int ch = s[i] - 'a';

            if (first[ch] == -1)
                first[ch] = i;

            last[ch] = i;
        }

        vector<pair<int, int>> intervals;

        // Try to create a valid interval
        for (int i = 0; i < s.size(); i++) {

            // Only start from first occurrence
            if (i != first[s[i] - 'a'])
                continue;

            int l = i;
            int r = last[s[i] - 'a'];

            bool valid = true;

            for (int j = l; j <= r; j++) {

                int ch = s[j] - 'a';

                // Character occurred before l
                if (first[ch] < l) {
                    valid = false;
                    break;
                }

                // Need to expand interval
                r = max(r, last[ch]);
            }

            if (valid) {
                intervals.push_back({l, r});
            }
        }

        // Sort by ending position
        sort(intervals.begin(), intervals.end(),
             [](pair<int,int>& a, pair<int,int>& b) {
                 return a.second < b.second;
             });

        vector<string> ans;

        int prevEnd = -1;

        // Greedy selection
        for (auto [l, r] : intervals) {

            if (l > prevEnd) {

                ans.push_back(s.substr(l, r - l + 1));

                prevEnd = r;
            }
        }

        return ans;
    }
};