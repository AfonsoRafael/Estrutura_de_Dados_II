# Grafos, BFS e DFS — Simulação de contingência na rede Brasília–Curitiba

**Disciplina:** Estrutura de Dados II — Ciência da Computação
**Estudo de caso:** pane relacionada ao GPS e impactos em voos no Aeroporto de Brasília (G1, 22 set. 2026)
**Nome:** Afonso Rafael Evangelista da Silva

> **Aviso:** esta é uma simulação computacional didática. As cidades são reais, mas as conexões e os bloqueios são **fictícios**. O resultado não representa rotas aéreas e não pode orientar um voo real.

## 1. Problema

Quando um recurso de navegação fica indisponível, a operação precisa ser replanejada e algumas ligações deixam de estar disponíveis. Este trabalho modela uma rede hipotética de conexões entre cidades como um grafo e estuda o que acontece com a conectividade quando arestas são removidas.

## 2. Pergunta de pesquisa e objetivo

**Pergunta:** quando uma ou mais conexões da rede simulada são bloqueadas, ainda existe caminho entre a origem e o destino? Quantas arestas a mais o desvio exige, e como BFS e DFS se comportam diante disso?

**Objetivo:** implementar BFS e DFS em Python, simular bloqueios sem alterar a rede original e comparar os caminhos encontrados pelos dois algoritmos.

## 3. Estrutura do grafo

- **Tipo:** não dirigido e não ponderado (cada ligação vale nos dois sentidos e todas têm o mesmo "custo").
- **Tamanho:** 11 vértices e 15 arestas.
- **Representação:** lista de adjacência (`dict` de listas), gerada a partir de uma lista de arestas pela função `construir_grafo`. Isso garante que toda aresta apareça nas listas dos dois extremos.

GRAFO 

<img width="977" height="845" alt="image" src="https://github.com/user-attachments/assets/68fd2cae-09a3-4714-bf9a-a41c5404f90f" />


GRAFO COM BLOQUEIO

<img width="832" height="616" alt="image" src="https://github.com/user-attachments/assets/b8c256eb-4975-4aad-aead-fd1cdcd77ff6" />


| Vértice | Vizinhos |
|---|---|
| Brasília | Goiânia, Belo Horizonte, Cuiabá, Palmas |
| Goiânia | Brasília, Uberlândia, Campo Grande |
| Belo Horizonte | Brasília, Uberlândia, Rio de Janeiro, São Paulo |
| Uberlândia | Goiânia, Belo Horizonte, São Paulo |
| Cuiabá | Brasília, Campo Grande |
| Campo Grande | Goiânia, Cuiabá, Londrina |
| São Paulo | Belo Horizonte, Uberlândia, Rio de Janeiro, Curitiba |
| Rio de Janeiro | Belo Horizonte, São Paulo |
| Londrina | Campo Grande, Curitiba |
| Curitiba | São Paulo, Londrina |
| Palmas | Brasília |

**Justificativa das conexões:**
- **Dois "corredores" até Curitiba:** um pelo Sudeste (via São Paulo) e outro pelo Oeste (Campo Grande → Londrina). Assim dá para testar se a rede continua conexa depois de vários bloqueios.
- **Ciclos** (por exemplo, Brasília–Goiânia–Uberlândia–Belo Horizonte–Brasília). Eles mostram por que o controle de `visitados` é obrigatório.
- **Palmas** tem uma única ligação, ou seja, a aresta Brasília–Palmas é uma **ponte**. Ela serve para demonstrar desconexão com um único bloqueio.

## 4. Como executar

Requisito: Python 3.8 ou superior, sem bibliotecas externas.

```bash
python solucao_grafos.py            # modo interativo
python solucao_grafos.py --testes   # bateria de testes automáticos
```

No modo interativo, o usuário informa a origem e o destino. Nomes sem acento ou com maiúsculas e minúsculas trocadas são aceitos (`brasilia`, `SAO PAULO`), e cidades inexistentes são rejeitadas com a lista de opções válidas. Em seguida, o usuário pode bloquear quantas conexões quiser, no formato `Cidade A - Cidade B`. O programa recusa conexões que não existem.

## 5. Organização do código

| Função | Papel |
|---|---|
| `construir_grafo` | Gera a lista de adjacência simétrica a partir das arestas |
| `bfs` | Busca em largura com `deque` (fila FIFO). Marca o vértice como visitado ao enfileirar |
| `dfs` | Busca em profundidade com pilha (LIFO). Usa `reversed()` para explorar o 1º vizinho primeiro |
| `bloquear_conexoes` | Devolve uma **cópia** da rede sem as arestas indicadas, removidas nos dois sentidos |
| `reordenar_vizinhos` | Cópia com outra ordem de vizinhos (Experimento D) |
| `resolver_nome` / `normalizar` | Validação da entrada do usuário |
| `formatar` | Exibe o caminho e a quantidade de arestas, ou a mensagem de "sem caminho" |

