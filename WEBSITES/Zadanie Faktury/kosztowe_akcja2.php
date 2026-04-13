<?php
$conn = mysqli_connect("localhost", "root", "", "system_fakturowy_jk");
 
if (isset($_POST['oplac'])) {
    $id = $_POST['id_faktury'];
    mysqli_query($conn, "UPDATE kosztowe SET oplacona = 1 WHERE id = $id");
}
 
$nieoplacone = mysqli_query($conn, "SELECT id, numer_faktury FROM kosztowe WHERE oplacona = 0");
?>
<section id="oplacenie-faktury">
<form method="POST">
    <select name="id_faktury">
        <?php while ($row = mysqli_fetch_assoc($nieoplacone)): ?>
            <option value="<?= $row['id'] ?>">
                ID <?= $row['id'] ?> – <?= $row['numer_faktury'] ?>
            </option>
        <?php endwhile; ?>
    </select>
    <br>
    <br>
    <button type="submit" name="oplac" class="btn">Opłać</button>
</form>
</section>