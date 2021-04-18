//manager.c
#include "manager.h"

void listProduct(product *p, int count){
	printf("\nNo weight  price  star  starnum\t Name\n");
	printf("=================================================\n");
	for(int i =0; i <count ; i++){
		if(p[i].weight == -1) continue;
		printf("%2d ", i+1);
		readProduct(p[i]);
	}
	printf("\n");
}
int selectDataNumber(product *p, int count){
	int idx;
	listProduct(p, count);
	printf("번호는?(취소: 0)");
	scanf("%d",&idx);
	return idx;
}
