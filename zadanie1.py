import argparse
import sys

def encrypting(text_to_encrypt, decrypted_text, password):
    shift = 0
    for character in password:
        shift = shift + ord(character)

    text = text_to_encrypt.read()
    index = 0
    for character in text:
        if ord(character) >= 65 and ord(character) <= 90:
            index = ord(character) - ord('A')
            index = (index + shift) % 26
            index = index + ord('A')
            character = chr(index)
            decrypted_text.write(character)
        elif ord(character) >= 97 and ord(character) <= 122:
            index = ord(character) - ord('a')
            index = (index + shift) % 26
            index = index + ord('a')
            character = chr(index)
            decrypted_text.write(character)
        else:
            decrypted_text.write(character)
    
   



def decrypting(text_to_decrypt, raw_text, password):
    shift = 0
    for character in password:
        shift = shift + ord(character)

    text = text_to_decrypt.read()
    index = 0
    for character in text:
        if ord(character) >= 65 and ord(character) <= 90:
            index = ord(character) - ord('A')
            index = (index - shift) % 26
            index = index + ord('A')
            character = chr(index)
            raw_text.write(character)
        elif ord(character) >= 97 and ord(character) <= 122:
            index = ord(character) - ord('a')
            index = (index - shift) % 26
            index = index + ord('a')
            character = chr(index)
            raw_text.write(character)
        else:
            raw_text.write(character)
    
   


parser = argparse.ArgumentParser()

parser.add_argument('-p', '--password')
parser.add_argument('-i', '--input')
parser.add_argument('-o', '--output')
parser.add_argument('-d', action='store_true')
parser.add_argument('-s', action='store_true')


args = parser.parse_args()

#test
if len(sys.argv) != 8:
    print("chyba")
    exit()

if args.s == True:
    text_to_encrypt = open(args.input, 'r') 
    decrypted_text = open(args.output, 'w')
    encrypting(text_to_encrypt, decrypted_text, args.password)
    text_to_encrypt.close
    decrypted_text.close
elif args.d == True:
    text_to_decrypt = open(args.input, 'r')
    raw_text = open(args.output, 'w')
    decrypting(text_to_decrypt, raw_text, args.password)
