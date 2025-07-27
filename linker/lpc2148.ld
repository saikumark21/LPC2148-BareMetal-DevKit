ENTRY(Reset_Handler)

MEMORY
{
  FLASH (rx) : ORIGIN = 0x00000000, LENGTH = 512K
  RAM (rwx)  : ORIGIN = 0x40000000, LENGTH = 32K
}

SECTIONS
{
  /* Vector table and main code */
  .text : {
    KEEP(*(.vectors))       /* Keep vector table */
    *(.text*)               /* Main code */
    *(.rodata*)             /* Read-only data (like consts) */
  } > FLASH

  /* Initialized data section: Load from FLASH, run in RAM */
  .data : {
    _data_start = .;
    *(.data*)
    _data_end = .;
  } > RAM AT > FLASH
  _data_load_start = LOADADDR(.data);

  /* Uninitialized data (zero-initialized at startup) */
   .bss : {
    _bss_start = .;
    *(.bss*)
    *(COMMON)
    _bss_end = .;
  } > RAM

  /* Stack definition (top of RAM) */
  . = ORIGIN(RAM) + LENGTH(RAM);
  _stack_top = .;
}
