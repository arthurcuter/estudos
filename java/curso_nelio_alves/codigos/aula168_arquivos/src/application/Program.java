package application;

import model.entities.Product;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Program {
    static void main(String[] args) {

        Locale.setDefault(Locale.US);
        Scanner sc = new Scanner(System.in);

        List<Product> list = new ArrayList<>();

        System.out.println("Enter file path: ");
        String sourceFileStr = sc.nextLine();
        // pega onde esta o arquivo e poe numa string

        File sourceFile = new File(sourceFileStr);
        // recebe o arquivo e transforma num caminho de verdade com a variável File
        // sourceFile agora é o arquivo que lemos

        String sourceFolderStr = sourceFile.getParent(); // pega a pasta do arquivo (o caminho antes do arquivo)

        boolean success = new File(sourceFolderStr + "\\out").mkdir();
        // comando para criar uma nova pasta na sourceFolderStr que pegamos antes (a pasta onde esta o arquivo que lemos)
        // criando uma nova subpasta chamada 'out' (+"\\out") + mkdir(), que é a operacao para criar novos diretorios
        // utilizamos boolean para saber se ele conseguiu criar a pasta (true ou false)

        String targetFileStr = sourceFolderStr + "\\out\\summary.csv";
        // cria uma String com o caminho do futuro arquivo que queremos criar


        // BLOCO TRY CATCH PARA PREVINIR EXCECOES
        // Entretanto, esse é um try with resources (try with resources)
        // Voce instancia as coisas que voce vai usar nele para que ele feche automaticamente
        // Dai nao precisa criar um bloco finally pra, por exemplo, dar br.close()
        try (BufferedReader br = new BufferedReader(new FileReader(sourceFileStr))) {
            // esta criando um BufferedReader (pois ele é um FileReader buffado) e esta
            //instanciando nele um FileReader, pois precisa. No FileReader, esta sendo
            // instanciado a String que contem o local onde esta o arquivo que vai ser LIDO
            // nesse caso o input.csv. ESSA PARTE É PARA LER O ARQUIVO.

            String itemCsv = br.readLine();
            // String para ler cada linha do arquivo. br (apelido do BufferedReader onde esta o caminho) com o metodo
            // readLine().

            // quando o readLine chega no final do arquivo, ele atribui o valor de null a variavel.
            // Entao, enquanto o itemCsv for diferente de null, ele vai continuar lendo o arquivo.
            // Quando chegar no final ele vai atribuir null a variavel e o laço While para
            while (itemCsv != null) {

                String[] fields = itemCsv.split(",");
                // cria um vetor de String onde os elementos serao separados pelas virgulas do texto.
                // ou seja, um texto "Arthur,Cuter" ia ter dois elementos
                // fields [0] = Arthur
                // fields [1] = Cuter


                String name = fields[0];
                // agora cria uma String name e coloca o valor da posicao 0 do vetor (que é o nome do produto)

                double price = Double.parseDouble(fields[1]);
                // cria um double, porem precisa converter, pois é um vetor de Strings. pra isso, ele usa o
                // Double.parseDouble(oQueVaiSerConvertido), nesse caso, a segunda posicao do vetor,
                // que é onde esta o preço

                int quantity = Integer.parseInt(fields[2]);

                list.add(new Product(name, price, quantity));
                // instancia um novo Product na lista que criamos la em cima,
                // com as informacoes que acabamos de conseguir separando

                itemCsv = br.readLine();
                // comando para ir para proxima linha. agora o valor da variavel vai ser a proxima linha
                // agora podemos prosseguir no While, avançando a linha
            }

            // Mesma logica do try de ler, mas agora para escrever (Write)
            try (BufferedWriter bw = new BufferedWriter(new FileWriter(targetFileStr))) {
                for(Product item : list) {
                    // para cada item na lista

                    bw.write(item.toString());
                    // escreva o toString que eu coloquei na classe Product

                    bw.newLine();
                    // e quebra a linha

                }

                System.out.println(targetFileStr + " created!");

            } catch (IOException e) {
                System.out.println("Error writing file: " + e.getMessage());
            }

        } catch (IOException e){
            // caso ele nao consiga ler por algum motivo ele cai no catch

            System.out.println("Error writing file: " + e.getMessage());

        }




        sc.close();
    }
}
