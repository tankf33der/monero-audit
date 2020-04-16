SANs + TIS:
blake        - ok
groestl      - ok
jh           - ok
-hmac-keccak - fails
skein        - ok

$ make interp
rm -rf mike.c *.o *.out
cat *.c > mike.c
cat memset >> mike.c
ccomp -interp -quiet mike.c
start
Stuck state: in function keccak_update, expression
        <loc is_aligned> = 0 == (7 & <ptr> - 0LL)
        Stuck subexpression: <ptr> - 0LL
        ERROR: Undefined behavior
        make: *** [Makefile:14: interp] Error 126

