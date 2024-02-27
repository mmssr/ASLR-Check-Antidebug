 

                               ,cayccD66KDDDRKqcc═,_
                           ,cG68888686I8868868666D$6KKc,
                        ,q666866886686666686666668U68Uc6^j=
                     _cD8UI8666886G666GG666666686687G8IK$68Dy_
                   yG68"6886G66666K66G66GGG6GGG6866K66$6^$68DUD_
                 _8I66K$686GKU6K86I66G688GG6666G66688^U"IU668RUU$
                _68U766$y$668K66866G868"66866688888U6ccc#G6866^UU$
                $$66K6IKcc8686666GGGGGGGGGGGGGGG668888666786U"$:$$`
                =$ID86D788U66666666668886866666888688H688U766D$U$$$_
               ,.=$66UU68U$6666866GGG6GGGGGGG666866886888$$$66$$$-$`
               =$$$$7I$I6688668886GGGGGGGGGGG66666888668D$'-$$H=-
               |H$U='$$666666688666GGGG66GGGGG6GGGG88668^$` `$
                7$6$-`$76886686GGGGGGGGGGGGGGGG66G6886868$
               _`!$$  :I8666G6888886G6G666668886868688868$_   -
               -|-yU- :$U7""""^""^^^^66888^7"'` _|$$""7"$$
               =.-$$=` `'`y≡ªM≈-     I688$`_ _=I666$$^        `  |-
               .  '$`_ ___,$$768Koocyy6GGKyGyc686^U$]═=jcc=  `=-
               ',=$  jyIGc$7?$D666G8UIGGGK686GGG86$$;yc86Uc$  :
                `$$` $6666GGGGGGG68667GGGK78^66688668888U$$$  `
                  $_ '7666666GG688U76$6GGK$7$6668668886U7U$    `=
                  |$- `$"766686888H$IUIGGK$$$766866688DU$`     `
                   ``   `!$6688886Uy|68GGKU$y$688888^^$       `
                          =7686^U6H$$76GG8H"""$7666$$"
                           $7$$j68$_ `7777`  _$6KK$$$=-  -
                       `-   $c6888D$=_    _$||66686H$   _=
                       `:-  $$7U777$$$$__=$$$$$$^'$$'   $=
                        :=  $$$yoa,,,aoooaooc═=ycc$$$   $`
                         `   $$6^6^$$''""""'`-$$"$7U
                              |U$$$$$$yooooooocccDU-
                               $$6688666G6G88888U7$
                        _-==,   `$"777"8^^^^^^7"'`
                     __=`$$$=$=     `'`^'''''`
                 _ycK$$$.$$$$$$$=_
             _yD888866D$$$|$$$$$$=-              --`    __
           yD68886886886$$$$UU^$$$$,-          `-=-`     _`--__
          I688866686G6688D$U6668666$$$$$$,,,$$$$$$$$-   `$$$$$$$$=
          7686666666668888886668888888888D688666D6$$$---:|$IUUUU66H
           I66686666G6668688888I888668888888886888U$$$$$|j666888666
            I88668666686GG6G6668888868888686666688$$$$ID66688888886


# ASLR-Check-Antidebug

Small crummy ChatGPT POC for an antidebug technique to check if ASLR is disabled on a PE binary. Malware analysts will frequently disable ASLR before debugging. Disabling ASLR ensures that memory addresses referenced within the binary remain consistent across runs. Disabling ASLR makes debugging easier by providing a consistent memory layout for analysis and debugging tools.

If you want to test this out, just manually edit the dynamic_address flags in the DLL characteristics portion of the PE optional header. 
