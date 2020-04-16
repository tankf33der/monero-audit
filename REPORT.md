### SANs + TIS:
```
blake        - ok
groestl      - ok
jh           - ok
-hmac-keccak - fails
skein        - ok
```

### KECCAK
```
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
```

```
$ tis-interpreter.sh keccak/*.c
[value] Analyzing a complete application starting at main
[value] Computing initial state
[value] Initial state computed

start

keccak/keccak.c:201:[kernel] warning: pointer subtraction:
                  assert \base_addr((char const *)in) ≡ \base_addr((char const *)0);
                  stack: keccak_update :: keccak/hmac-keccak.c:52 <-
                         hmac_keccak_init :: keccak/hmac-keccak.c:78 <-
                         hmac_keccak_hash :: keccak/main.c:21 <-
                         main
[value] Stopping at nth alarm
[value] user error: Degeneration occurred:
                    results are not correct for lines of code that can be reached from the degeneration point.
```
