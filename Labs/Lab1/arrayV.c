#include <stdio.h>

int main() {
  int a[3], b[3], c[3];
  int total[5];
  double ave[5];

  for (int x= 0; x<5; x++) {
    printf("\n%d번 학생 : ", x+1);
    scanf("%d %d %d", &a[x], &b[x], &c[x]);
  }

  for (int i=0; i<5 ; i++) {
    total[i]=a[i]+b[i]+c[i];
    ave[i]=total[i]/3.0;
  }

  for (int i=0; i<5; i++) {
    printf("\n%d번 학생의 총점은 %d, 평균은 %.1f", i+1, total[i], ave[i]);
    if (ave[i]>=90.0) printf("(등급 A)\n");
    else if (ave[i]>=80.0 && ave[i]<90.0) printf("(등급 B)\n");
    else if (ave[i]>=70.0 && ave[i]<80.0) printf("(등급 C)\n");
    else if (ave[i]>=60.0 && ave[i]<70.0) printf("(등급 D)\n");
    else if (ave[i]>=50.0 && ave[i]<60.0) printf("(등급 E)\n");
    else printf("(등급 F)\n");
  }

  return 0;
}