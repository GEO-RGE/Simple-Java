@echo off
cls
yacc -d -t simple_java.yacc
flex simple_java.flex
gcc lex.yy.c simple_java_main.c y.tab.c -DYYDEBUG -o simple_java.exe