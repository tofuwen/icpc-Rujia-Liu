/*
Automatic Poetry
Input: standard input
Output: standard output
Time Limit: 2 seconds
Memory Limit: 32 MB
 
¡°Oh God¡±, Lara Croft exclaims, ¡°it¡¯s one of these dumb riddles again!¡±
 
In Tomb Raider XIV, Lara is, as ever, gunning her way through ancient Egyptian pyramids, prehistoric caves and medival hallways. Now she is standing in front of some important Germanic looking doorway and has to solve a linguistic riddle to pass. As usual, the riddle is not very intellectually challenging.
 
This time, the riddle involves poems containing a ¡°Schuttelreim¡±. An example of a Schuttelreim is the following short poem:
 
Ein Kind halt seinen Schnabel nur,
wenn es hangt an der Nabelschnur.        
 
/*German contestants please forgive me. I had to modify something as they were not appearing correctly in plain text format*/
 /*
A Schuttelreim seems to be a typical German invention. The funny thing about this strange type of poetry is that if somebody gives you the first line and the beginning of the second one, you can complete the poem yourself. Well, even a computer can do that, and your task is to write a program which completes them automatically. This will help Lara concentrate on the ¡°action¡± part of Tomb Raider and not on the ¡°intellectual¡± part.
Input

The input will begin with a line containing a single number n. After this line follow n pairs of lines containing Schuttelreims. The first line of each pair will be of the form
s1<s2>s3<s4>s5
 
where the si are possibly empty, strings of lowercase characters or blanks. The second line will be a string of lowercase characters or blanks ending with three dots ¡°...¡±. Lines will we at most 100 characters long.
Output

For each pair of Schuttelreim lines l1 and l2 you are to output two lines c1 and c2 in the following way: c1 is the same as l1 only that the bracket marks ¡°<¡± and ¡°>¡± are removed. Line c2 is the same as l2 , except that instead of the three dots the string s4s3s2s5 should appear.

Sample Input

3
ein kind haelt seinen <schn>abel <n>ur
wenn es haengt an der ...
weil wir zu spaet zur <>oma <k>amen
verpassten wir das ...
<d>u <b>ist
...
Sample Output

ein kind haelt seinen schnabel nur
wenn es haengt an der nabel schnur
weil wir zu spaet zur oma kamen
verpassten wir das koma amen
du bist
bu dist
*/


#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	char a[110],b[110],s1[110],s2[110],s3[110],s4[110];
	int n;
	cin>>n;
	getchar();
	int i,j,p,q,m;
	for(i=0;i<n;i++)
	{
		gets(a);
		gets(b);
		for(j=0;j<strlen(a);j++)
		{
			if(a[j]!='<'&&a[j]!='>')
				putchar(a[j]);
		}
		putchar('\n');
		for(j=0;j<strlen(a)&&a[j]!='<';j++);
		for(p=0;p<strlen(a)&&a[p]!='>';p++);
		for(q=j+1;q<p;q++)
			s1[q-j-1]=a[q];
		s1[p-j-1]='\0';

	//	puts(s1);

		for(m=j+1;m<strlen(a)&&a[m]!='<';m++);
		for(q=p+1;q<m;q++)
			s2[q-p-1]=a[q];
		s2[m-p-1]='\0';

		//puts(s2);

		for(j=p+1;j<strlen(a)&&a[j]!='>';j++);
		for(q=m+1;q<j;q++)
			s3[q-m-1]=a[q];
		s3[j-m-1]='\0';
		for(q=j+1;q<strlen(a);q++)
			s4[q-j-1]=a[q];
		s4[strlen(a)-j-1]='\0';
		for(j=0;j<strlen(b);j++)
		{
			if(b[j]=='.')
				break;
			putchar(b[j]);
		}
		printf("%s",s3);
		printf("%s",s2);
		printf("%s",s1);
		printf("%s\n",s4);
	}
	return 0;
}