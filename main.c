
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



int** initMass(int** array, const int row, const int col)
 {
 printf("Attempt to init massive\n");
  array=(int**) calloc(sizeof(int*),row );
  for( int i=0 ; i<row ; ++i )
  {
      *(array + i) = (int*) calloc(sizeof(int), col);
  }
 printf("Massive was succesfully initialized\n"); 
return array;
}

void print_Mass(int** mass,int size_n, int size_m)
{
   
    for (int i=0 ; i<size_n ; i++ )
    {
        for( int j = 0 ; j < size_m ; j++ )
        {

          printf("[%d]",mass[i][j]);

        }
    printf("\n");
    }
}

void fill_Mass(int** mass,const int size_n, const int size_m)
 {
   printf("Attempt to fill massive\n");
    for (int i=0 ; i<size_n ; i++ )
    {
        for( int j = 0 ; j < size_m ; j++ )
        {
         *((*(mass+i))+j)=777;

        }
    
    }
 printf("Massive was siccesfully filled with 777 numbers\n");
 }


void sort_Mass(int** mass,const int size_n, const int size_m)

 {
  int tmp1;
   for(int k=0;k<size_n*size_m-1;k++)
  {
   for (int i=0 ; i<=size_n-1 ; i++ )
   {
       for( int j = 0 ; j <=size_m-1 ; j++ )
       {
           int tmp_i=0,tmp_j=0;



           if(j+1>size_m-1&&i<size_n-1)
           {
               tmp_i=i+1;
               tmp_j=0;
               if (mass[i][j]>mass[tmp_i][tmp_j])
               {
                   tmp1=mass[i][j];
                   mass[i][j]=mass[tmp_i][tmp_j];
                   mass[tmp_i][tmp_j]=tmp1;

               }
           }
           else
           {
               if(!(j+1>size_m-1&&i==size_n-1))
                {
                  if (mass[i][j]>mass[i][j+1])
                   {
                    tmp1=mass[i][j];
                    mass[i][j]=mass[i][j+1];
                    mass[i][j+1]=tmp1;
                   }
                }
           }
          
       }

   }
 }

 }


//********************************************************************************************
//******KMP algorithm prefix
//********************************************************************************************
void prefix_function (char *s1, int *pi, size_t n)
{
    for(int i=0;i<=n;i++)
    {
        pi[i]=99;

    }

    pi[0]=0;          // в i-м элементе (его индекс i-1) количество совпавших символов в начале и конце для подстроки длины
                 // p[0]=0 всегда, p[1]=1, если начинается с двух одинаковых

    int i=1;
    int j=0;

    for (int z=0;z<=n;z++)
    {
       if(s1[i]==s1[j])
          {
           pi[i]=j+1;
           i++;
           j++;

          }
        else
          {
           if(j==0)
               {
                 pi[i]=0;
                 i++;
               }
             else
               {
                 j=pi[j-1];
                }
            }
    }


    for(int i=0;i<=n;i++)
    {

        printf(" %d",pi[i]);
    }
}

//********************************************************************************************
//******KMP algorithm search
//********************************************************************************************
bool search_Func(char *s1, char *s2, int *pi, size_t n, size_t m)
   {
    int k=0;
    int l=0;
    //int z=0;
    bool flag=false;
    while(k<=m)
      {
       if (s2[k]==s1[l])
         {
           if(l==n)
           {
               printf("\nfounded at %d position\n",k-l);
               flag=true;
            }
           k++;
           l++;
        
         }
       else
         {
           if (l==0)
              {

               if(k==m&&flag!=true)
               {
                printf("Sorry, have no idea where you put your staff");
               }
               k++;
           }
           else
              {
               l=pi[l-1];
            
           }
          }
    }
     if (flag)
      {
         return true;
      }
    else
       {
         return false;
       }
}



//********************************************************************************************
//******KMP algorithm prefix
//********************************************************************************************

int main()
{

printf("*******************************\n");//cout<<"************************************\n";

printf("dynamical massive\n");//cout<<"dinamical massive\n";
const int row=3;
const int col=3;
int** mass1=initMass(mass1,row,col);


fill_Mass(mass1,row,col);

   
   printf("Filling in massive with actual data  1 9 3 5 7 6 4 3 8 \n");
   mass1[0][0]=1;
   mass1[0][1]=9;
   mass1[0][2]=2;
   mass1[1][0]=5;
   mass1[1][1]=7;
   mass1[1][2]=6;
   mass1[2][0]=4;
   mass1[2][1]=3;
   mass1[2][2]=8;
   
   print_Mass(mass1,row,col);
   sort_Mass(mass1,row,col);
   printf("\n");
   print_Mass(mass1,row,col);

//*******************************************************************
// KMP functions and data
//*******************************************************************

char s1[]="012345";
char s2[]="0123456789012345678901234567890123456789";
int pi[10];  //size of pi massive more then enough
int n=5;    //size of our search-1

//bool flag=false;
int m=37;    // size of full massive-1
//*******************************************************************
// KMP prefix fucntion
//*******************************************************************
printf("\nKMP TASK. This function will print prefix first and after results of search\n");
prefix_function(s1,pi,n);

printf("\n");
//for(int i=0;i<=n;i++)
//   {
//    printf(" %d",pi[i]);
//   }

printf("\n//***************************************************************");
printf("\n// Second part");
printf("\n//***************************************************************");
printf("\n");
if(search_Func(s1,s2,pi,n,m))
   {
     printf("Good job\n");
   }
else
    {
      printf("Do not be sad - next time we will find something \n");
    }   



}

