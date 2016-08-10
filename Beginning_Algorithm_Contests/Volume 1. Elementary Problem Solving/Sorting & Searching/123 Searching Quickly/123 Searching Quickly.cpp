/*
Searching Quickly 

Background

Searching and sorting are part of the theory and practice of computer science. For example, binary search provides a good example of an easy-to-understand algorithm with sub-linear complexity. Quicksort is an efficient   [average case] comparison based sort.

KWIC-indexing is an indexing method that permits efficient ``human search'' of, for example, a list of titles.

The Problem

Given a list of titles and a list of ``words to ignore'', you are to write a program that generates a KWIC (Key Word In Context) index of the titles. In a KWIC-index, a title is listed once for each keyword that occurs in the title. The KWIC-index is alphabetized by keyword.

Any word that is not one of the ``words to ignore'' is a potential keyword.

For example, if words to ignore are ``the, of, and, as, a'' and the list of titles is:

Descent of Man
The Ascent of Man
The Old Man and The Sea
A Portrait of The Artist As a Young Man
A KWIC-index of these titles might be given by:

                      a portrait of the ARTIST as a young man 
                                    the ASCENT of man 
                                        DESCENT of man 
                             descent of MAN 
                          the ascent of MAN 
                                the old MAN and the sea 
    a portrait of the artist as a young MAN 
                                    the OLD man and the sea 
                                      a PORTRAIT of the artist as a young man 
                    the old man and the SEA 
          a portrait of the artist as a YOUNG man

The Input

The input is a sequence of lines, the string :: is used to separate the list of words to ignore from the list of titles. 
Each of the words to ignore appears in lower-case letters on a line by itself and is no more than 10 characters in length. 
Each title appears on a line by itself and may consist of mixed-case (upper and lower) letters. Words in a title are separated by whitespace.
 No title contains more than 15 words.

There will be no more than 50 words to ignore, no more than than 200 titles, and no more than 10,000 characters in the titles and words to ignore combined. 
No characters other than 'a'-'z', 'A'-'Z', and white space will appear in the input.

The Output

The output should be a KWIC-index of the titles, with each title appearing once for each keyword in the title, and with the KWIC-index alphabetized by keyword. If a word appears more than once in a title, each instance is a potential keyword.

The keyword should appear in all upper-case letters. All other words in a title should be in lower-case letters. Titles in the KWIC-index with the same keyword should appear in the same order as they appeared in the input file. In the case where multiple instances of a word are keywords in the same title, the keywords should be capitalized in left-to-right order.

Case (upper or lower) is irrelevant when determining if a word is to be ignored.

The titles in the KWIC-index need NOT be justified or aligned by keyword, all titles may be listed left-justified.

Sample Input

is
the
of
and
as
a
but
::
Descent of Man
The Ascent of Man
The Old Man and The Sea
A Portrait of The Artist As a Young Man
A Man is a Man but Bubblesort IS A DOG


Sample Output

a portrait of the ARTIST as a young man 
the ASCENT of man 
a man is a man but BUBBLESORT is a dog 
DESCENT of man 
a man is a man but bubblesort is a DOG 
descent of MAN 
the ascent of MAN 
the old MAN and the sea 
a portrait of the artist as a young MAN 
a MAN is a man but bubblesort is a dog 
a man is a MAN but bubblesort is a dog 
the OLD man and the sea 
a PORTRAIT of the artist as a young man 
the old man and the SEA 
a portrait of the artist as a YOUNG man
*/

#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<cstring>
#include<stdlib.h>
using namespace std;


char c[3050][10000],s[210][10050],a[55][15];
int number=0;

int strcmp2(const void* a3,const void* b3)
{
	char *p=(char*)a3;
	char *q=(char*)b3;
	for(;!isupper(*p);p++);
	for(;!isupper(*q);q++);
	while(isupper(*p)&&isupper(*q))
	{
		if(*p>*q) return 1;
		if(*q>*p) return -1;
		p++;
		q++;
	}
	if(!isupper(*p)&&isupper(*q))
		return -1;
	if(isupper(*p)&&!isupper(*q))
		return 1;
	return 0;
}

int cmp_string(const void *a1, const void *b1)
{
	return strcmp((char*)a1,(char*)b1);
}

int cmp_upper(const void *a2, const void *b2)
{
	return strcmp2((char*)a2,(char*)b2);
}

void f(char string[],int n);


int main()
{
	int n=0;
	int i;
	while(gets(a[n]))
	{
		if(a[n][0]==':')
			break;
		n++;
	}
	qsort(a,n,sizeof(a[0]),cmp_string);
	int m=0;
	while(gets(s[m]))
	{
	//	if(s[m][0]=='!') break;
		for(i=0;i<strlen(s[m]);i++)
			if(isupper(s[m][i]))
				s[m][i]+=32;
		m++;
	}
	for(i=0;i<m;i++)
		f(s[i],n);
	qsort(c,number,sizeof(c[0]),strcmp2);
	for(i=0;i<number;i++)
		puts(c[i]);
	return 0;
}


void f(char string[],int n)
{
	char t[10010];
	char *p=string-1,*q=string;
	int i;
	while(1)
	{
		int step=0;
		int ok=1;
		q=p+1;
		for(p=p+1;*p!=' '&&*p!='\0';p++);
		for(i=q-string;i<p-string;i++)
			t[step++]=string[i];
		t[step]='\0';
		for(i=0;i<n&&strcmp(t,a[i])>=0;i++)
			if(strcmp(t,a[i])==0)
				ok=0;
		if(ok)
		{
			for(i=0;i<=strlen(string);i++)
			{
				if(i>=q-string&&i<p-string)
					c[number][i]=string[i]-32;
				else
					c[number][i]=string[i];
			}
			number++;
		}
		if(*p=='\0') break;
	}
}