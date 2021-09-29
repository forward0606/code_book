Dynamic_Programming_Knapsack_Tips
1.Check the specified subset sum whether exist // the num means the weight and value
2.Get the closest number to the specified num // the num means the weight and value
3.We can use three loops to solve two dimension knapsack problem. // two kinds of objects
4.Complete knapsack: Every objects can use infinitly. // exclude permutations and combinations
Complete Knapsack with permutations and combinations
Key code: dp[j] += dp[j-coins[i]];  // get the possibility
1.for items , for amount is about combination
2.for amount , for items is about permutation
Multi Knapsack
1.Put every same item into the same backpack, then you can count it easily
