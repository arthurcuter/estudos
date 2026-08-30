Em Java, Arrays Multidimensionais são [[Arrays]] com mais de uma dimensão, onde que cada dimensão é um colchete. Exemplo:

		int[][][][][] arrayNovo = new int[3][][][][];

Nesses casos, você só precisa declarar o tamanho da primeira dimensão, e o resto você pode omitir. Por padrão, no Java, caso você não inicialize, valores padrões são colocados nas posições dependendo do tipo do Array. Em Arrays multidimensionais, caso você não declare o tamanho de todas as dimensões, todos os indicies da primeira dimensão serão preenchidos com valores nulos (null), pois o compilador não sabe se todas as posições seguintes serão preenchidas com valores inteiros, ou apenas a referência para as outras dimensões (arrays), que são objetos. 
Na prática, são Arrays de Arrays, onde que cada índice de uma dimensão, aponta para o Array da próxima dimensão. Por exemplo, a posição [0]  [2] de um Array [3]  [3] simulando um jogo da velha, apontaria para a terceira coluna da primeira fileira. 

Também podemos inicializar cada dimensão de forma independente, desse jeito: 

	int[][] arrayUm = new int[3][];
	arrayUm[0] = new int[2];
	arrayUm[1] = new int[]{1, 2, 3, 4, 5};
	arrayUm[2] = new int[3];
	// inicializou todas as posições da segunda dimensão com tamanhos diferentes. 

Para exibirmos Arrays Multidimensionais, usamos formas encadeados, dessa forma:

	int[][] arrayTeste = new int[3][3];
	for(int i = 0; i < arrayTeste.length; i++) {
		for(int j = 0; j < arrayTeste[i].length; j++) {
			System.out.println(arrayTeste[i][j]);
		}
	}
	// Usamos "arrayTeste[i].length" pois queremos o tamanho da dimensão representada pelo valor i da primeira dimensão do vetor, que, nesse caso, é 3 (mas poderia ser 32121 ou qualquer valor diferente do 3 da primeira dimensão).

Nesse laço encadeado, ele começa uma repetição do primeiro laço, entra no laço de dentro, faz todas as repetições desse laço, e só então parte para a próxima repetição do primeiro laço, repetindo o processo até o fim do primeiro laço (nesse caso, do o **i**).

Outra forma:

	int[][] arrayDois = {{0, 0}, {0, 0, 0, 0}, {0, 0, 0}};
	// Array de 2 dimensões, de tamanho 3 na primeira dimensão e, na segunda dimensão, um array irregular, com tamanho 2 na posição [0], tamanho 4 na posição [1], e tamanho 3 na posição [2]

Também podemos usar o for each, dessa forma:

	for(int[] arrBase: arrayTeste) {
		for(int num: arrBase) {
			System.out.println(num);
		}
	}
	// Usamos um array de inteiros no primeiro laço pois estaremos percorrendo sobre Arrays, e dentro do laço, por elementos em cada Array. Ou seja, "percorra cada array dentro do meu array base, e dentro do array base percorra cada elemento". 