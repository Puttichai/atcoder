O = raw_input()
E = raw_input()
pw = ''
if len(O) == len(E):
    for (o, e) in zip(O, E):
        pw += o
        pw += e
elif len(O) > len(E):
    for (o, e) in zip(O[:len(E)], E):
        pw += o
        pw += e
    pw += O[-1]
else:
    for (o, e) in zip(O, E[:len(O)]):
        pw += o
        pw += e
    pw += E[-1]
print pw
