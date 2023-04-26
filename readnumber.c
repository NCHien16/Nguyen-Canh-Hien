#include <stdio.h>
 
char s[50] = "";
 
char *chuso(unsigned int n)
{
  char kyso[10][5]= {"", "mot", "hai", "ba", "bon", "nam", "sau",
                    "bay", "tam", "chin"};
  int donvi, chuc, tram;
 
  s[0] = 0;
  donvi = n % 10;
  n /= 10;
  chuc = n % 10;
  tram = n / 10;
  if (tram > 0)
  {
    strcat(s, kyso[tram]);
    strcat(s, " tram ");
  }
  if (chuc > 0)
  {
    if (chuc == 1)
       strcat(s, "muoi ");
    else
    {
       strcat(s, kyso[chuc]);
       strcat(s, " muoi ");
    }
  }
  if (donvi > 0)
  {
     if (chuc == 0 && tram != 0)
       strcat(s, "le ");
     if (donvi == 1)
       strcat(s, "mot");
     else if (donvi == 5 && (chuc != 0 || tram != 0))
       strcat(s, "lam");
     else if (donvi == 5 && (chuc = 0 || tram != 0))
       strcat(s, "nam");
     else
       strcat(s, kyso[donvi]);
  }
  return s;
}
 
void main()
{
  unsigned long n;
  unsigned ngan, trieu, ty, donvi;
  char chuoi[200];
 
  printf("\nNhap mot so  : ");
  scanf("%ld", &n);
  printf("So %ld doc bang chu la :\n", n);
  if (n == 0)
    printf("khong");
  else
  {
     donvi = n % 1000;
     n /= 1000;
     ngan = n % 1000;
     n /= 1000;
     trieu = n % 1000;
     ty = n / 1000;
     chuoi[0] = 0;
     if (ty > 0)
       printf("%s ty ", chuso(ty));
     if (trieu > 0)
       printf("%s trieu ", chuso(trieu));
     if (ngan > 0)
       printf("%s ngan ", chuso(ngan));
     if (donvi > 0)
       printf("%s", chuso(donvi));
  }
 
  getch();
}