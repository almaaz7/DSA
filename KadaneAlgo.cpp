#include<iostream>
#include<vector>

using namespace std;
// optimal Kadans algo
int solve(vector<int> &arr)
{
    int sum = 0;
    int maxi =arr[0];

    for(int i=0;i<arr.size();i++){
        sum = sum + arr[i];
        maxi = max(maxi,sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxi;
}
//brute force

int solve3(vector<int> arr){
    int sum =0;
    int maxi = INT_MIN;
    for(int i=0;i<arr.size();i++){
        for(int j =i;j<arr.size();j++){
            sum = 0;
            for(int k=i;k<j;k++){
                sum = sum + arr[k]; 
                maxi = max(sum,maxi);  
            }
        }
    }
    return maxi;
}
int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = solve3(arr);
    cout<<"ans is "<<ans;
}

