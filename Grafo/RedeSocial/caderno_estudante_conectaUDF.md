# Caderno do Estudante
# Projeto ConectaUDF: redes sociais com grafos
**Disciplina:** Algoritmos / Matemática Discreta / Ciência de Dados

## 1. O desafio
Você faz parte da equipe que analisa a rede social fictícia **ConectaUDF**. Sua missão é representar as amizades em um grafo, realizar cálculos e usar Python para interpretar a estrutura da rede.

## 2. Conceitos essenciais
- **Vértice (ou nó):** representa um usuário.
- **Aresta:** representa uma amizade entre dois usuários.
- **Grau:** quantidade de conexões diretas de um usuário.
- **Caminho:** sequência de usuários em que cada par consecutivo está conectado.
- **Densidade:** proporção entre as amizades existentes e todas as amizades possíveis.

Neste projeto, a amizade é recíproca. Portanto, usamos um **grafo não direcionado**.

## 3. Conheça os usuários
| Código | Usuário |
|---|---|
| A | Ana |
| B | Bruno |
| C | Carla |
| D | Diego |
| E | Elisa |
| F | Felipe |

As amizades são:
1. Ana — Bruno
2. Ana — Carla
3. Bruno — Carla
4. Bruno — Diego
5. Carla — Elisa
6. Diego — Elisa
7. Diego — Felipe
8. Elisa — Felipe

## 4. Passo a passo: desenhe o grafo
1. Desenhe seis círculos, um para cada usuário.
2. Escreva o nome de cada pessoa dentro do círculo.
3. Para cada amizade da lista, desenhe uma linha entre os dois usuários.
4. Não desenhe duas linhas para a mesma amizade.
5. Confira se todas as oito amizades aparecem.

   <img width="756" height="353" alt="image" src="https://github.com/user-attachments/assets/a241a95f-e2f3-45f6-a247-d406896ad56f" />


**Espaço para o seu desenho:** faça o grafo no caderno ou em uma ferramenta de desenho.

## 5. Passo a passo: calcule o grau
Conte quantas linhas chegam a cada círculo. Registre o resultado.

| Usuário | Amigos diretos | Grau |
|---|---|---:|
| Ana | Bruno - Carla | 2 |
| Bruno | Ana - Carla - Diego | 3 |
| Carla | Ana - Bruno - Elisa | 3 |
| Diego | Bruno - Elisa - Felipe | 3 |
| Elisa | Carla - Diego - Felipe | 3 |
| Felipe | Diego - Elisa | 2 |

**Pergunta 1:** quem tem mais conexões diretas?  
Resposta: Bruno, Carla, Diego e Elisa

## 6. Passo a passo: calcule o número de amizades
Some todos os graus. Como cada amizade conecta dois usuários, cada aresta é contada duas vezes.

**Fórmula:**  
`Número de arestas = soma dos graus ÷ 2`

1. Soma dos graus: 16
2. Divida por 2: 16 ÷ 2 = 8
3. Quantas amizades existem no grafo? 8

## 7. Passo a passo: calcule a densidade
A densidade compara as amizades existentes com o total de amizades possíveis.

Para um grafo simples não direcionado:

`D = 2 × E / (V × (V − 1))`

Em que:
- `D` = densidade;
- `E` = número de arestas;
- `V` = número de vértices.

Substitua os valores:
`D = 2 × 8 / ( 6 × ( 6 − 1))`

Resultado decimal: 16/30 = 0,53  
Resultado percentual: 53,3 %

**Interprete:** a rede tem poucas ou muitas das conexões possíveis? Explique com suas palavras.
R: Ao analisar a rede de amizades, podemos notar que ela possui mais da metade das conexões (com um porcentual de 53%). É uma rede moderadamente densa onde é bem conectada para um grupo pequeno (Tendo em vista que temos um máximo de 15 conexões possíveis entre 6 pessoas, onde pelo menos 8 conexões já são existentes).  
________________________________________________________________

## 8. Passo a passo: represente o grafo em Python
A lista de adjacência registra, para cada usuário, os nomes de seus amigos. Digite o código em Python (por exemplo, no Google Colab ou em outro ambiente disponível).

```python
rede = {
    "Ana": ["Bruno", "Carla"],
    "Bruno": ["Ana", "Carla", "Diego"],
    "Carla": ["Ana", "Bruno", "Elisa"],
    "Diego": ["Bruno", "Elisa", "Felipe"],
    "Elisa": ["Carla", "Diego", "Felipe"],
    "Felipe": ["Diego", "Elisa"]
}

# Quantidade de usuarios
n = len(rede)

# Calcule o grau de cada usuario
for usuario, amigos in rede.items():
    print(usuario, "tem", len(amigos), "conexoes")

# A soma dos graus conta cada amizade duas vezes
soma_graus = sum(len(amigos) for amigos in rede.values())
arestas = soma_graus // 2

print("Total de usuarios:", n)
print("Total de amizades:", arestas)

# Densidade do grafo
densidade = (2 * arestas) / (n * (n - 1))
print(f"Densidade: {densidade:.2%}")
```

### Entenda o código
1. `rede` guarda os usuários e suas listas de amigos.
2. `len(rede)` conta os usuários.
3. `len(amigos)` calcula o grau de cada usuário.
4. `sum(...)` soma os graus.
5. `// 2` divide a soma por dois para contar cada amizade uma única vez.
6. A fórmula final calcula a densidade.


