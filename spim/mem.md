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

```asm
li $v0, 1
move $a0, $t3
syscall
```

## Getting input form the user as a integer

```asm
li $v0, 5
syscall
move $t3, $v0
```

## Getting input as a text form a user

```asm
.data
underInput: .space 20

.text
li $v0, 4
la $a0, userInput
li $a1, 20
syscall
```

after syscall the text can be loaded from `userInput` by using `la` instruction
