#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
bool check_arg(string a);
int main (int argc,string argv[])
{
    if( (argc != 2) || ((check_arg(argv[1]))==false))
    {
        printf("Usage:./ceaser key\n");
        return 1;
    }
    else
    {
    int key=atoi(argv[1]);
   string plain=get_string("plaintext:");
   printf("ciphertext:");
    for(int i=0;i<strlen(plain);i++)
    {
        if(isalpha(plain[i]))
        {
            if(islower(plain[i]))
            {
             printf("%c",(((plain[i] + key) - 97) % 26) + 97);
            }
            else if(isupper(plain[i]))
            {
            printf("%c",(((plain[i] + key) - 65) % 26) + 65);
            }
        }
        else 
        {
            printf("%c",plain[i]);
        }
       
        
    }
    }
    printf("\n");
    
    return 0;
    
}
bool check_arg(string a)
{
   
      
        
    for(int i=0;i<strlen(a);i++)
    {
        if(!isdigit(a[i]))
        {
            return false;
            break;
        }
      
    }
       return true;     
}