## 6. Resultados (origem Brasília, destino Curitiba)

| Cenário | BFS | Arestas | DFS | Arestas |
|---|---|:-:|---|:-:|
| **A** Rede completa | Brasília → BH → São Paulo → Curitiba | 3 | Brasília → Goiânia → Uberlândia → BH → Rio → São Paulo → Curitiba | 6 |
| **B** Bloqueio BH–SP | Brasília → Goiânia → Uberlândia → São Paulo → Curitiba | 4 | Brasília → Goiânia → Uberlândia → BH → Rio → São Paulo → Curitiba | 6 |
| **C1** Bloqueios BH–SP e SP–Curitiba | Brasília → Goiânia → Campo Grande → Londrina → Curitiba | 4 | (mesmo caminho) | 4 |
| **C2** + bloqueio Londrina–Curitiba | sem caminho | — | sem caminho | — |
| **Extra** Ponte Brasília–Palmas (destino Palmas) | sem caminho | — | sem caminho | — |
| **D** Vizinhos de Brasília reordenados (Cuiabá primeiro) | Brasília → BH → São Paulo → Curitiba | 3 | Brasília → Cuiabá → Campo Grande → Goiânia → Uberlândia → BH → Rio → São Paulo → Curitiba | 8 |

Todos os 14 testes automáticos passaram. As saídas completas estão em `evidencias_testes.txt` (testes) e `evidencia_interativo.txt` (sessão interativa com entrada inválida e bloqueio inválido).

### Interpretação

- **A e B:** o BFS sempre devolve o caminho com o menor número de arestas. Com o bloqueio BH–SP, o desvio custa **+1 aresta** (de 3 para 4). O DFS segue o primeiro ramo até o fim e devolve caminhos mais longos, embora válidos.
- **C1:** mesmo com o corredor do Sudeste cortado, Curitiba continua alcançável pelo corredor Oeste. A rede ainda é **conexa** entre os dois vértices.
- **C2:** com as três arestas bloqueadas, Curitiba fica sem nenhuma ligação. O grafo se torna **desconexo**, e os dois algoritmos devolvem `None` depois de esgotar a fila ou a pilha.
- **Extra:** remover uma única **ponte** já isola um vértice. Isso mostra que a robustez depende de haver caminhos alternativos.
- **D:** o grafo é o mesmo, mas basta mudar a ordem dos vizinhos para o DFS devolver um caminho de 8 arestas. O BFS mantém o mínimo de 3, porque explora por níveis, e o número mínimo de arestas não depende da ordem.

## 7. Comparação BFS × DFS

| Aspecto | BFS | DFS |
|---|---|---|
| Estrutura | Fila (FIFO) | Pilha (LIFO) ou recursão |
| Estratégia | Explora por níveis (distância em arestas) | Aprofunda um ramo antes de voltar |
| Menor caminho? | **Sim**, em número de arestas, num grafo não ponderado | Não garante |
| Sensível à ordem dos vizinhos? | Pode mudar *qual* caminho mínimo sai, mas não o seu tamanho | Sim, pode mudar o caminho e o tamanho |
| Complexidade | O(V + E) | O(V + E) |
| Uso típico | Menor número de conexões, alcance por níveis | Testar se há caminho, explorar componentes |

## 8. Limitações

- **"Menor" aqui significa menos arestas**, e não menor tempo, distância ou custo. Para isso seria preciso um grafo **ponderado** e outro algoritmo, como Dijkstra ou A\* (Gomes, 2022, cap. 7).
- As conexões são fictícias e não consideram capacidade, horários, restrições operacionais, meteorologia nem regras de tráfego aéreo.
- O grafo é não dirigido. Uma rede real pode ter ligações num único sentido (grafo dirigido).
- O caminho é guardado como lista copiada a cada passo (`caminho + [vizinho]`). Isso é simples, mas gasta mais memória que guardar só o "pai" de cada vértice, o que faria diferença em redes grandes.
- O bloqueio é binário (a aresta existe ou não). Não há degradação parcial nem probabilidade de falha.

## 9. Referências

GOMES, Paulo César Rodacki. **Grafos: conceitos fundamentais, algoritmos e aplicações**. Blumenau: Editora IFC, 2022. ISBN 978-65-88089-12-5.

G1 DISTRITO FEDERAL. **Pane em GPS afeta voos da Azul no Aeroporto de Brasília; passageiros reclamam de atrasos**. 22 set. 2026. Disponível em: https://g1.globo.com/df/distrito-federal/noticia/2026/09/22/pane-em-gps-afeta-voos-da-azul-no-aeroporto-de-brasilia-passageiros-reclamam-de-atrasos.ghtml.
