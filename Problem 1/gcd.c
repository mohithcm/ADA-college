#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gcd1(int a,int b){
    int r,count=0;
    while(r!=0){
        count++;
        r=a%b;
        a=b;
        b=r;
    }
    return count;
}

int gcd2(int a,int b){
    int count=0;
    while(a!=b){
        if(a>b)
          a=a-b;
        else
         b=b-a;
        count++;
    }
    return count;
}

int gcd3(int a,int b){
    int r,count=0,t1,t2;
    if(a<b)
      r=a;
    else
      r=b;
    while(r!=1){
        count++;
        t1=a%r;
        if(t1==0){
          t2=b%r;
          if(t2==0)
            return count;
        }
        r=r-1;
    }
    return count;
}

void main(){
    FILE *fp1;
    int a,b,g;
    srand(time(0));
    system("rm mod.txt;    rm sub.txt;   rm cosint.txt");
    printf("Modulo\t Subtraction\t Consecutive integer\n");
    for(int i=0;i<10;i++){
        a=rand()%100;
        b=rand()%100;
        fp1=fopen("mod.txt","a");
        fprintf(fp1,"%d\t",(i+1));
        g=gcd1(a,b);
        fprintf(fp1,"%d\n",g);
        fclose(fp1);
        fp1=fopen("sub.txt","a");
        fprintf(fp1,"%d\t",(i+1));
        g=gcd2(a,b);
        fprintf(fp1,"%d\n",g);
        fclose(fp1);
        fp1=fopen("cosint.txt","a");
        fprintf(fp1,"%d\t",(i+1));
        g=gcd3(a,b);
        fprintf(fp1,"%d\n",g);
        fclose(fp1);
    }
}
