#include<stdio.h>
int f(int n){
int i,a=1;
if(n>1)
  for(i=1;i<=n/2;i++)
	  a=a+f(i);
  return a;
}
void main(){
  int n;
  scanf("%d",&n);
  printf("%d\n",f(n));
}
