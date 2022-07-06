## Printing text in console

```asm
.data
prompt: .asciiz "Enter an integer :"

.text
li $v0, 4
la $a0, prompt
syscall
```

## Printing a number in console

```
li $v0, 1
move $a0, $t3
syscall
```

## Getting input form the useer

```
li $v0, 5
syscall
move $t3, $v0
```
