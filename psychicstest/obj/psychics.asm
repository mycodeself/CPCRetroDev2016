;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.5.5 #9498 (Linux)
;--------------------------------------------------------
	.module psychics
	.optsdcc -mz80
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _sqrtf
	.globl _powf
	.globl _EuclideanDistance
	.globl _AABB_BoxCollision
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _DATA
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area _INITIALIZED
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area _DABS (ABS)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area _HOME
	.area _GSINIT
	.area _GSFINAL
	.area _GSINIT
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area _HOME
	.area _HOME
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area _CODE
;src/psychics.c:3: f32 EuclideanDistance(const Vector2D *a, const Vector2D *b)
;	---------------------------------
; Function EuclideanDistance
; ---------------------------------
_EuclideanDistance::
	push	ix
	ld	ix,#0
	add	ix,sp
	ld	hl,#-8
	add	hl,sp
	ld	sp,hl
;src/psychics.c:5: return sqrtf(powf(a->x - b->x, 2)+powf(a->y - b->y, 2));;
	ld	a,4 (ix)
	ld	-4 (ix),a
	ld	a,5 (ix)
	ld	-3 (ix),a
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
	ld	a,6 (ix)
	ld	-2 (ix),a
	ld	a,7 (ix)
	ld	-1 (ix),a
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	a,c
	sub	a, e
	ld	c,a
	ld	a,b
	sbc	a, d
	ld	b,a
	push	bc
	call	___sint2fs
	pop	af
	ld	c,l
	ld	b,h
	ld	hl,#0x4000
	push	hl
	ld	hl,#0x0000
	push	hl
	push	de
	push	bc
	call	_powf
	pop	af
	pop	af
	pop	af
	pop	af
	ld	-5 (ix),d
	ld	-6 (ix),e
	ld	-7 (ix),h
	ld	-8 (ix),l
	ld	l,-4 (ix)
	ld	h,-3 (ix)
	inc	hl
	inc	hl
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
	ld	l,-2 (ix)
	ld	h,-1 (ix)
	inc	hl
	inc	hl
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	a,c
	sub	a, e
	ld	c,a
	ld	a,b
	sbc	a, d
	ld	b,a
	push	bc
	call	___sint2fs
	pop	af
	ld	c,l
	ld	b,h
	ld	hl,#0x4000
	push	hl
	ld	hl,#0x0000
	push	hl
	push	de
	push	bc
	call	_powf
	pop	af
	pop	af
	pop	af
	pop	af
	ex	de, hl
	push	hl
	push	de
	ld	l,-6 (ix)
	ld	h,-5 (ix)
	push	hl
	ld	l,-8 (ix)
	ld	h,-7 (ix)
	push	hl
	call	___fsadd
	pop	af
	pop	af
	pop	af
	pop	af
	push	de
	push	hl
	call	_sqrtf
	ld	sp,ix
	pop	ix
	ret
;src/psychics.c:13: u8 AABB_BoxCollision(const Box *a, const Box *b)
;	---------------------------------
; Function AABB_BoxCollision
; ---------------------------------
_AABB_BoxCollision::
	push	ix
	ld	ix,#0
	add	ix,sp
;src/psychics.c:15: if(a->max.x < b->min.x || a->min.x > b->max.x)
	ld	c,4 (ix)
	ld	b,5 (ix)
	ld	l, c
	ld	h, b
	ld	de, #0x0004
	add	hl, de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	push	hl
	ld	l,6 (ix)
	ld	h,7 (ix)
	push	hl
	pop	iy
	pop	hl
	ld	l,0 (iy)
	ld	h,1 (iy)
	ld	a,e
	sub	a, l
	ld	a,d
	sbc	a, h
	jp	PO, 00117$
	xor	a, #0x80
00117$:
	jp	M,00101$
	ld	l, c
	ld	h, b
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	push	iy
	pop	hl
	inc	hl
	inc	hl
	inc	hl
	inc	hl
	ld	a, (hl)
	inc	hl
	ld	h,(hl)
	sub	a, e
	ld	a,h
	sbc	a, d
	jp	PO, 00118$
	xor	a, #0x80
00118$:
	jp	P,00102$
00101$:
;src/psychics.c:16: return 0;
	ld	l,#0x00
	jr	00107$
00102$:
;src/psychics.c:17: if(a->max.y < b->min.y || a->min.y > b->max.y)
	ld	l, c
	ld	h, b
	ld	de, #0x0006
	add	hl, de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	push	iy
	pop	hl
	inc	hl
	inc	hl
	ld	a, (hl)
	inc	hl
	ld	h,(hl)
	ld	l,a
	ld	a,e
	sub	a, l
	ld	a,d
	sbc	a, h
	jp	PO, 00119$
	xor	a, #0x80
00119$:
	jp	M,00104$
	ld	l, c
	ld	h, b
	inc	hl
	inc	hl
	ld	c,(hl)
	inc	hl
	ld	b,(hl)
	push	iy
	pop	hl
	ld	de, #0x0006
	add	hl, de
	ld	e,(hl)
	inc	hl
	ld	d,(hl)
	ld	a,e
	sub	a, c
	ld	a,d
	sbc	a, b
	jp	PO, 00120$
	xor	a, #0x80
00120$:
	jp	P,00105$
00104$:
;src/psychics.c:18: return 0;
	ld	l,#0x00
	jr	00107$
00105$:
;src/psychics.c:19: return 1;
	ld	l,#0x01
00107$:
	pop	ix
	ret
	.area _CODE
	.area _INITIALIZER
	.area _CABS (ABS)
