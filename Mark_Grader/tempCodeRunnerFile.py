import sys
kb = sys.stdin
code = kb.readline().strip()
decrypt1 = 10000 + int(code[3]+code[10]+code[17]+code[24]+code[31]) + int(code[7]+code[12]+code[17]+code[22]+code[27])
decrypt1 = str(decrypt1)
decrypt2 = int(decrypt1[-2]+decrypt1[-3]+decrypt1[-4])
decrypt2 = str(decrypt2)
if decrypt1[-2] == "0":
    decrypt2 = "0" + decrypt2
    if decrypt1[-3] == "0":
        decrypt2 = "0" + decrypt2
        if decrypt1[-4] == "0":
            decrypt2 = "0" + decrypt2
result = decrypt2
decrypt3 = int(decrypt2[0]) + int(decrypt2[1]) + int(decrypt2[2])
decrypt3 = str(decrypt3)
decrypt4 = int(decrypt3[-1]) + 1
alphabet = "ABCDEFGHIJ"
print(result + alphabet[decrypt4-1])