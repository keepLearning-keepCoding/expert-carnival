1.A mathematical proof is a verification of a **proposition** by a chain of **logical deductions** from a set of **axioms**.

2.Def: A **proposition** is a **statement** that is either true or false.

  Ex: 2 + 3 = 5

Ex: 
$$
\forall n \in N, n^2+n+41 \ is \ a\ prime\ number
$$
  $\forall$ is "Forall" symbol

  N indicates Natural numbers, ie. {0, 1, 2, 3, ...}

 Meaning: for each Natural number, $n^2+n+41$ is a prime number.

A **prime number** is a number that is **not divisible** by any other number besides itself and 1.

3.Def: A **predicate** is a **proposition** whose truth depends on the value of variable(s).

Ex: Every even integer but 2 is the sum of 2 primes.

​		Ex: 24 = 11 + 13

4.
$$
\forall n \in Z,n\geq 2 \implies n^2 \geq 4
$$
$\implies$ means implies.

 Z is integers, ie. {0,1,-1,2,-2,...}
5.Def: An implication $p\implies q$ is true if p is False or q is True.

#### Truth Table

| p    | q    | $p \implies q$ | $q \implies p$ | $p \iff q$ |
| ---- | ---- | -------------- | -------------- | ---------- |
| T    | T    | T              | T              | T          |
| T    | F    | F              | T              | F          |
| F    | T    | T              | F              | F          |
| F    | F    | T              | T              | T          |

### False implies anything is True.

### So p if and only if q is True when they're both True or both False, if they are different, then it's not True.

5. Ex: 
   $$
   \forall n \in Z,n \geq 2 \iff n^2 \geq 4
   $$
   

$\iff $ means "if and only if"

### Is n  bigger than 2 if and only  if n squared is bigger than 4?

### False,for example, -3

#### $\iff $ means you have to have an implication both ways, so you have to check both ways for it.

6. Def: An **axiom** is a **proposition** that is **"assumed" to be true**.

   There's **no proof** that **an axiom is true**.You just **assume** it because **you think it's reasonable**.

   In fact, the word "**axiom**" comes from **Greek**. It doesn't mean to be true. It means to think worthy——something you think is worthy enough to be assumed to be true.

7. Axioms should be

   a. consistent

   b. complete

  Def: A set of axioms is **consistent** if **no proposition** can be proved both **True** & **False**.

  Def: A set of axioms is said to be **complete** if it can be used to prove **every proposition** is either **True** or **False**.