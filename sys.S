.intel_syntax noprefix

.global write
.global read
.global fork
.global real_waitid

write:
mov rax, 1
syscall
ret

read:
mov rax, 0
syscall
ret

fork:
mov rax, 57
syscall ret

real_waitid:
mov rax, 247
mov r10, rcx
syscall
ret