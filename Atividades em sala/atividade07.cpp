/*Defina um algoritmo, apresente uma codificação para o algoritmo, e realize a análise do algoritmo utilizando a abordagem matemática. A análise do algoritmo deve identificar as primitivas, identificar a quantidade de vezes que cada uma das primitivas é executada e somar o custo total. O algoritmo deve utilizar estruturas de repetições aninhadas.
Demonstrar que f(n) = 5∗n3+2∗n+2+1 é Θ(g(n)).


Respostas:

Coloque sua(s) resposta(s) aqui!

1) void transposta (int matriz[M][M]) { 
for (int i = 0; i < M; i++) {
for (int j = 0; j < M; j++) { 
cout << matriz[j][i] << " ";
    }
cout << "\n"; 
  }
}
Custo do for (for (int i = 0; i < M; i++)) c1 2(n+1) 
Custo do for(for (int j = 0; j < M; j++)) c2 n*2(n+1)
Acesso a posição (cout << matriz[j][i] << " ") c3 n*n
f(n) = 2n+1+ 2n2+2n + n2 = f(n) = 3n2+4n+1

Complexidade Quadrática
2) gn = n³
0 ≤ c1*g(n) ≤ f(n) ≤ c2*g(n)
0 ≤ 1x1³ ≤ 5x1³ + 2x1 + 2+1 ≤ 10 x 1³
0 ≤ 1 ≤ 10 ≤ 10
n0 = 1
c1=1
c2 = 10
∀n> 1 sempre será verdadeira -> f(n) E O(n), pois g(n)=n limita
inferiormente e superiormente f(n)

*/