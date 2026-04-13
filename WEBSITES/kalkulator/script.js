const wyswietlacz = document.getElementById('wyswietlacz');
const przyciskCzysc = document.getElementById('wyczysc');
const przyciski = document.querySelectorAll('main button');

let aktualneWpisanie = ""; // wpisywana liczba
let poprzednieWpisanie = ""; // 1 w dzialaniu
let operacja = null; // znak obok liczby
let czyResetowacEkran = false;

// klikanie w przyciski
przyciski.forEach(przycisk => {
    przycisk.addEventListener('click', () => {
        const wartosc = przycisk.innerText;

        if (!isNaN(wartosc) || wartosc === '.') {
            obslugaLiczby(wartosc);
        } 
        else if (wartosc === '=') {
            obslugaRownosci();
        } 
        else {
            obslugaOperatora(wartosc);
        }
    });
});

// button wyczysc
przyciskCzysc.addEventListener('click', wyczyscWszystko);

function obslugaLiczby(cyfra) {
    if (czyResetowacEkran) {
        aktualneWpisanie = cyfra;
        czyResetowacEkran = false;
    } else {
        // mozliwosc dodania tylko jednej kropki (float'u)
        if (cyfra === '.' && aktualneWpisanie.includes('.')) return;
        
        // zamiana zera na cyfre
        if (aktualneWpisanie === "0" && cyfra !== ".") {
            aktualneWpisanie = cyfra;
        } else {
            aktualneWpisanie += cyfra;
        }
    }
    aktualizujWyswietlacz();
}

function obslugaOperatora(znak) {
    if (operacja !== null && aktualneWpisanie !== "") {
        obslugaRownosci();
    }
    
    poprzednieWpisanie = aktualneWpisanie || poprzednieWpisanie || wyswietlacz.innerText.split(' ')[0];
    operacja = znak;
    aktualneWpisanie = ""; 
    aktualizujWyswietlacz();
}

function obslugaRownosci() {
    if (operacja === null || aktualneWpisanie === "") return;
    
    let wynik;
    const liczba1 = parseFloat(poprzednieWpisanie);
    const liczba2 = parseFloat(aktualneWpisanie);

    switch (operacja) {
        case '+': wynik = liczba1 + liczba2; break;
        case '-': wynik = liczba1 - liczba2; break;
        case 'x': wynik = liczba1 * liczba2; break;
        case '/': 
            wynik = liczba2 === 0 ? "Błąd" : liczba1 / liczba2; 
            break;
        default: return;
    }

    aktualneWpisanie = wynik.toString();
    operacja = null;
    poprzednieWpisanie = "";
    czyResetowacEkran = true;
    aktualizujWyswietlacz();
}

function aktualizujWyswietlacz() {
    let tekstDoWyswietlenia = "";

    if (operacja !== null) {
        tekstDoWyswietlenia = `${poprzednieWpisanie} ${operacja} ${aktualneWpisanie}`;
    } else {
        tekstDoWyswietlenia = aktualneWpisanie || poprzednieWpisanie || "0";
    }

    // zmniejszenie czcionki zeby nie wyszla poza kalkulator
    if (tekstDoWyswietlenia.length > 16) {
        wyswietlacz.style.fontSize = "1.5rem";
    } 
    else if (tekstDoWyswietlenia.length > 10) {
        wyswietlacz.style.fontSize = "2.5rem";
    } 
    else {
        wyswietlacz.style.fontSize = "4rem";
    }

    wyswietlacz.innerText = tekstDoWyswietlenia;
}

function wyczyscWszystko() {
    aktualneWpisanie = "";
    poprzednieWpisanie = "";
    operacja = null;
    czyResetowacEkran = false;
    wyswietlacz.innerText = "0";
    wyswietlacz.style.fontSize = "4rem";
}