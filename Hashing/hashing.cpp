#include <stdio.h>
int tsize;

int hasht(int key)
{
   int i;
   i = key % tsize;
   return i;
}

//-------LINEAR PROBING-------
int rehashl(int key)
{
   int i;
   i = (key + 1) % tsize;
   return i;
}

//-------QUADRATIC PROBING-------
int rehashq(int key, int j)
{
   int i;
   i = (key + (j * j)) % tsize;
   return i;
}
int main()
{
   int key, arr[20], hash[20], i, n, s, op, j, k;
   printf("Enter the size of the hash table:  ");
   scanf("%d", &tsize);
   printf("\nEnter the number of elements: ");
   scanf("%d", &n);
   for (i = 0; i < tsize; i++)
      hash[i] = -1;
   printf("Enter Elements: ");
   for (i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }
   do
   {
      printf("\n1.Linear Probing\n2.Quadratic Probing \n3.Exit \nEnter your option: ");
      scanf("%d", &op);
      switch (op)
      {
      case 1:
         for (i = 0; i < tsize; i++)
            hash[i] = -1;
         for (k = 0; k < n; k++)
         {
            key = arr[k];
            i = hasht(key);
            while (hash[i] != -1)
            {
               i = rehashl(i);
            }
            hash[i] = key;
         }
         printf("\nThe elements in the array are: ");
         for (i = 0; i < tsize; i++)
         {
            printf("\n  Element at position %d: %d", i, hash[i]);
         }
         break;

      case 2:
         for (i = 0; i < tsize; i++)
            hash[i] = -1;

         for (k = 0; k < n; k++)
         {
            j = 1;
            key = arr[k];
            i = hasht(key);
            while (hash[i] != -1)
            {
               i = rehashq(i, j);
               j++;
            }
            hash[i] = key;
         }
         printf("\nThe elements in the array are: ");
         for (i = 0; i < tsize; i++)
         {
            printf("\n Element at position %d: %d", i, hash[i]);
         }
         break;
      }
   } while (op != 3);
}
/*
Enter the size of the hash table:  10

Enter the number of elements: 5
Enter Elements: 
11
21
71
44
94

1.Linear Probing    
2.Quadratic Probing 
3.Exit 
Enter your option: 1

The elements in the array are: 
  Element at position 0: -1    
  Element at position 1: 11    
  Element at position 2: 21    
  Element at position 3: 71    
  Element at position 4: 44
  Element at position 5: 94
  Element at position 6: -1
  Element at position 7: -1
  Element at position 8: -1
  Element at position 9: -1
1.Linear Probing
2.Quadratic Probing
3.Exit
Enter your option: 2

The elements in the array are:
 Element at position 0: -1
 Element at position 1: 11
 Element at position 2: 21
 Element at position 3: -1
 Element at position 4: 44
 Element at position 5: 94
 Element at position 6: 71
 Element at position 7: -1
 Element at position 8: -1
 Element at position 9: -1
1.Linear Probing
2.Quadratic Probing
3.Exit
Enter your option: 3
*/