Os arrays em Java são declarados da seguinte forma:
	
	int[] nomeDoArray = new int[3];
	// Pode se colocar os colchetes após o nome, mas a melhor prática é colocar antes

Além disso, também podemos declarar o Array já passando os valores dentro dele:

	int[] nomeDoArray = {1, 2, 3};
	
ou

	int[] nomeDoArray = new int[]{1, 2, 3};

O primeiro índice do Array é sempre 0. Sendo assim, um Array de tamanho 3 tem os índices 0, 1 e 2. O valor que colocamos dentro do colchete diz respeito ao **tamanho** do Array, apenas. Por padrão, no Java, caso você não inicialize, valores padrões são colocados nas posições dependendo do tipo do Array.

Em Java, podemos conseguir o tamanho do Array através do atributo length. Exemplo: 

	for(int i = 0; i < nomeDoArray.length; i++) {
		System.out.println(nomeDoArray[i]);
	}

Também podemos utilizar outro tipo de laço para exibir um Array, o for each, e sua sintaxe é essa: 

	for(int num: nomeDoArray) {
		System.out.println(num);
	}
	// É como se estivessemos dizendo "Para cada número (num) no vetor (nomeDoArray), faça (bloco de instrução)" 

Usamos esse for como uma forma simplificada da outra versão. Aqui não é possível acessar um índice específico, ela percorre todos os elementos. 