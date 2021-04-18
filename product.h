//product.h
#ifndef _PRODU_H
#define _PRODU_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[20];          //상품명
    int weight;             //무게
    int price;              //가격
    unsigned int star;  //별점
    int starnum;            //별점개수
}product;

int createProduct(product *p);
void readProduct(product p);
int updateProduct(product *p);
int deleteProduct(product *p);
int selectMenu();
void saveProductData(product* p, int count);
int loadProductData(product* p);

void searchProduct(product *p, int count);    //제품이름 검색
void searchStar(product *p, int count);       //별점별 검색
void searchPrice(product *p, int count);      //지정한 가격대 검색    

#endif
