    .section .vectors, "a"
    .code 32
    .global Reset_Handler

Vectors:
    LDR PC, =Reset_Handler    // Reset
    LDR PC, =Undef_Handler    // Undefined instruction
    LDR PC, =SWI_Handler      // Software interrupt
    LDR PC, =PAbt_Handler     // Prefetch abort
    LDR PC, =DAbt_Handler     // Data abort
    .word 0                   // Reserved
    LDR PC, =IRQ_Handler      // IRQ
    LDR PC, =FIQ_Handler      // FIQ

// Handlers
Reset_Handler:
    // Initialize stack pointer
    LDR SP, =_stack_top

    // Copy .data section from FLASH to RAM
    LDR R0, =_data_start
    LDR R1, =_data_load_start
    LDR R2, =_data_end
1:
    CMP R0, R2
    LDRLO R3, [R1], #4
    STRLO R3, [R0], #4
    BLO 1b

    // Clear .bss section
    LDR R0, =_bss_start
    LDR R1, =_bss_end
    MOV R2, #0
2:
    CMP R0, R1
    STRLO R2, [R0], #4
    BLO 2b

    // Jump to main
    BL main

    B .

Undef_Handler:
SWI_Handler:
PAbt_Handler:
DAbt_Handler:
IRQ_Handler:
FIQ_Handler:
    B .
