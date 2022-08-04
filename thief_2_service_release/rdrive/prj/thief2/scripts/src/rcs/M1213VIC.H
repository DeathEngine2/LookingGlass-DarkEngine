head	 1.6;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @ * @;


1.6
date	 2000.03.05.21.19.55;  author TJS;  state Exp;
branches ;
next	 1.5;

1.5
date	 2000.02.21.06.17.22;  author TJS;  state Exp;
branches ;
next	 1.4;

1.4
date	 2000.02.05.13.02.35;  author TJS;  state Exp;
branches ;
next	 1.3;

1.3
date	 2000.01.24.19.18.48;  author TJS;  state Exp;
branches ;
next	 1.2;

1.2
date	 2000.01.20.22.58.10;  author TJS;  state Exp;
branches ;
next	 1.1;

1.1
date	 2000.01.17.10.32.40;  author TJS;  state Exp;
branches ;
next	 ;


desc
@Constants relating to missions 12 and 13 victory conditions.
@


1.6
log
@There are three masks now.
@
text
@#define M13_LETTER_GOAL 3
#define M13_CULTIVATOR_GOAL 4
#define M12_CAGEY_GOAL 11
#define M12_LETTER_GOAL 4
#define M13_MASK_GOAL_0 0
#define M13_MASK_GOAL_1 1
#define M13_MASK_GOAL_2 2
#define M13_MASK_TOTAL 3



@


1.5
log
@Added M12_LETTER_GOAL
@
text
@d8 1
a8 1
#define M13_MASK_TOTAL 4
@


1.4
log
@Changed cagey goal number.
@
text
@d4 1
@


1.3
log
@Added mission 13 mask goals
@
text
@d3 1
a3 1
#define M12_CAGEY_GOAL 9
@


1.2
log
@Added M12_CAGEY_GOAL
@
text
@d4 6
@


1.1
log
@Initial revision
@
text
@d3 1
@
