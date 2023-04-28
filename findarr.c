#include <stdio.h>

void sapxep( int arr[], int n)
{
     for(int i = 0 ; i < n-1; i++ )
     {
        for (int j = 1 ; j < n-1; j++)
        {
            if( arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
     }
}

int timmang( int arr[],int n , int x)
{
  int l = 0 , r = n-1;
  while (l <= r)
  {
    int mid = ( l + r ) /2;
    if( arr[ mid] == x)
    {
        return 1 ;
    }
    else if (arr[mid] < x)
    {
        l = mid +1;
    }
    else
    {
        r = mid -1;
    }
    return 0;
  }
  
}
int main()
{   
    int arr[] = { 5, 3, 9, 13 ,6, 7, 1 , 8 , 24};
    int n = sizeof(arr) / sizeof(arr[0]);
     sapxep(arr,n);
     int x ;
     while (1)
     {
        printf("\nNhap so can tim");
        scanf("%d", &x);
        if ( x == -1 ) break;
  
        if( timmang(arr, n,x))
        {
            printf("\n Da tim thay %d", &x);
        }
        else
        {
            printf("khong co so can tim");
        }
     }
     return 0;

}