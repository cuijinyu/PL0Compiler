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
    DOSYM,      //  do
    READSYM,    //  read
    WRITESYM,   //  write
    CALLSYM,    //  call
    CONSTSYM,   //  const
    VARSYM,     //  var
    PROCSYM,    //  procedure
    ODDSYM,     //  odd
    COMMASYM,   //  ,
    DOTSYM,     //  .
    SEMSYM,     //  ;
    ASSIGNSYM,  //  :=
    NEQSYM,     //  <>(!=)
    LEFTBRACKET,    // (
    RIGHTBRACKET,    // )
    PROGRAM,    //  程序体
    SENTENCE,   //  语句
    EXPRESSION, //  表达式  
    CONDITION,  //  条件    
    ITEM,       //  项
    FACTOR,     //  因子
    EPS,        // 一不赛龙
    PSTART,     //  语法分析开始Seg
    PEND        //  语法分析结束Seg
};
#endif