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



Thm: ![](http://latex.codecogs.com/gif.latex?\forall{n}\geqslant{0}),![](http://latex.codecogs.com/gif.latex?1+2+3+...+n=\sum_{i=1}^{n}i=\sum_{.}^{1\leqslant{i}\leqslant{n}}i=\sum_{1\leqslant{i}\leqslant{n}}i=\frac{n(n+1)}{2})















