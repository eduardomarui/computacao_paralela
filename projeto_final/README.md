# Projeto de Cálculo da Constante de Euler (e)

## Descrição
Este projeto calcula a constante de Euler (*e*) utilizando a série de Taylor de forma paralela para alcançar uma alta precisão. O objetivo é explorar técnicas de computação paralela para otimizar o desempenho do cálculo.

## Requisitos de Compilação
- **Compilador C**: GCC com suporte para OpenMP
- **Bibliotecas**: OpenMP (para paralelismo)

## Como Compilar
```
gcc -fopenmp programa.c -o programa
```

## Como Executar
Execute o programa usando o seguinte comando:
```
./programa
```
## V0
serial
<br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/4175272e-f435-4bad-a576-974b149726cd)
<br>
paralelo <br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/de09316d-60d4-4893-a1f4-fe77daaad982)
<br>
critical <br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/9aa4383c-46dd-4cfd-b337-7039dce6537f)
<br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/48c5e942-6421-4722-b2e1-c98a4477441c)
<br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/9a79eb28-93dc-487e-8585-1abbc13a106c)
<br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/41080e25-a1d4-4e0b-8d61-bc3fb956a04e)
<br>
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/ba6cbac1-50be-4fcb-b441-3ba1310c5d25)
<br>
## Verificação dos Resultados
O programa imprime o valor calculado de e. Porém, na V0 não houve resultados significantes ao usar paralelismo devido à sobrecarga de gerenciamento de threads. Além disso, o cálculo da série de Taylor usando o tipo double não apresenta tanta complexidade computacional para se beneficiar do paralelismo.
## V1
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/780577a7-5d94-4baf-b9b7-7f65f35c74f5)
## Verificação dos Resultados
Na versão 1, utilizamos o cálculo incremental do fatorial, o que diminuiu o tempo de execução em relação à versão 0, mas não obteve impacto significativo ao aumentar o número de threads.

O cálculo incremental do fatorial foi utilizado para evitar o recálculo redundante dos fatoriais dentro do loop paralelo. Em vez de calcular o fatorial de cada número a cada iteração do loop, pré-calculamos os fatoriais e os armazenamos em um array. Isso reduz a complexidade computacional dentro do loop paralelo, permitindo que a operação de soma seja mais eficiente. Apesar dessa otimização ter reduzido o tempo de execução total, o impacto no desempenho com o aumento do número de threads foi limitado devido à sobrecarga de gerenciamento de threads e à diminuição da proporção de trabalho paralelo em relação ao trabalho sequencial.
## Problemas Conhecidos
Nenhum problema conhecido até o momento.
## V2 
![image](https://github.com/eduardomarui/computacao_paralela/assets/105756443/3b3e4eee-aed6-4b87-8fe7-d055a95c0775)
## Verificação dos Resultados
Cálculo do Fatorial em Partes
O cálculo do fatorial é dividido em partes menores que são distribuídas entre as threads. Cada thread calcula uma parte do fatorial, e os resultados parciais são combinados ao final.

Etapas do Cálculo:
Divisão de Trabalho: O intervalo de cálculo é dividido entre as threads. Por exemplo, se estamos calculando o fatorial de n usando nThreads threads, cada thread calcula um intervalo de parcela = n / nThreads.
Função calcular_fatorial_parcial: Cada thread chama esta função para calcular o produto dos números em seu intervalo. Por exemplo, a thread 0 calcula o produto de 1 a n/nThreads, a thread 1 calcula de (n/nThreads) + 1 a 2*(n/nThreads), e assim por diante.
Acumulação dos Resultados Parciais: Após cada thread calcular seu fatorial parcial, os resultados são combinados multiplicando-os para obter o fatorial completo.
3. Utilização da Biblioteca MPFR
A MPFR (Multiple Precision Floating-Point Reliable) é uma biblioteca para cálculos com precisão arbitrária, baseada na biblioteca GMP. Ela é usada para garantir que o cálculo do fatorial seja feito com alta precisão.
Nessa versão com mais cálculos decimais, a versão parelala se torna uma opção melhor que a serial, visto que diminui o tempo ao aumentar os processaodores, ao aumentar a eficiência do usa das threads no cálculo fatorial e aummentando a complexidade do problema.      


## Contato
Para dúvidas ou suporte, entre em contato através do e-mail: eduardomarui@gmail.com souzavitor370@gmail.com 




