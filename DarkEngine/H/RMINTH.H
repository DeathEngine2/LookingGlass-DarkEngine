/////////////////////////////////////////////////////////////////////
// RMINTH.H  -  Header for real mode interrupt installer
//
// This file contains all the defines for real mode interrupt
// replacement.  If the real mode interrupt handler changes, these
// defines must change to match.  Changing the real mode interrupt
// used should be no more than changing the RMH_INT_NUM define.
//
// Right now, calling more than one real mode routine isn't supported.
// (Since usually, we'll get an entry point into a TSR, this won't be
// a problem we're calling several real mode TSR, which should never 
// happen.)
//
// Future expansion : Allow calling of any real mode procedure, by
// moving the code modification to the real mode interrupt generation
// procedure.
//

#ifndef RMINTH_H
#define RMINTH_H

// This is the interrupt number to take over - it should be unused.
#define RMH_INT_NUM	0x66		// Here's a "free" interrupt

// This is the offset into the assembler routine of the CALL FAR address
// It shouldn't change unless the interrupt handler does.
#define RMH_ADDR_OFFSET	0x02

// This is the total size of the real mode interrupt handler in bytes
#define RMH_PROC_SIZE	8

// The real mode register structure
typedef struct real_mode_registers_
{
	ulong EDI;
	ulong ESI;
	ulong EBP;
	ulong reserved_by_system;
	ulong EBX;
	ulong EDX;
	ulong ECX;
	ulong EAX;
	ushort flags;
	ushort ES, DS, FS, GS, IP, CS, SP, SS;
} RealModeRegisters;

// Public routines
extern void install_rm_int_proc(ushort rm_seg, ushort rm_off);
extern ulong RMProcCall( RealModeRegisters *RMIp );

#endif
