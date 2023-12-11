#include<bits/stdc++.h>
using namespace std;


int solve(vector<int>& nums){
    int n = nums.size();
    
    vector<int> dp(n+1,1);
    vector<int> cnt(n+1,1);

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                dp[i] = max(dp[i], dp[j]+1);
                cnt[i] = max(cnt[i],cnt[j]+1);
            }
        }
    }

    int maxCnt=0;
    for(int i=0;i<n;i++){
        maxCnt = max(maxCnt,cnt[i]);
    }

    return maxCnt;

}

int findNumberOfLIS(vector<int>& nums){
    int ans = solve(nums);

    return ans;
}


int main(){
    int n;
    cin>>n;

    vector<int> nums;

    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        nums.push_back(t);
    }

    cout<<findNumberOfLIS(nums);
}