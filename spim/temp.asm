.data

arr1: .word 34, 23, 16, 25, 43, 36, 6, 12, 17, 19, 33, 39, 21, 37, 50
arr2: .word 0

len: .word 16

endl: .asciiz " "

.text
.globl main
.ent main

main:

li $s0, 0  #counter
li $s1, 1  #arr1 pointer
li $s2, 1  #arr2 pointer
li $s3, 1  #one
li $s4, 16
li $s5,0

la $t0, arr1
la $t1, arr2

loop:

    lw $t2, 0($t0)

    add $t3, $t2, $s3

    beq $t3, $s5, even
        # if odd
        addi $t4, $t2, -1
        j endIF
    even:
        #if even
        addi $t4, $t2, 1
    endIF:

    sw $t4, 0($t1)

    addi $t0, $t0, 4
    addi $t1, $t1, 4
    addi $s0, $s0, 1

blt $s0, $s4, loop

li $s0, 1
la $t0, arr2

loop1:

    lw $t1, 0($t0)

    li $v0, 1
    move $a0, $t1
    syscall

    li $v0, 4
    la $a0, endl
    syscall

    addi $t0, $t0, 4
    addi $s0, $s0, 1

blt $s0, $s4, loop1

li $v0, 10
syscall