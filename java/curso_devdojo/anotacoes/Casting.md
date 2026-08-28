Em Java, você pode "forçar" um tipo a caber no outro, através do Casting. Exemplo:

	int idade = (int) 10000000000L
	// Usamos (int) para fazer o Casting e o L no final para sinalizar que aquele é um numero long
	
Por padrão, esse número não caberia em um tipo int, e sim em um tipo long, porém através do Casting forçamos ele a se comportar como um int. Para isso, o compilador corta bits. 

	float salario = (float) 2500.0D

Esse é um caso onde você forçou um tipo a ser outro, mas ele coube, pois o float suporta essa quantidade de bits. 