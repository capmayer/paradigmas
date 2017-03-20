#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.

def addSrTo(names): return list(map(lambda c: "Sr. " + c, names))

#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.

def crazyMath(numbs): return list(map(lambda c: 3*c**2 + 2/c + 1, numbs))

#Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.

def onlyEndWithA(names): return list(filter(lambda c: c[-1]== 'a', names))

#Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970. Para testar a condição, sua função deverá subtrair a idade do ano atual.

def only1970(ages): return list(filter(lambda c: 2017 - c > 1970, ages))

#O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.

def imperativoToFunctional(): return list(map(lambda c: c * 2, [1, 2, 3, 4])) 
