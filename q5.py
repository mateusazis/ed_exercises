import sys

class Node(object):
    def __init__(self, value):
        self.prox = None
        self.value = value

def create_list(elements):
    ant = None
    first = None
    for e in elements:
        n = Node(e)
        if ant:
            ant.prox = n
        ant = n
        first = first or n
    return first


def print_list(l):
    while l:
        sys.stdout.write(str(l.value))
        sys.stdout.write(" ")
        l = l.prox
    print('')

def invert(l):
    if not l:
        return l

    ant = l
    cur = ant.prox
    ant.prox = None
    while cur:
        next_node = cur.prox
        cur.prox = ant
        ant = cur
        cur = next_node

    return ant

def to_list(n):
    resp = []
    while n:
        resp.append(n.value)
        n = n.prox
    return resp