#include <stdio.h>

int main() {
  int a1, a2, a3, b1, b2, b3, c1, c2, c3, d1, d2, d3, e1, e2, e3;
  int total1, total2, total3, total4, total5;
  double ave1, ave2, ave3, ave4, ave5;

  printf("1번 학생 : ");
  scanf("%d %d %d", &a1, &a2, &a3);
  printf("\n2번 학생 : ");
  scanf("%d %d %d", &b1, &b2, &b3);
  printf("\n3번 학생 : ");
  scanf("%d %d %d", &c1, &c2, &c3);
  printf("\n4번 학생 : ");
  scanf("%d %d %d", &d1, &d2, &d3);
  printf("\n5번 학생 : ");
  scanf("%d %d %d", &e1, &e2, &e3);

  total1=a1+a2+a3;
  total2=b1+b2+b3;
  total3=c1+c2+c3;
  total4=d1+d2+d3;
  total5=e1+e2+e3;
  ave1=total1/3.0;
  ave2=total2/3.0;
  ave3=total3/3.0;
  ave4=total4/3.0;
  ave5=total5/3.0;

  printf("\n1번 학생의 총점은 %d, 평균은 %.1f", total1, ave1);
  if (ave1>=90.0) printf("(등급 A)\n");
  if (ave1>=80.0 && ave1<90.0) printf("(등급 B)\n");
  if (ave1>=70.0 && ave1<80.0) printf("(등급 C)\n");
  if (ave1>=60.0 && ave1<70.0) printf("(등급 D)\n");
  if (ave1>=50.0 && ave1<60.0) printf("(등급 E)\n");
  if (ave1<50.0) printf("(등급 F)\n");
  printf("\n2번 학생의 총점은 %d, 평균은 %.1f", total2, ave2);
  if (ave2>=90.0) printf("(등급 A)\n");
  if (ave2>=80.0 && ave2<90.0) printf("(등급 B)\n");
  if (ave2>=70.0 && ave2<80.0) printf("(등급 C)\n");
  if (ave2>=60.0 && ave2<70.0) printf("(등급 D)\n");
  if (ave2>=50.0 && ave2<60.0) printf("(등급 E)\n");
  if (ave2<50.0) printf("(등급 F)\n");
  printf("\n3번 학생의 총점은 %d, 평균은 %.1f", total3, ave3);
  if (ave3>=90.0) printf("(등급 A)\n");
  if (ave3>=80.0 && ave3<90.0) printf("(등급 B)\n");
  if (ave3>=70.0 && ave3<80.0) printf("(등급 C)\n");
  if (ave3>=60.0 && ave3<70.0) printf("(등급 D)\n");
  if (ave3>=50.0 && ave3<60.0) printf("(등급 E)\n");
  if (ave3<50.0) printf("(등급 F)\n");
  printf("\n4번 학생의 총점은 %d, 평균은 %.1f", total4, ave4);
  if (ave4>=90.0) printf("(등급 A)\n");
  if (ave4>=80.0 && ave4<90.0) printf("(등급 B)\n");
  if (ave4>=70.0 && ave4<80.0) printf("(등급 C)\n");
  if (ave4>=60.0 && ave4<70.0) printf("(등급 D)\n");
  if (ave4>=50.0 && ave4<60.0) printf("(등급 E)\n");
  if (ave4<50.0) printf("(등급 F)\n");
  printf("\n5번 학생의 총점은 %d, 평균은 %.1f", total5, ave5);
  if (ave5>=90.0) printf("(등급 A)\n");
  if (ave5>=80.0 && ave5<90.0) printf("(등급 B)\n");
  if (ave5>=70.0 && ave5<80.0) printf("(등급 C)\n");
  if (ave5>=60.0 && ave5<70.0) printf("(등급 D)\n");
  if (ave5>=50.0 && ave5<60.0) printf("(등급 E)\n");
  if (ave5<50.0) printf("(등급 F)\n");

  return 0;
}