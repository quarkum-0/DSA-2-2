//COPIED
#include<stdio.h>

int n,k;
int packer(int*,int,int*);

int main(){
	scanf("%d %d",&n,&k);
	int arr[n],box[k];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<k;i++) box[i]=0;//the box contains subsequence sum
	printf("%d\n",packer(arr,0,box));
}

int packer(int arr[],int idx,int box[]){
	if(idx==n){
		int m=0; // m is finding the max of subsequence sum
		for(int i=0;i<k;i++){
			if(m<box[i]){
				m=box[i];
			}
		}
		return m;
	}
	int mb=1000000;
	for(int i=0;i<k;i++){
		box[i]+=arr[idx];
		int temp=packer(arr,idx+1,box);
		box[i]-=arr[idx];
		if(mb>temp) mb=temp;
	}

	return mb;
}