Código:

link : https://colab.research.google.com/drive/1nPUqzW-AyDs1SVcCnaH7x9ihLCoBgT5D?usp=sharing

## 9. Passo a passo: encontre um caminho
Encontre um caminho de Ana até Felipe. Cada passagem por uma linha corresponde a uma aresta.

Exemplo de registro:
`Ana → Bruno → Diego → Felipe`

- Quantas arestas há no caminho? 3
- Você encontrou outro caminho com a mesma quantidade de arestas? Qual? Sim, Ana → Carla → Elisa → Felipe

________________________________________________________________

## 10. Desafio em grupo
Amplie a rede social:
1. Adicione pelo menos quatro usuários fictícios.
2. Crie no mínimo cinco novas amizades.

  <img width="966" height="405" alt="image" src="https://github.com/user-attachments/assets/229a42d4-67f1-4c8e-9452-aa67ae18bdbb" />

3. Atualize a lista de adjacência no Python.

  # Lista de adjacência atualizada com 10 usuários e 14 amizades

```python
rede_ampliada = {
  "Ana": ["Bruno", "Carla"],
  "Bruno": ["Ana", "Carla", "Diego", "Gabriel"],
  "Carla": ["Ana", "Bruno", "Elisa", "Gabriel"],
  "Diego": ["Bruno", "Elisa", "Felipe"],
  "Elisa": ["Carla", "Diego", "Felipe", "Igor"],
  "Felipe": ["Diego", "Elisa", "Helena"],
  "Gabriel": ["Bruno", "Carla", "Julia"],
  "Helena": ["Felipe", "Igor"],
  "Igor": ["Elisa", "Helena"],
  "Julia": ["Gabriel"]
}
# Quantidade de usuários (V)
n = len(rede_ampliada)
print("=== GRAU DE CADA USUÁRIO (REDE AMPLIADA) ===")
for usuario, amigos in rede_ampliada.items():

  print(f"{usuario}: {len(amigos)} conexões -> {amigos}")
# Cálculo de arestas (E)
soma_graus = sum(len(amigos) for amigos in rede_ampliada.values())
arestas = soma_graus // 2
# Cálculo de densidade (D)
densidade = (2 * arestas) / (n * (n - 1))
print("\n=== RESUMO MÉTRICO ===")
print(f"Soma dos graus: {soma_graus}")
print(f"Total de usuários (V): {n}")
print(f"Total de amizades (E): {arestas}")
print(f"Densidade da rede: {densidade:.4f} ({densidade:.2%})")
# Identificando os usuários mais conectados

maior_grau = max(len(amigos) for amigos in rede_ampliada.values())

mais_conectados = [u for u, a in rede_ampliada.items() if len(a) == maior_grau]

print(f"Usuários mais conectados (Grau {maior_grau}): {', '.join(mais_conectados)}")
```
   
4. Recalcule os graus, o total de arestas e a densidade.

1. Soma dos graus: 28
2. Divida por 2: 28 ÷ 2 = 14
3. Quantas amizades existem no grafo? 14

   ## Densidade
`D = 2 × 14 / ( 10 × ( 10 − 1))`

Resultado decimal: 28/90 = 0,31  
Resultado percentual: 31,11 %

5. Compare a densidade antes e depois da ampliação.
| Usuário | Amigos diretos | Grau |
|---|---|---:|
| Ana | Bruno - Carla | 2 |
| Bruno | Ana - Carla - Diego - Gabriel | 4 |
| Carla | Ana - Bruno - Elisa - Gabriel | 4 |
| Diego | Bruno - Elisa - Felipe | 3 |
| Elisa | Carla - Diego - Felipe - Igor | 4 |
| Felipe | Diego - Elisa - Helena | 3 |
| Gabriel | Bruno - Carla - Julia | 3 |
| Helena | Felipe - Igor | 2 |
| Igor | Elisa - Helena | 2 |
| Julia | Gabriel | 1 |

6. Identifique os usuários com mais conexões.
Os usuários com mais conexão são Bruno, Carla e Elisa


7. Explique como a rede poderia recomendar uma nova amizade.

Se duas pessoas não são amigas, mas têm três amigos em comum, é provável que se conheçam. A rede pode usar essa informação para sugerir a amizade, mostrando quem são os amigos em comum.

## 11. Entrega
Entregue:
- desenho do grafo;
- tabela com os graus;
- cálculos de arestas e densidade;
- código Python executável;
- respostas às perguntas e breve conclusão.

## 12. Pergunta de reflexão
Duas pessoas ainda não são amigas, mas têm três amigos em comum. Como essa informação poderia ser usada para sugerir uma nova conexão? Quais cuidados de privacidade devem ser considerados ao analisar redes sociais?

Se duas pessoas não são amigas, mas têm três amigos em comum, é provável que se conheçam. A rede pode usar essa informação para sugerir a amizade, mostrando quem são os amigos em comum.
Sobre privacidade, o cuidado principal é que a pessoa saiba que seus dados são usados e possa escolher se quer isso. Também é preciso evitar que a sugestão exponha vínculos que alguém prefere manter em sigilo. 
