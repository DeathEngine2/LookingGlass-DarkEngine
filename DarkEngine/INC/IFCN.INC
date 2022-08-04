;
; $Source: r:/prj/lib/src/2d/rcs/ifcn.inc $
; $Revision: 1.1 $
; $Author: kevin $
; $Date: 1994/08/16 12:38:24 $
;
; Function type indices for table lookups.
;
; This file is part of the 2d library.
;


IFNDEF	_ifcn_inc
_ifcn_inc	EQU		1

   GRC_PIXEL                    equ 0
   GRC_LINE                     equ 0    ;same as GRC_PIXEL
   GRC_WIRE_POLY_LINE           equ 01
   GRC_DEGEN_LINE               equ 02
   GRC_BITMAP                   equ 03
   GRC_STENCIL_BITMAP           equ 04
   GRC_CLUT_BITMAP              equ 05
   GRC_HFLIP_BITMAP             equ 06
   GRC_CLUT_HFLIP_BITMAP        equ 07
   GRC_MASK_BITMAP              equ 08
   GRC_HDOUBLE_BITMAP           equ 09
   GRC_VDOUBLE_BITMAP           equ 10
   GRC_HVDOUBLE_BITMAP          equ 11
   GRC_HDOUBLE_BLEND_BITMAP     equ 12
   GRC_VDOUBLE_BLEND_BITMAP     equ 13
   GRC_HVDOUBLE_BLEND_BITMAP    equ 14
   GRC_SCALE                    equ 15
   GRC_TRANS_SCALE              equ 16
   GRC_LIT_SCALE                equ 17
   GRC_TRANS_LIT_SCALE          equ 18
   GRC_CLUT_SCALE               equ 19
   GRC_TRANS_CLUT_SCALE         equ 20
   GRC_POLY                     equ 21
   GRC_MORE_POLY                equ 22
   GRC_LIN                      equ 23
   GRC_TRANS_LIN                equ 24
   GRC_LIT_LIN                  equ 25
   GRC_TRANS_LIT_LIN            equ 26
   GRC_CLUT_LIN                 equ 27
   GRC_TRANS_CLUT_LIN           equ 28
   GRC_BILIN                    equ 29
   GRC_TRANS_BILIN              equ 30
   GRC_LIT_BILIN                equ 31
   GRC_TRANS_LIT_BILIN          equ 32
   GRC_CLUT_BILIN               equ 33
   GRC_TRANS_CLUT_BILIN         equ 34
   GRC_FLOOR                    equ 35
   GRC_TRANS_FLOOR              equ 36
   GRC_LIT_FLOOR                equ 37
   GRC_TRANS_LIT_FLOOR          equ 38
   GRC_CLUT_FLOOR               equ 39
   GRC_TRANS_CLUT_FLOOR         equ 40
   GRC_WALL2D                   equ 41
   GRC_TRANS_WALL2D             equ 42
   GRC_LIT_WALL2D               equ 43
   GRC_TRANS_LIT_WALL2D         equ 44
   GRC_CLUT_WALL2D              equ 45
   GRC_TRANS_CLUT_WALL2D        equ 46
   GRC_WALL1D                   equ 47
   GRC_TRANS_WALL1D             equ 48
   GRC_LIT_WALL1D               equ 49
   GRC_TRANS_LIT_WALL1D         equ 50
   GRC_CLUT_WALL1D              equ 51
   GRC_TRANS_CLUT_WALL1D        equ 52
   GRC_PER                      equ 53
   GRC_TRANS_PER                equ 54
   GRC_LIT_PER                  equ 55
   GRC_TRANS_LIT_PER            equ 56
   GRC_CLUT_PER                 equ 57
   GRC_TRANS_CLUT_PER           equ 58
   GRC_PER_VSCAN                equ 59
   GRC_TRANS_PER_VSCAN          equ 60
   GRC_LIT_PER_VSCAN            equ 61
   GRC_TRANS_LIT_PER_VSCAN      equ 62
   GRC_CLUT_PER_VSCAN           equ 63
   GRC_TRANS_CLUT_PER_VSCAN     equ 64
   GRD_FUNCS                    equ 65
                                     
ENDIF                                
                                     
                                     
                                     
