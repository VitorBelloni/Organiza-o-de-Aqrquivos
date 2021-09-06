#!/usr/bin/python
# 

import linecache
import sys

def binary_search(query, inicio, fim, total):
    posicao = (inicio + fim)/2

    linha = linecache.getline(r"cep_ordenado.dat", posicao)
    cep_posicao = linha[-10:len(linha)-1]        

    if fim == inicio:
        if posicao == total:
            print("O CEP " + query + " nao foi encontrado !!!")
        else:
            if query == cep_posicao:
                registro = linha
            else:
                posicao = posicao + 1
                linha = linecache.getline(r"cep_ordenado.dat", posicao)
                if query == cep_posicao:
                    registro = linha
                else:
                    posicao = posicao - 1
                    linha = linecache.getline(r"cep_ordenado.dat", posicao)
                    registro = linha
            print("==================================================================================")
            print("CEP ENCONTRADO !!!")
            print("ENDERECO ABAIXO")
            print("==================================================================================")
            print(registro)
    else:
        if query < cep_posicao:
            posicao = posicao - 1
            binary_search(query, inicio, posicao, total)
        else:
            posicao = posicao + 1
            binary_search(query, posicao, fim, total)

sys.setrecursionlimit(800000)

inicioarq = 0
fimarq = sum(1 for line in open('cep_ordenado.dat')) 

binary_search("20541005", inicioarq, fimarq, fimarq)