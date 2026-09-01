Existem diversos tipos de comentários em Java, e são usados para comentar algo no código sem afetá-lo, servem para comunicação entre desenvolvedores. Não afetam a execução do programa e não são instruções do Bytecode. São eles:
- Comentário em linha
	Usa-se //, seguido pelo comentário. Exemplo:
		
		// lsso é um comentário
		
- Comentário de várias linhas
	Usa-se /* no início do comentário, e (asterisco)/ no final. Exemplo: 
		
		/* Isso é um comentário de
		varias linhas */
		
- Javadoc
	Comentário especial usado para documentar a sua classe, método, atributo ou outros aspectos do código. Ele deve estar associado ao elemento que está sendo documentado. É possível usar HTML e outras tags específicas. Exemplo: 
		
		/**
		* Isso é um comentário <b>javadoc</b>
		*/
		
	Ele pode ser visualizado de forma renderizada usando Ctrl + Q no Windows e F1 no macOS.

Tirando o comentário Javadoc, não é recomendado comentar muito o código, e deve se evitar ao máximo, baseado nas normas do Código Limpo. 