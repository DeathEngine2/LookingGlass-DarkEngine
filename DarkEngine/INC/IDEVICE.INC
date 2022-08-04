;
; $Source: r:/prj/lib/src/2d/rcs/idevice.inc $
; $Revision: 1.2 $
; $Author: ept $
; $Date: 1995/04/13 10:53:58 $
;
; Symbolic constants for function table references.
;
; This file is part of the 2d library.
;

ifndef idevice_inc
idevice_inc equ 1

GRT_INIT_DEVICE         equ     0t
GRT_CLOSE_DEVICE        equ     1t
GRT_SET_MODE            equ     2t
GRT_GET_MODE            equ     3t
GRT_SAVE_STATE          equ     4t
GRT_RESTORE_STATE       equ     5t
GRT_STAT_HTRACE         equ     6t
GRT_STAT_VTRACE         equ     7t
GRT_SET_PAL             equ     8t
GRT_GET_PAL             equ     9t
GRT_SET_WIDTH           equ     10t
GRT_GET_WIDTH           equ     11t
GRT_SET_FOCUS           equ     12t
GRT_GET_FOCUS           equ     13t
GRT_CANVAS_TABLE        equ     14t
GRT_SPAN_TABLE		equ     15t
GRD_DEVICE_FUNCS        equ     16t

endif   ;ndef idevice_inc
