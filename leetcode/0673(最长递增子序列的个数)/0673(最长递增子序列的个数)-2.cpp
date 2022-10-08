if(nums[i]>nums[j]){
    if(dp[i].first < dp[j].first+1){
        dp[i].first = dp[j].first+1;
        dp[i].second = dp[j].second;
        maxl = max(maxl, dp[i].first);
    }
    else if(dp[i].first == dp[j].first+1){
        dp[i].second += dp[j].second;
    }
}                