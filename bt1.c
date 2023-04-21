#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arrrandom(int* mang[] , int a )
{
    srand((int) time(0));
   for(int i = 0 ; i < a ; i++)
   {
       mang[i] = rand()%10;
   }
}

void sapxep( int* mang[],int a)
{
        for(int i = 0 ; i < a ; i++)
    {
        for(int j=i+1; j < a; j++)
        {
            if( mang[i] >= mang[j])
            {
                int  mt = mang[i];
                mang[i] = mang[j];
                mang[j] = mt;
            }
            
        }   
    }
}
void lietke(int* mang[], int a)
{
   
}


int main()
{
    int a;
    printf(" Nhap so phan tu cua mang: ");
    scanf("%d", &a);
    int mang[100];
    arrrandom(mang , a);
    printf(" \n Ta co mang tao ngau nhien");
    for(int i=0;i<a ;i++)
		{
			printf(" %d",mang[i]);
		}
    sapxep(mang,a);
    printf(" \n Ta co mang sau khi sap xep: ");
    for(int i=0;i<a ;i++)
		{
			printf("%d ",mang[i]);
		}
     int dem[100]={0};
    for(int i = 0 ; i < a ; i++)
    {
        dem[mang[i]]++;
    }
    for(int i = 0; i < a ; i++)
    {
        if(dem[mang[i]] !=0)
        {
            printf("\nso %d xuat hien %d lan ", mang[i], dem[mang[i]]);
            dem[mang[i]]=0;
        }
    }
  return 0;
}