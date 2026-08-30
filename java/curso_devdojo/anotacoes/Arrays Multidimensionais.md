Em Java, Arrays Multidimensionais são [[Arrays]] com mais de uma dimensão, onde que cada dimensão é um colchete. Exemplo:

		int[][][][][] arrayNovo = new int[3][][][][];

Nesses casos, você só precisa declarar o tamanho da primeira dimensão, e o resto você pode omitir. Por padrão, no Java, caso você não inicialize, valores padrões são colocados nas posições dependendo do tipo do Array. Em Arrays multidimensionais, caso você não declare o tamanho de todas as dimensões, todos os indicies da primeira dimensão serão preenchidos com valores nulos (null), pois o compilador não sabe se todas as posições seguintes serão preenchidas com valores inteiros, ou apenas a referência para as outras dimensões (arrays), que são objetos. 
Na prática, são Arrays de Arrays, onde que cada índice de uma dimensão, aponta para o Array da próxima dimensão. Por exemplo, a posição [0]  [2] de um Array [3]  [3] simulando um jogo da velha, apontaria para a terceira coluna da primeira fileira. 

Para exibirmos Arrays Multidimensionais, usamos formas encadeados, dessa forma:

	int[][] arrayTeste = new int[3][3];
	for(int i = 0; i < arrayTeste.length; i++) {
		for(int j = 0; i < arrayTeste[0].length; i++) {
			System.out.println(arrayTeste[i][j]);
		}
	}
	// Usamos "arrayTeste[0].length" pois queremos o tamanho da dimensão representada pelo valor 0 da primeira dimensão do vetor, que, nesse caso, é 3 (mas poderia ser 32121 ou qualquer valor diferente do 3 da primeira dimensão).

Nesse laço encadeado, ele começa uma repetição do primeiro laço, entra no laço de dentro, faz todas as repetições desse laço, e só então parte para a próxima repetição do primeiro laço, repetindo o processo até o fim do primeiro laço (nesse caso, do o **i**).

Também podemos usar o for each, que é bem mais simples 