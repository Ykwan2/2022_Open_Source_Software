#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "product.h"

void readProduct(product s) {
    printf("\t%s \t%s %18s %8d", s.name, s.info, s.weight, s.price);
    if (s.shipping==0)  printf("    새벽배송\n");
    if (s.shipping==1)  printf("    택배배송\n");
}

void listProduct(product *s, int count) {
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게     가격    배송방식\n");
    printf("===================================================================================\n");
    int a=count;
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) {
            a--;
            continue;
        }
        printf("%2d", i+1);
        readProduct(s[i]);
    }
    printf("\n총 %d개의 주문이 있습니다.\n", a);
}

int selectDataNo (product *s, int count) {
    int no;
    listProduct(s, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
}

int createProduct(product *s) {
    printf("\n제품이름 ? ");
    scanf(" %[^\n]s", s->name);
    printf("제품정보 ? ");
    scanf(" %[^\n]s", s->info);
    printf("제품 무게 ? ");
    scanf(" %[^\n]s", s->weight);
    printf("제품 가격 ? ");
    scanf(" %d", &s->price);
    printf("배송 방법 ? (0:새벽 배송, 1:택배 배송) ");
    scanf(" %d", &s->shipping);
    printf("=> 제품 추가 완료 ! \n");
    return 1;
}

int updateproduct(product* s) {
    printf("\n새 제품이름 ? ");
    scanf(" %[^\n]s", s->name);
    printf("새 제품정보 ? ");
    scanf(" %[^\n]s", s->info);
    printf("새 제품 무게 ? ");
    scanf(" %[^\n]s", s->weight);
    printf("새 제품 가격 ? ");
    scanf(" %d", &s->price);
    printf("새 배송 방법 ? (0:새벽 배송, 1:택배 배송) ");
    scanf(" %d", &s->shipping);
    printf("=> 제품 변경 완료 ! \n");
    return 1;
}

int deleteProduct(product *s) {
    s->price=-1;
    printf("=> 삭제됨!\n");
    return 1;
}

void saveData(product *s, int count) {
    FILE *fp;
    fp=fopen("product.txt", "wt");
    for (int i=0; i< count; i++) {
        if(s[i].price==-1) continue;
        fprintf(fp, "%s, %s, %s, %d %d\n",  s[i].name, s[i].info, s[i].weight, s[i].price, s[i].shipping);
    }
    fclose(fp);
    printf("=> 저장됨! \n");
}

int loadData(product *s, int number) {
    int count=0, i=0;
    FILE *fp;
    fp=fopen("product.txt", "rt");
    printf("=> 데이터 가져오는 중...\n");
    if (fp==NULL) {
        printf("=> 파일 없음 \n");
    }
    else {
    for (;i<number;i++) {
        fscanf(fp, " %[^,], %[^,], %[^,], %d %d", s[i].name, s[i].info, s[i].weight, &s[i].price, &s[i].shipping);
        if (feof(fp)) break;
        count++;
    }
    printf("=> %d 개의 주문 정보를 읽었습니다!\n", count);
    }
    fclose(fp);
    return i;
}

void searchProductName(product *s, int count) {
    int scnt=0;
    char search[20];
    printf("검색할 제품 이름? ");
    scanf(" %[^\n]s", search);
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게    가격   배송방식\n===========================================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) continue;
        if (strstr(s[i].name, search)) {
             printf("%2d", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    printf("\n총 %d개의 주문이 있습니다.\n", scnt);
    if (scnt==0) printf("=> 검색된 데이터 없음!\n");
}   

void searchProductShipping(product *s, int count){
    int scnt=0;
    int search;
    printf("검색할 제품 배송 방법? (0:새벽 배송, 1:택배 배송) ");
    scanf(" %d", &search);
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게    가격   배송방식\n===========================================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) continue;
        if (s[i].shipping==search) {
            printf("%2d", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    printf("\n총 %d개의 주문이 있습니다.\n", scnt);
    if (scnt==0) printf("=> 검색된 데이터 없음!\n");   
}

void searchProductPrice(product *s, int count){
    int scnt=0;
    int search;
    printf("검색할 제품 가격? ");
    scanf(" %d", &search);
    printf("\n********* 제품 **********\n");
    printf("\n번호\t제품이름\t\t제품정보\t\t무게    가격   배송방식\n===========================================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].price==-1) continue;
        if (s[i].price==search) {
             printf("%2d", i+1);
            readProduct(s[i]);
            scnt++;
        }
    }
    printf("\n총 %d개의 주문이 있습니다.\n", scnt);
    if (scnt==0) printf("=> 검색된 데이터 없음!\n");
}

int selectProduct(){
    int Product;
    printf("\n****** 제품 판매 ******\n1. 제품 조회\n2. 제품 추가\n3. 제품 수정\n4. 제품 삭제\n5. 제품 저장\n6. 제품이름 검색\n7. 제품가격 검색\n8. 제품 배송방법 검색\n0. 종료\n");
    printf("\n=> 원하는 메뉴는? ");
    scanf("%d", &Product);
    return Product;
}

int main(void){
    product sp[50];
    int count = 0, Product;
    int index=0;
    
    count = loadData(sp, 50);
    index = count;
    while (1){
        Product = selectProduct();
        if (Product == 0) break;
        if (Product == 1 || Product == 3 || Product == 4 || Product == 5 || Product == 6 || Product == 7 || Product == 8) {
            if (count==0) continue;
        }
        if (Product == 1) {
            listProduct(sp, index);
        }
        else if (Product == 2) {
            count += createProduct(&sp[index++]);
        }
        else if (Product == 3) {
            int no=selectDataNo(sp, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateproduct(&sp[no-1]);
        }
        else if (Product == 4) {
            int no=selectDataNo(sp, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)");
            scanf("%d", &deleteok);
            if (deleteok == 1) {
                if (deleteProduct(&sp[no-1])) {
                    count--;
                }
            }
        }
        else if (Product==5) {
            saveData(sp, index);
        }
        else if (Product==6) {
            searchProductName(sp, count);
        }
        else if (Product==7) {
            searchProductPrice(sp, count);
        }
        else if (Product==8) {
            searchProductShipping(sp, count);
        }
    }
    printf("종료됨!\n");
    return 0;
}
