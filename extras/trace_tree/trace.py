import re

trace_test = "Call: (7) avo(roberto, _G1492) ? creep  -> Chamada da regra avo verificando quem é neto de 'roberto' (caso possua).   Call: (8) pai(roberto, _G1568) ? creep  -> Chamada da regra pai verificando quem é filho de 'roberto' (caso possua).   Exit: (8) pai(roberto, joao) ? creep    -> Retorno positivo da regra pai afirmando que 'roberto' é pai de 'joao'.   Call: (8) pai(joao, _G1492) ? creep     -> Chamada da regra pai verificando quem é filho de 'joao' (caso possua).   Exit: (8) pai(joao, jose) ? creep       -> Retorno positivo da regra pai afirmando que 'joao' é pai de 'jose'.   Exit: (7) avo(roberto, jose) ? creep "


# Nodo class
class Nodo(object):
    # init
    def __init__(self, name="nodo"):
        self.name = name
        self.childs = []
        self.parent = None
        self.need_exit = False

    # add children
    def add_child(self, child):
        assert isinstance(child, Nodo)
        self.childs.append(child)

    # add parent
    def add_parent(self, parent):
        assert isinstance(parent, Nodo)
        self.parent = parent


# parse the trace
def parse_trace(trace): return re.findall("call|exit|fail|redo", trace.lower())

# define n1 as parent if not none and n2 as child
def dive(n1, n2):
    if n1 is None:
        n2.need_exit = True
    else:
        n1.need_exit = True
        n1.add_child(n2)
        n2.add_parent(n1)

# not implemented yet
def rise(n1):
    if n1 is not None:
        n1.need_exit = False

# may be used to get last nodo that need an exit
def get_nodo_need_exit(nodos):
    return list(filter(lambda x: x.need_exit, nodos))[-1]

# nodos list to controll them
nodos = []

# gerate the nodos based in the keyword "call", should be improved soon
def gerate_nodos(keywords):
    c = 0
    nodo_master = None
    nod1 = None
    for key in keywords:
        if (key=="call"):
            nod1 = Nodo(c)
            nodos.append(nod1)
            dive(nodo_master, nod1)
            nodo_master = nod1
            c += 1
        elif (key=="exit"):
            nodo_master = nod1.parent
            nod1 = nodo_master
            rise(nodo_master)
    return nodos[0]

# gerate the tree for the javascript render
def gerate_nodo_tree(nodo):
    tree = {}
    tree['name'] = nodo.name
    if(nodo.parent):
        tree['parent'] = nodo.parent.name
    else:
        tree['parent'] = nodo.parent
    tree['children'] = []
    for child in nodo.childs:
        tree['children'].append(gerate_nodo_tree(child))
    return tree

# call all
def transformer(trace):
    return [gerate_nodo_tree(gerate_nodos(parse_trace(trace)))]
