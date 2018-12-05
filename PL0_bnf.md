> 非终结符前加@ EBS代表一步赛龙
```
@program -> @div_program .
@div_program -> @const_part @sctence | @var_part @sctence | @pro_part @sctence | @sctence
@const_part -> CONST @iden = @uint @const ; 
@const -> , @iden = @uint @const | EBS
@uint -> @num @uint | EBS
@var_part -> VAR @iden @var
@var -> , VAR @iden @var | EBS
@iden -> @alpha @iden_next
@iden_next -> @alpla @iden_next | @number @iden_next | EBS
@procedure -> @procedure_head @div_program ; @procedure | @procedure | EBS
@procedure_head -> PROCEDURE @iden ;
@sctence -> @assign | @condition | @while | @call | @write | @read | @complex | EBS
@assign -> BEGIN @sctence @e_sctence END
@e_sctence -> ; @sctence @e_sctence | EBS
@condition -> @express @relation @express | ODD @express
暂未完成
```
