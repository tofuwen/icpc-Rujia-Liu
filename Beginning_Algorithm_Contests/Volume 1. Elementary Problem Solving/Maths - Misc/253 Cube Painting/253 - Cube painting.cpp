/*Cube painting 

We have a machine for painting cubes. It is supplied with three different colors: blue, red and green. Each face of the cube gets one of these colors. The cube's faces are numbered as in Figure 1.



Figure 1.

Since a cube has 6 faces, our machine can paint a face-numbered cube in   different ways. When ignoring the face-numbers, the number of different paintings is much less, because a cube can be rotated. See example below. We denote a painted cube by a string of 6 characters, where each character is a b, r, or g. The   character (  ) from the left gives the color of face i. For example, Figure 2 is a picture of rbgggr and Figure 3 corresponds to rggbgr. Notice that both cubes are painted in the same way: by rotating it around the vertical axis by 90  , the one changes into the other.

  

Input

The input of your program is a textfile that ends with the standard end-of-file marker. Each line is a string of 12 characters. The first 6 characters of this string are the representation of a painted cube, the remaining 6 characters give you the representation of another cube. Your program determines whether these two cubes are painted in the same way, that is, whether by any combination of rotations one can be turned into the other. (Reflections are not allowed.)

Output

The output is a file of boolean. For each line of input, output contains TRUE if the second half can be obtained from the first half by rotation as describes above, FALSE otherwise.

Sample Input

rbgggrrggbgr
rrrbbbrrbbbr
rbgrbgrrrrrg
Sample Output

TRUE
FALSE
FALSE
*/


#include<stdio.h>
//#include<iostream>
//using namespace std;

char *front,*back,*left,*right,*up,*down;

void turnright();
void turnfront();
void rotate();
int equal(char b[]);

int main()
{
	char a[10],b[10],s[15];
	int i,j,z;
	while(gets(s))
	{
		int ok=0;
		for(i=0;i<6;i++)
		{
			a[i]=s[i];
			b[i]=s[i+6];
		}
		a[6]='\0';
		b[6]='\0';
		up=a;
		down=a+5;
		front=a+1;
		back=a+4;
		left=a+2;
		right=a+3;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				for(z=0;z<4;z++)
				{
					if(equal(b))
					{
						printf("TRUE\n");
						ok=1;
						break;
					}
					turnright();
				}
				if(ok) break;
				rotate();
			}
			if(ok) break;
			turnfront();
		}
		if(!ok)
			printf("FALSE\n");
	}
	return 0;
}



void turnright()
{
	char *t;
	t=right;
	right=up;
	up=left;
	left=down;
	down=t;
}

void turnfront()
{
	char *t;
	t=front;
	front=up;
	up=back;
	back=down;
	down=t;
}

void rotate()
{
	char *t;
	t=front;
	front=right;
	right=back;
	back=left;
	left=t;
}

int equal(char b[])
{
	if(*up==b[0]&&*down==b[5]&&*front==b[1]&&*back==b[4]&&*left==b[2]&&*right==b[3])
		return 1;
	return 0;
}