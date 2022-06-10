#include <stdio.h>
#include <stdlib.h>

struct student {
  int a, b, c;
  int total;
  double ave;
  char d;
} p[5];

void averageCal(struct student* p[]) {
  for (int i=0; i<5 ; i++) {
   p[i]->ave=p[i]->total/3.0;
  } 
}

void totalCal(struct student* p[]) {
  for (int i=0; i<5 ; i++) {
    p[i]->total=p[i]->a+p[i]->b+p[i]->c;
  }
}

void gradeCal(struct student* p[]) {
  for (int i=0; i<5 ; i++) {
    if (p[i]->ave>=90.0) p[i]->d='A';
    else if (p[i]->ave>=80.0 && p[i]->ave<90.0) p[i]->d='B';
    else if (p[i]->ave>=70.0 && p[i]->ave<80.0) p[i]->d='C';
    else if (p[i]->ave>=60.0 && p[i]->ave<70.0) p[i]->d='D';
    else if (p[i]->ave>=50.0 && p[i]->ave<60.0) p[i]->d='E';
    else p[i]->d='F';
  }
}

int main() {
  struct student *p[5];
  for (int i=0; i< sizeof(p) / sizeof(struct student *);i++){
    p[i]=malloc(sizeof(struct student));
  }

  for (int x= 0; x<5; x++) {
    printf("\n%d번 학생 : ", x+1);
    scanf("%d %d %d", &p[x]->a, &p[x]->b, &p[x]->c);
  }

  totalCal(p);
  averageCal(p);
  gradeCal(p);

  for (int i=0; i<5; i++) printf("\n%d번 학생의 총점은 %d, 평균은 %.1f(등급 %c)\n", i+1,p[i]->total,p[i]->ave, p[i]->d);
   
  for (int i = 0; i < sizeof(p) / sizeof(struct student *); i++)   
    {
        free(p[i]); 
    }

  return 0;
}