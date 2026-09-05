# =====================================================================
# DESAFIO MASTER: Triagem Hospitalar com Protocolo de Cores (Manchester)
# =====================================================================
from collections import deque
import time

class Paciente:
    def __init__(self, nome, cor_triagem):
        self.nome = nome
        self.cor = cor_triagem.upper()
        # Define o peso numérico da prioridade (quanto menor o número, mais urgente)
        MAPA_PRIORIDADE = {'VERMELHO': 1, 'LARANJA': 2, 'AMARELO': 3, 'VERDE': 4, 'AZUL': 5}
        self.peso = MAPA_PRIORIDADE.get(self.cor, 5)

    def __repr__(self):
        return f"{self.nome} ({self.cor})"


class SistemaHospitalar:
    def __init__(self):
        # A fila inicia completamente vazia, dependendo apenas do usuario
        self.fila = deque()

    def inserir_por_prioridade(self, novo_paciente):
        """
        Insere o paciente na posição correta da fila baseado na sua urgência (cor).
        Garante tempo otimizado e respeita a ordem de chegada entre cores iguais.
        """
        if not self.fila:
            self.fila.append(novo_paciente)
            return

        # Se for o caso mais grave (Vermelho), insere após o último vermelho
        if novo_paciente.peso == 1:
            posicao = 0
            for paciente in self.fila:
                if paciente.peso == 1:
                    posicao += 1
                else:
                    break
            self.fila.insert(posicao, novo_paciente)
        
        # Se for o caso menos grave (Azul), vai direto para o final da fila (append)
        elif novo_paciente.peso == 5:
            self.fila.append(novo_paciente)
            
        # Para as cores intermediárias (Laranja, Amarelo, Verde), localiza a posição correta
        else:
            posicao = 0
            inserted = False
            for paciente in self.fila:
                # Avança até achar alguém com menor prioridade (peso maior que o dele)
                if paciente.peso <= novo_paciente.peso:
                    posicao += 1
                else:
                    self.fila.insert(posicao, novo_paciente)
                    inserted = True
                    break
            if not inserted:
                self.fila.append(novo_paciente)

    def chamar_proximo(self):
        if self.fila:
            paciente = self.fila.popleft()
            print(f"\n[CHAMADA] Proximo paciente: {paciente} dirija-se ao Consultorio 1.")
        else:
            print("\nFila vazia! Nenhum paciente aguardando atendimento no momento.")

    def exibir_painel(self):
        print("\n==============================================")
        print("PAINEL DA FILA DE ATENDIMENTO ATUAL")
        print("==============================================")
        if not self.fila:
            print("  [ Fila vazia - Nenhum paciente aguardando ]")
        else:
            for i, paciente in enumerate(self.fila, 1):
                print(f"  {i} Lugar -> {paciente}")
        print("==============================================\n")


# =====================================================================
# MENU INTERATIVO (INTERFACE DO USUÁRIO NO COLAB)
# =====================================================================
hospital = SistemaHospitalar()

while True:
    print("--- SISTEMA DE TRIAGEM HOSPITALAR ---")
    print("1. Cadastrar Novo Paciente (Triagem)")
    print("2. Chamar Proximo Paciente para Atendimento")
    print("3. Visualizar Painel da Fila Completa")
    print("4. Encerrar Sistema")
    
    opcao = input("Digite a opcao desejada (1-4): ").strip()

    if opcao == '1':
        nome = input("\nDigite o nome do paciente: ").strip()
        if not nome:
            print("Nome invalido. Cadastro cancelado.\n")
            continue
            
        print("\nSelecione a classificacao de risco (Protocolo de Manchester):")
        print("1. VERMELHO - Emergencia (Risco imediato)")
        print("2. LARANJA  - Muito Urgente")
        print("3. AMARELO  - Urgente")
        print("4. VERDE    - Pouco Urgente (Fluxo Padrao)")
        print("5. AZUL     - Nao Urgente")
        
        cor_opcao = input("Digite o numero da cor (1-5): ").strip()
        
        mapa_cores = {'1': 'VERMELHO', '2': 'LARANJA', '3': 'AMARELO', '4': 'VERDE', '5': 'AZUL'}
        cor_escolhida = mapa_cores.get(cor_opcao)
        
        if cor_escolhida:
            novo_p = Paciente(nome, cor_escolhida)
            hospital.inserir_por_prioridade(novo_p)
            print(f"\nPaciente {novo_p} adicionado com sucesso na posicao correta da fila!\n")
        else:
            print("Opcao de cor invalida. Paciente nao cadastrado.\n")
            
        time.sleep(1)

    elif opcao == '2':
        hospital.chamar_proximo()
        time.sleep(1.5)
        print()

    elif opcao == '3':
        hospital.exibir_painel()
        input("Pressione ENTER para voltar ao menu...")
        print()

    elif opcao == '4':
        print("\nDesligando o sistema hospitalar. Ate logo!")
        break
    else:
        print("Opcao invalida! Digite um numero de 1 a 4.\n")
        time.sleep(1)
