#include <bits/stdc++.h> 
   
int f(vector<int> &heights,int ind,vector<int> &dp) 
{
   

    if(ind==0) {
        return 0;
    }
     if(dp[ind]!=-1) {
        return dp[ind];
     }
    int right=INT_MAX;
    int left=f(heights,ind-1,dp)+ abs(heights[ind]-heights[ind-1]);
    if(ind>1) 
        right=f(heights,ind-2,dp)+ abs(heights[ind]-heights[ind-2]);
    
    return dp[ind]=min(left,right);
    
    
}



int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n,-1);
    dp[0]=0;
    
    for(int i=1;i<n;i++) {
        int fs=dp[i-1]+abs(heights[i-1]-heights[i]);
        int ss=INT_MAX;
        if(i>1)
        ss=dp[i-2]+abs(heights[i-2]-heights[i]);
        dp[i]=min(fs,ss);
    }
    return dp[n-1];
  // vector<int> dp(n+1,-1);
   return f(heights,n-1,dp);
        
}