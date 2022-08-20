.data
buf: .word 0
l: .word 10
prompt: .asciiz "Enter an integer :"
first: .asciiz " X "
second: .asciiz " = "
ex: .asciiz "\n"
.text
.globl main
.ent main

main:


# Printing text on console
li $v0, 4
la $a0, prompt
syscall

	# Getting user input
	li $v0, 5
	syscall
	move $t3, $v0

# Printing a number
li $v0, 1
move $a0, $t3
syscall

	# Printing text
	li $v0, 4
	la $a0, ex
	syscall
lw $t2, l
li $s0, 1

loop:
# Printing out a number
li $v0, 1
move $a0, $t3
syscall

mult $t3, $s0
mflo $t1 
	
	# Printing out text
	li $v0, 4
	la $a0, first
	syscall

  # printing number
  li $v0, 1
  move $a0, $s0
  syscall

	# text
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
