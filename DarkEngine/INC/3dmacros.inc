;
; $Source: t:/prj/tech/libsrc/3d/rcs/3dmacros.inc $
; $Revision: 1.24 $
; $Author: JAEMZ $
; $Date: 1995/09/29 17:56:41 $
;
; 3D Object interpreter opcodes
;
 

ifdef dbg_on
_itrp_dbg equ 1
endif

	enum	0,OP_EOF	;eof is zero!
enum2	OP_JNORM
	enum2	OP_LNRES
	enum2	OP_MULTIRES
	enum2	OP_POLYRES
	enum2	OP_SETCOLOR
	enum2	OP_SORTNORM
	enum2	OP_DEBUG
	enum2	OP_SETSHADE
	enum2	OP_GOURSURF
	enum2	OP_X_REL
	enum2	OP_Y_REL
	enum2	OP_Z_REL
	enum2	OP_XY_REL
	enum2	OP_XZ_REL
	enum2	OP_YZ_REL
	enum2	OP_ICALL_P
	enum2	OP_ICALL_B
	enum2	OP_ICALL_H
	enum2	OP_
	enum2	OP_SFCAL
	enum2	OP_DEFRES
	enum2	OP_DEFRES_I
	enum2	OP_GETPARMS
	enum2	OP_GETPARMS_I
	enum2	OP_GOUR_P
	enum2	OP_GOUR_VC
        enum2   OP_V_COLOR
        enum2   OP_VS_COLOR
        enum2   OP_RGBSHADES
        enum2   OP_DRAW_MODE
        enum2   OP_P_COLOR
        enum2   OP_PS_COLOR
        enum2   OP_SCALERES
        enum2   OP_VPNT_P
        enum2   OP_VPNT_V
        enum2   OP_SETUV
        enum2   OP_UVLIST
        enum2   OP_TMAP
        enum2   OP_DBG
        enum2   OP_AXLE_ROT
        enum2   OP_AXLE_SLIDE
        enum2   OP_VCALL
        enum2   OP_WIRE
        enum2   OP_VHOT
        enum2   OP_VLIGHT
        enum2   OP_FT_CLUT
        enum2   OP_FT_NORM
        enum2   OP_SETGOUR
        enum2   OP_SETLTYPE
        enum2   OP_LJNORM
        ; new stuff
        enum2   OP_GEN_NORM
        enum2   OP_VLIGHT_RES

DBG_POLY_ID  equ 1
DBG_POLY_MAX equ 2

ILT_NONE        equ 0
ILT_FLAT        equ 1
ILT_GOURAUD     equ 2

defobj	macro	scalef,xsize,ysize,zsize,radius,sort_offset,ret_dist
	dw	scalef
	endm

rp	macro	points:vararg
	for	pnt,<points>
	 dw	pnt
	endm
	endm

pt	macro	x,y,z
	dd	(x),(y),(z)
	endm

debug	macro
	dw	OP_DEBUG
	endm

eof	macro
	dw	OP_EOF
	endm

jnorm	macro	lbl,nx,ny,nz,px,py,pz
	local	zlbl
zlbl:
	dw	OP_JNORM,lbl-zlbl
	dd	nx,ny,nz,(px),(py),(pz)
	endm

; lit normal
ljnorm	macro	lbl,nx,ny,nz,px,py,pz
	local	zlbl
zlbl:
	dw	OP_LJNORM,lbl-zlbl
	dd	nx,ny,nz,(px),(py),(pz)
	endm


lnres	macro	p1,p2
	dw	OP_LNRES	;,p1*8,p2*8
	 rp	p1,p2
	endm

multires	macro	start,n
	dw	OP_MULTIRES,n	;,start*8
	 rp	start
	endm

scaleres	macro	start,n,scale_f
	dw	OP_SCALERES,n,scale_f
	 rp	start
	endm

polygon	macro	points:vararg
	local	n
	n = @ArgCount(points)
	if	n lt 3
	 .err	<Polygon must have at least 3 Points>
	endif
	polyres	n,points
	endm

polyres	macro	npts,points:vararg
	dw	OP_POLYRES,npts
	 rp	points
	endm

draw_mode       macro   poly_type, check, wire
        dw      OP_DRAW_MODE
        dw      ((poly_type SHL 5) OR (check SHL 7) OR (wire SHL 8))
        endm

