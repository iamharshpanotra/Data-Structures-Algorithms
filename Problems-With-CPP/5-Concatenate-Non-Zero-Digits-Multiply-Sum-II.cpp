// 3756. Concatenate Non-Zero Digits and Multiply by Sum II

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        long long MOD = 1000000007LL;  // 10^9 + 7

        // Step 1: Precompute powers of 10 modulo MOD
        // power10[k] = (10^k) % MOD
        // This helps in "shifting" numbers when extracting substring-like values
        vector<long long> power10(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        // Step 2: Build prefix arrays
        vector<long long> pref_sum(n + 1, 0);     // Prefix sum of all digits
        vector<long long> pref_x(n + 1, 0);       // Prefix concatenated non-zero number (mod MOD)
        vector<int> new_count(n + 1, 0);          // Count of non-zero digits up to i

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';  // Convert char to int

            // Update prefix sum (includes zeros - they add 0 anyway)
            pref_sum[i + 1] = pref_sum[i] + digit;

            if (digit != 0) {
                // Append this non-zero digit to the running number
                // (current_number * 10 + digit) % MOD
                pref_x[i + 1] = (pref_x[i] * 10 + digit) % MOD;
                new_count[i + 1] = new_count[i] + 1;
            } else {
                // Zero: ignore for x and count
                pref_x[i + 1] = pref_x[i];
                new_count[i + 1] = new_count[i];
            }
        }

        // Step 3: Process each query
        vector<int> ans;
        for (const auto& q : queries) {
            int l = q[0];
            int r = q[1];

            // Number of non-zero digits in range [l..r]
            int k = new_count[r + 1] - new_count[l];

            // Sum of digits in range (same as sum of digits in x)
            long long sum_val = pref_sum[r + 1] - pref_sum[l];

            // Compute x (number formed by non-zero digits in [l..r]) modulo MOD
            // x = (pref_x[r+1] - pref_x[l] * 10^k) % MOD
            long long left_contrib = (pref_x[l] * power10[k]) % MOD;
            long long value = (pref_x[r + 1] - left_contrib + MOD) % MOD;

            // Final answer: (x * sum) % MOD
            long long total = (value * sum_val) % MOD;

            ans.push_back((int)total);
        }

        return ans;
    }
};