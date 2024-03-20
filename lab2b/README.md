
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/c906d7bb-3992-4604-9994-f61a8f8f21b3) <br>
Executei o seguinte programa em serie, e o tempo de execução foi de 0.000001 segundos. <br>
Após isso executei o programa em paralelo, com 1,2,4,6,8 processadores. <br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/d327f559-e339-4ea3-b326-7fb94ce348bc) <br>
Obtive o resultado acima <br>
Para 1: 0.000514 segundos<br>
Para 2: 0.000097 segundos<br>
Para 4: 0.000122 segundos<br>
Para 6: 0.000164 segundos<br>
Para 8: 0.000241 segundos<br>
Assim, gerei o grafico abaixo em Python: <br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/e0797973-e13f-4bf1-96c7-1afaab512183) <br>
A partir do gráfico, pude concluir que com 2 threads, observamos o menor tempo de execução, o que indica o melhor desempenho de paralelismo para esta configuração específica, no entanto ao adicionar mais threads além de um certo ponto não resultou em melhorias de desempenho e e até piorou o desempenho devido ao overhead associado à gestão das threads adicionais. <br>
Ao calcular o speed up obtive esse resultado: <br>
1 Thread: Speedup: 1.946 <br>
2 Threads: Speedup: 10.309 <br>
4 Threads: Speedup: 8.197 <br>
6 Threads: Speedup: 6.098 <br>
8 Threads: Speedup: 4.149 <br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/2c5d9c01-4662-4c72-980d-4169e89ee084) <br>
Para melhorar o desempenho, pensamos na solução de invés de usar thread para cada linha da matriz que participaria da multiplicação que no caso é uma matriz 4x4, separar em blocos menores as multiplicações para ter maiores benefícios e usos das threads, porém por já ser uma matriz pequena  no exemplo não obtive um aumento significativo no desempenho, continuando tendo um impacto negativo no uso de muitas threads devido ao overhead.
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/96657604-c138-4b5b-a168-db06262c4c88) <br>
Ao calcular o Speed up do codigo otimizado, obtive este resultado: 
1 Thread: Speedup: 1.923 <br>
2 Threads: Speedup: 11.364 <br>
4 Threads: Speedup: 7.813 <br>
6 Threads: Speedup: 5.848 <br>
8 Threads: Speedup: 4.132 <br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/dd2d66bb-14d1-49dc-8efa-30087d70cc38)

