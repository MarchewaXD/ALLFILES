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
            <a href="kosztowe.php"><section class="menu"><h2>Faktury Kosztowe</h2></section></a>
            <section class="menuC"><h2>Faktury Sprzedażowe</h2></section>
        </nav>
        <section id="kosztowe-opis">
            <?php include 'sprzedazowe_akcja.php'; ?>
            <a href="dodaj_sprzedazowe.php"><button id="przycisk-faktury">Dodaj fakture</button></a>
            <?php include 'sprzedazowe_akcja2.php'; ?>
        </section>
    </main>
    <footer>
        <h3>&copy; Jakub Korczak 2026</h3>
    </footer>
</body>
</html>