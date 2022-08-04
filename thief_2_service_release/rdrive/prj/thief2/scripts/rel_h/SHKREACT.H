/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

// $Header: r:/prj/cam/src/shock/RCS/shkreact.h 1.2 1998/10/26 13:27:59 XEMU Exp $

#ifndef __SHKREACT_H
#define __SHKREACT_H

////////////////////////////////////////////////////////////
// ACT/REACT REACTIONS FOR SHOCK
//

#define REACTION_SET_MODEL "set_model"
#define REACTION_LIGHT_OFF "light_off"
#define REACTION_LIGHT_ON  "light_on"
#define REACTION_RADIATE   "radiate"
#define REACTION_POISON    "toxin"

EXTERN void ShockReactionsInit(void);
EXTERN void ShockReactionsPostLoad(void);


#endif // __SHKREACT_H
