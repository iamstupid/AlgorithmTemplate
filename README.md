# AlgorithmTemplate
Algorithm templates
##bdtz.h
You should always include this file.

`bdtz.h` defines some basic types.

`ul`:`unsigned long`

`ull`:`unsigned long long`

`ll`:`long long`

`il`:`int`

`long long` is 64_bit int;

###bdtz utilities
####namespace `fastIO`
contains a fast input/output tunnel to standard IO(`stdin/stdout`).

`getc` getchar(FASTER);

`rdu`  read `unsigned [int]` which `[int]` stands for `long long/long/int`.

`rdu`(multiple parameters) read multiple uint one time.

`putc` putchar(FASTER/delayed/incompatiable with printf);

`pru` puts `unsigned [int]`

NOTE: `putc([val],1)` will flush the buffer after outputing `[val]`. if `[val]==-1` it won't output any characters.

**`NOTE [VERY IMPORTANT]` The fastIO functional must be used with an flushing output call at the end of the program if you have done any output.**
