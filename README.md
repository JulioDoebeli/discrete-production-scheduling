# Introduction

This is a c language program to generate a file in lp solve input format with the description of linear program that solves the problem for the given instance.


## "The Time Use Scaling Problem" aka "Cutting Paper Rolls" aka "Simple discrete production scheduling"

A company rents machines (for remote use) on demand from its customers. The only restriction is that the machines can only be used during the same working day (working hours from 8 am to 5 pm). Possibly more than one of these uses can be rented in the same day for the same machine, if the sum of the times is less than 9 hours of business.

Each customer asks how long, in minutes, he will use a machine. This time must be between 0 and 540 minutes. The company has m machines. Upon receiving a set of orders, the company manager needs to schedule which machine and which day each use will be made.

Consider that the demand (orders) is given by a set of n pairs (ni, ti), where ni is the number of requests of time ti, with 1 ≤ i ≤ n. to meet demand requests.

BONUS: The above problem is analogous to the problem  "Cutting Paper Rolls" from the book "Understanding and Using Linear Programming" by Jiˇrí Matoušek and Bernd Gärtner.

The input and output formats are described below and the standard input and output (stdin and stdout) are be used. The input is made up of a set of integers. Numbers can be separated by 1 or more spaces, tabs or end of line.

### Input
Two numbers, representing m and n, followed by n pairs of numbers representing the order quantities with each time (in minutes), ni and ti.

### Output
A file in lp solve input format with the description of the linear program that solves the problem for the given instance. The input format of lp solve is described in the URL below: http://lpsolve.sourceforge.net/5.5/lp-format.htm

# Compile
To compile type ```make compile``` on terminal. To compile, run tests and log test results type ```make all```, or just ```make```.


# Examples

Example of lp solve input
An example, taken from another problem, can be seen below.

```c
min: 100x31 + 100x32;
x11 + x21 + x31 = 10;
x12 + x22 + x32 = 20;
x11 + x12 <= 5;
x21 + x22 <= 10;
x31 + x32 <= 50;
x21 = 0;
```


## EX1
to run this example type ```make run``` on terminal

### Input 1
```c
3 4
10 200
5 330
10 420
8 500
```

### Output 1
```c
/* Objective function */
MIN: X0 + X1 + X2 + X3 + X4 + X5;

/* Variable bounds (aka min and max value) */
X0 >= 0;
X0 <= 11;
X1 >= 0;
X1 <= 6;
X2 >= 0;
X2 <= 6;
X3 >= 0;
X3 <= 6;
X4 >= 0;
X4 <= 11;
X5 >= 0;
X5 <= 9;

/* Variable Constraints */
1*X0 + 2*X1 + 1*X2 >= 10;
1*X2 + 1*X3 >= 5;
1*X4 >= 10;
1*X5 >= 8;

/* Variable Types */
int X0;
int X1;
int X2;
int X3;
int X4;
int X5;

/* Linear equations system explained 
	eq 0: 1*200
	eq 1: 2*200
	eq 2: 1*200 + 1*330
	eq 3: 1*330
	eq 4: 1*420
	eq 5: 1*500
*/
```

### Solution 1 by pl_solve
|Variables|MILP Feasible|result
|:-------:|:-----------:| :---:
|         |26           |26
|X0       |0            |0
|X1       |3            |3
|X2       |5            |5
|X3       |0            |0
|X4       |10           |10
|X5       |8            |8

## EX2
to run this example type ```make run2``` on terminal

### Input 2
```c
3 5
20 100
10 200
5 330
10 420
8 500
```

