Classes em Java são como formas, templates, etc, de elementos. Nelas, podem existir atributos e métodos, e podemos gerar objetos, que é como se construíssemos algo baseado em um projeto. Exemplo: 

	public class Pessoa {
		public String nome;
		public int idade;
		public char sexo;
	}

No programa principal:

	Pessoa p1 = new Pessoa();
	p1.nome = "Arthur";
	p1.idade = 20;
	p1.sexo = 'M';

Em um local você definiu o que é uma pessoa, definindo a classe Pessoa, e no programa principal você criou um objeto, ou seja, uma instância dessa Pessoa, e atribuiu valores aos atributos dela. 

Uma classe também pode ter métodos, que são as funções em C, ou seja, blocos de código que realizam coisas. Exemplo: 

	public class Pessoa {
		public String nome;
		public int idade;
		public char sexo;

		public void comer () {
			System.out.println(nome + " comeu!");
		}
	}

No programa principal:

	Pessoa p1 = new Pessoa();
	p1.nome = "Arthur";
	p1.idade = 20;
	p1.sexo = 'M';

	p1.comer();

A classe Pessoa é uma classe de domínio, porque ela mapeia um conceito real do negócio. As classes que representam dados (nome, idade, etc.) e comportamentos (como comer de uma Pessoa), são classes de domínio, e as que realizam operações que não pertencem a apenas uma entidade, são chamadas de classes de serviço, e classes utilitárias são classes que fornecem funções de auxilio genéricas, como "Math.max(10, 20);".

Os atributos dentro de uma classe não precisam ser inicializados, pois vem com valores padrões, sendo eles: 
- 0 para valores inteiros
- 0.0 para valores flutuantes 
- '\u0000' (unicode) para valores char
- null para valores de referência (Pessoa, String, etc.)
- false para valores booleanos 
Variáveis locais ainda precisam ser inicializadas
É possível inicializar o atributo na declaração da classe, definindo um valor inicial que irá para todos os objetos que você criar. Exemplo: 

	public class Pessoa {
		public String nome = "Arthur";
		public int idade;
		public char sexo;

		public void comer () {
			System.out.println(nome + " comeu!");
		}
	}

No programa principal:

	Pessoa p1 = new Pessoa();
	System.out.println(p1.nome);

Ele exibirá "Arthur". Entretanto, ainda é possível trocar esse nome posteriormente:

	p1.nome = "Tutu";
	System.out.println(p1.nome);

Exibirá "Tutu".