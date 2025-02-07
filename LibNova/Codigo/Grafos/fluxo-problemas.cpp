// Fluxo - Problemas

// 1: Problema do Corte
- Entrada:
	- N itens
	- Curso Wi Inteiro
	- M restricoes: se eu pegar Ai, eu preciso pegar Bi...
- Saida: valor maximo pegavel

- Solucao: corte maximo com Dinitz
	- dinitz(n+m+1)
	- f(i,0,n): i -> SNK com valor Ai
	- f(i,0,m):
		* SRC -> n+i com valor Wi
		* ParaTodo dependente Bj: n+i -> Bj com peso INF
	- ans = somatorio(Wi) - maxFlow(SRC,SNK);

/* ======================================================= */