it_dbg  macro   lbl,dbg_code,dbg_data
	local	dlbl
dlbl:
        dw      OP_DBG
        if     (opattr(lbl)) and 001h
        dw      lbl-dlbl
        else
;; get over ourselves, at it were
        dw      lbl+8           
        endif
        dw      dbg_code,dbg_data
        endm

setcolor	macro	colornum
	dw	OP_SETCOLOR,colornum
	endm

quad	macro	r1,r2,r3,r4
	ifb	<r4>
	.err    <Quad must have 4 points>
	endif
	polyres	4,r1,r2,r3,r4
	endm

triang	macro	r1,r2,r3
	ifb	<r3>
	.err	<Triang must have 3 points>
	endif
	polyres	3,r1,r2,r3
	endm

sortnorm	macro	nx,ny,nz,px,py,pz,rtn0,rtn1
	local	lbl1
lbl1:
	dw	OP_SORTNORM
	dd	nx,ny,nz,(px),(py),(pz)
	dd	rtn0-lbl1,rtn1-lbl1
	endm

setshade	macro	n
	if	n ne 0
	 dw	OP_SETSHADE,n
	endif
	endm

shade	macro	r,c
	rp	r
	dw	c SHL 8	;make sfix
	endm

rgbshades	macro	n
	if	n ne 0
	 dw	OP_RGBSHADES,n
	endif
	endm

rgb_set	macro	ptnum,r,g,b
	rp	ptnum
        dd      ((r SHL 2) OR (g SHL 13) OR (b SHL 24))
        endm


; these gour thingees are history, I'm rewriting it, -Jaemz
        ; WHY DO THESE BOTH HAVE IGNORE SHADE! WHAT ARE WE, STUPID
; gouraud shade next polygon
goursurf	macro	colbase,shade	;ignore shade!
	dw	OP_GOURSURF,colbase
	endm

;same as goursurf, but get color base from a variable
goursurfv	macro	colvar,shade	;ignore shade!
	dw	OP_GOUR_P,colvar
	endm

gour_p	macro	colvar
	dw	OP_GOUR_P,colvar
	endm

gour_vc	macro	colvar
	dw	OP_GOUR_VC,colvar
	endm


;virtual color table accessors
vcolor  macro   vcolnum, shade
        ifb     <shade>
        dw      OP_V_COLOR,vcolnum
        else
        dw      OP_VS_COLOR,vcolnum,shade
        endif
        endm

;colors as parameters
pcolor  macro   pvar,shade
        ifb     <shade>
        dw      OP_P_COLOR,pvar
        else
        dw      OP_PS_COLOR,pvar,shade
        endif
        endm

vpnt_p  macro   dest,p_idx
        dw      OP_VPNT_P,p_idx,dest
        endm

vpnt_v  macro   dest,v_pnt
        dw      OP_VPNT_V,v_pnt,dest
        endm

x_rel	macro	dst,src,dx
	dw	OP_X_REL
	rp	dst,src
	dd	(dx)
	endm

y_rel	macro	dst,src,dy
	dw	OP_Y_REL
	rp	dst,src
	dd	(dy)
	endm

z_rel	macro	dst,src,dz
	dw	OP_Z_REL
	rp	dst,src
	dd	(dz)
	endm

xy_rel	macro	dst,src,dx,dy
	dw	OP_XY_REL
	rp	dst,src
	dd	(dx),(dy)
	endm

xz_rel	macro	dst,src,dx,dz
	dw	OP_XZ_REL
	rp	dst,src
	dd	(dx),(dz)
	endm

yz_rel	macro	dst,src,dy,dz
	dw	OP_YZ_REL
	rp	dst,src
	dd	(dy),(dz)
	endm

defres	macro	dest,x,y,z,i
	ifb	<i>
	 dw	OP_DEFRES
	 rp	dest
	 pt	x,y,z
	else
	 dw	OP_DEFRES_I
	 rp	dest
	 pt	x,y,z
	 dw	i SHL 8	;make sfix
	endif
	endm

icall_h	macro	subobj,ox,oy,oz,var_num
	dw	OP_ICALL_H
	dd	subobj
	dd	(ox),(oy),(oz)
	dw	var_num
	endm

