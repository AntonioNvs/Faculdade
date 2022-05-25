## Criação de simulações para fins de treino em robótica

### Não bate!
* O primeiro projeto baseia-se em uma arena, com a criação de objetos de tamanho e posiçõies aleatórias, destacados em verde, do qual o robô (o quadrado vermelho), tem que evitar a colisão ao seu andar. O objetivo é simples, ao prever uma colisão, mude a direção do robô para outra aleatória, simulando um robô que necessite andar sem colidir com obstáculos em um ambiente indefinido.
* ![Robot Simulation](https://i.ibb.co/JFVD1w0/Robot-Simulation.png)

### WaveFront Simulation
* O segundo projeto é um ambiente simulando um grid *N x N* com obstáculos da cor *azul*, cujo objetivo é, com o objeto atual estando no canto superior esquerdo, conseguir encontrar o menor caminho que o leve até o *goal*, no canto inferior direito, Para isso, é simulado o algoritmo de **WaveFront**, o qual mapeia o ambiente como uma *onda*, da qual atualiza as casas vizinhas sempre com um valor a mais com a anterior. Nesse caso, foi utilizado *BFS* com conectividade 4.
* <img src="[drawing.jpg](https://i.ibb.co/LYbwTcP/wavefront.gif)" alt="WaveFront Simulation" style="width:200px;height:200px"/>
