#Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.

def somaQuad(x,y): return x**2 + y**2

#Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.

def hasEqHeads(l1, l2): return l1[0] == l2[0]

#Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome. Defina uma função auxiliar para ajudar neste exercício.

def addSrTo(names): return list(map(addSrToAux, names))

def addSrToAux(name): return "Sr. " + name

#Crie uma função que receba uma string e retorne o número de espaços nela contidos. Defina uma função auxiliar para ajudar neste exercício.

def spaceInString(s): return len(list(filter(spaceInStringAux, s)))

def spaceInStringAux(c): return c == ' '

#Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista. Defina uma função auxiliar para ajudar neste exercício.

def crazyMath(numbs): return list(map(crazyMathAux, numbs))

def crazyMathAux(numb): return 3*numb**2 + 2/numb + 1

#Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos. Defina uma função auxiliar para ajudar neste exercício.

def onlyNegative(numbs): return list(filter(onlyNegativeAux, numbs))

def onlyNegativeAux(numb): return numb < 0

#Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive. Defina uma função auxiliar para ajudar neste exercício.

def inRange(numbs): return list(filter(inRangeAux, numbs))

def inRangeAux(numb): return numb > 0 and numb < 100

#Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares. Defina uma função auxiliar para ajudar neste exercício.

def onlyPair(numbs): return list(filter(onlyPairAux, numbs))

def onlyPairAux(numb): return numb%2==0

#Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False. Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.

def charFound(c, s): return bool(len(list(filter(lambda t:t==c, s))))

#Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string.

def addHtmlTo(parms): return list(map(addHtmlToAux, parms))

def addHtmlToAux(parm): return "<h1>"+ parm + "</h1>"