icall_p	macro	subobj,ox,oy,oz,var_num,m0,m1,m2,m3,m4,m5,m6,m7,m8
	dw	OP_ICALL_P
	dd	subobj
	dd	(ox),(oy),(oz)
	dw	var_num
	endm

icall_b	macro	subobj,ox,oy,oz,var_num
	dw	OP_ICALL_B
	dd	subobj
	dd	(ox),(oy),(oz)
	dw	var_num
	endm

axle_rot      macro	varnum,ox,oy,oz,m0,m1,m2,m3,m4,m5,m6,m7,m8
	dw	OP_AXLE_ROT ;2
	dw	varnum     ; 4
	dd	(ox),(oy),(oz)
        ; 16, note transpose, cause that's the way it is, get a real 3d
        dd      m0,m3,m6
        dd      m1,m4,m7
        dd      m2,m5,m8
        ; 52
	endm

axle_slide      macro	varnum,ox,oy,oz,m0,m1,m2,m3,m4,m5,m6,m7,m8
	dw	OP_AXLE_SLIDE ;2
	dw	varnum     ; 4
	dd	(ox),(oy),(oz)
        ; 28
        dd      m0,m3,m6
        dd      m1,m4,m7
        dd      m2,m5,m8
        ; 64
	endm

wire_poly            macro	points:vararg
	local	n
	n = @ArgCount(points)
	if	n lt 3
	 .err	<Wire must have at least 3 Points>
	endif
        dw      OP_WIRE,n
         rp points
	endm


; NEW STUFF

vert_info macro op,points:vararg
        local   npts
        npts = @ArgCount(points) - 1
        dw op,npts
         rp points
        endm

gen_norm macro lbl,nx,ny,nz,px,py,pz
	local	zlbl
zlbl:
        dw      OP_GEN_NORM
	dw	lbl-zlbl
	dd	nx,ny,nz,(px),(py),(pz)
        endm

solid_pgon macro points:vararg
        vert_info 0,points
        endm

wire_pgon macro points:vararg
        vert_info 1,points
        endm

tmap_pgon macro points:vararg
        vert_info 2,points
        endm

uv_info  macro u,v
        dd u,v
        endm

vlight_info	macro	vnum,nx,ny,nz,px,py,pz
	dw	vnum
	dd	nx,ny,nz,(px),(py),(pz)
	endm

vlight_res	macro	
	dw	OP_VLIGHT_RES
	endm

vcall           macro   varnum,ox,oy,oz
        dw      OP_VCALL
        dw      varnum
        dd      (ox),(oy),(oz)
        endm

vhot            macro   varnum,ox,oy,oz
        dw      OP_VHOT
        dw      varnum
        dd      (ox),(oy),(oz)
        endm

vlight	macro	vnum,nx,ny,nz,px,py,pz
	dw	OP_VLIGHT,vnum
	dd	nx,ny,nz,(px),(py),(pz)
	endm

ft_clut macro
        dw      OP_FT_CLUT
        endm

ft_norm macro
        dw      OP_FT_NORM
        endm

; there, this is all the control we need
setgour         macro n
        dw      OP_SETGOUR
        db      n
        endm

setltype        macro n
        dw      OP_SETLTYPE
        db      n
        endm

sfcal	macro	lbl
	local	zlbl
zlbl:
	dw	OP_SFCAL,lbl-zlbl
	endm

;getparms	macro	dest_ofs,src_ofs,count
;	dw	OP_GETPARMS,dest_ofs,src_ofs,count
;	endm

;getparms_i	macro	dest_ofs,src_ptr_ofs,src_ofs,count
;	dw	OP_GETPARMS_I,dest_ofs,src_ptr_ofs,src_ofs,count
;	endm

setuv   macro   pt,u,v
        dw      OP_SETUV
        rp      pt
        dd      u,v
        endm

uvlist  macro   pt_cnt
	if	pt_cnt ne 0
         dw      OP_UVLIST, pt_cnt
	endif
        endm

map_uv  macro   pt,u,v
        rp      pt
        dd      u,v
        endm

tmap    macro   tmap_context,points:vararg
        local   n
        n=@ArgCount(points)
	if	n lt 3
	 .err	<Tmap must have at least 3 Points>
	endif
        dw      OP_TMAP, tmap_context, n
        rp      points
        endm

ifdef _itrp_dbg

