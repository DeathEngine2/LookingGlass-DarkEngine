head	 1.2;
branch   ;
access   ;
symbols  ;
locks    ; strict;
comment  @@;


1.2
date	 2000.01.31.18.31.43;  author adurant;  state Exp;
branches ;
next	 1.1;

1.1
date	 1999.12.07.21.03.51;  author adurant;  state Exp;
branches ;
next	 ;


desc
@cpysrc.pl
@


1.2
log
@thief2 not cam
@
text
@

# perl script to copy the sources and built libraries

#  options are -prjback <foo> -daily -targetroot 
# 

# prjback gets used to build targetroot i.e:
#  $targetroot= $prjback\cam\$dailydir
#

# if $targetroot is used on command line, then the prjback and dailydir
# are meaningless but it is certainly an easier way to specify the 
# root. 

# prjback only used for where the sources are going to be copied to
# (copylist has full paths)
# prjback only used to build the name of the $targetroot. 

&process_cmdline(@@ARGV);

# if -targetroot was specified 
if($targetroot eq "") {
# we use $prjback and $dailydir to build the $targetroot
# if -prjback was specified
    if($prjback eq "") {
        $prjback="o:\\prj";
    }
    else {
        printf "using $prjback as prjback\n";
    }
# if -daily was specified 
    if($dailydir eq "") {
        $dailydir="daily";
    }
    else {
        printf "using $dailydir as dailydir\n";
    }

    $targetroot = $prjback . "\\thief2\\$dailydir";
}
else {
    printf "using $targetroot as targetroot\n";
}

open(INPUTLIST, "copylist") 
         || die "Cannot open the list\n";

while (<INPUTLIST>) {
    if (/^\s*\n$/) {
        printf "blank line found\n";
        $_ = <INPUTLIST>;
        next;
    }
        
    printf "Current directory is $_\n";
    chop;
    $source=$_;
    $source =~ /(.{2})(\\)(\w*)(.*)/;
    if($pullprj) {
        $rest= $4;  # $3 is top level dir, usually prj
    }
    else {
        $rest= $2 . $3 . $4;  # $3 is top level dir, usually prj
    }

    $target=$targetroot . $rest; 
    &create_tree($target);
    
    system("copy $source,$target");
    if (-d "$source\\win32") {
       $t = $target;
       $s = $source;
       $target = $target . "\\win32";
       $source = $source . "\\win32";
       &create_tree($target);
       system("copy $source,$target");
       $target = $t;
       $source = $s;
   }
    if (-e "$source\\rcs\\makefile") {   # ain't gona do much without the 
       $target = $target . "\\rcs";      # makefile. 
       $source = $source . "\\rcs";
       &create_tree($target);
       system("copy $source\\makefile,$target");
       if (-e "$source\\master.mh") {
          system("copy $source\\master.mh,$target");
       } # master.mh
       if (-e "$source\\flags.mh") {
          system("copy $source\\flags.mh,$target");
       } # flags.mh
       if (-e "$source\\config.mh") {
          system("copy $source\\config.mh,$target");
       } # config.mh
   } # makefile

}

close(INPUTLIST);
    
sub create_tree
{
 local ($path) = @@_;

@@idirs = split (/\\/,$path);

 $pathsep='';              # don't want a pathsep first time thru
 $mdir='';
  foreach $d (@@idirs)
  {
     $mdir=$mdir.$pathsep.$d;
     $pathsep="\\";             # now we want pathsep        
     if ($d =~ /[a-z]:/) {      # dont want to create x: 
         next;
     }
     if ( ! -d $mdir)
     {printf "creating  $mdir\n";
      system("mkdir $mdir");}
     }
}

sub process_cmdline
{
    local(@@argv) = @@_;

    while (@@argv) {
        $option = shift @@argv;
        if($option =~ /-prjback/) {
            $prjback = shift(@@argv);
        }

        if($option =~ /-daily/) {
            $dailydir = shift(@@argv);
        }

        if($option =~ /-targetroot/) {
            $targetroot = shift(@@argv);
        }

        if($option =~ /-pullprj/) {
            $pullprj = 1;
        }




    } # of while 

}





@


1.1
log
@Initial revision
@
text
@d40 1
a40 1
    $targetroot = $prjback . "\\cam\\$dailydir";
@
