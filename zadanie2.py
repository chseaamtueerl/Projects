import math
import csv

def encrypting(text_to_encrypt):
    shift = 3
    ciphered = ""
    index = 0
    for character in text_to_encrypt:
        if ord(character) >= 65 and ord(character) <= 90:
            index = ord(character) - ord('A')
            index = (index + shift) % 26
            index = index + ord('A')
            character = chr(index)
            ciphered += character
            #decrypted_text.write(character)
        elif ord(character) >= 97 and ord(character) <= 122:
            index = ord(character) - ord('a')
            index = (index + shift) % 26
            index = index + ord('a')
            character = chr(index)
            ciphered += character
            #decrypted_text.write(character)
        else:
            ciphered += character
            #decrypted_text.write(character)
    return ciphered

hesla = open("hesla.csv")
tajny_subor = csv.reader(hesla)
pouzivatelia = []
for riadok in tajny_subor:
    pouzivatelia.append(riadok)
hesla.close

for i in range(5):
    pouzivatelia[i][0] = pouzivatelia[i][0].split(":")

meno = input("meno: ")
heslo = input("heslo: ")
heslo = encrypting(heslo)
kluc = input("overovaci kluc: ")
prvy = 1
for j in range(5):
    prvy = 1
    for l in pouzivatelia[j]:
        if prvy == 1:
            prvy = 0
        else:
            pouzivatelia[j][0].append(l)

if meno == "" or heslo == "" or kluc == "":
    print("chyba")
    exit()

pozicia = 0
for j in range(5):
    if pouzivatelia[j][0][0] == meno:
        pozicia = j

spravne_heslo = False
if heslo == pouzivatelia[pozicia][0][1]:
    spravne_heslo = True

spravny_kluc = False
poloha = 0
for poz in range(2, len(pouzivatelia[pozicia][0])):
    if pouzivatelia[pozicia][0][poz] == kluc:
        spravny_kluc = True
        poloha = poz
        break

if spravny_kluc and spravne_heslo:
    print("ok")
    del pouzivatelia[pozicia][0][poz]
    #print(pouzivatelia[pozicia][0])
else:
    print("chyba")

fp = open("hesla.csv", "w")
writer = csv.writer(fp)
row = ""
bodky = 2
pocitac = 0
for x in range(5):
    row = ""
    bodky = 2
    pocitac = 0
    for y in pouzivatelia[x][0]:
        row += y
        if bodky > 0:
            row += ":"
            bodky= bodky - 1
        elif pocitac != len(pouzivatelia[x][0])-1:
            row += ","
        pocitac = pocitac + 1
    if x != 4:
        fp.write(row + "\n")
    else:
        fp.write(row)
#print(row)