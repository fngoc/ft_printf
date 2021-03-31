# ft_printf

## Description

A rewritten printf function using variable arguments.

The compilation was with flags: ``gcc -Wall -Wextra -Werror``.

All files pass to ``Norminette``.

No memory leaks.

## Using

``make`` and ``make all`` build the library with the project, or recompile the modified file, also rebuilding the library.

``make re`` deletes all ``.o`` files, deletes ``libftprintf.a``, rebuilds the library.

``make clean`` deletes all ``.o`` files.

``make fclean`` deletes all ``.o`` files, also deletes ``libftprintf.a``.

## my_test

Compiling the project with ``main.c``, and look at the result. Also, do not forget to check all possible found tests for your ft_printf. The basis for the tests was taken from [timurmug](https://github.com/timurmug). Removed all ``undefined behaviour`` tests, added their own tests.

## Evaluation

![alt tag](media/appraisal_ft_printf.png "Appraisal ft_printf")
