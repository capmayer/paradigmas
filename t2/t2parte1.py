#1. Defina uma função addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado.
def addSuffix(suf, names): return [suf + name for name in names]

#2. Escreva uma função countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.
def countShorts(words): return len([word for word in words if len(word)<5])

#3. Defina uma função stripVowels(s) que receba uma string e retire suas vogais.
def stripVowels(s): return ''.join([c for c in s if not c in 'aeiouAEIOU'])

#4. Defina uma função hideChars(s) que receba uma string, possivelmente contendo espaços, e que retorne outra string substituindo os demais caracteres por '-', mas mantendo os espaços.
def hideChards(s): return ''.join([c if c==" " else "-" for c in s if c])

#5. Defina uma função que receba um número n e retorne uma tabela de números de 1 a n e seus quadrados.
def genTable(numbs): return [(numb, numb**2) for numb in range(1, numbs+1)]

#6. Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista.
def genCode(strings): return ''.join([string[0]+string[-1] for string in strings])

#7. Defina uma função myZip(l1,l2) que reproduza o comportamento da função zip do Python.
def myZip(l1, l2): return [(l1[x], l2[x]) for x in range(min(len(l1), len(l2)))]

#8. Escreva uma função enumerate(words) que numere cada palavra da lista recebida.
def enumerate(words): return [(words.index(word)+1, word) for word in words]

#9. Escreva uma função isBin(s) que verifique se a string recebida representa um número binário.
def isBin(s): return not bool([c for c in s if not c in '01'])

#10. Escreva uma função bin2dec(digits), que receba uma lista de dígitos representando um número binário e retorne seu equivalente em decimal.
def bin2dec(digits): return sum([2**num for num in range(len(digits)-1,-1,-1) if digits[-num-1] in '1'])
