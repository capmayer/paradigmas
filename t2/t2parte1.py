def hideChards(s): return ''.join([c if c==" " else "-" for c in s if c])

def genTable(numbs): return [(numb, numb**2) for numb in range(1, numbs+1)]

def genCode(strings): return ''.join([string[0]+string[-1] for string in strings])

def myZip(l1, l2): return [(l1[x], l2[x]) for x in range(min(len(l1), len(l2)))]

def enumerate(words): return [(words.index(word)+1, word) for word in words]

def isBin(s): return not bool([c for c in s if not c in '01'])

def bin2dec(digits): return sum([2**num for num in range(len(digits)-1,-1,-1) if digits[-num-1] in '1'])
