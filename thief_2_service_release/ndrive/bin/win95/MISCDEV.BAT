@echo off
if %OS%a==Windows_NTa goto punt_anarkey
if exist c:\app\anarkey\anarkey.com c:\app\anarkey\anarkey -a2000 -e -h4000 -u400 -X\
if exist c:\app\anarkey\akaload.exe c:\app\anarkey\akaload c:\app\anarkey\anarkey.aka
:punt_anarkey
set dx0=/alt:+!/an/al/p/vid:d/so:*enc/vl:on/he:1/st:0/vl:off/ca:low
