import re

trace_test = "?- avo(joao, Y).   Call: (7) avo(joao, _G331) ? creep  Call: (8) pai(joao _G407) ? creep  Exit: (8) pai(joao, jose) ? creep   Call: (8) pai(jose, _G331) ? creep  -> Chamada da regra pai ve   Fail: (8) pai(jose, _G331) ? creep  -> Retorno negativo da reg   Fail: (7) avo(joao, _G331) ? creep  -> Retorno negativo da regra avô afirmando qu não é avô). false."


# Nodo class
class Nodo(object):
    # init
    def __init__(self, name="nodo"):
        self.name = name
        self.childs = []
        self.parent = []
        self.need_exit = False

    # add children
    def add_child(self, child):
        assert isinstance(child, Nodo)
        self.childs.append(child)

    # add parent
    def add_parent(self, parent):
        assert isinstance(parent, Nodo)
        self.parent.append(parent)


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
    n1.need_exit = False

# may be used to get last nodo that need an exit
def get_nodo_need_exit(nodos):
    return list(filter(lambda x: x.need_exit, nodos))[-1]

# nodos list to controll them
nodos= []

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
        if (key=="exit"):
            rise(nodo_master)
    return nodos[0]

# gerate the tree for the javascript render
def gerate_nodo_tree(nodo):
    tree = {}
    tree['name'] = nodo.name
    if(nodo.parent):
        tree['parent'] = nodo.parent[0].name
    else:
        tree['parent'] = nodo.parent
    tree['children'] = []
    for child in nodo.childs:
        tree['children'].append(gerate_nodo_tree(child))
    return tree

# call all
def transformer(trace):
    return [gerate_nodo_tree(gerate_nodos(parse_trace(trace)))]
