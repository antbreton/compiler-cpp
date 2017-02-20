# compiler-cpp

## Description

This is simple compiler based on a bottom-up analysis. 
It can evaluate expressions of the following grammar :

1) E'-> E
2) E -> E+E
3) E -> E*E
4) E -> ( E )
5) E -> val

## How it works

The execution pipeline is composed by 3 steps :
- Lexical Analysis
- Syntax Analysis
- Evaluation of the expression.

Errors Management : 
If there is a syntax error, the analysis will stop and show where the error is located.
Otherwise, If the lexical analysis finds characteres which don't bellow to the grammar lexic, 
it will ignore them and return a symbole stack well-formed.

## Technical Aspect

The lexical analysis is managed in the <b>lexer</b> class. 

The syntax analysis is managed in the <b>automate</b> class.
It respects a <b>state design pattern</b>. All states are located in the module <b>Etat</b>.

All symboles are managed with a inheritance architecture located in the <b>Symbole</b> module. 

## Quick Start

First off, extract the compressed archive.

then,
> $ make

run the executable
> $ ./analyse

then type an expression
> Step 0 : Type a line
>		((1+1)*5)*2

