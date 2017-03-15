#exe 1

def somaQuad(x,y): return x**2 + y**2

#exe 2

def hasEqHeads(l1, l2): return l1[0] == l2[0]

#exe 3

def addSrTo(names): return list(map(addSrToAux, names))

def addSrToAux(name): return "Sr. " + name

#exe 4

def spaceInString(s): return len(list(filter(spaceInStringAux, s)))

def spaceInStringAux(c): return c == ' '

#exe 5

def crazyMath(numbs): return list(map(crazyMathAux, numbs))

def crazyMathAux(numb): return 3*numb*2 + 2/numb + 1

#exe 6

def onlyNegative(numbs): return list(filter(onlyNegativeAux, numbs))

def onlyNegativeAux(numb): return numb < 0

#exe 7

def inRange(numbs): return list(filter(inRangeAux, numbs))

def inRangeAux(numb): return numb > 0 and numb < 100

#exe 8

def onlyPair(numbs): return list(filter(onlyPairAux, numbs))

def onlyPairAux(numb): return numb%2==0

#exe 9

def charFound(c, s): return bool(len(list(filter(lambda t:t==c, s))))

#def charFoundAux(c): return True

#exe 10

def addHtmlTo(parms): return list(map(addHtmlToAux, parms))

def addHtmlToAux(parm): return "<h1>"+ parm + "</h1>"
