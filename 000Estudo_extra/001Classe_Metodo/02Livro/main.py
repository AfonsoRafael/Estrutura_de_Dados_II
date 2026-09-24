from Livro import Livro

livros = []

def menu():
    print("""
________MENU________

1 criar livro
2 mostrar lista de livros
0 sair""")
    escolha = int(input("Informe o que deseja realizar: "))
    return escolha

def criarLivro(livros):
    titulo = input("informe o titulo: ")
    autor = input("informe o autor: ")
    livro = Livro(titulo, autor)
    livros.append(livro)
    return livros

def mostrarLivros(livros):
    if(livros == None):
        return print("Lista de livros vazia!")