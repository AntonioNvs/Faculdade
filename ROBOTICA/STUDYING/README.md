## Criação de simulações para fins de treino em robótica

### Não bate!
* O primeiro projeto baseia-se em uma arena, com a criação de objetos de tamanho e posiçõies aleatórias, destacados em verde, do qual o robô (o quadrado vermelho), tem que evitar a colisão ao seu andar. O objetivo é simples, ao prever uma colisão, mude a direção do robô para outra aleatória, simulando um robô que necessite andar sem colidir com obstáculos em um ambiente indefinido.
* <img src="https://i.ibb.co/JFVD1w0/Robot-Simulation.png" alt="Robot Simulation" width="500"/>

### WaveFront Simulation
* O segundo projeto é um ambiente simulando um grid *N x N* com obstáculos da cor *azul*, cujo objetivo é, com o objeto atual estando no canto superior esquerdo, conseguir encontrar o menor caminho que o leve até o *goal*, no canto inferior direito, Para isso, é simulado o algoritmo de **WaveFront**, o qual mapeia o ambiente como uma *onda*, da qual atualiza as casas vizinhas sempre com um valor a mais com a anterior. Nesse caso, foi utilizado *BFS* com conectividade 4.
* <img src="https://i.ibb.co/LYbwTcP/wavefront.gif" alt="WaveFront Simulation" width="500"/>

### Campos potenciais
* O terceiro projeto é uma simulação do modelo de navegação por campos potenciais, no qual o *goal* é retratado como uma força de atração para o robô e os obstáculos como força repulsiva, conseguindo, assim, a partir da construção e somatório dessas forças, definir o movimento ordenado do robô. Logo, o programa feito tem o robô como o círculo verde e os obstáculos como os círculos laranja. A definição do *goal* é dada pelo clique do mouse na tela, entretanto, por distorções na captura da tela, o *goal* e o ponteiro do mouse não ficaram no mesmo ponto.
* <img src="https://i.ibb.co/HCJ0qjG/Vetorial-Camp-Simulator-2022-06-08-09-55-30.gif" alt="Potencial Camp Simulation"/>
