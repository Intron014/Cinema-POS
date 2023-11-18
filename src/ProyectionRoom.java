public class ProyectionRoom {
    private int number;
    private int[][] seats;

    public ProyectionRoom(int number, int rows, int columns) {
        this.number = number;
        this.seats = new int[rows][columns];
    }
}
