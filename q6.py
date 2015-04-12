def swap(n, pos):
    if not n or not n.prox:
        raise Exception("Invalid list position to swap.")

    ant = None
    first = n
    i = 0
    while i < pos:
        if not n:
            raise Exception("Invalid list position to swap.")
        i += 1
        ant = n
        n = n.prox

    if not n or not n.prox:
        raise Exception("Invalid list position to swap.")

    next = n.prox
    if ant:
        ant.prox = next
    n.prox = next.prox
    next.prox = n

    return next if pos == 0 else ant