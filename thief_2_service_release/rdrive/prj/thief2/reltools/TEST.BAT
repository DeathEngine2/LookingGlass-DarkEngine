
iff .%1.==.resume. .OR. .%2.==.resume. then
   input Resume where? %%WhereResume
   iff .%WhereResume.==.. then
      set WhereResume=build
   endiff
   goto %WhereResume
endiff

:Build
echo ha
