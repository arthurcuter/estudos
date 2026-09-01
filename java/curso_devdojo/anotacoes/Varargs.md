Em Java, na passagem de parâmetros de um método, podemos utilizar Varargs para simplificar. Invés de por exemplo, usarmos: 

	public void somarArray(int[] numeros);

Podemos usar:

	public void somarArrayVarargs(int... numeros);

Dessa forma, além de aceitar o vetor normalmente como parâmetro, ele também aceita uma sequência de números. Ele transforma essa sequência de números em um vetor por trás dos panos. Exemplo:

Lógica dos métodos:

	public void somarArray(int[] numeros) {
	    int soma = 0;
	    for (int num : numeros) {
	        soma += num;
	    }
	    System.out.println(soma);
	}
	
	public void somarArrayVarargs(int... numeros){
	    int soma = 0;
	    for (int num : numeros) {
	        soma += num;
	    }
	    System.out.println(soma);
	}

Programa principal:

	int[] numeros = new int[]{1, 2, 3, 4};
	somarArrayVarargs(1, 2, 3, 4);
	somarArrayVarargs(numeros);
	somarArray(numeros);
	// Todos exibem 10 no terminal

Também é possível chamar Varargs sem nenhum valor:

	somarArrayVarargs();

E ele precisa sempre ser o último parâmetro do método:

	public void calcular(String nome, int... numeros);


