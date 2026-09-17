class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
         int n = arr.size();
        const int INF = 1e9;

        // best[i] = minimum length of a target-sum subarray
        // completely inside arr[0 ... i-1]
        vector<int> best(n + 1, INF);

        // prefixSum -> index
        unordered_map<int, int> mp;

        // prefix sum 0 exists before the array starts
        mp[0] = 0;

        int prefixSum = 0;
        int ans = INF;

        for (int i = 1; i <= n; i++) {

            prefixSum += arr[i - 1];

            // We can always carry forward the previous best
            best[i] = best[i - 1];

            // Need:
            // prefixSum - previousPrefix = target
            // previousPrefix = prefixSum - target

            if (mp.find(prefixSum - target) != mp.end()) {

                int j = mp[prefixSum - target];

                // Current subarray is arr[j ... i-1]
                int len = i - j;

                // best[j] is completely before j,
                // so the two subarrays don't overlap
                if (best[j] != INF) {
                    ans = min(ans, best[j] + len);
                }

                // Current subarray can become the best
                // target-sum subarray up to index i
                best[i] = min(best[i], len);
            }

            // Store the latest prefix-sum index
            mp[prefixSum] = i;
        }

        return ans == INF ? -1 : ans;
    }
};