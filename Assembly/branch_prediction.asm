section .data
    arr times 1000000 db 0  ; Array of zeros (predictable pattern)
    sum dq 0

section .text
    global _start

_start:
    mov rcx, 1000000    ; Loop counter
    mov rbx, sum        ; Sum variable

loop_start:
    cmp byte [arr + rcx], 0  ; Compare with zero
    jne skip_increment       ; If not zero, skip

    inc qword [rbx]          ; Increment sum

skip_increment:
    loop loop_start          ; Loop until counter reaches 0

    ; Exit
    mov rax, 60
    xor rdi, rdi
    syscall
