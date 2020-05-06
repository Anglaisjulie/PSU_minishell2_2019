# MINISHELL 2

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/b26ccab78bb346d4b61886cffcdc0459)](https://app.codacy.com/manual/Anglaisjulie/PSU_minishell2_2019?utm_source=github.com&utm_medium=referral&utm_content=Anglaisjulie/PSU_minishell2_2019&utm_campaign=Badge_Grade_Dashboard)

Simple reproduction of the tcsh shell (PART 2).

- **Binary name:** mysh
- **Repository name:** PSU_minishell2_2019
- **Repository rigths:** ramassage-tek
- **Language:** C
- **Compilation:** via Makefile, including re, clean and fclean rules

# Subject

The goal of the project is to enrich your minishell1 project by adding semicolons (‘;’), pipes (‘|’), and the four redirections (‘>’, ‘<’, ‘>>’, ‘<<’) management.
Here is a simple example of a command you must hanlde:

```
∼/PSU_minishell2_2019> ./mysh
> mkdir test ; cd test ; ls -a ; ls | cat | wc -c > tutu ; cat tutu
...
5
>
```

> :bulb: Error output, standard input and standard output redirections will be considered as bonuses.

## Authorized functions

- malloc, free, exit, opendir, readdir, closedir, getcwd, chdir
- fork, stat, lstat, fstat, open, close, getline
- read, write, execve, isatty, wait, waitpid
- wait3, wait4, signal, kill, getpid, strerror, perror, strsignal
- pipe, dup, dup2

## Compile & Execute

```
∼/PSU_minishell2_2019> make
∼/PSU_minishell2_2019> ./mysh
>
```

## Use of functional tests

Do not display the prompt for tests.

```
∼/PSU_minishell2_2019> make
∼/PSU_minishell2_2019> ./tests/git_minishell_tests.sh
```