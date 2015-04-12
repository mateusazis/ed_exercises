def find_modo(l):
    ordered = list(l)
    ordered.sort()

    best_element = None
    best_count = 0
    last_element = None
    cur_count = 0

    for e in ordered:
        if e == last_element:
            cur_count += 1
        else:
            if cur_count > best_count:
                best_count = cur_count
                best_element = last_element
            cur_count = 1
        last_element = e
        
    if cur_count > best_count:
        best_count = cur_count
        best_element = last_element

    return best_element