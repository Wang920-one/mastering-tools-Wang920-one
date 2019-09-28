#include <stdio.h>
#define MAX 20
void main()
{
 FILE *fa,*fb;
 char stra[MAX],strb[MAX],c;
 printf("请输入源文件名:");
 scanf("%s",stra);
 printf("请输入目标文件名:");
 scanf("%s",strb);
 fa=fopen(stra,"r");
 fb=fopen(strb,"w");
 if(fa)
 {
 if(fb)
 {
 while((c=getc(fa))!=EOF)
 putc(c,fb);
 fclose(fa);
 fclose(fb);
 }
 else
 printf("can't open %s",strb);
 }
 else
 printf("can't open %s",stra);
}
