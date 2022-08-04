/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

#ifndef	EXCEPTIONHANDLER_H
#define	EXCEPTIONHANDLER_H


EXTERN BOOL g_fTrapExceptions;

#if defined(_WIN32) && !defined(__WATCOMC__) && !defined(SHIP)

// Copyright © 1998 Bruce Dawson.

// We forward declare PEXCEPTION_POINTERS so that the function
// prototype doesn't needlessly require windows.h.
typedef struct _EXCEPTION_POINTERS EXCEPTION_POINTERS, *PEXCEPTION_POINTERS;
int __cdecl RecordExceptionInfo(PEXCEPTION_POINTERS data, const char *Message);

/*
// Sample usage - put the code that used to be in main into HandledMain.
// To hook it in to an MFC app add exceptionattacher.cpp from the mfctest
// application into your project.
int main(int argc, char *argv[])
{
	int Result = -1;
	__try
	{
		Result = HandledMain(argc, argv);
	}
	__except(RecordExceptionInfo(GetExceptionInformation(), "main thread"))
	{
		// Do nothing here - RecordExceptionInfo() has already done
		// everything that is needed. Actually this code won't even
		// get called unless you return EXCEPTION_EXECUTE_HANDLER from
		// the __except clause.
	}
	return Result;
}
*/

#define BEGIN_EXCEPT_TRY __try
#define BEGIN_EXCEPT_CATCH(s) __except(RecordExceptionInfo(GetExceptionInformation(), s ": " __FILE__))

#else

#define BEGIN_EXCEPT_TRY 
#define BEGIN_EXCEPT_CATCH(s)

#endif

#endif
