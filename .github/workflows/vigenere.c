 #include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_arg(string a);
int shift(char c);
int main (int argc,string argv[])
{
   if( (argc != 2) || ((check_arg(argv[1]))==false))
    {
   printf("Usage:./vigenere keyword\n");
        return 1;
    }
    else
    {
    
   string plain=get_string("plaintext:");
   printf("ciphertext:");
   int key;
   int lengthKey=strlen(argv[1]);
   for(int i=0,j=0;i<strlen(plain);i++)
    {
        key=shift(argv[1][j%lengthKey]);
        if(isalpha(plain[i]))
        {
         if(islower(plain[i])) 
         {
             printf("%c",(((plain[i] + key) - 97) % 26) + 97);
         }
         else 
         {
             printf("%c",(((plain[i] + key) - 65) % 26)+ 65);
         }
          j++;
        }
      else
      {
          printf("%c",plain[i]);
      }
    }
    printf("\n");
    }
    
    
    return 0;
    
}
bool check_arg(string a)
{
   
      
        
   for(int i=0;i<strlen(a);i++)
    {
        if(!isalpha(a[i]))
        {
            return false;
            break;
        }
      
    }
       return true;     
}
int shift(char c)
{
    if(isupper(c))
    {
        return c-'A';
    }
    else if(islower(c))
    {
        return c-'a';
    }
    return 0;
}
