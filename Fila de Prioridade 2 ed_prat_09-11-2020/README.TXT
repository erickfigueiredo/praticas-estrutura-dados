UNIVERSIDADE FEDERAL DE VIÇOSA

ALUNO: Erick Lima Figueiredo        MA: 98898
PROFESSOR: Salles Vianna            Disc: ESTRUTURA DE DADOS

1- Tempo de execução para diferentes etapas número 1:

Input 11: 0,00s user 0,01s system 89% cpu 0,008 total

Input 14: 0,01s user 0,00s system 73% cpu 0,010 total

Input 17: 0,04s user 0,00s system 79% cpu 0,055 total

Input 110: 65,09s user 0,14s system 99% cpu 1:05,78 total


3- Comparação de tempo entre implementações de medianas:

Input 1:    Mediana -       0,01s user 0,02s system 88% cpu 0,030 total
            Mediana Lenta - 0,06s user 0,01s system 96% cpu 0,072 total

Input 2:    Mediana -       0,01s user 0,04s system 94% cpu 0,046 total
            Mediana Lenta - 0,31s user 0,01s system 99% cpu 0,321 total

Input 3:    Mediana -       0,01s user 0,06s system 93% cpu 0,073 total 
            Mediana Lenta - 1,32s user 0,03s system 99% cpu 1,354 total

Input 4:    Mediana -       0,17s user 0,31s system 98% cpu 0,484 total
            Mediana Lenta - 895,85s user 1,04s system 99% cpu 14:57,48 total

Input 5:    Mediana -       0,26s user 0,39s system 99% cpu 0,647 total
            Mediana Lenta - MUITO TEMPO 

Input 6:    Mediana -       0,63s user 1,03s system 97% cpu 1,700 total
            Mediana Lenta - MUITO TEMPO

4- Qual a diferença entre busca por largura e busca por profundidade?

A busca em largura visita as posições vizinhas, na primeira iteração visita os vizinhos em
primeiro grau do ponto de partida, já na segunda o algoritmo considera posições que podem ser
alcançadas a partir de dois movimentos partindo do ponto inicial. Já a busca em profundidade 
realiza buscas de forma mais focada, pois ao invés de visitar um nível inteiro antes de ir para
o próximo, esse aplica ações sucessivas até onde puder, geralmente são implementados com o uso 
da técnica de backtracking.

fonte de pesquisa para confirmar interpretação: https://iascblog.wordpress.com/2015/11/02/buscas-em-largura-e-profundidade-aplicadas-a-inteligencia-artificial/