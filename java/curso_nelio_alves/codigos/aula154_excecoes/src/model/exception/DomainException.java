package model.exception;
// RuntimeException = nao precisa tratar obrigatoriamente (colocar o throws DomainException na declaracao)
// Exception = precisa
public class DomainException extends RuntimeException {

    private static final long serialVersionUID = 1L;

    public DomainException (String msg) {
        super(msg);
    }

}
