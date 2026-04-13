<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>System Fakturowy</title>
    <link rel="stylesheet" href="style.css">
    <script>
    if (window.location.search != "") {
        history.replaceState(null, "", "zaloguj.php");
    }
</script>
</head>
<body>
    <header>
        <h1>System Fakturowy</h1>
    </header>
    <main>
        <section id="info">
            <p>System Faktur Logowanie</p>
        </section>
        <section id="login-panel">
            <form method="POST" action="zaloguj_akcja.php">
                <input type="text" name="login" placeholder="Login:">
                <hr>
                <input type="password" name="haslo" placeholder="Hasło:">
        </section>
        <section id="przycisk">
            <button type="submit">Zaloguj</button>
            </form>
        </section>
        <section id="php">
            <?php
            if (isset($_GET['blad'])) {
                if ($_GET['blad'] == 'uzytkownik') echo "<p>Taki użytkownik nie istnieje!</p>";
                if ($_GET['blad'] == 'haslo') echo "<p>Błędne hasło!</p>";
            }
            ?>
        </section>
    </main>
    <footer>
        <h3>&copy; Jakub Korczak 2026</h3>
    </footer>
</body>
</html>