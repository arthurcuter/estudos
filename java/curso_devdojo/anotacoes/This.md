Podemos usar a referência "this" para se referir a um atributo da instância de um objeto, por exemplo, quando vamos usa-lo em um método. Exemplo: 

	public class Estudante {
		String nome;
		int idade;
		char sexo;
		
		public void imprimir () {
			System.out.println(this.nome);
			System.out.println(this.idade);
			System.out.println(this.sexo);
		}
	}

Dessa forma, não é necessário referenciar o objeto necessariamente, pois com o "this", o compilador entende que o método se refere ao atributo desse objeto. 

Ele não é obrigatório, mas é útil quando tanto o parâmetro quanto um atributo do objeto possuem o mesmo nome. Dessa forma, ao utilizar "this", entende-se que está se referindo ao atributo, e não ao parâmetro. 