Grammar for Simple Compiler Phase 2:
```
expressions -> 'expressions' ID '(' 'infix' ',' 'postfix' ')' 'begin' expr_list 'end'

expr_list -> expr ';' expr_list | ε

expr -> term expr'

expr' -> '+' term expr' | '-' term expr' | ε

term -> factor term'

term' -> '*' factor term' | '/' factor term' | 'DIV' factor term' | 'MOD' factor term' | ε

factor -> '(' expr ')' | NUM | ID | ID 'times' NUM | ID 'plus' NUM | ID 'minus' NUM
```

## In this grammar:

1. `expressions` is the starting non-terminal representing a list of expressions.
2. Each `expressions` block consists of an identifier (`ID`) followed by `(` `infix` `,` `postfix` `)` indicating the expression type, and then 'begin' and 'end' delimiters.
3. `expr_list` represents a list of expressions within the `expressions` block.
4. `expr` represents an expression consisting of terms separated by `+` or `-`.
5. `term` represents a term consisting of factors separated by `*`, `/`, `DIV`, or `MOD`.
6. `factor` represents a factor, which could be a number (`NUM`), identifier (`ID`), or an expression within parentheses.

**Note**: This grammar includes the new keywords and operators introduced in Phase 2 of the project.


