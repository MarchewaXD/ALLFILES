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
            <section class="menu"><h2>Faktury Sprzedażowe</h2></section>
        </nav>
        <section id="system-opis">
            <h2>Systemy fakturowe</h2>
            <p>Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.</p>

            <p>Lorem ipsum dolor sit amet consectetur adipiscing elit. Quisque faucibus ex sapien vitae pellentesque sem placerat. In id cursus mi pretium tellus duis convallis. Tempus leo eu aenean sed diam urna tempor. Pulvinar vivamus fringilla lacus nec metus bibendum egestas. Iaculis massa nisl malesuada lacinia integer nunc posuere. Ut hendrerit semper vel class aptent taciti sociosqu. Ad litora torquent per conubia nostra inceptos himenaeos.</p>
        </section>
    </main>
    <footer>
        <h3>&copy; Jakub Korczak 2026</h3>
    </footer>
</body>
</html>