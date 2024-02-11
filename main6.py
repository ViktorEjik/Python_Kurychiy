import ast

def tree(a_tree, b_tree):
    if len(a_tree) != len(b_tree):
        return False
    res = list()
    for i in range(len(a_tree)):
        if(type(a_tree[i]) != type(b_tree[i])):
            res.append(False)
        elif isinstance(a_tree[i], ast.Assign):
            if not all(map(lambda x, y: isinstance(x, type(y)), a_tree[i].targets, b_tree[i].targets)):
                res.append(False)
                continue
            elif not isinstance(a_tree[i].value, type(b_tree[i].value)):
                res.append(False)
                continue
            
            if isinstance(a_tree[i].value, ast.Constant):
                res.append(a_tree[i].value.value == b_tree[i].value.value)
                continue
            elif isinstance(a_tree[i].value, ast.Attribute):
                res.append(True)
                continue
            elif isinstance(a_tree[i].value, ast.Call):
                if a_tree[i].value.fun.id != b_tree[i].value.fun.id:
                    res.append(False)
                    continue
                if len(a_tree[i].value.args) != len(a_tree[i].value.args):
                    res.append(False)
                    continue
                res.append(True)
                continue
        elif isinstance(a_tree[i], ast.FunctionDef):
            res.append(len(a_tree[i].args.args) == len(b_tree[i].args.args))
        elif isinstance(a_tree[i], ast.For):
            res.append(a_tree[i].iter.func.id == b_tree[i].iter.func.id)
            if len(a_tree[i].iter.args) != len(a_tree[i].iter.args):
                res.append(False)
                continue
            res.append(True)
            res.append(tree(a_tree[i].body, b_tree[i].body))
        elif isinstance(a_tree[i].value, ast.Call):
                if a_tree[i].value.func.id != b_tree[i].value.func.id:
                    res.append(False)
                    continue
                if len(a_tree[i].value.args) != len(a_tree[i].value.args):
                    res.append(False)
                    continue
                res.append(True)
                continue
    return all(res)

    

def copypaste(A, B):
    if A is B or A == B:
        return True

    A_parse = ast.parse(A)
    B_parse = ast.parse(B)

    return tree(A_parse.body, B_parse.body)
