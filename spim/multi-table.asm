.data

prompt: .asciiz "Enter an integer: "
cross: .asciiz " X "
equal: .asciiz " = "
endl: .asciiz "\n"
limit: .word 10

.text
.globl main
.ent main

main:

li $v0, 4
la $a0, prompt
syscall

li $v0, 5
syscall
move $t0, $v0

li $t1, 1
lw $t3, limit
addi $t3, $t3, 1

loop:

	mult $t0, $t1
	mflo $t2

	li $v0, 1
	move $a0, $t0
	syscall

	li $v0, 4
	la $a0, cross
	syscall

	li $v0, 1
	move $a0, $t1
	syscall

	li $v0, 4
	la $a0, equal
	syscall

	li $v0, 1
	move $a0, $t2
	syscall

	li $v0, 4
	la $a0, endl
	syscall

	addi $t1, $t1, 1

blt $t1, $t3, loop

li $v0, 10
syscall