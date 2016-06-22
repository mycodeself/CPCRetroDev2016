                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.5.5 #9498 (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module psychics
                              6 	.optsdcc -mz80
                              7 	
                              8 ;--------------------------------------------------------
                              9 ; Public variables in this module
                             10 ;--------------------------------------------------------
                             11 	.globl _sqrtf
                             12 	.globl _powf
                             13 	.globl _EuclideanDistance
                             14 	.globl _AABB_BoxCollision
                             15 ;--------------------------------------------------------
                             16 ; special function registers
                             17 ;--------------------------------------------------------
                             18 ;--------------------------------------------------------
                             19 ; ram data
                             20 ;--------------------------------------------------------
                             21 	.area _DATA
                             22 ;--------------------------------------------------------
                             23 ; ram data
                             24 ;--------------------------------------------------------
                             25 	.area _INITIALIZED
                             26 ;--------------------------------------------------------
                             27 ; absolute external ram data
                             28 ;--------------------------------------------------------
                             29 	.area _DABS (ABS)
                             30 ;--------------------------------------------------------
                             31 ; global & static initialisations
                             32 ;--------------------------------------------------------
                             33 	.area _HOME
                             34 	.area _GSINIT
                             35 	.area _GSFINAL
                             36 	.area _GSINIT
                             37 ;--------------------------------------------------------
                             38 ; Home
                             39 ;--------------------------------------------------------
                             40 	.area _HOME
                             41 	.area _HOME
                             42 ;--------------------------------------------------------
                             43 ; code
                             44 ;--------------------------------------------------------
                             45 	.area _CODE
                             46 ;src/psychics.c:3: f32 EuclideanDistance(const Vector2D *a, const Vector2D *b)
                             47 ;	---------------------------------
                             48 ; Function EuclideanDistance
                             49 ; ---------------------------------
   4000                      50 _EuclideanDistance::
   4000 DD E5         [15]   51 	push	ix
   4002 DD 21 00 00   [14]   52 	ld	ix,#0
   4006 DD 39         [15]   53 	add	ix,sp
   4008 21 F8 FF      [10]   54 	ld	hl,#-8
   400B 39            [11]   55 	add	hl,sp
   400C F9            [ 6]   56 	ld	sp,hl
                             57 ;src/psychics.c:5: return sqrtf(powf(a->x - b->x, 2)+powf(a->y - b->y, 2));;
   400D DD 7E 04      [19]   58 	ld	a,4 (ix)
   4010 DD 77 FC      [19]   59 	ld	-4 (ix),a
   4013 DD 7E 05      [19]   60 	ld	a,5 (ix)
   4016 DD 77 FD      [19]   61 	ld	-3 (ix),a
   4019 DD 6E FC      [19]   62 	ld	l,-4 (ix)
   401C DD 66 FD      [19]   63 	ld	h,-3 (ix)
   401F 4E            [ 7]   64 	ld	c,(hl)
   4020 23            [ 6]   65 	inc	hl
   4021 46            [ 7]   66 	ld	b,(hl)
   4022 DD 7E 06      [19]   67 	ld	a,6 (ix)
   4025 DD 77 FE      [19]   68 	ld	-2 (ix),a
   4028 DD 7E 07      [19]   69 	ld	a,7 (ix)
   402B DD 77 FF      [19]   70 	ld	-1 (ix),a
   402E DD 6E FE      [19]   71 	ld	l,-2 (ix)
   4031 DD 66 FF      [19]   72 	ld	h,-1 (ix)
   4034 5E            [ 7]   73 	ld	e,(hl)
   4035 23            [ 6]   74 	inc	hl
   4036 56            [ 7]   75 	ld	d,(hl)
   4037 79            [ 4]   76 	ld	a,c
   4038 93            [ 4]   77 	sub	a, e
   4039 4F            [ 4]   78 	ld	c,a
   403A 78            [ 4]   79 	ld	a,b
   403B 9A            [ 4]   80 	sbc	a, d
   403C 47            [ 4]   81 	ld	b,a
   403D C5            [11]   82 	push	bc
   403E CD 90 52      [17]   83 	call	___sint2fs
   4041 F1            [10]   84 	pop	af
   4042 4D            [ 4]   85 	ld	c,l
   4043 44            [ 4]   86 	ld	b,h
   4044 21 00 40      [10]   87 	ld	hl,#0x4000
   4047 E5            [11]   88 	push	hl
   4048 21 00 00      [10]   89 	ld	hl,#0x0000
   404B E5            [11]   90 	push	hl
   404C D5            [11]   91 	push	de
   404D C5            [11]   92 	push	bc
   404E CD D7 43      [17]   93 	call	_powf
   4051 F1            [10]   94 	pop	af
   4052 F1            [10]   95 	pop	af
   4053 F1            [10]   96 	pop	af
   4054 F1            [10]   97 	pop	af
   4055 DD 72 FB      [19]   98 	ld	-5 (ix),d
   4058 DD 73 FA      [19]   99 	ld	-6 (ix),e
   405B DD 74 F9      [19]  100 	ld	-7 (ix),h
   405E DD 75 F8      [19]  101 	ld	-8 (ix),l
   4061 DD 6E FC      [19]  102 	ld	l,-4 (ix)
   4064 DD 66 FD      [19]  103 	ld	h,-3 (ix)
   4067 23            [ 6]  104 	inc	hl
   4068 23            [ 6]  105 	inc	hl
   4069 4E            [ 7]  106 	ld	c,(hl)
   406A 23            [ 6]  107 	inc	hl
   406B 46            [ 7]  108 	ld	b,(hl)
   406C DD 6E FE      [19]  109 	ld	l,-2 (ix)
   406F DD 66 FF      [19]  110 	ld	h,-1 (ix)
   4072 23            [ 6]  111 	inc	hl
   4073 23            [ 6]  112 	inc	hl
   4074 5E            [ 7]  113 	ld	e,(hl)
   4075 23            [ 6]  114 	inc	hl
   4076 56            [ 7]  115 	ld	d,(hl)
   4077 79            [ 4]  116 	ld	a,c
   4078 93            [ 4]  117 	sub	a, e
   4079 4F            [ 4]  118 	ld	c,a
   407A 78            [ 4]  119 	ld	a,b
   407B 9A            [ 4]  120 	sbc	a, d
   407C 47            [ 4]  121 	ld	b,a
   407D C5            [11]  122 	push	bc
   407E CD 90 52      [17]  123 	call	___sint2fs
   4081 F1            [10]  124 	pop	af
   4082 4D            [ 4]  125 	ld	c,l
   4083 44            [ 4]  126 	ld	b,h
   4084 21 00 40      [10]  127 	ld	hl,#0x4000
   4087 E5            [11]  128 	push	hl
   4088 21 00 00      [10]  129 	ld	hl,#0x0000
   408B E5            [11]  130 	push	hl
   408C D5            [11]  131 	push	de
   408D C5            [11]  132 	push	bc
   408E CD D7 43      [17]  133 	call	_powf
   4091 F1            [10]  134 	pop	af
   4092 F1            [10]  135 	pop	af
   4093 F1            [10]  136 	pop	af
   4094 F1            [10]  137 	pop	af
   4095 EB            [ 4]  138 	ex	de, hl
   4096 E5            [11]  139 	push	hl
   4097 D5            [11]  140 	push	de
   4098 DD 6E FA      [19]  141 	ld	l,-6 (ix)
   409B DD 66 FB      [19]  142 	ld	h,-5 (ix)
   409E E5            [11]  143 	push	hl
   409F DD 6E F8      [19]  144 	ld	l,-8 (ix)
   40A2 DD 66 F9      [19]  145 	ld	h,-7 (ix)
   40A5 E5            [11]  146 	push	hl
   40A6 CD 3F 4E      [17]  147 	call	___fsadd
   40A9 F1            [10]  148 	pop	af
   40AA F1            [10]  149 	pop	af
   40AB F1            [10]  150 	pop	af
   40AC F1            [10]  151 	pop	af
   40AD D5            [11]  152 	push	de
   40AE E5            [11]  153 	push	hl
   40AF CD B2 41      [17]  154 	call	_sqrtf
   40B2 DD F9         [10]  155 	ld	sp,ix
   40B4 DD E1         [14]  156 	pop	ix
   40B6 C9            [10]  157 	ret
                            158 ;src/psychics.c:13: u8 AABB_BoxCollision(const Box *a, const Box *b)
                            159 ;	---------------------------------
                            160 ; Function AABB_BoxCollision
                            161 ; ---------------------------------
   40B7                     162 _AABB_BoxCollision::
   40B7 DD E5         [15]  163 	push	ix
   40B9 DD 21 00 00   [14]  164 	ld	ix,#0
   40BD DD 39         [15]  165 	add	ix,sp
                            166 ;src/psychics.c:15: if(a->max.x < b->min.x || a->min.x > b->max.x)
   40BF DD 4E 04      [19]  167 	ld	c,4 (ix)
   40C2 DD 46 05      [19]  168 	ld	b,5 (ix)
   40C5 69            [ 4]  169 	ld	l, c
   40C6 60            [ 4]  170 	ld	h, b
   40C7 11 04 00      [10]  171 	ld	de, #0x0004
   40CA 19            [11]  172 	add	hl, de
   40CB 5E            [ 7]  173 	ld	e,(hl)
   40CC 23            [ 6]  174 	inc	hl
   40CD 56            [ 7]  175 	ld	d,(hl)
   40CE E5            [11]  176 	push	hl
   40CF DD 6E 06      [19]  177 	ld	l,6 (ix)
   40D2 DD 66 07      [19]  178 	ld	h,7 (ix)
   40D5 E5            [11]  179 	push	hl
   40D6 FD E1         [14]  180 	pop	iy
   40D8 E1            [10]  181 	pop	hl
   40D9 FD 6E 00      [19]  182 	ld	l,0 (iy)
   40DC FD 66 01      [19]  183 	ld	h,1 (iy)
   40DF 7B            [ 4]  184 	ld	a,e
   40E0 95            [ 4]  185 	sub	a, l
   40E1 7A            [ 4]  186 	ld	a,d
   40E2 9C            [ 4]  187 	sbc	a, h
   40E3 E2 E8 40      [10]  188 	jp	PO, 00117$
   40E6 EE 80         [ 7]  189 	xor	a, #0x80
   40E8                     190 00117$:
   40E8 FA 05 41      [10]  191 	jp	M,00101$
   40EB 69            [ 4]  192 	ld	l, c
   40EC 60            [ 4]  193 	ld	h, b
   40ED 5E            [ 7]  194 	ld	e,(hl)
   40EE 23            [ 6]  195 	inc	hl
   40EF 56            [ 7]  196 	ld	d,(hl)
   40F0 FD E5         [15]  197 	push	iy
   40F2 E1            [10]  198 	pop	hl
   40F3 23            [ 6]  199 	inc	hl
   40F4 23            [ 6]  200 	inc	hl
   40F5 23            [ 6]  201 	inc	hl
   40F6 23            [ 6]  202 	inc	hl
   40F7 7E            [ 7]  203 	ld	a, (hl)
   40F8 23            [ 6]  204 	inc	hl
   40F9 66            [ 7]  205 	ld	h,(hl)
   40FA 93            [ 4]  206 	sub	a, e
   40FB 7C            [ 4]  207 	ld	a,h
   40FC 9A            [ 4]  208 	sbc	a, d
   40FD E2 02 41      [10]  209 	jp	PO, 00118$
   4100 EE 80         [ 7]  210 	xor	a, #0x80
   4102                     211 00118$:
   4102 F2 09 41      [10]  212 	jp	P,00102$
   4105                     213 00101$:
                            214 ;src/psychics.c:16: return 0;
   4105 2E 00         [ 7]  215 	ld	l,#0x00
   4107 18 41         [12]  216 	jr	00107$
   4109                     217 00102$:
                            218 ;src/psychics.c:17: if(a->max.y < b->min.y || a->min.y > b->max.y)
   4109 69            [ 4]  219 	ld	l, c
   410A 60            [ 4]  220 	ld	h, b
   410B 11 06 00      [10]  221 	ld	de, #0x0006
   410E 19            [11]  222 	add	hl, de
   410F 5E            [ 7]  223 	ld	e,(hl)
   4110 23            [ 6]  224 	inc	hl
   4111 56            [ 7]  225 	ld	d,(hl)
   4112 FD E5         [15]  226 	push	iy
   4114 E1            [10]  227 	pop	hl
   4115 23            [ 6]  228 	inc	hl
   4116 23            [ 6]  229 	inc	hl
   4117 7E            [ 7]  230 	ld	a, (hl)
   4118 23            [ 6]  231 	inc	hl
   4119 66            [ 7]  232 	ld	h,(hl)
   411A 6F            [ 4]  233 	ld	l,a
   411B 7B            [ 4]  234 	ld	a,e
   411C 95            [ 4]  235 	sub	a, l
   411D 7A            [ 4]  236 	ld	a,d
   411E 9C            [ 4]  237 	sbc	a, h
   411F E2 24 41      [10]  238 	jp	PO, 00119$
   4122 EE 80         [ 7]  239 	xor	a, #0x80
   4124                     240 00119$:
   4124 FA 44 41      [10]  241 	jp	M,00104$
   4127 69            [ 4]  242 	ld	l, c
   4128 60            [ 4]  243 	ld	h, b
   4129 23            [ 6]  244 	inc	hl
   412A 23            [ 6]  245 	inc	hl
   412B 4E            [ 7]  246 	ld	c,(hl)
   412C 23            [ 6]  247 	inc	hl
   412D 46            [ 7]  248 	ld	b,(hl)
   412E FD E5         [15]  249 	push	iy
   4130 E1            [10]  250 	pop	hl
   4131 11 06 00      [10]  251 	ld	de, #0x0006
   4134 19            [11]  252 	add	hl, de
   4135 5E            [ 7]  253 	ld	e,(hl)
   4136 23            [ 6]  254 	inc	hl
   4137 56            [ 7]  255 	ld	d,(hl)
   4138 7B            [ 4]  256 	ld	a,e
   4139 91            [ 4]  257 	sub	a, c
   413A 7A            [ 4]  258 	ld	a,d
   413B 98            [ 4]  259 	sbc	a, b
   413C E2 41 41      [10]  260 	jp	PO, 00120$
   413F EE 80         [ 7]  261 	xor	a, #0x80
   4141                     262 00120$:
   4141 F2 48 41      [10]  263 	jp	P,00105$
   4144                     264 00104$:
                            265 ;src/psychics.c:18: return 0;
   4144 2E 00         [ 7]  266 	ld	l,#0x00
   4146 18 02         [12]  267 	jr	00107$
   4148                     268 00105$:
                            269 ;src/psychics.c:19: return 1;
   4148 2E 01         [ 7]  270 	ld	l,#0x01
   414A                     271 00107$:
   414A DD E1         [14]  272 	pop	ix
   414C C9            [10]  273 	ret
                            274 	.area _CODE
                            275 	.area _INITIALIZER
                            276 	.area _CABS (ABS)
