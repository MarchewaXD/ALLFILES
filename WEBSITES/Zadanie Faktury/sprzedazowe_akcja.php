<?php
$conn = mysqli_connect("localhost", "root", "", "system_fakturowy_jk");
 
$wynik = mysqli_query($conn, "
    SELECT sprzedazowe.*, kontrahenci.nazwa AS nazwa_kontrahenta 
    FROM sprzedazowe
    JOIN kontrahenci ON sprzedazowe.kontrahent_id = kontrahenci.id 
    ORDER BY data_wystawienia DESC
");
?>
 
<table>
    <tr>
        <th>ID</th>
        <th>Numer faktury</th>
        <th>Data wystawienia</th>
        <th>Kontrahent</th>
        <th>Wartość brutto</th>
        <th>Opłacona</th>
    </tr>
    <?php while ($row = mysqli_fetch_assoc($wynik)): ?>
    <tr>
        <td><?= $row['id'] ?></td>
        <td><?= $row['numer_faktury'] ?></td>
        <td><?= $row['data_wystawienia'] ?></td>
        <td><?= $row['nazwa_kontrahenta'] ?></td>
        <td><?= number_format($row['wartosc_brutto'], 2, ',', ' ') ?> zł</td>
        <td><?= $row['oplacona'] ? 'TAK' : 'NIE' ?></td>
    </tr>
    <?php endwhile; ?>
</table>