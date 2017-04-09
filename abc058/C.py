n = int(raw_input())
S = []
alphabet = 'abcdefghijklmnopqrstuvwxyz'
for i in xrange(n):
    S.append(raw_input())

res = ''
for alph in alphabet:
    min_encounter = S[0].count(alph)
    if min_encounter == 0:
        continue
    
    for s in S[1:]:
        encounter = s.count(alph)
        min_encounter = min(encounter, min_encounter)
        if min_encounter == 0:
            break

    if min_encounter == 0:
        continue
    res += alph * min_encounter
print res
