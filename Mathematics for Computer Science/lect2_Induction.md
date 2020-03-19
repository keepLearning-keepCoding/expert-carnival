# Proof by Contradiction

To prove P is true, we assume P is False(ie,![](http://latex.codecogs.com/gif.latex?\neg)P is True) & then you use that hypothesis to derive a falsehood or contradiction.

If P is true, then   ![](http://latex.codecogs.com/gif.latex?\neg)P  is false,  and this means that  ![](http://latex.codecogs.com/gif.latex?\neg)P ![](http://latex.codecogs.com/gif.latex?\implies)F is true.



Ex:Thm: ![](http://latex.codecogs.com/gif.latex?\sqrt{2}) is **irrational**.

An irrational number is something that can't be expressed as the ratio of integers.

Proof  (by Contradiction).

Assume for the purpose of contradiction,  that ![](http://latex.codecogs.com/gif.latex?\sqrt{2}) is **rational**.

![](http://latex.codecogs.com/gif.latex?\implies) ![](http://latex.codecogs.com/gif.latex?\sqrt{2}) = a/b (a fraction in lowest terms,ie. a and b have no common divisors.)

![](http://latex.codecogs.com/gif.latex?\implies) ![](http://latex.codecogs.com/gif.latex?{2=a^2/b^2})

![](http://latex.codecogs.com/gif.latex?\implies)![](http://latex.codecogs.com/gif.latex?{2b^2=a^2})

![](http://latex.codecogs.com/gif.latex?\implies) a is even  (2![](http://latex.codecogs.com/gif.latex?\mid)a)

![](http://latex.codecogs.com/gif.latex?\implies) ![](http://latex.codecogs.com/gif.latex?4\mid{a^2})

![](http://latex.codecogs.com/gif.latex?\implies)![](http://latex.codecogs.com/gif.latex?4\mid{2b^2})

![](http://latex.codecogs.com/gif.latex?\implies)![](http://latex.codecogs.com/gif.latex?\2\mid{b^2})

![](http://latex.codecogs.com/gif.latex?\implies) b is even (![](http://latex.codecogs.com/gif.latex?2\mid{b}))

![](http://latex.codecogs.com/gif.latex?\implies) a/b is not in lowest terms

![](http://latex.codecogs.com/gif.latex?\implies) contradiction(※)

![](http://latex.codecogs.com/gif.latex?\implies)![](http://latex.codecogs.com/gif.latex?\sqrt{2}) is irrational.  ![](http://latex.codecogs.com/gif.latex?\square)



## Induction axiom

​		Let P(n) be a predicate. If P(0) is true and <img src="http://latex.codecogs.com/gif.latex?\forall{n}\in\mathbb{N}"/>,(P(n)![](http://latex.codecogs.com/gif.latex?\implies)P(n+1)) is true, then ![](http://latex.codecogs.com/gif.latex?\forall{n}\in\mathbb{N}),P(n) is true.

Note: In the preceding part, ![](http://latex.codecogs.com/gif.latex?\mathbb{N}) is natural number.

A easy-understanding interpretation: If P(0),P(0)![](http://latex.codecogs.com/gif.latex?\implies)P(1),P(1)![](http://latex.codecogs.com/gif.latex?\implies)P(2),.... are true

then P(0),P(1),P(2).... are true.



**Thm**: ![](http://latex.codecogs.com/gif.latex?\forall{n}\geqslant{0}),![](http://latex.codecogs.com/gif.latex?1+2+3+...+n=\sum_{i=1}^{n}i=\sum_{.}^{1\leq{i}\leq{n}}{i}=\sum_{1\leqslant{i}\leqslant{n}}i=\frac{n(n+1)}{2})

If n=1, 1+2+...+n = 1

If n ![](http://latex.codecogs.com/gif.latex?\leq{0}), 1+2+...+n=0

If n = 4, ![](http://latex.codecogs.com/gif.latex?1+2+3+4=10=\frac{4(5)}{2})

Proof: by induction.

Let P(n) be proposition that ![](http://latex.codecogs.com/gif.latex?\sum_{i=1}^{n}i=\frac{n(n+1)}{2})

**BaseCase**:  P(0) is true.

![](http://latex.codecogs.com/gif.latex?\sum_{i=1}^{0}i=0=\frac{0(0+1)}{2})

**Inductive Step**: For ![](http://latex.codecogs.com/gif.latex?n\geq{0}),show ![](http://latex.codecogs.com/gif.latex?P(n)\implies{P(n+1)}) is true.

Assume P(n) is true, for purposes of  induction.

(ie., assume ![](http://latex.codecogs.com/gif.latex?1+2+...+n=\frac{n(n+1)}{2}))

need to show ![](http://latex.codecogs.com/gif.latex?1+2+...+n+(n+1)=\frac{(n+1)(n+2)}{2})

![](http://latex.codecogs.com/gif.latex?1+2+...+n+(n+1))

![](http://latex.codecogs.com/gif.latex?=\frac{n(n+1)}{2}+n+1)

![](http://latex.codecogs.com/gif.latex?=\frac{n^2+n+2n+2}{2})

![](http://latex.codecogs.com/gif.latex?=\frac{(n+1)(n+2)}{2})![](http://latex.codecogs.com/gif.latex?\square)

We have prove that ![](http://latex.codecogs.com/gif.latex?=\forall{n}\geq{0},P(n)\implies{P(n+1)})

We've done everything we need to apply induction.  We've got P(0) is true, and P(n) implies P(n+1) for n bigger than or equal to zero.



**Thm**: ![](http://latex.codecogs.com/gif.latex?\forall{n}\in\mathbb{N}),![](http://latex.codecogs.com/gif.latex?3\mid{n^3-n}), ie. ![](http://latex.codecogs.com/gif.latex?{n^3-n}) is a multiple of 3.

Ex: n = 5,  ![](http://latex.codecogs.com/gif.latex?3\mid{(125-5)})

Proof, by induction.

Let P(n):   ![](http://latex.codecogs.com/gif.latex?3\mid{(n^3-n)})

**BaseCase**: n = 0, ![](http://latex.codecogs.com/gif.latex?3\mid{0-0})

**Inductive Step**: For ![](http://latex.codecogs.com/gif.latex?n\geq{0}), show ![](http://latex.codecogs.com/gif.latex?P(n)\implies{P(n+1)}) is True.



Assume P(n) true, ie.  ![](http://latex.codecogs.com/gif.latex?3\mid{(n^3-n)})

<img src="./img/lect2/equation_1.png" alt="equation_1" height="100" />

**Because:**

<img src="./img/lect2/equation_2.png" alt="equation_2" height="100" />

**Therefore:** <img src="./img/lect2/equation_3.png" alt="equation_3" height="40" />

The **key steps in induction** are always the same. You write down "proof by induction". You identify your predicate. You do the **base case**, usually n equals 0, but it could be something else. And then you do your **inductive step**.

**Base Case **  P(b)  is true.

**Inductive Step**: <img src="./img/lect2/equation_4.png" alt="equation_4" style="zoom:50%;" />

**Conclude**:	<img src="./img/lect2/equation_5.png" alt="equation_5" style="zoom:50%;" />    

Let's now do a false proof using induction.

Thm(NOT!)   All horses are the same color.

Pf: by induction.

​	P(n): In any set of n horses( (n)![](http://latex.codecogs.com/gif.latex?\geq)1), the horses are all the same color.

BaseCase: P(1)   It's true since just 1 horse.

Inductive Step: Assume P(n) to prove P(n+1)

Consider **any** set of n+1 horses, H~1~,H~2~,...,H~n+1~

Then H~1~,H~2~,...H~n~  are the same color,

​		  H~2~,H~3~,...H~n+1~   are the same color,

Since color(H~1~) = color(H~2~,...H~n~) = color(H~n+1~)

![](http://latex.codecogs.com/gif.latex?\implies) all n+1 are the same color ![](http://latex.codecogs.com/gif.latex?\implies) P(n+1) ![](http://latex.codecogs.com/gif.latex?\square).



**Thm**:  ![](http://latex.codecogs.com/gif.latex?\forall{n}\exists)  way to tile a  <img src="./img/lect2/equation_6.png" alt="equation_6" width="50" /> region with a center square missing(for Bill).

Pf: by induction.

P(n):![](http://latex.codecogs.com/gif.latex?\forall{n}\exists)  way to tile a  <img src="./img/lect2/equation_6.png" alt="equation_6" width="50" /> region with any  square missing(for Bill).

Base Case: P(0) one  ![](http://latex.codecogs.com/gif.latex?\square) for bill

Inductive Step: For ![](http://latex.codecogs.com/gif.latex?n\geq{0}), assume P(n) to verify Inductive Hypothesis.

So we need to show P(n+1) is true.

Consider a 2^n+1^X2^n+1^  courtyard.

P(n)![](http://latex.codecogs.com/gif.latex?\implies)P(n+1).









