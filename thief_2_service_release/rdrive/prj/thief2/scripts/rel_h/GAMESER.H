/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/* TO USE THIS LIBRARY, YOU MUST HAVE THE LOOKING GLASS */
/* TIMER INSTALLED, INITIALIZED, AND RUNNING */

#ifndef _gameser_h
#define _gameser_h


/************************/
/* Callback definitions */
/************************/

typedef void (*send_callback)(void *);
typedef void (*receive_callback)(void *, ushort);
typedef void (*error_callback)(int error);


/************************************************/
/* gs_init                                      */
/*                                              */
/* Parameters:                                  */
/*    port = com port (1 or 2)                  */
/*                                              */
/*    baud = the baud rate that the port was    */
/*       opened at                              */
/*    received_callback = pointer to a function */
/*       that will be called whenever valid     */
/*       information is received                */
/*                                              */
/*    error_callback = pointer to a function    */
/*       that will be called whenever an        */
/*       unrecoverable error has occurred.      */
/*                                              */
/* Returns:                                     */
/*    0 = okay                                  */
/*   -1 = error                                 */
/*                                              */
/* Initializes the game-serial library          */
/************************************************/
int gs_init(int port,int baud,
            receive_callback, error_callback);

/************************************************/
/* gs_close                                     */
/*                                              */
/* Parameters:                                  */
/*       None                                   */
/*                                              */
/* Returns:                                     */
/*    0 = okay                                  */
/*   -1 = error                                 */
/*                                              */
/* Shuts down the game-serial library           */
/************************************************/
int gs_close();

/************************************************/
/* gs_send                                      */
/*                                              */
/* Parameters:                                  */
/*    data = pointer to chunk of data to send   */
/*                                              */
/*    length = length of chunk of data          */
/*                                              */
/*    send_callback = callback to call whenever */
/*       data is done being transmitted         */
/*                                              */
/*    callback_data = pointer to value which is */
/*       passed along as first parameter to     */
/*       the send callback function             */
/*                                              */
/* Returns:                                     */
/*    0 = okay                                  */
/*   -1 = no room for data                      */
/*                                              */
/* Places the data into a queue of data that is */
/* waiting to be transmitted.  If the queue is  */
/* full, -1 is returned and the data will not   */
/* be transmitted.  The data pointed to by      */
/* void *data can NOT BE DE-ALLOCATED until the */
/* send callback is called.  Game-serial does   */
/* not make a copy of the data for itself.      */
/************************************************/
int gs_send(void *data, ushort length, send_callback, void *callback_data);

/************************************************/
/* gs_idle                                      */
/*                                              */
/* Parameters:                                  */
/*       NONE                                   */
/*                                              */
/* Returns:                                     */
/*       NOTHING                                */
/*                                              */
/* All of the dirty work is done here.  Call me */
/* pretty frequently, at least a couple of      */
/* times per frame, if not more.                */
/************************************************/
void gs_idle();


/****************************************/
/* Possible parameters to error_calback */
/****************************************/

#define GS_NO_ERROR 0
#define GS_OUT_OF_MEMORY 1
#define GS_CONNECTION_LOST 2
#define GS_UNABLE_TO_RESYNCH 3
#define GS_STARTUP_FAILED 4
#define GS_SERIOUS_INTERNAL_ERROR_A 5
#define GS_SERIOUS_INTERNAL_ERROR_B 6
#define GS_SERIOUS_INTERNAL_ERROR_C 7

#endif
