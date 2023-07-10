#include<iostream>
#include<vector>

using namespace std;

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

int main()
{
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = solve(arr);
    cout<<"ans is "<<ans;
}