### Output 2
```c
/* Objective function */
MIN: X0 + X1 + X2 + X3 + X4 + X5 + X6 + X7 + X8 + X9 + X10 + X11 + X12 + X13 + X14 + X15 + X16 + X17;

/* Variable bounds (aka min and max value) */
X0 >= 0;
X0 <= 21;
X1 >= 0;
X1 <= 11;
X2 >= 0;
X2 <= 8;
X3 >= 0;
X3 <= 6;
X4 >= 0;
X4 <= 5;
X5 >= 0;
X5 <= 8;
X6 >= 0;
X6 <= 11;
X7 >= 0;
X7 <= 6;
X8 >= 0;
X8 <= 11;
X9 >= 0;
X9 <= 6;
X10 >= 0;
X10 <= 6;
X11 >= 0;
X11 <= 11;
X12 >= 0;
X12 <= 11;
X13 >= 0;
X13 <= 6;
X14 >= 0;
X14 <= 6;
X15 >= 0;
X15 <= 6;
X16 >= 0;
X16 <= 11;
X17 >= 0;
X17 <= 9;

/* Variable Constraints */
1*X0 + 2*X1 + 3*X2 + 4*X3 + 5*X4 + 3*X5 + 2*X6 + 2*X7 + 1*X8 + 1*X9 + 1*X10 + 1*X11 >= 20;
1*X5 + 1*X6 + 1*X8 + 2*X9 + 1*X12 + 2*X13 + 1*X14 >= 10;
1*X7 + 1*X10 + 1*X14 + 1*X15 >= 5;
1*X11 + 1*X16 >= 10;
1*X17 >= 8;

/* Variable Types */
int X0;
int X1;
int X2;
int X3;
int X4;
int X5;
int X6;
int X7;
int X8;
int X9;
int X10;
int X11;
int X12;
int X13;
int X14;
int X15;
int X16;
int X17;

/* Linear equations system explained 
	eq 0: 1*100
	eq 1: 2*100
	eq 2: 3*100
	eq 3: 4*100
	eq 4: 5*100
	eq 5: 3*100 + 1*200
	eq 6: 2*100 + 1*200
	eq 7: 2*100 + 1*330
	eq 8: 1*100 + 1*200
	eq 9: 1*100 + 2*200
	eq10: 1*100 + 1*330
	eq11: 1*100 + 1*420
	eq12: 1*200
	eq13: 2*200
	eq14: 1*200 + 1*330
	eq15: 1*330
	eq16: 1*420
	eq17: 1*500
*/
```

### Solution 2 by pl_solve
|Variables|MILP Feasible|MILP Better|result
|---------|-------------|-----------|------
|         |28           |27         |27
|X0       |0|0         |0
|X1       |0|0         |0
|X2       |0|0         |0
|X3       |0|0         |0
|X4       |2|1         |1
|X5       |0|0         |0
|X6       |0|0         |0
|X7       |0|1         |1
|X8       |0|0         |0
|X9       |3|3         |3
|X10      |0|0         |0
|X11      |10|10       |10
|X12      |0|0         |0
|X13      |0|0         |0
|X14      |5|4         |4
|X15      |0|0         |0
|X16      |0|0         |0
|X17      |8|8         |8

## EX3
to run this example type ```make run2``` on terminal

### Input 3
```c
3 6
30 50
20 100
10 200
5 330
10 420
8 500
```

