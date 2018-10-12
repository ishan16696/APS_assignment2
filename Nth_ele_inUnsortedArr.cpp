#include <bits/stdc++.h>
#include<time.h>
using namespace std;


//********************************** swap call by refrence ********************************************************************************

void interchange(int *temp1,int *temp2){
	int temp3=*temp1;
	*temp1=*temp2;
	*temp2=temp3;
}


//************************************************  PARTITION *********************************************************************************
int QuickSortpartition(int terr[],int start,int end){  // here start and end are index not position
		int i,k;
		i=start-1;
		int size=end-start+1;
		int comp=rand()%size;  // mod to put  it in size of array  and rand() function to make it randomised quickSort().
		//cout << terr[start+comp] << endl;
		//cout << terr[end] << endl;
		interchange(&terr[start+comp],&terr[end]);
		comp=terr[end];
		for(k=start;k<end;k++){
			if(terr[k]<=comp){
				i++;
				interchange(&terr[i],&terr[k]);
			}
		}
		interchange(&terr[i+1],&terr[end]);
		//cout << i << endl;
		return i+1;

}

//****************************************  SEARCH of nth smallest element ************************************************************************
int find_nth_smallest(int input[],int l,int r,int ele){
		int size=r-l+1;

		if(ele >0 && ele <=size)
		{
		int pos=QuickSortpartition(input,l,r);
		//cout << pos<<" ";
		if(pos-l==ele-1){
			return input[pos];
		}
		else if(pos-l>ele-1){
			return find_nth_smallest(input,l,pos-1,ele);  // call on the left sub array
		}
		else{
			return find_nth_smallest(input,pos+1,r,ele-(pos-l+1));// call on the right sub array
		}

	}

	return -1;
}





//************************************************************** MAIN ****************************************************************************
int main(){
	clock_t time_st,time_en;
	cout << "Enter the no of elements:" <<endl;
	int n,ele;
	cin >> n;
	int input[n]; // make the array
	cout << "Enter:" << endl;
	for(int i=0;i<n;i++){
		cin >> input[i];
	}
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i]=input[i];

	cout << "Enter the nth smallest element you want to search:" << endl;
	cin >> ele;
	time_st=clock();
	int result=find_nth_smallest(input,0,n-1,ele);
	time_en = clock();
	cout << result << endl;
	double time_taken = ((double)time_en-time_st)/CLOCKS_PER_SEC * 1000;
	cout << time_taken << "ms"<<endl;


	//comaprison
	time_st=clock();
	nth_element(arr,arr+ele-1,arr+n);

	time_en = clock();
	time_taken = ((double)time_en-time_st)/CLOCKS_PER_SEC * 1000;
	cout << time_taken << "ms"<<endl;
	cout << arr[ele-1]<<endl;
	return 0;
}