@REM=(qq!
@echo off
perl %0.bat %1 %2 %3 %4 %5 %6 %7 %8 %9
goto end !) if 0 ;

if ($#ARGV < 1) {
  print <<"END";
inc2h equfile [incfile ...] hfile
converts .inc files to a .h file.
END
  exit;
}

$hfile = pop (@ARGV);
open (HFILE, ">> $hfile");
select (HFILE);
while (<>) {
  $incline = $_;
  # translate dddh numbers to 0xddd
  s/(\d[0-9,a-f,A-F]*)h/0x$1/g;
  # translate a equ b into #define a (b)
  s/(\w+)\s+equ\s+([^\;\n]*).*/\#define $1 \($2\)/g;
  # translate ; comments to // comments
  s/\;(.*)$/\/\/$1/g;
  # translate extrns and externdefs with ;export comments to externs.
  s/externdef\s+_(\w+)\:\w+\s+\/\/\s*export \<(.*)\>/extern $2 $1\;/g;
  s/extrn\s+_(\w+)\:\w+\s+\/\/\s*export \<(.*)\>/extern $2 $1\;/g;
  # throw away unmarked extrns and externdefs.
  s/externdef\s+.*//g;
  s/extrn\s+.*//g;
  if ($_ ne "\n" && $incline ne $_) {
    print;
  }
}

@REM=(qq!
:end !) if 0 ;