### Output 3
```c
/* Objective function */
MIN: X0 + X1 + X2 + X3 + X4 + X5 + X6 + X7 + X8 + X9 + X10 + X11 + X12 + X13 + X14 + X15 + X16 + X17 + X18 + X19 + X20 + X21 + X22 + X23 + X24 + X25 + X26 + X27 + X28 + X29 + X30 + X31 + X32 + X33 + X34 + X35 + X36 + X37 + X38 + X39 + X40 + X41 + X42 + X43 + X44 + X45 + X46 + X47 + X48 + X49 + X50 + X51 + X52 + X53 + X54 + X55 + X56 + X57 + X58 + X59 + X60 + X61 + X62 + X63 + X64 + X65 + X66 + X67 + X68 + X69;

/* Variable bounds (aka min and max value) */
X0 >= 0;
X0 <= 31;
X1 >= 0;
X1 <= 16;
X2 >= 0;
X2 <= 11;
X3 >= 0;
X3 <= 9;
X4 >= 0;
X4 <= 7;
X5 >= 0;
X5 <= 6;
X6 >= 0;
X6 <= 6;
X7 >= 0;
X7 <= 5;
X8 >= 0;
X8 <= 5;
X9 >= 0;
X9 <= 4;
X10 >= 0;
X10 <= 5;
X11 >= 0;
X11 <= 6;
X12 >= 0;
X12 <= 6;
X13 >= 0;
X13 <= 6;
X14 >= 0;
X14 <= 6;
X15 >= 0;
X15 <= 7;
X16 >= 0;
X16 <= 7;
X17 >= 0;
X17 <= 7;
X18 >= 0;
X18 <= 9;
X19 >= 0;
X19 <= 9;
X20 >= 0;
X20 <= 8;
X21 >= 0;
X21 <= 9;
X22 >= 0;
X22 <= 9;
X23 >= 0;
X23 <= 6;
X24 >= 0;
X24 <= 11;
X25 >= 0;
X25 <= 11;
X26 >= 0;
X26 <= 8;
X27 >= 0;
X27 <= 11;
X28 >= 0;
X28 <= 11;
X29 >= 0;
X29 <= 6;
X30 >= 0;
X30 <= 16;
X31 >= 0;
X31 <= 11;
X32 >= 0;
X32 <= 8;
X33 >= 0;
X33 <= 6;
X34 >= 0;
X34 <= 11;
X35 >= 0;
X35 <= 11;
X36 >= 0;
X36 <= 6;
X37 >= 0;
X37 <= 11;
X38 >= 0;
X38 <= 6;
X39 >= 0;
X39 <= 6;
X40 >= 0;
X40 <= 11;
X41 >= 0;
X41 <= 21;
X42 >= 0;
X42 <= 11;
X43 >= 0;
X43 <= 8;
X44 >= 0;
X44 <= 6;
X45 >= 0;
X45 <= 11;
X46 >= 0;
X46 <= 11;
X47 >= 0;
X47 <= 6;
X48 >= 0;
X48 <= 11;
X49 >= 0;
X49 <= 6;
X50 >= 0;
X50 <= 6;
X51 >= 0;
X51 <= 11;
X52 >= 0;
X52 <= 21;
X53 >= 0;
X53 <= 11;
X54 >= 0;
X54 <= 8;
X55 >= 0;
X55 <= 6;
X56 >= 0;
X56 <= 5;
X57 >= 0;
X57 <= 8;
X58 >= 0;
X58 <= 11;
X59 >= 0;
X59 <= 6;
X60 >= 0;
X60 <= 11;
X61 >= 0;
X61 <= 6;
X62 >= 0;
X62 <= 6;
X63 >= 0;
X63 <= 11;
X64 >= 0;
X64 <= 11;
X65 >= 0;
X65 <= 6;
X66 >= 0;
X66 <= 6;
X67 >= 0;
X67 <= 6;
X68 >= 0;
X68 <= 11;
X69 >= 0;
X69 <= 9;

/* Variable Constraints */
1*X0 + 2*X1 + 3*X2 + 4*X3 + 5*X4 + 6*X5 + 7*X6 + 8*X7 + 9*X8 + 10*X9 + 8*X10 + 7*X11 + 6*X12 + 6*X13 + 6*X14 + 5*X15 + 5*X16 + 5*X17 + 4*X18 + 4*X19 + 4*X20 + 4*X21 + 4*X22 + 4*X23 + 3*X24 + 3*X25 + 3*X26 + 3*X27 + 3*X28 + 3*X29 + 2*X30 + 2*X31 + 2*X32 + 2*X33 + 2*X34 + 2*X35 + 2*X36 + 2*X37 + 2*X38 + 2*X39 + 2*X40 + 1*X41 + 1*X42 + 1*X43 + 1*X44 + 1*X45 + 1*X46 + 1*X47 + 1*X48 + 1*X49 + 1*X50 + 1*X51 >= 30;
1*X10 + 1*X11 + 1*X12 + 2*X13 + 1*X15 + 2*X16 + 1*X18 + 2*X19 + 3*X20 + 1*X21 + 1*X24 + 2*X25 + 3*X26 + 1*X27 + 1*X30 + 2*X31 + 3*X32 + 4*X33 + 2*X34 + 1*X35 + 1*X36 + 1*X41 + 2*X42 + 3*X43 + 4*X44 + 2*X45 + 1*X46 + 1*X47 + 1*X52 + 2*X53 + 3*X54 + 4*X55 + 5*X56 + 3*X57 + 2*X58 + 2*X59 + 1*X60 + 1*X61 + 1*X62 + 1*X63 >= 20;
1*X14 + 1*X17 + 1*X21 + 1*X22 + 1*X27 + 1*X28 + 1*X34 + 1*X35 + 1*X37 + 2*X38 + 1*X45 + 1*X46 + 1*X48 + 2*X49 + 1*X57 + 1*X58 + 1*X60 + 2*X61 + 1*X64 + 2*X65 + 1*X66 >= 10;
1*X23 + 1*X29 + 1*X36 + 1*X39 + 1*X47 + 1*X50 + 1*X59 + 1*X62 + 1*X66 + 1*X67 >= 5;
1*X40 + 1*X51 + 1*X63 + 1*X68 >= 10;
1*X69 >= 8;

/* Variable Types */
int X0;
int X1;
int X2;
int X3;
int X4;
int X5;
int X6;
int X7;
int X8;
int X9;
int X10;
int X11;
int X12;
int X13;
int X14;
int X15;
int X16;
int X17;
int X18;
int X19;
int X20;
int X21;
int X22;
int X23;
int X24;
int X25;
int X26;
int X27;
int X28;
int X29;
int X30;
int X31;
int X32;
int X33;
int X34;
int X35;
int X36;
int X37;
int X38;
int X39;
int X40;
int X41;
int X42;
int X43;
int X44;
int X45;
int X46;
int X47;
int X48;
int X49;
int X50;
int X51;
int X52;
int X53;
int X54;
int X55;
int X56;
int X57;
int X58;
int X59;
int X60;
int X61;
int X62;
int X63;
int X64;
int X65;
int X66;
int X67;
int X68;
int X69;

/* Linear equations system explained 
	eq 0: 1*50
	eq 1: 2*50
	eq 2: 3*50
	eq 3: 4*50
	eq 4: 5*50
	eq 5: 6*50
	eq 6: 7*50
	eq 7: 8*50
	eq 8: 9*50
	eq 9: 10*50
	eq10: 8*50 + 1*100
	eq11: 7*50 + 1*100
	eq12: 6*50 + 1*100
	eq13: 6*50 + 2*100
	eq14: 6*50 + 1*200
	eq15: 5*50 + 1*100
	eq16: 5*50 + 2*100
	eq17: 5*50 + 1*200
	eq18: 4*50 + 1*100
	eq19: 4*50 + 2*100
	eq20: 4*50 + 3*100
	eq21: 4*50 + 1*100 + 1*200
	eq22: 4*50 + 1*200
	eq23: 4*50 + 1*330
	eq24: 3*50 + 1*100
	eq25: 3*50 + 2*100
	eq26: 3*50 + 3*100
	eq27: 3*50 + 1*100 + 1*200
	eq28: 3*50 + 1*200
	eq29: 3*50 + 1*330
	eq30: 2*50 + 1*100
	eq31: 2*50 + 2*100
	eq32: 2*50 + 3*100
	eq33: 2*50 + 4*100
	eq34: 2*50 + 2*100 + 1*200
	eq35: 2*50 + 1*100 + 1*200
	eq36: 2*50 + 1*100 + 1*330
	eq37: 2*50 + 1*200
	eq38: 2*50 + 2*200
	eq39: 2*50 + 1*330
	eq40: 2*50 + 1*420
	eq41: 1*50 + 1*100
	eq42: 1*50 + 2*100
	eq43: 1*50 + 3*100
	eq44: 1*50 + 4*100
	eq45: 1*50 + 2*100 + 1*200
	eq46: 1*50 + 1*100 + 1*200
	eq47: 1*50 + 1*100 + 1*330
	eq48: 1*50 + 1*200
	eq49: 1*50 + 2*200
	eq50: 1*50 + 1*330
	eq51: 1*50 + 1*420
	eq52: 1*100
	eq53: 2*100
	eq54: 3*100
	eq55: 4*100
	eq56: 5*100
	eq57: 3*100 + 1*200
	eq58: 2*100 + 1*200
	eq59: 2*100 + 1*330
	eq60: 1*100 + 1*200
	eq61: 1*100 + 2*200
	eq62: 1*100 + 1*330
	eq63: 1*100 + 1*420
	eq64: 1*200
	eq65: 2*200
	eq66: 1*200 + 1*330
	eq67: 1*330
	eq68: 1*420
	eq69: 1*500
*/
```

