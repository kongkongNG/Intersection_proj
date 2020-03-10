## 一、数学准备(无法查看公式[参考这里](https://blog.csdn.net/bitcarmanlee/article/details/87829033))
(直线：$y=kx+b,圆：(x-n)^2+(y-m)^2=r^2$)

### 0 已知点求直线k，b公式

$k = \frac{y_2 - y_1}{x_2-x_1},b = \frac{x_2y_1 - x_1y_2}{x_2-x_1}或b = y - kx$

### 1 相交检测

**1）直线与直线**

斜率是否相等（$k_1 = k_2 ? 相交 ：不相交$ ）

**2）直线与圆**

圆心到直线距离与半径比较

$将x=n,y=m带入d = |\frac{kx-y+b}{\sqrt{k^2+1}}|$

**3）圆与圆**

圆心距离与半径之和比较

### 2 交点公式

**1）两直线交点公式**

$x = \frac{b_2-b_1}{k_1-k_2}, y=kx+b$

**2）直线与圆交点公式**

$联立得到的一元二次方程组Ax^2+Bx+C = 0，其中$

$A = 1+k^2,B = 2k(b-m)-2n,C=(b-m)^2+n^2-r^2$

一元二次方程组求解：

$x = \frac{-b\pm \sqrt{b^2-4ac}}{2a}$

**4）两圆交点公式**

<!-- https://blog.csdn.net/weixin_39061140/article/details/102948557 -->

[参考博客](https://blog.csdn.net/qq_18509807/article/details/84950132)

本次项目中采用博客中的解法二，其中解法二的最终交点结果有误，经计算更正为：

<!-- $\left\{\begin{matrix}x_c=x_0-\frac{h}{d}(y2-y1)\\y_c=y_0+\frac{h}{d}(x2-x1)  \\\end{matrix}\right. 或 \left\{\begin{matrix}x_d=x_0+\frac{h}{d}(y2-y1)\\y_c=y_0-\frac{h}{d}(x2-x1)  \\\end{matrix}\right.$ -->

<!-- ![](assets/md_2020-03-10-18-50-53.png) -->
![md_2020-03-10-18-50-53.png](https://i.loli.net/2020/03/10/7rNLuMpoZk4SbFY.png)


## 二、类设计

几何对象
* 几何对象接口 Geometry
  * struct Point
  * isIntersect(Geometry* obj)
  * getInterPoint(Geometry* obj)
* 直线类 Line
* 圆类  Circle

主业务
* Intersection
  * count_intersection(string fileIn, string fileOut)
  

## 三、需注意的问题

* 几何对象的参数应该为double，保证计算过程的精确

## 四、bug汇总

* 浮点数的精度问题以及去重问题
  * `set<Type>`的type如果没有重写`operator<`会报 “*C2678 二进制< 没有找到接受const类型的左操作数的运算符*” 的错
  * 重载`operator<`的函数中必须有大小比较，不能直接返回true或false，否则会有assertion报错
* 没有考虑直线与坐标轴平行的情况（已完成）
  * 垂直于x轴的直线与圆交点
    * $(lx-n)^2+(y-m)^2 = r^2=>y=m \pm \sqrt{r^2 - (lx-n)^2}$
  * 垂直于y轴的直线
    * $(x-n)^2+(b-m)^2 = r^2=>x=n\pm \sqrt{r^2-(b-m)^2}$

* 没有考虑两圆內离的情况
  * `d > r1+r2`外离，`d < |r1-r2|`內离


