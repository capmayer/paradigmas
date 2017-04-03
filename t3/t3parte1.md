?- avo(joao, Y).
   Call: (7) avo(joao, _G331) ? creep  -> Chamada da regra avo verificando quem é neto de 'joao' (caso possua).
   Call: (8) pai(joao, _G407) ? creep  -> Chamada da regra pai verificando quem é filho de 'joao' (caso possua).
   Exit: (8) pai(joao, jose) ? creep   -> Retorno positivo da regra pai afirmando que 'joao' é pai de 'jose'.
   Call: (8) pai(jose, _G331) ? creep  -> Chamada da regra pai verificando quem é filho de 'jose' (caso possua). 
   Fail: (8) pai(jose, _G331) ? creep  -> Retorno negativo da regra pai afirmando que 'jose' não possui filhos.
   Fail: (7) avo(joao, _G331) ? creep  -> Retorno negativo da regra avô afirmando que 'joao' não possui netos (ou não é avô).
false.


?- avo(roberto, Y).
   Call: (7) avo(roberto, _G1492) ? creep  -> Chamada da regra avo verificando quem é neto de 'roberto' (caso possua).
   Call: (8) pai(roberto, _G1568) ? creep  -> Chamada da regra pai verificando quem é filho de 'roberto' (caso possua).
   Exit: (8) pai(roberto, joao) ? creep    -> Retorno positivo da regra pai afirmando que 'roberto' é pai de 'joao'.
   Call: (8) pai(joao, _G1492) ? creep     -> Chamada da regra pai verificando quem é filho de 'joao' (caso possua).
   Exit: (8) pai(joao, jose) ? creep       -> Retorno positivo da regra pai afirmando que 'joao' é pai de 'jose'.
   Exit: (7) avo(roberto, jose) ? creep    -> Retorno positivo da regra avô afirmando que 'roberto' é avô de 'jose'.
Y = jose ;                                 -> Não foram percorridos todos os nodos de 'roberto', pode haver mais um resposta.
   Redo: (8) pai(roberto, _G1568) ? creep  -> Continuação da chamada da regra pai verificando quem é filho de 'roberto'.
   Exit: (8) pai(roberto, julio) ? creep   -> Retorno positivo da regra pai afirmando que 'roberto' é pai de 'julio'.
   Call: (8) pai(julio, _G1492) ? creep    -> Chamada da regra pai verificando quem é filho de 'julio'. 
   Exit: (8) pai(julio, marcos) ? creep    -> Retorno positivo da regra pai afirmando que 'julio'  pai de 'marcos'.
   Exit: (7) avo(roberto, marcos) ? creep  -> Retorno positivo da regra avô afirmando que 'roberto' é avô de 'marcos'.
Y = marcos ;                               -> Não foram percorridos todos os nodos de 'julio', pode haver mais um resposta.
   Redo: (8) pai(julio, _G1492) ? creep    -> Continuação da chamada da pegra pai verificando quem é filho de 'julio'.
   Exit: (8) pai(julio, mario) ? creep     -> Retorno positivo da regra pai afirmando que 'julio' é pai de 'mario'.
   Exit: (7) avo(roberto, mario) ? creep   -> Retorno positivo da regra avô afirmando que 'roberto' é avô de 'mario'.
Y = mario.

