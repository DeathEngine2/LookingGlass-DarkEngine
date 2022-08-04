@echo off
for %a in (@%1) do echo %@format[7,%@word[1,%a]] %@word[0,%a] >> vtdump.tmp
sort vtdump.tmp
del /q vtdump.tmp
