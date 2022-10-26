#include <bits/stdc++.h> 
typedef long long int ll;

ll maximumNonAdjacentSum(vector<ll> &nums){
    ll n = nums.size();
    vector<long long int> dp(n+1,-1);
//     return solve(dp,nums,n-1);
    dp[0] = nums[0];
    ll neg = 0;
    for(int i=1;i<n;i++){
        ll take = nums[i];
        if(i>1){take += dp[i-2];}
        ll nottake = dp[i-1];
        dp[i] = max(take,nottake);
    }
    return dp[n-1];
}

long long int houseRobber(vector<int>& valueInHouse)
{
    ll n = valueInHouse.size();
    vector<ll> temp1,temp2;
    if(n==1){return valueInHouse[0];}
    for(int i=0;i<n;i++){
        if(i!=0){temp1.push_back(valueInHouse[i]);}
        if(i!=n-1){temp2.push_back(valueInHouse[i]);}
    }
    return max(maximumNonAdjacentSum(temp1),maximumNonAdjacentSum(temp2));
}




