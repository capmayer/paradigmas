aoLado(X, Y, L) :- nextto(X, Y, L).
aoLado(X, Y, L) :- nextto(Y, X, L).

um_entre(X, Y, L) :-
  nth0(PX, L, X),
  nth0(PY, L, Y),
  Dif is abs(PX-PY),
  Dif == 2.


findAvioes(Avioes, Informacao) :-
  Avioes = [_, _, _, _, _],
  member(aviao(milton, vermelha, _, _,_), Avioes),
  member(aviao(walter, _, radio, _,_), Avioes),
  member(aviao(_, verde, _, pesca, _), Avioes),
  member(aviao(rui, _,_, futebol, _), Avioes),
  nextto(aviao(_,branca, _,_,_), aviao(_,verde,_,_,_), Avioes),
  member(aviao(_,_,altimetro, _, leite), Avioes),
  member(aviao(_,preta,_,_,cerveja), Avioes),
  member(aviao(_,vermelha, _, natacao, _), Avioes),
  nth0(0, Avioes, aviao(farfarelli, _,_,_,_)),
  aoLado(aviao(_,_,_,_,cafe), aviao(_,_,hidraulico,_,_), Avioes),
  aoLado(aviao(_,_,_,_,cerveja), aviao(_,_,bussula,_,_), Avioes),
  member(aviao(_,_,_,equitacao,cha), Avioes),
  member(aviao(nascimento,_,_,_,agua), Avioes),
  aoLado(aviao(farfarelli,_,_,_,_), aviao(_,azul,_,_,_), Avioes),
  um_entre(aviao(_,_,hidraulico,_,_), aviao(_,_,altimetro,_,_), Avioes),
  member(aviao(_,_,_,tenis,_), Avioes),
  member(aviao(Informacao,_,temperatura,_,_), Avioes).

positivos1([],[]).
positivos1([H|T],L) :- H > 0, positivos1(T,Resto), L = [H|Resto].
positivos1([H|T],L) :- H =< 0, positivos1(T,L).

positivos2([],[]).
positivos2([H|T],L) :- H > 0, L = [H|Resto], positivos2(T,Resto).
positivos2([H|T],L) :- H =< 0, positivos2(T,L).

positivos3([],[]).
positivos3([H|T],[H|R]) :- H > 0, positivos3(T, R).
positivos3([H|T], L) :- H =< 0, positivos3(T, L).
/* Todos apresentam mesma quantidade de inferencias. */


largest1([X],X).
largest1([X|Xs],X) :- largest1(Xs,Y), X>=Y.
largest1([X|Xs],N) :- largest1(Xs,N), N>X.

largest2([X|Xs], N) :- aux(Xs, X, N).
aux([], N, N).
aux([X|Xs], M, N) :-
   M1 is max(X, M),
   aux(Xs, M1, N).

/* largest2 apresentou um desempenho 900% melhor que largest1 */
