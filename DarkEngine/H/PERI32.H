

#define setup_periscope();  peri_start_periscope();  peri_int_2();
void peri_int_2(void);
#pragma aux peri_int_2= "int 2h"

unsigned short get_ds(void);
#pragma aux get_ds="mov ax,ds"

unsigned short get_cs(void);
#pragma aux get_cs="mov ax,cs"


extern unsigned long wank_peri(void);
void peri_start_periscope(void);

