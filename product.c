//product.c
#include "product.h"

int createProduct(product *p){
	printf("상품명은? ");
	getchar();
	fgets(p->name, sizeof(p->name)-1, stdin);	//scanf("%s",p->name);
	p->name[strlen(p->name)-1] = '\0';
	printf("상품 무게(g)는? ");
	scanf("%d",&p->weight);
	printf("가격은? ");
	scanf("%d",&p->price);	
	printf("별점은? ");
	scanf("%u",&p->star);
	while (p->star<1 || p->star>5) {
		printf("다시 입력하세요 : ");
		scanf("%u", &p->star);
		continue;
	}
	printf("별점 개수는? ");
	scanf("%d",&p->starnum);
	printf("==> 추가됨!\n");
	return 1;
}
void readProduct(product p){
	printf("%-5dg  %-7d %-2u   (%-6d) %s\n", p.weight, p.price, p.star, p.starnum, p.name);
}
int updateProduct(product *p){
	printf("상품명은? ");
	getchar();
	fgets(p->name, sizeof(p->name)-1, stdin);	//scanf("%s",p->name);
	p->name[strlen(p->name)-1] = '\0';
	printf("상품 무게(g)는? ");
	scanf("%d",&p->weight);
	printf("가격은? ");
	scanf("%d",&p->price);
	printf("별점은? ");
	scanf("%u",&p->star);
	while (p->star<1 || p->star>5) {
		printf("다시 입력하세요 : ");
		scanf("%u", &p->star);
		continue;
	}
	printf("별점 개수는? ");
	scanf("%d",&p->starnum);
	printf("==> 추가됨!\n");
	return 1;
}
int deleteProduct(product *p){
	p->weight = -1;
	p->price = -1;
	return 1;
}
int selectMenu(){
	int menu;
	printf("\n*** 점수계산기 ***\n");
	printf("1. 상품 조회\n");
	printf("2. 상품 추가\n");
	printf("3. 상품 수정\n");
	printf("4. 상품 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 상품명 검색\n");
	printf("7. 별점별 검색\n");
	printf("8. 가격대 검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
	return menu;
}

void saveProductData(product* p, int count){
	FILE *fp;
	fp = fopen("product.txt", "wt");
	for(int i = 0; i < count; i++){
		if(p[i].weight == -1) continue;
		fprintf(fp, "%s %d %d %u %d\n", p[i].name, p[i].weight, p[i].price, p[i].star, p[i].starnum);
	}
	fclose(fp);
	printf("=> 저장됨! \n");
}
int loadProductData(product* p){
	int i=0;
	FILE *fp;
	fp = fopen("product.txt","rt");
	if(fp == NULL) {
		    printf("=> 파일 없음\n");
		    return 0;
	}
	for(; i < 100; i++){
		fscanf(fp, "%s", p[i].name);
		if(feof(fp)) break;
		fscanf(fp, "%d", &p[i].weight);
		fscanf(fp, "%d", &p[i].price);
		fscanf(fp, "%u", &p[i].star);
		fscanf(fp, "%d", &p[i].starnum);
	}
	fclose(fp);
	printf("=> 로딩 성공!\n");
	return i;
}

void searchProduct(product *p, int count){
	int scnt = 0;
	char search[20];
	printf("검색할 제품은? ");
	scanf("%s", search);
	printf("****************************\n");
	for(int i =0; i <count ; i++){
		if(p[i].price == -1) continue;
		if(strstr(p[i].name, search)){
			printf("%2d ", i+1);
			readProduct(p[i]);
			scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}
void searchStar(product *p, int count){
	int scnt = 0;
	unsigned int search;
	printf("검색할 별점? ");
	scanf("%d", &search);
	printf("****************************\n");
	for(int i =0; i <count ; i++){
		if(p[i].price == -1) continue;
		if(p[i].star == search){
			printf("%2d ", i+1);
			readProduct(p[i]);
			scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}
void searchPrice(product *p, int count){
	int scnt = 0;
	int min=0, max=0;
	printf("검색할 가격대(최소 최대)? ");
	scanf("%d %d", &min, &max);
	printf("****************************\n");
	for(int i =0; i <count ; i++){
		if(p[i].price == -1) continue;
		if(min<p[i].price && p[i].price<max){
			printf("%2d ", i+1);
			readProduct(p[i]);
			scnt++;
		}
	}
	if(scnt == 0) printf("=> 검색된 데이터 없음!");
	printf("\n");
}
