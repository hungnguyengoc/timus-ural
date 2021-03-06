//#include "stdafx.h"
#include <iostream>
using namespace std;

const int maxn=55;
int data[maxn];
int n, ans;

void change(int &a, int &b, int &c){
	int tmp=a;
	a=b;
	b=c;
	c=tmp;
}

void check(int a, int b, int c){
	for(int i=1;i<=n;++i)
	{
		if(i!=a && abs(data[i]-data[a])==abs(i-a))
			return ;
		if(i!=b && abs(data[i]-data[b])==abs(i-b))
			return ;
		if(i!=c && abs(data[i]-data[c])==abs(i-c))
			return ;
	}
	++ans;
}

int main(){
	scanf("%d", &n);
	int tmp;
	for(int i=1;i<=n;++i){
		scanf("%d", &tmp);
		scanf("%d", &data[tmp]);
	}
	ans=0;

	for(int i=1;i<=n-2;++i)
		for(int j=i+1;j<=n-1;++j)
			for(int k=j+1;k<=n;++k){
				change(data[i], data[j], data[k]);
				check(i, j, k);
				change(data[i], data[j], data[k]);
				check(i, j, k);
				change(data[i], data[j], data[k]);
			}
	printf("%d\n", ans);
	return 0;

}
