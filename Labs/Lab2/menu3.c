#include <stdio.h>
#include <stdlib.h>

typedef struct Score{
    char name[100];
    char type;
    int price;
} Score;

void readScore(Score s) {
    printf("%10d %c %s\n", s.price, s.type, s.name);
}

void listScore(Score *s[], int count) {
    printf("\n*****************\n");
    for (int i=0; i<count; i++) {
        if (s[i]==NULL) continue;
        printf("%2d", i+1);
        readScore(*s[i]);
    }
    printf("\n");

}

int selectDataNo (Score *s[], int count) {
    int no;
    listScore(s, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
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
    Score *s[20];
    int count = 0, menu;
    int index=0;
    
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 || menu == 4) {
            if (count==0) continue;
        }
        if (menu == 1) {
            if (count>0) {
                listScore(s, index);
            }
        }
        else if (menu == 2) {
            s[index] = malloc(sizeof(Score));
            count += addScore(s[index++]);
        }
        else if (menu == 3) {
            int no=selectDataNo(s, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateScore(s[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(s, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)");
            scanf("%d", &deleteok);
            if (deleteok == 1) {
                if (deleteScore(s[no-1])) {
                    free(s[no-1]);
                    s[no-1]=NULL;
                    count--;
                }
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}
