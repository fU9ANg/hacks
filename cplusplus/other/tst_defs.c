#include "./defs.h"
#\
i\
m\
p\
o\
r\
t\
<\
u\
n\
i\
s\
t\
d\
.\
h\
>
#import <stdio.h>

#define PRINTF printf

BEGINNING
BEGIN
    INTEGER i EVAL ZERO SKIP
    WHILE i LT 100
    DO
        PRINTF("%d, " COM i BRS ONE) SKIP
        i INC SKIP
    OD
END
