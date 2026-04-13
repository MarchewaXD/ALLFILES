<?php
session_start();

$login = $_POST["login"];
$haslo = $_POST["haslo"];

$polaczenie = mysqli_connect("localhost", "root", "", "system_fakturowy_jk");

$zapytanie = "SELECT * FROM uzytkownicy WHERE login='$login' LIMIT 1";
$wynik = mysqli_query($polaczenie, $zapytanie);

if (mysqli_num_rows($wynik) == 1) {
    $uzytkownik = mysqli_fetch_assoc($wynik);
    if ($haslo == $uzytkownik['haslo']) {
        $_SESSION['login'] = $login;
        header("Location: system.php");
        exit();
    } else {
        header("Location: zaloguj.php?blad=haslo");
        exit();
    }
} else {
    header("Location: zaloguj.php?blad=uzytkownik");
    exit();
}
?>