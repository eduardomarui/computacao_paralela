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

## Verificação dos Resultados
O programa imprime o valor calculado de *e*. Verifique este valor comparando-o com o valor padrão de *e* até as casas decimais desejadas.


## Problemas Conhecidos
Nenhum problema conhecido até o momento.

## Contato
Para dúvidas ou suporte, entre em contato através do e-mail: souzavitor370@gmail.com

## Licença
Este projeto está licenciado sob a Licença MIT.



