# $Header: r:/prj/cam/scripts/osm/RCS/makefile 1.11 1998/10/25 15:42:22 CCAROLLO Exp $

VPATH=..\src;r:\prj\cam\scripts\src

TARGETS=miss1.osm miss2.osm miss4.osm miss7.osm miss8.osm miss9.osm miss10.osm \
miss12.osm miss15.osm gen.osm convict.osm

all: $(TARGETS)
loopall = $(TARGETS,.osm=)

clean:
     rm $(TARGETS)

%foreach var in $(loopall)
$(var).osm: $(var).scr gen.scr evidence.scr traps.scr
        -buildscr $(.SOURCE)
%endfor

