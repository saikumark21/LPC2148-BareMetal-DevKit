#ifndef DEFINES_H
#define DEFINES_H

#define SETBIT(DATA,BIT) DATA = DATA | (1 << BIT)
#define CLRBIT(DATA,BIT) DATA = DATA & (~(1 << BIT))
#define READBIT(DATA,BIT) ((DATA >> BIT) & 1)

#endif //defines.h