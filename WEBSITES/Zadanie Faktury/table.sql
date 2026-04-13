CREATE TABLE kontrahenci (
    id INT AUTO_INCREMENT PRIMARY KEY,
    nazwa VARCHAR(50) NOT NULL,
    adres VARCHAR(100)
);

CREATE TABLE uzytkownicy (
    id INT AUTO_INCREMENT PRIMARY KEY,
    login VARCHAR(50) NOT NULL,
    haslo VARCHAR(50) NOT NULL
);

CREATE TABLE sprzedazowe (
    id INT AUTO_INCREMENT PRIMARY KEY,
    numer_faktury VARCHAR(50) NOT NULL,
    kontrahent_id INT,
    data_wystawienia DATE,
    wartosc_brutto DECIMAL(10,2),
    oplacona BOOLEAN,
    FOREIGN KEY (kontrahent_id) REFERENCES kontrahenci(id)
);

CREATE TABLE kosztowe (
    id INT AUTO_INCREMENT PRIMARY KEY,
    numer_faktury VARCHAR(50) NOT NULL,
    data_wystawienia DATE,
    kontrahent_id INT,
    wartosc_brutto DECIMAL(10,2),
    oplacona BOOLEAN,
    FOREIGN KEY (kontrahent_id) REFERENCES kontrahenci(id)
);

INSERT INTO uzytkownicy(login, haslo) VALUES ('admin', 'admin123');

INSERT INTO kontrahenci (nazwa) VALUES
('Firma Alpha Sp. z o.o.'),
('Beta Solutions S.A.'),
('Gamma Trade');

INSERT INTO kosztowe (numer_faktury, data_wystawienia, kontrahent_id, wartosc_brutto, oplacona) VALUES
('FK/2025/001', '2025-01-10', 1, 1230.00, 1),
('FK/2025/002', '2025-02-14', 2, 540.50, 0),
('FK/2025/003', '2025-03-05', 1, 3200.00, 1),
('FK/2025/004', '2025-04-18', 3, 890.75, 0),
('FK/2025/005', '2025-05-22', 2, 450.00, 1),
('FK/2025/006', '2025-06-30', 1, 7600.20, 0),
('FK/2025/007', '2025-07-11', 3, 215.00, 1),
('FK/2025/008', '2025-08-03', 2, 1100.00, 0),
('FK/2025/009', '2025-09-19', 1, 3340.90, 1),
('FK/2025/010', '2025-10-25', 3, 670.00, 0);

INSERT INTO kosztowe (numer_faktury, kontrahent_id, data_wystawienia, wartosc_brutto, oplacona) VALUES
('FK/2026/001', 1, '2026-01-05', 1230.00, 1),
('FK/2026/002', 2, '2026-01-18', 540.50, 0),
('FK/2026/003', 1, '2026-02-03', 3200.00, 1),
('FK/2026/004', 3, '2026-02-21', 890.75, 0),
('FK/2026/005', 2, '2026-02-28', 450.00, 1),
('FK/2026/006', 1, '2026-03-10', 7600.20, 0),
('FK/2026/007', 3, '2026-03-15', 215.00, 1),
('FK/2026/008', 2, '2026-03-22', 1100.00, 0),
('FK/2026/009', 1, '2026-04-01', 3340.90, 1),
('FK/2026/010', 3, '2026-04-08', 670.00, 0);

INSERT INTO sprzedazowe (numer_faktury, kontrahent_id, data_wystawienia, wartosc_brutto, oplacona) VALUES
('FS/2026/001', 1, '2026-01-03', 2100.00, 1),
('FS/2026/002', 2, '2026-01-09', 750.00, 0),
('FS/2026/003', 3, '2026-01-15', 4300.50, 1),
('FS/2026/004', 1, '2026-01-22', 980.00, 0),
('FS/2026/005', 2, '2026-02-01', 1250.00, 1),
('FS/2026/006', 3, '2026-02-08', 620.75, 0),
('FS/2026/007', 1, '2026-02-14', 8900.00, 1),
('FS/2026/008', 2, '2026-02-20', 330.00, 0),
('FS/2026/009', 3, '2026-02-27', 5600.00, 1),
('FS/2026/010', 1, '2026-03-05', 1450.00, 0),
('FS/2026/011', 2, '2026-03-11', 2780.00, 1),
('FS/2026/012', 3, '2026-03-17', 910.00, 0),
('FS/2026/013', 1, '2026-03-23', 3300.00, 1),
('FS/2026/014', 2, '2026-03-29', 475.00, 0),
('FS/2026/015', 3, '2026-04-02', 6700.00, 1),
('FS/2026/016', 1, '2026-04-05', 1890.00, 0),
('FS/2026/017', 2, '2026-04-07', 540.00, 1),
('FS/2026/018', 3, '2026-04-08', 2250.00, 0),
('FS/2026/019', 1, '2026-04-09', 3100.00, 1),
('FS/2026/020', 2, '2026-04-10', 780.00, 0);