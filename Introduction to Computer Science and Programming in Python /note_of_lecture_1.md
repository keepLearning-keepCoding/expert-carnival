### 1. SCALAR OBJECTS

| type     | meaning                   | example        |
| -------- | ------------------------- | -------------- |
| int      | integers                  | 5              |
| float    | real numbers              | 3.27           |
| bool     | Boolean values            | True and False |
| NoneType | special and has one value | None           |

You can use **type()** to see the **type** of **an object**.

### 2.TYPE CONVERSIONS(CAST)

You can convert object of one type to another.

- float(3) converts integer 3 to float 3.0
- int(3.9) truncates float 3.9 to integer 3

### 3. to show output from code to a user, use *print* command

### 4. EXPRESSIONS

- **combine objects and operators** to form expressions

- an expression has a **value**, which has a type

- syntax for a simple expression

  \<object\> \<operator\> \<object\>

### 5. OPERATORS ON ints and floats

| expression | meaning                              | type of result                                               |
| ---------- | ------------------------------------ | ------------------------------------------------------------ |
| i+j        | the sum                              | if both are ints,result is int<br />if either or both are floats, result is float |
| i-j        | the difference                       | if both are ints,result is int<br />if either or both are floats, result is float |
| i*j        | the product                          | if both are ints,result is int<br />if either or both are floats, result is float |
| i/j        | division                             | result is float                                              |
| i%j        | the remainder when i is divided by j |                                                              |
| i**j       | i to the power of j                  |                                                              |

#### 6. BINDING VARIABLES AND VALUES

- **equal sign** is an **assignment** of a value to a variable name

  **pi** = 3.14159

  pi_approx = 22/7

- value stored in computer memory
- an assignment binds name to value
- retrieve value associated with name or variable by invoking the name, by typing **pi**

### 7. ABSTRACTING EXPRESSIONS

- Why give names to values of expressions?

- To reuse names instead of values

- easier to change code later

  pi = 3.14159

  radius = 2.2

  area = pi\*(radius\*\*2)

### 8. CHANGING BINDINGS

- can **re-bind** variable names using **new assignment statements**

- previous value may **still stored in memory** but **lost the handle for it**

- value for area does not change until you tell the computer to do the calculation again

  