#include"stdio.h"
main(){
	int i,n;
	float s=0.0;
	while(scanf("%d",&n) != EOF){
		if(n>0){

			for(i=0;i<n;i++){
				s+=(1.0/(4*i-3) - 1.0/(4*i-1));
			}
			printf("%.5f",4*s);
		}
	}
}
