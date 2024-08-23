# Base-Defense
Projeto final da disciplina de Linguagem de Programação 1.
## Requisitos
- G++
- Makefile
- SFML
## Intruções
1. O herói tem vida limitada a 100
2. O herói tem uma quantidade limitada de projéteis
3. O herói pode se mover em qualquer direção controlado pelo clique do mouse em um local “destino”. Quando se clicar com o botão direito do mouse em um ponto do mapa, O herói tem esse local setado como “destino” e deve caminhar nessa direção.
4. O herói pode sair livremente da base.
5. O herói pode disparar projéteis pressionando a tecla “Q”. O projétil deve ter um alcance máximo e deve ter a direção apontando para o cursor do mouse no momento do disparo.
6. Os inimigos surgem nas bordas do mapa aleatoriamente em um intervalo fixo de tempo (que pode ir diminuindo para aumentar a dificuldade do jogo)
7. O inimigo caminha em direção ao centro da base, ou ao herói (livre escolha do programador)
8. O inimigo dispara os projéteis sempre em direção ao herói.
9. Os projéteis podem colidir com o herói, outro inimigo, ou com a base.
10. A base deve resistir até um número limitado de tiros, podendo regenerar sua estrutura com o tempo
11. Quando abatido, o inimigo deixa no mapa uma quantidade aleatória limitada de projéteis que pode ser coletada pelo herói se o mesmo passar sobre o item ou esse item desaparece após um determinado tempo caso o herói não o colete.
12. O jogo deve finalizar se a base conseguir ser protegida por um determinado período de tempo ou se ela for destruída.
## Comandos
- Compilar: make all
- Rodar: make run
- Compilar e rodar: make dev
- Remover objetos: make clean
## Sobre o jogo:
> Você é um soldado encarregado de proteger sua base contra ondas de inimigos que aparecem aleatoriamente. 
> Utilize suas habilidades e estratégias para repelir os ataques e garantir a sobrevivência da sua base!
## Jogabilidade:
> Use o botão direito do mouse para mover-se.
> Pressione a tecla "Q" para atirar contra as hordas de inimigos.