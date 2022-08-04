# feed me a path, I will create it for you! Yum!

$path=shift(@ARGV);

if ( $path eq ""){
    printf "Usage mkdirs pathname\n";
    exit;
}
else { 
    &create_tree ($path);
}

sub create_tree
{
 local ($path) = @_;

@idirs = split (/\\/,$path);

 $pathsep='';              # don't want a pathsep first time thru
 $mdir='';
  foreach $d (@idirs)
  {
     $mdir=$mdir.$pathsep.$d;
     $pathsep="\\";             # now we want pathsep        
     if ( ! -d $mdir)
     {printf "creating  $mdir\n";
      system("mkdir $mdir");}
     }


}
