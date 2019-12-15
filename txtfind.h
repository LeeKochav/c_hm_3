#ifndef _TXTFIND_H_
#define _TXTFIND_H_

void getLine(char s[]);
void getWord(char w[]);
int substring(char *str1,char *str2);
int similar(char *s, char* t, int n);
void print_lines(char*str);
void print_similar_words(char* str);

#endif