VECT_NUM equ 9
org 7C00h

jmp Start

count db 41h
hello db 'Hello\ntest'


clock:
  pusha

  mov ah, [count]
  inc ah
  mov [count], ah

  mov al, [count]
  mov ah, 0Ah
  mov cx, 1
  int 10h


  ; Send EOI
  mov al, 61h
  out 20h, al
  ; return
  popa
  iret

keyboard:

  pusha


  ; Read code
  in al, 60h
  int 19h
  mov ah, [count]
  inc ah
  mov [count], ah

  mov al, [count]
  mov ah, 0Ah
  mov cx, 1
  int 10h


  ; Send EOI
  mov al, 61h
  out 20h, al
  ; return
  popa
  iret



Start:

mov ah, [count]
inc ah
mov [count], ah

mov ah, 00h
mov al, 03h
int 10h

mov ah, [count]
inc ah
mov [count], ah


push ds
push word 0
pop ds
cli
mov word [cs: VECT_NUM * 4 + 0], keyboard
mov [cs:VECT_NUM * 4 + 2],cs


sti


mov ah, [count]
inc ah
mov [count], ah



jmp $





times 0200h - 2 - ($ - $$)  db 0

dw 0AA55h
