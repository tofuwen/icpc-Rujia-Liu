/*
ClockHands 
The medieval interest in mechanical contrivances is well illustrated by the development of the mechanical clock, the oldest of which is driven by weights and controlled by a verge, an oscillating arm engaging with a gear wheel. It dates back to 1386.

Clocks driven by springs had appeared by the mid-15th century, making it possible to con- struct more compact mechanisms and preparing the way for the portable clock.

English spring-driven pendulum clocks were first commonly kept on a small wall bracket and later on a shelf. Many bracket clocks contained a drawer to hold the winding key. The earliest bracket clocks, made for a period after 1660, were of architectural design, with pillars at the sides and a pediment on top.

In 17th- and 18th-century France, the table clock became an object of monumental design, the best examples of which are minor works of sculpture.

The longcase clocks (also called grandfather clocks) are tall pendulum clock enclosed in a wooden case that stands upon the floor and is typically from 6 to 7.5 feet (1.8 to 2.3 m) in height. Later, the name ``grandfather clock'' became popular after the popular song "My Grandfather's Clock," written in 1876 by Henry Clay Work.


One of the first atomic clocks was an ammonia-controlled clock. It was built in 1949 at the National Bureau of Standards, Washington, D.C.; in this clock the frequency did not vary by more than one part in 108

Nuclear clocks are built using two clocks. The aggregate of atoms that emit the gamma radiation of precise frequency may be called the emitter clock; the group of atoms that absorb this radiation is the absorber clock. One pair of these nuclear clocks can detect energy changes of one part in 1014 , being about 1,000 times more sensitive than the best atomic clock.

The cesium clock is the most accurate type of clock yet developed. This device makes use of transitions between the spin states of the cesium nucleus and produces a frequency which is so regular that it has been adopted for establishing the time standard.


The history of clocks is fascinating, but unrelated to this problem. In this problem, you are asked to find the angle between the minute hand and the hour hand on a regular analog clock. Assume that the second hand, if there were one, would be pointing straight up at the 12. Give all angles as the smallest positive angles. For example 9:00 is 90 degrees; not -90 or 270 degrees.

Input 

The input is a list of times in the form H:M, each on their own line, with 1<=H<=12 and 00<=M<=59 . The input is terminated with the time 0:00. Note that H may be represented with 1 or 2 digits (for 1-9 or 10-12, respectively); M is always represented with 2 digits (The input times are what you typically see on a digital clock).
Output 

The output displays the smallest positive angle in degrees between the hands for each time. The answer should between 0 degrees and 180 degrees for all input times. Display each angle on a line by itself in the same order as the input. The output should be rounded to the nearest 1/1000, i.e., three places after the decimal point should be printed.
Sample Input 

12:00
9:00
8:10
0:00
Sample Output 

0.000
90.000
175.000
*/

#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	double hour,minute;
	double angle;
	char c[10];
	while(gets(c))
	{
		if(c[0]=='0')
			break;
		sscanf(c,"%lf:%lf",&hour,&minute);
		if((12-hour)<0.1)
			hour=0;
		hour=30*hour+minute/2;
		minute=6*minute;
		if(hour>minute)
			angle=hour-minute;
		else
			angle=minute-hour;
		if(angle>180)
			angle=360-angle;
		printf("%.3lf\n",angle);
	}
	return 0;
}