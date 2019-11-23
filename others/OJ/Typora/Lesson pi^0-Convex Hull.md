#### Lesson pi^0-Convex Hull

##### Problem Description

We define a function gay(i) :
$$
gay(i)=\begin{cases}
0 & if\space i=k*x*x\space x>1,k\ge1 \\
i*i & else
\end{cases}
$$
Now,your task is to calculate
$$
\sum\limits_{num=1}^{n}(\sum\limits_{i=1}^{num}gay(i))mod \space p
$$


##### Input

Multiple test cases. Please use EOF.

In each test case , there are two integers n,p, which are described above.
$$
(1\le n\le 10^{10},1\le p\le 10^{11})
$$
The number of test cases is no more than 100.

##### Output

For each test case print the answer in one line.

##### Sample Input 		

1 10

8 19230817

##### Sample Output

1
396

##### Reference

莫比乌斯函数

莫比乌斯反演

杜教筛