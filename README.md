# Lecture 11-2: LAMBDAS IN C++

`Slide 01` [Part 01. 2nd Midterm](https://ensemble.reed.edu/Watch/Rw34Xnf9) *04m00s*  
`Slide 03` [Part 02. Overview of C++ Lambdas](https://ensemble.reed.edu/Watch/Sk83Bey7) *06m15s*  
`Slide 05` [Part 03. History of Lambda](https://ensemble.reed.edu/Watch/Zr23Rkj5) *15m00s*  
`Slide 11` [Part 04. C++ Lambda Syntax](https://ensemble.reed.edu/Watch/q6A5Gdj3) *07m30s*  
`Slide 35` [Part 05. Copy Capture](https://ensemble.reed.edu/Watch/Mz23XrEg) *07m45s*  
`Slide 44` [Part 06. Reference Capture](https://ensemble.reed.edu/Watch/d7C3TiXc) *07m10s*  
`Slide 56` [Part 07. Function Class](https://ensemble.reed.edu/Watch/c8E3Zar6) *04m00s*  
  

Here we look at expressing functions *anonymously* within
function and procedure bodies. These function objects are
often called "lambdas" by the programming community, because
they were first introduced by John McCarthy's 1958 invention
of the programming language Lisp, and borrowing the notation
from Alonzo Church's *lambda calculus*.  

In C++, the use of function objects is complicated because of the
language's object memory model. It requires you to specify a *capture
list* of the stack variables used either *by value* (sometimes called
"*by copy*" instead) or *by reference* within the body of the lambda.
Here is the lambda expression syntax:

&nbsp;&nbsp;&nbsp;&nbsp; `[` *capture-list* `] (` *parameter-list* `) -> ` *return-type* `{` *body* `}`

The `samples` folder contains code examples that I used in my slides.

Incidentally, if the body changes any variables or objects that it captures *by value*
(if they are *copy captures*) then it needs to include the `mutable` keyword, like
so:

&nbsp;&nbsp;&nbsp;&nbsp; `[` *capture-list* `] (` *parameter-list* `) mutable -> ` *return-type* `{` *body* `}`

This makes the "lambda" or "closure" have some hidden state, and its `operation()` will no longer be a `const` method.

