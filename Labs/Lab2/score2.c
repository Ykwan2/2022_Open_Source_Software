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
    printf("%9s %5d %5d %6d %5d %5.1f\n", s.name, s.kor, s.eng, s.math, s.total, s.ave);
}

void listScore(Score *s, int count) {
    printf("\n No  Name   Kor   Eng   Math   Sum   Avg\n================================\n");
    for (int i=0; i<count; i++) {
        if (s[i].kor==-1) continue;
        printf("%2d", i+1);
        readScore(s[i]);
    }
    printf("\n");

}

int selectDataNo (Score *s, int count) {
    int no;
    listScore(s, count);
    printf("번호는 (취소 : 0)? ");
    scanf("%d", &no);
    return no;
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
    printf("=> 추가됨!\n");
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
    printf("=> 수정됨!\n");
    s->total=s->kor+s->eng+s->math;
    s->ave=s->total/3.0;
    return 1;
}

int deleteScore(Score *s) {
    s->kor=-1;
    s->eng=-1;
    s->math=-1;
    s->total=-1;
    s->ave=-1;
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
    Score sp[20];
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
                listScore(sp, index);
            }
        }
        else if (menu == 2) {
            count += addScore(&sp[index++]);
        }
        else if (menu == 3) {
            int no=selectDataNo(sp, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateScore(&sp[no-1]);
        }
        else if (menu == 4) {
            int no=selectDataNo(sp, index);
            if (no==0) {
                printf("=> 취소됨!\n");
                continue;
            }
            int deleteok;
            printf("정말로 삭제하시겠습니까? (삭제 : 1)");
            scanf("%d", &deleteok);
            if (deleteok == 1) {
                if (deleteScore(&sp[no-1])) {
                    count--;
                }
            }
        }
    }
    printf("종료됨!\n");
    return 0;
}
