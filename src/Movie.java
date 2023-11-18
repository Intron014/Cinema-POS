import java.time.LocalDate;

public class Movie {
    private String title;
    private LocalDate releaseDate;
    private int duration;
    private String description;
    private ProyectionTypes projectionType;

    public Movie(String title, LocalDate releaseDate, int duration, String description, ProyectionTypes projectionType) {
        this.title = title;
        this.releaseDate = releaseDate;
        this.duration = duration;
        this.description = description;
        this.projectionType = projectionType;
    }

}
