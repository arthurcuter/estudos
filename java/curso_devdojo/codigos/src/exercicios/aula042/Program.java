package exercicios.aula042;

public class Program {
    public static void main(String[] args) {
        Carro carro1 = new Carro();
        Carro carro2 = new Carro();

        carro1.nome = "Jason";
        carro1.modelo = "Kwid";
        carro1.ano = 2025;

        carro2.nome = "Marcos";
        carro2.modelo = "Jetta";
        carro2.ano = 2024;

        System.out.println("Carro1:\n" + "Nome: " + carro1.nome +
                "\nModelo: " + carro1.modelo + "\nAno: " + carro1.ano);
        System.out.println("\nCarro2:\n" + "Nome: " + carro2.nome +
                "\nModelo: " + carro2.modelo + "\nAno: " + carro2.ano);

    }
}
