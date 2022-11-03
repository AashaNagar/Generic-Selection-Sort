#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int myComparator(void *left,void *right)
{
int *i,*j;
i=(int*)left;
j=(int*)right;
return (*i)-(*j);
}
void insertionSort(void *ptr,int cs,int es,int(*p2f)(void*,void*))
{
int y,z;
void *block;
block=(void*)malloc(sizeof(es));
y=1;
while(y<=cs-1)
{
memcpy(block,(const void*)(ptr+(y*es)),es);
z=y-1;
while(z>=0&&p2f(ptr+(z*es),block)>0)
{
memcpy(ptr+((z+1)*es),(const void*)(ptr+(z*es)),es);
z--;
}
memcpy(ptr+(z+1)*es,(const void*)block,es);
y++;
}
free(block);
}
int main()
{
int *x,req,y;
printf("Enter your req:");
scanf("%d",&req);
x=(int*)malloc(sizeof(int)*req);
y=0;
while(y<req)
{
printf("Enter number :");
scanf("%d",&x[y]);
y++;
}
insertionSort(x,req,sizeof(int),myComparator);
y=0;
while(y<req)
{
printf("%d\n",x[y]);
y++;
}
free(x);
return 0;
}

