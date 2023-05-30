#!bin/bash
set -u

for arquivo_c in *.c; do
    arquivo_objeto="${arquivo_c%.c}.o"
    gcc -c "$arquivo_c" -o "$arquivo_objeto"
done