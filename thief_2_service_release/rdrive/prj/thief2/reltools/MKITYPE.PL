#
# this script generates the ilist.X files which the installer reads


# only one arg for now, -cd2 
# make a new arg, which tells it what file to read to tell it what to do...

$arg = shift(@ARGV);

open(INSTRUCTIONS,$arg) or die "cannot open instructions file";

while (<INSTRUCTIONS>) {
    $itypespath = $_;
    chomp($itypespath);
    if ($rootpath = <INSTRUCTIONS>) {chomp $rootpath}
    else {die "cannot read rootpath";}
    if ($findrule = <INSTRUCTIONS>) {chomp $findrule}
    else {die "cannot read findrule";}
    if ($excludefile = <INSTRUCTIONS>) {chomp $excludefile}
    else {die "cannot read excludefile";}

    open(EXCLUDE,$excludefile) or die "cannot open " . $excludefile;
    @exclusions = <EXCLUDE>;
    close (EXCLUDE);

    $tmp = $ENV{'TEMP'};
    $logname = "flog";  
    $lognameu = "flog" . ".u"; #unsorted

# find . -print just leaves a bunch of junk in the front that has to get 
# peeled off... why not find * -print?  AMSD 05/31/99
# ahh... there are good and sufficient reasons later on.  Makes searching
# for path a headache if you don't know it's going to start with ./
# just a warning... :)

    print "find $rootpath -name \"$findrule\" -print | grep -v itype > $lognameu\n";

    system("find $rootpath -name \"$findrule\" -print | grep -v itype > $lognameu");

    system("sort -f $lognameu \> $logname");
    &makelist($logname,$itypespath,\@exclusions);
    system("del $lognameu"); 
    system("del $logname");

   unlink($logname);
} #end of while

# routine to open the log produced by find, get the file size,
# add up all the files and write the text files used by the
# installer. 


sub makelist
{
my ($logname,$listname,$excludearray);

$logname = shift @_;
$listname = shift @_;
$excludearray = shift @_;

open (LIST, $logname) or die "youch, cannot open $logname";
open (ILIST, ">$listname") or die "oh no, cannot open $listname";

printf "Creating $listname\n";


# get rid of first line which just has a dot

$fake = <LIST>;

$total=0;

while (<LIST>) {
    chop;

# we have to count directories

    if (!-d) {
	$isadir = 0;
	}
    else  {  
	$isadir = 1;
    }

#    if (!-d) {

	$excludethis = 0;  # default is not to exclude this file.  
        ($dev,$ino,$mode,$nlink,$uid,$gid, $rdev,$size,$atime,$mtime,
        $ctime,$blksize,$blocks) = stat($_);  # to get the size of the file
# windows is fucked up and will treat files under 32k as 32k depending
# on sector size... AGGG This is safest (according to DT and DC)

# Actually, it's 32768 not 32000... which was causing problems. 2#%@#%@ dos.
#  AMSD 06/20/99

# It's even worse than that!!!.  Since it rounds all files up to these 
# boundaries... it's messing things up even on much bigger files.  Going
# to have to do a generic roundup.  


#for directories and whatnot.
    if ($size < 1) {
	$size = 32768;
    }			      

	if ( ($size % 32768) != 0) {
	    $size = $size + 32768 - ($size % 32768);
	}

#        if ($size < 32768) {
#            $size = 32768
#            }

    $path = $_;

#    printf "$path \n";


#delete the stuff that was part of rootpath...  I think we want to do this


    $path =~ s~([^\/]*\/)~\.\/~;

#    printf "$path \n";

        $path =~ s~\/~\\~g; # change foo/bar to foo\bar (Darn Unix people..)
# so what I need to do now, in a departure from the original, is to search
# for proper prefixes of the path in the exclude file, so that I can exclude 
# entire directories, like SanFrancisco or the like.  AMSD 05/31/99

# ok, so recurse is going to hold the string I'm going to loop around(the path)
	$recurse = $path;
	$excludedir = '';

	while ($recurse =~ /([^\\]*)\\(.*)/){	
# now $1 should have the first directory name, and $2 should have the rest.
	    $recurse = $2; # ok, recurse recurses down to remainder.
            $excludedir = $excludedir .$1 . '\\'; 
                 # ok, excludedir gets the dir to search(including previous)
	    if (&find_value($excludedir,@$excludearray)) {
#	        printf "$excludedir$recurse being excluded from $listname\n";
	        $excludethis++;
	    }			#endif
	}#endwhile
   
	if (!$excludethis) {    #if we haven't already given it the boot...
            $path =~ /.*\\(.*$)/; # get the file name
            $filename = $1;       # keep it
            if (&find_value($filename,@$excludearray)) {
# Patmac requests that this line not be printed.  It can always be put back
# in for debugging.  Maybe I'll add a commandline bit for it. AMSD 05/01/99
#               printf "$filename being excluded from $listname\n";
            }
            else {
                $path =~ /(\.\\)(.*)(\\)($filename)/;# get the path (if any)
                $line = $2 . "##" . $filename . "=$size\n";
                $totalsize += $size;
		if ($isadir != 1) {
                  push(@LINES, $line);
	      }
	    }
	}

#   } # not a directory
#	else {
#	    #directories, however, do take up space...
#	    $totalsize += 32768
#	}


} # while LIST

# write the total
        printf ILIST  "$totalsize\n";
# reverse the list
    while (@LINES) {
        push(@RLINES,pop(@LINES));
    }

    while (@RLINES) {
        $line = pop(@RLINES);
        printf ILIST $line;
    }


close LIST;
close ILIST;
$totalsize=0;



} # end of routine


# look in an array for a value.  If found, return true, if not return false. 

sub find_value
{
    local ($string,@array) = @_;
    $limit=$#array;
    
#   since $#array returns the proper length (with subscript cut down one),
#   want <=, not < or we lose the last element.  AMSD 05/31/99
    for(local($cnt)=0;$cnt <= $#array;$cnt++) {
        $temp = shift @array;  # perl5 bug, can't combine statements
        push(@array,$temp);
        chop($temp);
        $temp =~ tr/A-Z/a-z/;
        $string =~ tr/A-Z/a-z/;
#        if (!index($temp,$string)) {
# I want an exact match with the new system. AMSD 05/31/99
	if ($temp eq $string) {
           return 1;
        }
    }

    return 0;
}


