#include<iostream>
using namespace std;

int placevalue(int n,int r)
{
    int res = 1;
    for(int i =0;i<r;i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

int main()
{
    cout<<placevalue(5-1,3-1);
}