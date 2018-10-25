#ifndef TAG_H
#define TAG_H
enum Tag{
    PLUSSYM,    // +
    SUBSYM,     //  -
    MULTSYM,    //  *
    DIVSYM,     //  /
    EQSYM,      //  =
    LSYM,       //  <
    GSYM,       //  >
    LEQSYM,     //  <=
    GEQSYM,     //  >=
    NUMSYM,     //  number 
    IDESYM,     //  identifier
    IFSYM,      //  if
    ELSESYM,    //  else
    THENSYM,    //  then
    WHILESYM,   //  while
    BEGINSYM,   //  begin
    ENDSYM,     //  end
    READSYM,    //  read
    WRITESYM,   //  write
    CALLSYM,    //  call
    CONSTSYM,   //  const
    VARSYM,     //  var
    PROCSYM,    //  procedure
    COMMASYM,   //  ,
    DOTSYM,     //  .
    SEMSYM,     //  ;
    ASSIGNSYM,  //  :=
    NEQSYM,     //  <>(!=)
    LEFTBRACKET,    // (
    RIGHTBRACKET    // )
};
#endif