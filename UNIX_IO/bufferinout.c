#include<stdio.h>
int main()

{
int i;
fprintf(stdout,"a");
scanf("%d",&i);
fprintf(stderr,"a has been written\n");
fprintf(stdout,"b");
fprintf(stderr,"b has been written\n");
fprintf(stdout,"\n");
fprintf(stdout,"%d",i);
return 0;


}

