/* A Banda formada por alunos da escola vai fazer um show no clube. Eles vão tocar exatamente sete
músicas: J, K, L, M, N, O e P, não necessariamente nessa ordem. As músicas vão ser apresentadas de
acordo com as seguintes condições:
• N é a primeira ou a sétima música a ser apresentada. Done
• L é apresentada em algum momento após J. Done
• P é apresentada em algum momento após K.
• Exatamente uma música é apresentada entre J e M, seja J apresentada antes de M ou não.
• Exatamente uma música é apresentada entre K e N, seja K apresentada antes de N ou não. */


regra1(Musicas) :-
  nth0(0, Musicas, n).
regra1(Musicas) :-
  nth0(6, Musicas, n).

regra2(Musicas, X, Y) :-
  nth0(P1, Musicas, X),
  nth0(P2, Musicas, Y),
  Dif is P1-P2,
  Dif > 0.

regra3(Musicas, X, Y) :-
  nth0(P1, Musicas, X),
  nth0(P2, Musicas, Y),
  Dif is abs(P1-P2),
  Dif = 2.

questoes(Musicas) :-
  Musicas = [_,_,_,_,_,_,_],
  M = [j, k, l, m, n, o, p],
  permutation(M, Musicas),
  regra1(Musicas),
  regra2(Musicas, l, j),
  regra2(Musicas, p, k),
  regra3(Musicas, j, m),
  regra3(Musicas, k, n).

/* Questão 1. Qual das seguintes é uma ordem em
que as músicas podem ser apresentadas, da primeira
para a sétima?
(A) J, L, O, M, K, P, N  false
(B) K, P, N, O, J, L, M  false
(C) M, O, J, L, K, P, N  true
(D) N, L, K, O, M, P, J  false
(E) N, P, K, O, J, L, M  false
*/
/*
questoes([j,l,o,m,k,p,n]).
questoes([k,p,n,o,j,l,m]).
questoes([m,o,j,l,k,p,n]).
questoes([n,l,k,o,m,p,j]).
questoes([n,p,k,o,j,l,m]).
*/

/* Questão 2. Qual das seguintes afirmativas pode
ser verdadeira?
(A) L é a primeira música. false
(B) P é a primeira música. false
(C) P é a segunda música. false
(D) K é a quarta música. false
(E) O é a sétima música. true
*/
/*
questoes([l,_,_,_,_,_,_]).
questoes([p,_,_,_,_,_,_]).
questoes([_,p,_,_,_,_,_]).
questoes([_,_,_,k,_,_,_]).
questoes([_,_,_,_,_,_,o]).
*/

/* Questão 3. Se L é a quarta música apresentada,
qual das seguintes afirmativas pode ser verdadeira?
(A) J é a primeira música. true
(B) J é a segunda música. false
(C) K é a terceira música. false
(D) M é a quinta música. false
(E) O é a primeira música. false
*/
/*
questoes([j,_,_,l,_,_,_]).
questoes([_,j,_,l,_,_,_]).
questoes([_,_,k,l,_,_,_]).
questoes([_,_,_,l,m,_,_]).
questoes([o,_,_,l,_,_,_]).
*/

/* Questão 4. Se P é a quarta música apresentada,
então a sétima música apresentada deve necessariamente
ser:
(A) J
(B) L
(C) M  true
(D) N
(E) O
*/
/*
questoes([_,_,_,p,_,_,X]).
*/

/* Questão 5. Se K é apresentada em algum momento
após M, a quinta música apresentada não
pode ser:
(A) J  true
(B) K
(C) L
(D) O
(E) P
*/
/*
questoes(X), regra2(X, k, m).
*/