tmap_dbg        macro   pgon_id,tmap_context,points:vararg
;        local   zlbl
;        dbg     zlbl,DBG_POLY_ID,pgon_id
        local   n
        n=@ArgCount(points)
        it_dbg  6+(n*2),DBG_POLY_ID,pgon_id
        tmap    tmap_context,points
;zlbl:   
        endm

quad_dbg	macro	pgon_id,r1,r2,r3,r4
;        local   zlbl
;        dbg     zlbl,DBG_POLY_ID,pgon_id
        it_dbg  4+(4*2),DBG_POLY_ID,pgon_id
        quad    r1,r2,r3,r4
;zlbl:   
        endm


triang_dbg	macro	pgon_id,r1,r2,r3
;        local   zlbl
;        dbg     zlbl,DBG_POLY_ID,pgon_id
        it_dbg  4+(3*2),DBG_POLY_ID,pgon_id
        triang  r1,r2,r3
;zlbl:   
        endm


polygon_dbg	macro	pgon_id,points:vararg
;        local   zlbl,harold
;harold:
;        dbg     harold,DBG_POLY_ID,pgon_id
;        dbg     zlbl,DBG_POLY_ID,pgon_id
        local   n
        n=@ArgCount(points)
        it_dbg  4+(2*n),DBG_POLY_ID,pgon_id
        polygon points
;zlbl:   
        endm

else

tmap_dbg        macro   pgon_id,tmap_context,points:vararg
        tmap    tmap_context,points
        endm

quad_dbg	macro	pgon_id,r1,r2,r3,r4
        quad    r1,r2,r3,r4
        endm

triang_dbg	macro	pgon_id,r1,r2,r3
        triang  r1,r2,r3
        endm

polygon_dbg	macro	pgon_id,points:vararg
        polygon points
        endm

endif

cavesurf        macro
        endm
vexsurf         macro
        endm

; stereo stuff
ifdef stereo_on

; sets the current canvas to the saved rt canvas bits
; trashes esi and ebx
set_rt_canv     macro
        mov ebx,_g3d_rt_canv_bits
        mov esi,grd_canvas
        mov GRS_CANVAS_BM+GRS_BITMAP_BITS[esi],ebx
        endm

; reverses the action of rt_canv
; trashes esi and ebx
set_lt_canv     macro
        mov ebx,_g3d_lt_canv_bits
        mov esi,grd_canvas
        mov GRS_CANVAS_BM+GRS_BITMAP_BITS[esi],ebx
        endm

; copies points in a list ecx long at esi to the temporary
; buffer and adds the requisite offset
; loading new address into esi
; destroys esi,eax,ecx,edi
move_to_stereo   macro
        local l1
        local already_projected
        dec     ecx;
        l1:
        mov     edi,[esi+ecx*4]                 ;copy point
        test    [edi].p3_flags,PF_PROJECTED
        jnz      already_projected              ;test for projection
        push    ecx
        call    g3_project_point
        pop     ecx
        already_projected:
        add     edi,_g3d_stereo_base
        mov     _g3d_stereo_tmp[ecx*4],edi
        dec     ecx
        jns     l1
        lea     esi,_g3d_stereo_tmp
        endm


;copies over a list and copies uv and rgb information
;eax=num of points,edx=address of points
;leaves address of  new list in edx
;modifies eax,ecx,edx,edi,esi
move_to_stereo_and_uvi  macro
        local l1
        local already_projected
        local continued
        lea     ecx,_g3d_stereo_tmp
        l1:
        mov     esi,[edx]       ;address of point in esi
        mov     edi,esi
        add     edi,_g3d_stereo_base     ;twin address in edi
        mov     [ecx],edi               ;put  address  in list
        test    [esi].p3_flags,PF_PROJECTED
        jnz     already_projected

        pushm   eax,edx,ecx
        mov     edi,esi
        call    g3_project_point
        popm    eax,edx,ecx
        jmp     continued

        already_projected:
        add     esi,21          ;go to u,v and i
        add     edi,21
        movsb                   ;copy p3_flags
        movsd                   ;copy uv
        movsw                   ;copy i
        continued:
        add     edx,4           ;increment source
        add     ecx,4           ;increment dest
        dec     eax
        jnz     l1
        lea     edx,_g3d_stereo_tmp
        endm

endif
