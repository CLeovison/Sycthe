	.file	"strings.c"
	.intel_syntax noprefix
	.text
	.globl	string_init
	.def	string_init;	.scl	2;	.type	32;	.endef
	.seh_proc	string_init
string_init:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	cmp	QWORD PTR 16[rbp], 0
	je	.L4
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR [rax], 0
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR 8[rax], 0
	jmp	.L1
.L4:
	nop
.L1:
	pop	rbp
	ret
	.seh_endproc
	.globl	string_create
	.def	string_create;	.scl	2;	.type	32;	.endef
	.seh_proc	string_create
string_create:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 64
	.seh_stackalloc	64
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	lea	rax, -32[rbp]
	mov	rcx, rax
	call	string_init
	cmp	QWORD PTR 24[rbp], 0
	jne	.L6
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L9
.L6:
	mov	rax, QWORD PTR 24[rbp]
	mov	rcx, rax
	call	strlen
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	add	rax, 1
	mov	rcx, rax
	call	malloc
	mov	QWORD PTR -16[rbp], rax
	cmp	QWORD PTR -16[rbp], 0
	jne	.L8
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L9
.L8:
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, 1[rax]
	mov	rdx, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR -16[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	memcpy
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR -24[rbp], rax
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
.L9:
	mov	rax, QWORD PTR 16[rbp]
	add	rsp, 64
	pop	rbp
	ret
	.seh_endproc
	.globl	string_append
	.def	string_append;	.scl	2;	.type	32;	.endef
	.seh_proc	string_append
string_append:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 80
	.seh_stackalloc	80
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	mov	QWORD PTR 32[rbp], r8
	lea	rax, -48[rbp]
	mov	rcx, rax
	call	string_init
	cmp	QWORD PTR 24[rbp], 0
	je	.L11
	cmp	QWORD PTR 32[rbp], 0
	jne	.L12
.L11:
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -48[rbp]
	mov	rdx, QWORD PTR -40[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L15
.L12:
	mov	rax, QWORD PTR 24[rbp]
	mov	rcx, rax
	call	strlen
	mov	QWORD PTR -8[rbp], rax
	mov	rax, QWORD PTR 32[rbp]
	mov	rcx, rax
	call	strlen
	mov	QWORD PTR -16[rbp], rax
	mov	rdx, QWORD PTR -8[rbp]
	mov	rax, QWORD PTR -16[rbp]
	add	rax, rdx
	mov	QWORD PTR -24[rbp], rax
	mov	rax, QWORD PTR -24[rbp]
	add	rax, 1
	mov	rcx, rax
	call	malloc
	mov	QWORD PTR -32[rbp], rax
	cmp	QWORD PTR -32[rbp], 0
	jne	.L14
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -48[rbp]
	mov	rdx, QWORD PTR -40[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L15
.L14:
	mov	rcx, QWORD PTR -8[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR -32[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	memcpy
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -8[rbp]
	lea	rcx, [rdx+rax]
	mov	rdx, QWORD PTR -16[rbp]
	mov	rax, QWORD PTR 32[rbp]
	mov	r8, rdx
	mov	rdx, rax
	call	memcpy
	mov	rdx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -24[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR -40[rbp], rax
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -48[rbp]
	mov	rdx, QWORD PTR -40[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
.L15:
	mov	rax, QWORD PTR 16[rbp]
	add	rsp, 80
	pop	rbp
	ret
	.seh_endproc
	.globl	string_trim
	.def	string_trim;	.scl	2;	.type	32;	.endef
	.seh_proc	string_trim
string_trim:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 96
	.seh_stackalloc	96
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	QWORD PTR 24[rbp], rdx
	lea	rax, -64[rbp]
	mov	rcx, rax
	call	string_init
	cmp	QWORD PTR 24[rbp], 0
	jne	.L17
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -64[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L26
.L17:
	mov	rax, QWORD PTR 24[rbp]
	mov	rcx, rax
	call	strlen
	mov	QWORD PTR -24[rbp], rax
	mov	QWORD PTR -8[rbp], 0
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR -16[rbp], rax
	jmp	.L19
.L21:
	add	QWORD PTR -8[rbp], 1
.L19:
	mov	rax, QWORD PTR -8[rbp]
	cmp	rax, QWORD PTR -16[rbp]
	jnb	.L22
	mov	rdx, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR -8[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movzx	eax, al
	mov	ecx, eax
	mov	rax, QWORD PTR __imp_isspace[rip]
	call	rax
	test	eax, eax
	jne	.L21
	jmp	.L22
.L24:
	sub	QWORD PTR -16[rbp], 1
.L22:
	mov	rax, QWORD PTR -16[rbp]
	cmp	QWORD PTR -8[rbp], rax
	jnb	.L23
	mov	rax, QWORD PTR -16[rbp]
	lea	rdx, -1[rax]
	mov	rax, QWORD PTR 24[rbp]
	add	rax, rdx
	movzx	eax, BYTE PTR [rax]
	movzx	eax, al
	mov	ecx, eax
	mov	rax, QWORD PTR __imp_isspace[rip]
	call	rax
	test	eax, eax
	jne	.L24
.L23:
	mov	rax, QWORD PTR -16[rbp]
	sub	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	rax, QWORD PTR -32[rbp]
	add	rax, 1
	mov	rcx, rax
	call	malloc
	mov	QWORD PTR -40[rbp], rax
	cmp	QWORD PTR -40[rbp], 0
	jne	.L25
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -64[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	jmp	.L26
.L25:
	mov	rdx, QWORD PTR 24[rbp]
	mov	rax, QWORD PTR -8[rbp]
	add	rdx, rax
	mov	rcx, QWORD PTR -32[rbp]
	mov	rax, QWORD PTR -40[rbp]
	mov	r8, rcx
	mov	rcx, rax
	call	memcpy
	mov	rdx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR -32[rbp]
	add	rax, rdx
	mov	BYTE PTR [rax], 0
	mov	rax, QWORD PTR -40[rbp]
	mov	QWORD PTR -64[rbp], rax
	mov	rax, QWORD PTR -32[rbp]
	mov	QWORD PTR -56[rbp], rax
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR -64[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
.L26:
	mov	rax, QWORD PTR 16[rbp]
	add	rsp, 96
	pop	rbp
	ret
	.seh_endproc
	.ident	"GCC: (Rev2, Built by MSYS2 project) 14.2.0"
	.def	strlen;	.scl	2;	.type	32;	.endef
	.def	malloc;	.scl	2;	.type	32;	.endef
	.def	memcpy;	.scl	2;	.type	32;	.endef
