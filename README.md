# AlgorithmTemplate
Algorithm templates

> **`WARNING`** AlgorithmTemplate does a lot with macros; their relationship may also be complex. DON'T TRY TO EDIT THEM UNLESS YOU HAVE FULLY TESTED THEY ARE EQUIVALENT

Dependences are mostly auto-solved.
##bdtz.h
You would always include this file.

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

####namespace `basicDCMath`
Contains some useful functionals on `unsigned [int]`s.
**ull functionals**

`ladd lmul lpow` do avoids overflow modding some ull;

`lfpm`does not.

**ul functionals**

`lmul lfpm` do avoids overflow.

**linv**

Get inverse mop `p` less or equal than `n` in linear time to `n`.
