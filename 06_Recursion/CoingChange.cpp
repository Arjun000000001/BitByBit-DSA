#include <bits/stdc++.h>
using namespace std;

/*
============================================================
 LeetCode 322 - Coin Change
 This file demonstrates the progression:
 1. Brute Force (Pure Recursion)
 2. Better (Recursion + Pruning)
 3. Optimal (Dynamic Programming)
============================================================
*/

// ------------------------------------------------------------
// 1. BRUTE FORCE (Pure Recursion)
// ------------------------------------------------------------
// Idea:
// Try all possible combinations of coins.
// If amount becomes exactly 0 -> valid solution.
// If amount becomes negative -> invalid path.
//
// Time Complexity: Exponential (Very Slow)
// Verdict: Correct but TLE

int bruteHelper(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    if (amount < 0) return INT_MAX;

    int ans = INT_MAX;
    for (int coin : coins) {
        int res = bruteHelper(coins, amount - coin);
        if (res != INT_MAX)
            ans = min(ans, res + 1);
    }
    return ans;
}

int coinChangeBrute(vector<int>& coins, int amount) {
    int res = bruteHelper(coins, amount);
    return res == INT_MAX ? -1 : res;
}

// ------------------------------------------------------------
// 2. BETTER APPROACH (Recursion + Pruning)
// ------------------------------------------------------------
// Idea:
// Same recursion as brute force, but keep track of the
// minimum coins found so far (mini).
// Stop exploring paths that already use >= mini coins.
//
// Time Complexity: Better than brute, still exponential
// Verdict: Correct but still TLE for large inputs

void betterHelper(vector<int>& coins, int amount,
                  int currSum, int count, int& mini) {

    if (currSum == amount) {
        mini = min(mini, count);
        return;
    }

    if (currSum > amount) return;

    // Pruning: already worse than best answer
    if (count >= mini) return;

    for (int coin : coins) {
        betterHelper(coins, amount,
                     currSum + coin,
                     count + 1,
                     mini);
    }
}

int coinChangeBetter(vector<int>& coins, int amount) {
    int mini = INT_MAX;
    betterHelper(coins, amount, 0, 0, mini);
    return mini == INT_MAX ? -1 : mini;
}

// ------------------------------------------------------------
// 3. OPTIMAL APPROACH (Dynamic Programming)
// ------------------------------------------------------------
// Idea:
// dp[x] = minimum coins needed to make amount x
// Build solution bottom-up.
//
// Time Complexity: O(amount * number_of_coins)
// Verdict: Accepted and optimal

int coinChangeOptimal(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
}

// ------------------------------------------------------------
// Driver code (for local testing)
// ------------------------------------------------------------
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    cout << "Brute Force: " << coinChangeBrute(coins, amount) << endl;
    cout << "Better (Pruning): " << coinChangeBetter(coins, amount) << endl;
    cout << "Optimal (DP): " << coinChangeOptimal(coins, amount) << endl;

    return 0;
}
