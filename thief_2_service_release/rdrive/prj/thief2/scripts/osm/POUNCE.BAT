goto try_delete
:try_again
sleep 300
:try_delete
rm %1
if exist %1 goto try_again
make %1

