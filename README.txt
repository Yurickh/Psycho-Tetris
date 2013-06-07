Grupo:
Andre Lima - 12/0059908
Yurick Hauschild - 12/0024136
Mariana Pannunzio - 12/0018276

PSYCHO TETRIS mega beta
	versão: 1.0

INSTRUÇÕES:

========================================================================
	Índice:
		I) Execução
			a) Linux
			b) Windows e outros OS
		II) Gameplay
			a) O Objetivo
			b) Movendo Peças
			c) Perdendo o jogo
		III) Bugs conhecidos
========================================================================

	I) Execução

		a) Linux
			Para executar o código em linux, só é preciso encontrar o arquivo já compilado tetris.exe na pasta bin/ e executá-lo.

		b) Windows ou outros OS
			Caso queira jogar em outros Sistemas Operacionais, é possível compilar o código a partir dos arquivos contidos na pasta src/. Para tal, é necessário instalar o ncurses previamente. Para tal, acesse http://www.gnu.org/software/ncurses/ e procure as informações relativas ao seu sistema operacional.

-------------------------------------------------------------------------

	II) Gameplay

		a) O Objetivo
			O objetivo do jogo é impedir que a pilha de peças alcance o topo da tela. Para isso, o jogador deve combinar as peças de modo a formar linhas completas. Toda linha completa de peças na tela será imediatamente deletada, diminuindo a altura total da pilha de peças.

		b) Movendo Peças
			Você deve mover peças usando as teclas A, S e D do teclado, que movem a peça para o lado, para baixo e para a direita, respectivamente. A tecla W toda a peça, para que você a posicione na forma que julgar melhor aos seus objetivos.

		c) Perdendo o jogo
			Você perde o jogo quando sua pilha de peças alcança o topo da tela. A derrota é instantânea, então evite acumular muitas peças!

-------------------------------------------------------------------------

	III) Bugs conhecidos

		a) Movimentação de último momento
			O jogador deve ser capaz de rearranjar a peça mesmo ela já tendo tocado o fundo da tela/outra peça.

		b) Fim de jogo
			O fim de jogo não é claro, parecendo que ele verifica a linha errada.

		c) Peças não rodam
			As peças devem rodar ao se apertar a tecla W.

-------------------------------------------------------------------------

Divirta-se!

