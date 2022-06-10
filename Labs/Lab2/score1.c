#include <stdio.h>
#include <stdlib.h>

typedef struct Score{
    char name[20];
    int kor;
    int eng;
    int math;
    int total;
    double ave;
} Score;
 
void readScore(Score s) {
    printf("%s %5d %5d %6d %5d %5.1f\n", s.name, s.kor, s.eng, s.math, s.total, s.ave);
}

int addScore(Score *s) {
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    s->total=s->kor+s->eng+s->math;
    s->ave=s->total/3.0;
    return 1;
}

int updateScore(Score* s) {
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    s->total=s->kor+s->eng+s->math;
    s->ave=s->total/3.0;
    return 1;
}

int deleteScore(Score *s) {
    s->kor=-1;
    printf("=> 삭제됨!\n");
    return 1;
}

int selectMenu(){
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1-> 조회\n");
    printf("2-> 추가\n");
    printf("3-> 수정\n");
    printf("4-> 삭제\n");
    printf("0-> 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}


int main(void){
    Score s;
    int count = 0, menu;
    
    while (1){
        menu = selectMenu();
        if (menu == 0) break;
        if (menu == 1 || menu == 3 || menu == 4) {
            if (count==0) continue;
        }
        if (menu == 1) {
            printf("Name   Kor   Eng   Math   Sum   Avg\n");
            if (s.kor !=-1) readScore(s);
        }
        else if (menu == 2) count += addScore(&s);
        else if (menu == 3) updateScore(&s);
        else if (menu == 4) deleteScore(&s);
    }
    printf("종료됨!\n");
    return 0;
}
