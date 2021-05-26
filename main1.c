/*
**********  Second task on  Algorithm course                                 ****
**********  Filename >main.cpp                                               ****
**********  IDE > QT Creator 4.13.2||CodeBlocks 20.03 + GCC 10.2.0           ****
**********  Created by > "~ORDA~" , Anton Bondarenko                         ****
**********  Date 27.05.2021                                                  ****
*/

// DONE●   - 
//1-запросить у пользователя 11 чисел и записать их в последовательность П 
//2 -инвертировать последовательность П 
//3 - для каждого элемента последовательности П произвести вычисление по формуле sqrt(fabs(Х)) + 5 * pow(Х, 3) 
//4 -  если результат вычислений превышает 400 проинформировать пользователя.

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdbool.h>
void print_mass(double digit[],const int size)
 {
   for(int i=0;i<size;i++)
     {
       printf("\na[%d] %2.2lf",i,digit[i]);
      }
     printf("\n");  
 }

void invert_mass(double digit[],const int size)
 {
  double tmp=0;
  for(int i=0; i<size/2;i++)
     {
       tmp=digit[i];
       digit[i]=digit[size-1-i];
       digit[size-1-i]=tmp;
      }
 }
 void result_mass(double digit[],const int size)
    {
       for(int i=0;i<size;i++)
        {
         if(sqrt(fabs(digit[i])) + 5 * pow(digit[i], 3)>400 )
            {
             printf("\nWarning! Result for a[%d]>400",i);
            }
        } 
    }
int main()
{

     const int size=11; 
     double digit[11];
     for(int i=0;i<size;i++)
        {
          printf("Please enter your number: ");
          scanf("%lf",&digit[i]);
         }
    print_mass(digit,size);
    invert_mass(digit,size);
    print_mass(digit,size);
    result_mass(digit,size);
    printf("\n");   
         
 
 }
        