?- azulejos(120, A).
   Call: (7) azulejos(120, _G1492) ? creep       -> Chamada da regra azulejos verificando quantos quadrados podem ser montados com os azulejos.
   Call: (8) 120>0 ? creep                       -> Chamada da regra Na>0 verificando se 120 é maior que 0.
   Exit: (8) 120>0 ? creep                       -> Retorno positivo da regra Na>0 afirmando que 120 é maior que 0. (hehe)
   Call: (8) _G1571 is floor(sqrt(120)) ? creep  -> Chamada da regra aritmética de arredondando para baixo da raiz quadrada de 120.
   Exit: (8) 10 is floor(sqrt(120)) ? creep      -> Retorno positivo da regra com o resultado da operação.
   Call: (8) _G1577 is 120-10*10 ? creep         -> Chamada da regra aritmética de definição do resto de azulejos. (120 - 100)
   Exit: (8) 20 is 120-10*10 ? creep             -> Retorno positivo da regra com o resultado da operação.
   Call: (8) azulejos(20, _G1578) ? creep        -> 1ª chamada recurssiva da regra azulejos passando os azulejos restantes como parametro.
   Call: (9) 20>0 ? creep                        -> Chamada da regra Na>0 verificando se 20 é maior que 0.
   Exit: (9) 20>0 ? creep                        -> Retorno positivo da regra Na>0 afirmando que 20 é maior que 0.
   Call: (9) _G1581 is floor(sqrt(20)) ? creep   -> Chamada da regra aritmética de arredondando para baixo da raiz quadrada de 20.
   Exit: (9) 4 is floor(sqrt(20)) ? creep        -> Retorno positivo da regra com o resultado da operação.
   Call: (9) _G1587 is 20-4*4 ? creep            -> Chamada da regra aritmética de definição do resto de azulejos.
   Exit: (9) 4 is 20-4*4 ? creep                 -> Retorno positivo da regra com o resultado da operação.
   Call: (9) azulejos(4, _G1588) ? creep         -> 2ª chamada recurssiva da regra azulejos passando os azulejos restantes como parametro.
   Call: (10) 4>0 ? creep                        -> Chamada da regra Na>0 verificando se 4 é maior que 0.
   Exit: (10) 4>0 ? creep                        -> Retorno positivo da regra Na>0 afirmando que 120 é maior que 0. (hehe)
   Call: (10) _G1591 is floor(sqrt(4)) ? creep   -> Chamada da regra aritmética de arredondando para baixo da raiz quadrada de 4.
   Exit: (10) 2 is floor(sqrt(4)) ? creep        -> Retorno positivo da regra com o resultado da operação.
   Call: (10) _G1597 is 4-2*2 ? creep            -> Chamada da regra aritmética de definição do resto de azulejos.
   Exit: (10) 0 is 4-2*2 ? creep                 -> Retorno positivo da regra com o resultado da operação.
   Call: (10) azulejos(0, _G1598) ? creep        -> 3ª chamada recurssiva da regra azulejos passando os azulejos restantes como parametro.
   Exit: (10) azulejos(0, 0) ? creep             -> 3º retorno positivo do fato azulejos(0, 0).
   Call: (10) _G1600 is 1+0 ? creep              -> Chamada da regra aritmética de soma definindo a quantidade de quadrados que podem ser montados. 
   Exit: (10) 1 is 1+0 ? creep                   -> Retorno positivo da regra com o resultado da operação.
   Exit: (9) azulejos(4, 1) ? creep              -> 2º retorno positivo da chamada recurssiva de azulejos.
   Call: (9) _G1603 is 1+1 ? creep               -> Chamada da regra aritmética de soma definindo a quantidade de quadrados que podem ser montados.
   Exit: (9) 2 is 1+1 ? creep                    -> Retorno positivo da regra com o resultado da operação.
   Exit: (8) azulejos(20, 2) ? creep             -> 1º retorno positivo da chamada recurssiva de azulejos.
   Call: (8) _G1492 is 1+2 ? creep               -> Chamada da regra aritmética de soma definindo a quantidade de quadrados que podem ser montados.
   Exit: (8) 3 is 1+2 ? creep                    -> Retorno positivo da regra com o resultado da operação.
   Exit: (7) azulejos(120, 3) ? creep            -> Retorno positivo da regra azulejos afirmando que 3 quadrados podem ser montados.
A = 3 ;                                          -> A 3ª chamada ainda pode percorrer o caminho da regra azulejos, não o fato.
   Redo: (10) azulejos(0, _G1598) ? creep        -> Continuação da 3ª chamada.
   Call: (11) 0>0 ? creep                        -> Chamada da regra Na>0 verificando se 0 é maior que 0.
   Fail: (11) 0>0 ? creep                        -> Retorno negativo da regra, logo as demais regras não precisam ser testadas.
   Fail: (10) azulejos(0, _G1598) ? creep        -> 3º retorno negativo da chamada recurssiva.
   Fail: (9) azulejos(4, _G1588) ? creep         -> 2º retorno negativo da chamada recurssiva.
   Fail: (8) azulejos(20, _G1578) ? creep        -> 1º retorno negativo da chamada recurssiva.
   Fail: (7) azulejos(120, _G1492) ? creep       -> Retorno negativo da regra azulejos.
false.
