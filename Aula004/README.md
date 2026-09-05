# Sistema de Triagem Hospitalar (Protocolo de Manchester)

Este projeto implementa um sistema de gerenciamento de fila para atendimento medico baseado no Protocolo de Manchester. O objetivo principal e garantir que pacientes com casos mais graves sejam atendidos prioritariamente, sem que o sistema perca a ordem de chegada de pacientes com o mesmo nivel de urgencia.

---

## 1. Regras de Negocio do Projeto

O sistema adota o padrao internacional de triagem por cores. Cada cor representa um nivel de gravidade e define a posicao que o paciente ocupara na fila de espera assim que der entrada no hospital:

1. **VERMELHO (Emergencia):** Pacientes com risco imediato de morte. Entram no inicio absoluto da fila. Se houver mais de um paciente vermelho, respeita-se a ordem de chegada entre eles.
2. **LARANJA (Muito Urgente):** Pacientes com risco significativo. Entram logo atras dos pacientes vermelhos, mas na frente de todos os outros.
3. **AMARELO (Urgente):** Pacientes com gravidade moderada. Entram atras dos laranjas e na frente dos verdes.
4. **VERDE (Pouco Urgente):** Fluxo padrao do hospital. Entram atras dos amarelos e na frente dos azuis.
5. **AZUL (Nao Urgente):** Casos simples ou de baixa complexidade. Vao diretamente para o final absoluto da fila.

---

## 2. Arquitetura e Engenharia do Codigo

O algoritmo foi desenvolvido em Python utilizando boas praticas de estruturas de dados para garantir alta eficiencia e escalabilidade.

### A Estrutura collections.deque
A dica de arquitetura central do projeto e a utilizacao do deque (Double-Ended Queue / Fila de Duas Pontas) do modulo nativo collections. 

* **Por que nao usar uma lista comum?** Em listas tradicionais do Python, inserir um elemento na primeira posicao (lista.insert(0, elemento)) ou remover do inicio (lista.pop(0)) exige que o computador desloque todos os outros elementos na memoria. Isso gera um custo computacional de Tempo O(n), o que tornaria o sistema lento em hospitais com muitos pacientes.
* **A vantagem do deque:** O deque e implementado como uma lista duplamente encadeada. Isso permite que operacoes no inicio (appendleft e popleft) e no fim (append) ocorram em Tempo Constante O(1), ou seja, sao processadas instantaneamente de forma otimizada.

### Logica de Insercao por Prioridade
O metodo inserir_por_prioridade analisa o peso numerico atribuido a cada cor (Vermelho = 1 ate Azul = 5). 

* **Extremos da Fila:** Pacientes com peso 1 (Vermelho) tentam utilizar a vantagem do appendleft() sempre que possivel. Pacientes com peso 5 (Azul) utilizam diretamente o append().
* **Insercao Intermediaria:** Para as cores intermediarias, o algoritmo percorre a fila sequencialmente. Ele avanca enquanto encontrar pacientes com prioridade maior ou igual (pesos menores ou iguais) e realiza a insercao (insert) exatamente antes do primeiro paciente que possuir uma urgencia menor (peso maior). Isso garante que o novo paciente fique atras de quem chegou antes com a mesma cor, mantendo a integridade do atendimento por ordem de chegada.
