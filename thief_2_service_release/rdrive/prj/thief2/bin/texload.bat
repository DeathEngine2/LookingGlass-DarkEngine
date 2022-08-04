@echo off
cat texlist.fil | n:\bin\win95\grep -v '!!!' > texlist.fil
cat texlist.fil | n:\bin\win95\awk -F\\ 'BEGIN {print "load_family core_1\nremove_family all"} {print "load_a_texture " $1 " " $2}' > texload.cmd
