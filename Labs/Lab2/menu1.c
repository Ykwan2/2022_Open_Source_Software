#include <stdio.h>
#include <stdlib.h>

typedef struct Score{
    char name[100];
    char type;
    int price;
} Score;
 
void readScore(Score s) {
    int no=1;
    printf("%d %10d %c %s\n", no, s.price, s.type, s.name);
}

int addScore(Score *s) {
    printf("메뉴명은? ");
    scanf(" %[^\n]s", s->name);
    printf("메뉴종류(P/S/R)? ");
    scanf(" %c", &s->type);
    printf("가격은? ");
    scanf(" %d", &s->price);
    return 1;
}

int updateScore(Score* s) {
    printf("새 메뉴명은? ");
    scanf(" %[^\n]s", s->name);
    printf("새 메뉴종류(P/S/R)? ");
    scanf(" %c", &s->type);
    printf("새 가격은? ");
    scanf(" %d", &s->price);
    printf("=>수정성공!\n");
    return 1;
}

int deleteScore(Score *s) {
    s->price=-1;
    printf("=> 삭제됨!\n");
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** PizzaYaho ***\n1. 메뉴조회\n2. 메뉴추가\n3. 메뉴수정\n4. 메뉴삭제\n0. 종료\n");
    printf("\n=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int main(void){
    Score sp;
    int count = 0, menu;
    
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 || menu == 4) {
            if (count==0) continue;
        }
        if (menu == 1) {
            printf("*****************\n");
            if (sp.price !=-1) readScore(sp);
        }
        else if (menu == 2) count+=addScore(&sp);
        else if (menu == 3) updateScore(&sp);
        else if (menu == 4) deleteScore(&sp);
    }
    printf("종료됨!\n");
    return 0;
}
