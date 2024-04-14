Grafo Direcionado Aciclico (DAG):
* Definicao
	- tem direcao
	- nao tem ciclos
	- problemas com ele => usar DP (estados da DP = vertices DAG)
	- so tem um topological sort
* Aplicacoes
	- Single Source (Shortest / Longest) Path na DAG => O(V + E)
	- Numero de caminhos entre 2 vertices => O(V + E)
	- Numero de caminhos de um vertice para todos os outros => O(V + E)
	- DP de 'minimizacao', 'maximizacao', 'contar algo' => menor | maior | contar numero de caminhos na recursao de DP na DAG
* Exemplos
	- mochila
	- troco