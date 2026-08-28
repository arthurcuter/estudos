Break e Continue são comandos usados em laços de repetição para parar ou continuar a execução.
Ao utilizar "break;" dentro de um laço de repetição, ele imediatamente encerra a execução daquele laço. Exemplo:

	for(int i = 1; i < 10; i++ ) {
		System.out.println(i);
		if(i == 5) {
			break;
		}
	}
	// Quando o "i" chegar no 5, o laço para. 
	
Ao utilizar "continue;" dentro de um laço de repetição, ele vai parar a iteração atual do laço, ignorando tudo que está abaixo dele no laço, e iniciar a próxima. Exemplo: 

	for(int i = 1; i < 10; i++) {
		if(i == 5) {
			continue;
		}
		System.out.println(i);
	}
	// Ele vai exibir de 1 até 9, porém ignorando o 5  devido ao "continue"