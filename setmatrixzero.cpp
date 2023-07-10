#include<iostream>
#include<vector>
using namespace std;

//optimal solution
vector<vector<int>> setMatrix3(vector<vector<int>>& arr,int n,int m)
{
	int col = 1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				arr[i][0] = 0;

				if(j!=0){
					arr[0][j]=0;
				}else{
					col = 0;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(arr[i][j]!=0){
				if(arr[0][j]==0 ||arr[i][0]==0){
					arr[i][j]=0;
				}
			}
		}
	}
	if(arr[0][0]==0){
		for(int j =0;j<m;j++){
			arr[0][j]=0;
		}
	}
	if(col == 0){
		for(int i=0;i<n;i++){
			arr[i][0]=0;
		}
	}
	return arr;
}
//better approach

vector<vector<int>> setMatrix2(vector<vector<int>>& arr,int n,int m)
{
	int col[m] = {0};
	int row[n] = {0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}

	for(int i =0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]!=0){
				if(row[i]== 1 || col[j]==1){
					arr[i][j]=0;
				}
			}
		}
	}
	return arr;
}

//brute force
void setrow(vector<vector<int>>& arr,int i,int m){
	for(int j=0;j<m;j++){
		if(arr[i][j]!=0){
			arr[i][j]=-1;
		}
	}
}
void setcol(vector<vector<int>>& arr,int j,int n){
	for(int i=0;i<n;i++){
		if(arr[i][j]!=0){
			arr[i][j]=-1;
		}
	}
}

vector<vector<int>> setMatrix(vector<vector<int>>& arr,int n,int m)
{
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==0){
				setrow(arr,i,m);
				setcol(arr,j,n);
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]==-1){
				arr[i][j]=0;
			}
		}
	}
	return arr;
}

void print(vector<vector<int>> arr,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
     }
}
int main()
{
	int n,m;
	cin>>n>>m;
    vector<vector<int>> arr(n,vector<int>(m,0));
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
     }
	 print(arr,n,m);

	 vector<vector<int>> ans = setMatrix3(arr,n,m);

	 print(ans,n,m);
}