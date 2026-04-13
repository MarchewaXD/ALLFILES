<?php
session_start();

if (!isset($_SESSION['login'])) {
    header("Location: zaloguj.php");
    exit();
}
?>
<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>System Fakturowy</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <header>
        <h1>System Fakturowy</h1>
        <p style="font-size:12px;">
            Jesteś zalogowany jako:
            <?php echo $_SESSION['login']; ?>
        </p>
    </header>
    <main id="system-index">
        <nav>
            <section class="menu"><h2>Faktury Kosztowe</h2></section>
            <a href="sprzedazowe.php"><section class="menuC"><h2>Faktury Sprzedażowe</h2></section></a>
        </nav>
        <section id="kosztowe-opis">
            <form method="POST" action="">
                <label for="numer_faktury">Numer faktury:</label><br>
                <input type="text" name="numer_faktury"><br>
                <label for="data_wystawienia">Data wystawienia:</label><br>
                <input type="date" name="data_wystawienia"><br>
                <label for="kontrahent_id">Numer kontrahenta:</label><br>
                <input type="number" name="kontrahent_id"><br>
                <label for="wartosc_brutto">Wartość brutto:</label><br>
                <input type="number" name="wartosc_brutto"><br>
                <label for="czy_oplacona">Czy opłacona (1-tak, 0-nie):</label><br>
                <input type="number" name="czy_oplacona"><br>
                <button type="submit" id="przycisk-faktury">Dodaj fakture</button>
            </form>
            <?php

// połączenie z bazą
$conn = mysqli_connect("localhost", "root", "", "system_fakturowy_jk");

if($_SERVER["REQUEST_METHOD"] == "POST"){

// pobranie danych z formularza
$numer_faktury = $_POST['numer_faktury'];
$data_wystawienia = $_POST['data_wystawienia'];
$kontrahent_id = $_POST['kontrahent_id'];
$wartosc_brutto = $_POST['wartosc_brutto'];
$czy_oplacona = $_POST['czy_oplacona'];

// sprawdzenie czy wszystkie pola są wypełnione
if ($numer_faktury != "" && $data_wystawienia != "" && $kontrahent_id != "" && $wartosc_brutto != "" && $czy_oplacona != "") {

    // zapytanie SQL
    $sql = "INSERT INTO sprzedazowe (numer_faktury, data_wystawienia, kontrahent_id, wartosc_brutto, oplacona)
            VALUES ('$numer_faktury', '$data_wystawienia', $kontrahent_id, $wartosc_brutto, $czy_oplacona)";

    // wykonanie zapytania
    if (mysqli_query($conn, $sql)) {
        echo "<p>Dodano fakturę!</p>";
        echo '<meta http-equiv="refresh" content="3;url=sprzedazowe.php">';
    } else {
        echo "<p>Błąd: </p>" . mysqli_error($conn);
    }

} else {
    echo "<p>Wypełnij wszystkie pola!</p>";
}

// zamknięcie połączenia
mysqli_close($conn);
}
?>
        </section>
    </main>
    <footer>
        <h3>&copy; Jakub Korczak 2026</h3>
    </footer>
</body>
</html>