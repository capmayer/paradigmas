/*
Várias regras de simplificação. Define os tails como iguais, para que assim os heads sejam considerados iguais também.
*/
sr([do,not|X],[dont|Y],X,Y).
sr([can,not|X],[cant|Y],X,Y).
sr([cannot|X],[cant|Y],X,Y).
sr([will,not|X],[wont|Y],X,Y).
sr([dreamed|X],[dreamt|Y],X,Y).
sr([dreams|X],[dream|Y],X,Y).
sr([how|X],[what|Y],X,Y).
sr([when|X],[what|Y],X,Y).
sr([alike|X],[dit|Y],X,Y).
sr([same|X],[dit|Y],X,Y).
sr([certainly|X],[yes|Y],X,Y).
sr([maybe|X],[perhaps|Y],X,Y).
sr([deutsch|X],[xfremd|Y],X,Y).
sr([francais|X],[xfremd|Y],X,Y).
sr([espanol|X],[xfremd|Y],X,Y).
sr([machine|X],[computer|Y],X,Y).
sr([machines|X],[computer|Y],X,Y).
sr([computers|X],[computer|Y],X,Y).
sr([am|X],[are|Y],X,Y).
sr([your|X],[my|Y],X,Y).
sr([were|X],[was|Y],X,Y).
sr([me|X],[you|Y],X,Y).
sr([you,are|X],[im|Y],X,Y).
sr([i,am|X],[youre|Y],X,Y).
sr([myself|X],[yourself|Y],X,Y).
sr([yourself|X],[myself|Y],X,Y).
sr([mom|X],[mother|Y],X,Y).
sr([dad|X],[father|Y],X,Y).
sr([i|X],[you|Y],X,Y).
sr([you|X],[i|Y],X,Y).
sr([my|X],[your|Y],X,Y).
sr([everybody|X],[everyone|Y],X,Y).
sr([nobody|X],[everyone|Y],X,Y).

/*
Define uma regra para determinar o tipo do char passado com base na tabela ASCII.
46 ponto final.
De 65 a 90, 97 a 123 e 48 a 57 números e letras.
De 33 a 47, 58 a 64 e 91 a 96 pontuações.
Abaixo ou igual a 32 espaço em branco.
Qualquer outro valor passado em X será considerado um caracter especial.
 */
my_char_type(46,period) :- !.
my_char_type(X,alphanumeric) :- X >= 65, X =< 90, !.
my_char_type(X,alphanumeric) :- X >= 97, X =< 123, !.
my_char_type(X,alphanumeric) :- X >= 48, X =< 57, !.
my_char_type(X,whitespace) :- X =< 32, !.
my_char_type(X,punctuation) :- X >= 33, X =< 47, !.
my_char_type(X,punctuation) :- X >= 58, X =< 64, !.
my_char_type(X,punctuation) :- X >= 91, X =< 96, !.
my_char_type(X,punctuation) :- X >= 123, X =< 126, !.
my_char_type(_,special).

/*
Define uma regra para transformar X em lower case com base na tabela ASCII.
De 65 (A) a 90 (Z) adicionando-se 32 obtem-se o correspondente minusculo.
Caso o valor de X não esteja nesse intervalo é retornado o próprio X.
*/
lower_case(X,Y) :-
	X >= 65,
	X =< 90,
	Y is X + 32, !.

lower_case(X,X).
