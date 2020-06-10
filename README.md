# Campeonato Cubo
Programa em C feito para gerar um rankin do campeonado de cubo mágico que aconteceu na EXPOTEC de 2015.



### Motivação

As médias feitas nos campeonatos de cubo mágico são um pouco trabalhosas, para fazer deve-se excluir o maior e o menor tempos e enfim somar os três tempos restantes e dividir por 3. Além disso o menor dos tempos é uma informação importante, já que ele é o critétio de desempate.

Com o objetivo de automatizar esse processo, contrui o programa para ser utilizado no campeonato que seria realizado no colégio onde estudava.

### Funcionamento do Programa

O programa  começa te pedindo o nome da modalidade e quantos participantes irão participar dela.

![Inicio](/images/inicio.png)

Depois disso começam a ser inputados os nomes dos participantes e seus respectivos tempos. Uma regra do programa é que no final de cada tempo deve ser colocado um ponto. Depois de colocar o nome o programa pergunta se o participante teve alguma nenhuma, uma ou duas penalidades, um penalidade é denonimada DNF e duas é considerado DNS, se um usuário toma um DNS seus tempos não são considerados. Essas notações são usadas pela comunidade de Cubo Mágico.

![Inicio](/images/nomes.png)

_**OBS:** Uma limitação do programa, nessa versão, é que os tempos inputados devem ser colocados em segundos, neste caso se o competidor fez 1:10.05 devem ser inputados 70.05_

No no final do cadastro dos nomes o programa gera o rankin de todos os usuário, apresentando o nome, a média, o melhor tempo e a colocação.

![Inicio](/images/final.png)

O mais legal é que o programa gera um arquivo `txt` com o nome que você indicou no início contendo esse resultado apresentado no final.

![Inicio](/images/arquivo.png)