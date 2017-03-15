#exe1

def addSrTo(names): return list(map(lambda c: "Sr. " + c, names))

#exe2

def crazyMath(numbs): return list(map(lambda c: 3*c*2 + 2/c + 1, numbs))

#exe 3

def onlyEndWithA(names): return list(filter(lambda c: c[-1]== 'a', names))

#exe 4

def only1970(ages): return list(filter(lambda c: 2017 - c > 1970, ages))

#exe 5

def imperativoToFunctional(): return list(map(lambda c: c * 2, [1, 2, 3, 4])) 
