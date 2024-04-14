Criterio |   BFS (V + E) | Dijkstra (E*log V) | Bellman-Ford (V*E) | Floyd-Warshall (V^3)
---------+---------------+--------------------+--------------------+----------------------
Max Size | V + E <= 100M | V + E <= 1M        | V * E <= 100M      | V <= 450
Sem-Peso | CRIA          | Ok                 | Ruim               | Ruim no geral
Peso     | WA            | Melhor             | Ok                 | Ruim no geral
Peso Neg | WA            | Modificado Ok      | Ok                 | Ruim no geral
Neg-Cic  | Nao Detecta   | Nao Detecta        | Detecta            | Detecta
Grafo Peq| WA se peso    | Overkill           | Overkill           | Melhor