### Solution 3 by pl_solve
|Variables|MILP Feasible|result
|:-:|:-:|:-:
||30|30
|X0|0|0
|X1|0|0
|X2|0|0
|X3|0|0
|X4|0|0
|X5|0|0
|X6|0|0
|X7|0|0
|X8|0|0
|X9|0|0
|X10|0|0
|X11|0|0
|X12|0|0
|X13|0|0
|X14|0|0
|X15|0|0
|X16|0|0
|X17|0|0
|X18|0|0
|X19|0|0
|X20|0|0
|X21|0|0
|X22|0|0
|X23|0|0
|X24|0|0
|X25|0|0
|X26|0|0
|X27|0|0
|X28|0|0
|X29|0|0
|X30|0|0
|X31|0|0
|X32|0|0
|X33|2|2
|X34|0|0
|X35|0|0
|X36|5|5
|X37|0|0
|X38|0|0
|X39|0|0
|X40|8|8
|X41|0|0
|X42|0|0
|X43|0|0
|X44|0|0
|X45|0|0
|X46|0|0
|X47|0|0
|X48|0|0
|X49|0|0
|X50|0|0
|X51|0|0
|X52|0|0
|X53|0|0
|X54|0|0
|X55|0|0
|X56|0|0
|X57|0|0
|X58|0|0
|X59|0|0
|X60|0|0
|X61|5|5
|X62|0|0
|X63|2|2
|X64|0|0
|X65|0|0
|X66|0|0
|X67|0|0
|X68|0|0
|X69|8|8
