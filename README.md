# 💻 Algoritmo FNC-3-SAT 

- O objetivo desse trabalho prático é a implementação para o “Problema da Satisfatividade (SAT)”. Mais especificamente, trataremos do problema conhecido por FNC-3-SAT, que é uma versão de SAT. Esse é um problema intratável, pois sua solução exata somente é possível através do cálculo e avaliação de todas as possíveis saídas, o que chamamos de força bruta.

- O objetivo é encontrar uma configuração de valores lógicos para as variáveis envolvidas na equação de entrada, tal que a mesma seja avaliada como verdadeira, isto é, que ela seja satisfeita.

- Como se trata de um algoritmo de elevado custo computacional, a configuração do computador de testes é levada em conta, no caso a configuração foi: 


## 🧪 Resultados 

- O algoritmo foi rodado no modo automático para as seguintes entradas: 15, 20, 30, 45 literais

	- Entrada N = 15 - Tempo: 0s
	- Entrada N = 20 - Tempo: 7s
	- Entrada N = 30 - Tempo: 10800s
	- Entrada N = 45 - Tempo: 61200s

- No gráfico abaixo é nítido o aumento exponencial do tempo de
    processamento do algoritmo à medida que a entrada aumenta, tendo
    um comportamento assintótico O(n2).


  ![grafico](https://github.com/IcaroM-CdC/Trabalho-pratico-2-AEDS/blob/main/imagens/Grafico%20desempenho.png)


## 🚀  Executando 

- Clone o repositorio

	```bash
	$ git clone https://github.com/IcaroM-CdC/Trabalho-pratico-2-AEDS.git
	```

- Siga os passos abaixo
	```bash
	# Compilando o algoritmo
	$ make compile

	# Iniciando o algoritmo
	$ make run
	```
