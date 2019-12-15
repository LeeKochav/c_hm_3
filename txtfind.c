#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30
#define DIFF 1
#define DATA 3


char text[LINE][LINE];

void getLine(char s[])
{
    char c;
    int size=0;
    while(scanf("%c",&c)==1&&size<LINE)
    {
       if(c=='\n')
       {
           return;
       }
       s[size++]=c;
    }
    return;
}

void getWord(char w[])
{
    char c;
    int size=0;
    while(scanf("%c",&c)==1&&size<WORD)
    {
        if((c=='\n')||(c=='\t')||(c==' '))
        {
            return;
        }
        w[size++]=c;
    }
    return;

}

int substring(char *str1,char *str2)
{
    int str1_len=strlen(str1);
    int str2_len=strlen(str2);
    int ans;
    for(int i=0; i<str1_len; i++)
    {
        if(str1[i]==str2[0])
        {
            ans=1;
            for(int j=1; j<str2_len&&ans; j++)
            {
                if(str1[i+j]!=str2[j])
                {
                    ans=0;
                }
            }
            if(ans)
            {
            return ans;
            }
        }
    }
    return 0;
}
int similar(char *s, char* t, int n)
{
    int diff=0;
    int s_len=strlen(s);
    int t_len=strlen(t);
    int j=0;
    for(int i=0; i<s_len; i++)
    {
        if(s[i]==t[j])
        {
            j++;
        }
        else
        {
         diff++;   
        }
        
    }
    if(diff==0&&t_len==s_len)
    {
        return 1;
    }
    else if(diff==n&&t_len==s_len-diff)
    {
        return 1;
    }
    
    return 0;
}
void print_lines(char*str)
{
    for(int i=DATA; i<LINE; i++)
    {
       getLine(text[i]);
        if(substring(text[i],str))
        {
            printf("%s\n",text[i]);
        }
            
    }
}
void print_similar_words(char* str)
{
    for(int i=DATA; i<LINE; i++)
    {
       getWord(text[i]);
       if(similar(text[i],str,DIFF))
        {
            printf("%s\n",text[i]);
        }
            
    }
}
int main()
{   
   for(int i=0; i<DATA; i++)
   {
       getWord(text[i]); 
   }
   if(text[1][0]=='a')
   {
       print_lines(text[0]);
   }
   else if(text[1][0]=='b')
   {
        print_similar_words(text[0]);
   }
    return 0;
}