#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int handleLow(char* c,int m,int k,int sum){
	int x=0;
	if(k>9*m) return 0;
	if(sum<k) x=m-1;
	else x=1;
	while(sum!=k && x>=0 && x<m){
		if(sum>k){
			if(c[x]-'0'>0){
				c[x]-=1;
				sum--;
			}else x++;
		}

		if(sum<k){
			if(c[x]-'0'<9){
				c[x]+=1;
				sum++;
			}else x--;
		}
	}
	if(sum==k) return 1;
	else 0;
}

int handleHigh(char* c,int m,int k,int sum){
	int x=0;
	if(k>9*m) return 0;
	if(sum>k) x=m-1;
	while(sum!=k && x>=0 && x<m){
		if(sum>k){
			if(c[x]-'0'>0){
				c[x]-=1;
				sum--;
			}else x--;
		}
	}
	if(c[0]=='0') return 0;
	if(sum==k) return 1;
	else 0;
}

int main(){
	int m,k; scanf("%d %d",&m,&k);
	char* low=(char*) malloc(sizeof(char)*m);
	char* high=(char*) malloc(sizeof(char)*m);

	low[0]='1';
	for(int i=1;i<m;i++) low[i]='0';
	for(int i=0;i<m;i++) high[i]='9';

	int lw=handleLow(low,m,k,1);
	int hg=handleHigh(high,m,k,9*m);
	printf("%s %s\n",(lw?low:"-1"),(hg?high:"-1"));

	free(low); free(high);
}