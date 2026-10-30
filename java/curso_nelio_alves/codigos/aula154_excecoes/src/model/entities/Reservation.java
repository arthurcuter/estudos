package model.entities;

import model.exception.DomainException;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.TimeUnit;

public class Reservation {

    private Integer roomNumber;
    private Date checkin;
    private Date checkout;

    private static SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");

    public Reservation() {
    }

    public Reservation(Integer roomNumber, Date checkin, Date checkout) {
        if (!checkout.after(checkin)) {
            throw new DomainException("Check-out date must be after check-in date");
        }
        this.roomNumber = roomNumber;
        this.checkin = checkin;
        this.checkout = checkout;
    }

    public Integer getRoomNumber() {
        return roomNumber;
    }

    public void setRoomNumber(Integer roomNumber) {
        this.roomNumber = roomNumber;
    }

    public Date getCheckin() {
        return checkin;
    }

    public Date getCheckout() {
        return checkout;
    }

    public long duration() {
        long diff = checkout.getTime() - checkin.getTime();
        // usando getTime pega o tempo em milisegundos das duas datas (checkin e checkout), e subtrai
        return TimeUnit.DAYS.convert(diff, TimeUnit.MILLISECONDS);
        // usa TimeUnit para converter de milisegundos para dias
    }

    public void updateDates(Date checkin, Date checkout) {

        Date now = new Date();
        if (checkin.before(now) || checkout.before(now)) {
            // se A DATA DE CHECKIN FOR ANTES QUE AGORA E A DATA DE CHECKOUT FOR ANTES QUE AGORA entao
            throw new DomainException("Reservation dates for update must be future dates");
            // ele vai lançar esse tipo de excecao
        }
        if (!checkout.after(checkin)) {
            throw new DomainException("Check-out date must be after check-in date");
        }
        this.checkin = checkin;
        this.checkout = checkout;
    }

    @Override // ToString é sempre uma sobreposição, entao poe override
    public String toString() {
        return "Room "
                + roomNumber
                + ", check-in: "
                + sdf.format(checkin)
                + ", checkout: "
                + sdf.format(checkout)
                + ", "
                + duration()
                + " nights";
    }

}
