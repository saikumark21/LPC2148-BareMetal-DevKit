#ifndef LPC214X_H
#define LPC214X_H

//----------------------
// Configrations
//----------------------





// ----------------------
// GPIO (Legacy I/O Block)
// ----------------------

#define IO0PIN     (*(volatile unsigned long *)0xE0028000)
#define IO0SET     (*(volatile unsigned long *)0xE0028004)
#define IO0DIR     (*(volatile unsigned long *)0xE0028008)
#define IO0CLR     (*(volatile unsigned long *)0xE002800C)

#define IO1PIN     (*(volatile unsigned long *)0xE0028010)
#define IO1SET     (*(volatile unsigned long *)0xE0028014)
#define IO1DIR     (*(volatile unsigned long *)0xE0028018)
#define IO1CLR     (*(volatile unsigned long *)0xE002801C)

// ------------------------
// Fast GPIO (FIO Registers)
// ------------------------

#define FIO0DIR    (*(volatile unsigned long *)0x3FFFC000)
#define FIO0MASK   (*(volatile unsigned long *)0x3FFFC010)
#define FIO0PIN    (*(volatile unsigned long *)0x3FFFC014)
#define FIO0SET    (*(volatile unsigned long *)0x3FFFC018)
#define FIO0CLR    (*(volatile unsigned long *)0x3FFFC01C)

// -----------------
// Pin Function Select
// -----------------

#define PINSEL0    (*(volatile unsigned long *)0xE002C000)
#define PINSEL1    (*(volatile unsigned long *)0xE002C004)

// ----------------------
// PLL (Clock Control)
// ----------------------

#define PLLCON     (*(volatile unsigned long *)0xE01FC080)
#define PLLCFG     (*(volatile unsigned long *)0xE01FC084)
#define PLLSTAT    (*(volatile unsigned long *)0xE01FC088)
#define PLLFEED    (*(volatile unsigned long *)0xE01FC08C)

#define VPBDIV     (*(volatile unsigned long *)0xE01FC100)

// -------------------
// Memory Accelerator Module
// -------------------

#define MAMCR      (*(volatile unsigned long *)0xE01FC000)
#define MAMTIM     (*(volatile unsigned long *)0xE01FC004)

// -------------------
// Timer 0 and Timer 1
// -------------------

#define T0IR       (*(volatile unsigned long *)0xE0004000)
#define T0TCR      (*(volatile unsigned long *)0xE0004004)
#define T0TC       (*(volatile unsigned long *)0xE0004008)
#define T0PR       (*(volatile unsigned long *)0xE000400C)
#define T0PC       (*(volatile unsigned long *)0xE0004010)
#define T0MCR      (*(volatile unsigned long *)0xE0004014)
#define T0MR0      (*(volatile unsigned long *)0xE0004018)

#define T1IR       (*(volatile unsigned long *)0xE0008000)
#define T1TCR      (*(volatile unsigned long *)0xE0008004)
#define T1TC       (*(volatile unsigned long *)0xE0008008)
#define T1PR       (*(volatile unsigned long *)0xE000800C)
#define T1PC       (*(volatile unsigned long *)0xE0008010)
#define T1MCR      (*(volatile unsigned long *)0xE0008014)
#define T1MR0      (*(volatile unsigned long *)0xE0008018)

// -------------------
// UART0 and UART1
// -------------------

#define U0RBR      (*(volatile unsigned char *)0xE000C000)
#define U0THR      (*(volatile unsigned char *)0xE000C000)
#define U0IER      (*(volatile unsigned char *)0xE000C004)
#define U0IIR      (*(volatile unsigned char *)0xE000C008)
#define U0FCR      (*(volatile unsigned char *)0xE000C008)
#define U0LCR      (*(volatile unsigned char *)0xE000C00C)
#define U0LSR      (*(volatile unsigned char *)0xE000C014)
#define U0DLL      (*(volatile unsigned char *)0xE000C000)
#define U0DLM      (*(volatile unsigned char *)0xE000C004)

#define U1RBR      (*(volatile unsigned char *)0xE0010000)
#define U1THR      (*(volatile unsigned char *)0xE0010000)
#define U1IER      (*(volatile unsigned char *)0xE0010004)
#define U1IIR      (*(volatile unsigned char *)0xE0010008)
#define U1FCR      (*(volatile unsigned char *)0xE0010008)
#define U1LCR      (*(volatile unsigned char *)0xE001000C)
#define U1LSR      (*(volatile unsigned char *)0xE0010014)
#define U1DLL      (*(volatile unsigned char *)0xE0010000)
#define U1DLM      (*(volatile unsigned char *)0xE0010004)

// -------------------
// VIC (Interrupt Controller)
// -------------------

#define VICIRQStatus   (*(volatile unsigned long *)0xFFFFF000)
#define VICIntEnable   (*(volatile unsigned long *)0xFFFFF010)
#define VICIntSelect   (*(volatile unsigned long *)0xFFFFF00C)
#define VICVectAddr    (*(volatile unsigned long *)0xFFFFF030)
#define VICVectCntl0   (*(volatile unsigned long *)0xFFFFF200)
#define VICDefVectAddr (*(volatile unsigned long *)0xFFFFF034)

#endif // LPC214X_H
