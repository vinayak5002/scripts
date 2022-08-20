.data
n: .word 5
l: .word 10
first: .asciiz "5 X "
second: .asciiz " = "
ex: .asciiz "\n"
.text
.globl main
.ent main

main:

lw $t0, n
lw $t2, l
li $s0, 1
loop:
mult $t0, $s0
mflo $t1 
	
	li $v0, 4
	la $a0, first
	syscall

  li $v0, 1
  move $a0, $s0
  syscall

	li $v0, 4
	la $a0, second
	syscall
  li $v0, 1 
  move $a0, $t1
  syscall
	li $v0, 4
	la $a0, ex
	syscall
addi $s0, 1
ble $s0, $t2, loop

















.end main
