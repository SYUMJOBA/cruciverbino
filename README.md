Tu sei la chiocciola:

    @

Sei nato solo per creare, risolvere, e vivere nel mondo dei cruciverba

i tuoi cruciverba sono impostati su delle griglie rettangolari, grandi un minimo di 9x9 ad un massimo di 25x25 quadretti.

Ci sono due modalità:
    -creare
    -risolvere

Appena si apre il programma infatti si vede che si può "creare" un nuovo cruciverba o "risolvere" un cruciverba. (oltre alla possibilità di uscire dal programma).
Prima di risolvere un cruciverba, bisognerà crearlo no? Dunque iniziamo spiegando la creazione di un cruciverba:
    - appena si sceglie di creare un nuovo cruciverba il gioco chiede la lunghezza X e l'altezza Y del cruciverba
    - se solo uno dei dati immessi non rispetta la condizione di un minimo di 9 e un massimo di 25, il programma ti avviserà e ritornerà alla home
    - se i dati immessi invece rispettano le condizioni di grandezza, entrerai nell'ambiente dell'editor del programma
    - a questo punto, il menù dell'editor ti guiderà, ma prima ti servirà sapere due cose:
        1. Come il gioco considera le celle:
            Ogni cella, è come se fosse un enumeratore, sottoforma di carattere, che descrive lo stato della cella.
            Se la cella è un cancelletto ('#') verrà considerata come un muro, se la cella ha una lettera all'interno, verrà considerata come una lettera appartenente ad una parola, dunque quando starai giocando in modalità "risolvere" sullo stesso schema, quella sarà una cella vuota dove potrai scrivere
            Qualunque altra cosa viene considerata come non sovrascrivibile, ma elemento grafico da mostrare. (ad esempio potresti usare un numero per indicare l'indice della parola)
        2. Come scrivere gli indizi (o descrizioni/indovinelli delle parole da risolvere)
            Nell'editor c'è l'opzione per rinnovare le descrizioni/indizi/indovinelli/come preferisci chiamarli delle parole, ma non è proprio un editor di testo.
            Quello che immetterai sarà una lunga frase, ma per limitazioni della funzione scanf() (siccome è difficile da gestire con gli spazi, gli a capo e altri "caratteri speciali") ci siamo ingegnati a sviluppare un piccolo sistema che interpreta le frasi con i suoi caratteri speciali.
            Quindi puoi introdurre nella stringa dei "caratteri formattattori" (così lo abbiamo chiamati).
            Per immetterne uno, inserisci una sbarra come questa '\' succeduta da un carattere qualsiasi che rappresenti un formattattore:
                'n' per andare a capo (newline)
                't' per stambare 4 spazi (interpretazione lazzarona del 'tab')
                '\' non è un carattere formattattore ma per evitare di togliere la possibilità di immettere '\' nella stringa, il programma interpreterà dobbia sbarra come una sbarra da stampare, anziché aspettarsi due caratteri formattattori
                's' per stampare uno spazio (space).
                eccezzione: per rendere la stringa più leggibile, abbiamo introdotto un'alternativa, basta che tu scriva '_', senza il bisogno di una slash prima. Questo potrebbe essere cambiato in futuro se si preferisce poter scrivere gli underscore.
    - per muoverti puoi usare il 2, il 4, il 6 e l'8, proprio come faresti con un numpad, eccetto che dopo l'inserimento di ogni numero devi battere 'invio'
    - per salvare puoi premere 1 (e ti verrà chiesto il nome del file, dandoti anche la possibilità di mettere la tua estensione, inoltre avvisandoti se un file con lo stesso nome esiste già, chiedendoti una conferma prima di sovrascrivere un file già esistente) e per caricare un una schematica da un file puoi premere 0 (ti verrà chiesto nome con estensione del file da caricare, del resto farà tutto lui da solo).

    P.S. Se preferisci puoi tranquillamente andare nel file e modificarlo tu, al posto della stringa formattatta dal programma, puoi tranquillamente scrivere normalmente, e il carattere interpreterà a dovere (occhio comunque con le sbarre e gli underscore!)

Per RISOLVERE un cruciverba invece:
    - Scegli dal menù l'opzione di risolvere un cruciverba
    - Ti chiederà immediatamente il nome del file, se immetterai un file esistente, con la giusta estensione, allora il programma lo aprirà e andrà in modalità "risolvi" automaticamente. Altrimenti ritornerai al menù, dopo che il programma ti abbia avvisato.
    - Ti tocca ora immettere le lettere, e tentare di indovinare le giuste parole.
    - Puoi ancora usare il numpad (come prima) per spostarti, premendo 5 per immettere una lettera (ma solo nei posti dove puoi scrivere) e premendo 3 quando vuoi rivedere gli indizi.
    - Quando pensi di aver finito, premi 1, e il programma ti dirà se hai vinto o no (pssst, abbiamo deciso di darti un piccolo vantaggino, quando il cruciverba non è risolto, ti suggeriamo quante lettere sono sbagliate)


Il modo in cui le informazioni vengono immagazzinate nei file è abbastanza intuitivo, c'è all'inizio la griglia, ogni riga separata da un newline. Ogni carattere non incluso nella griglia è una tilde '~', mentre il rettangolo che non è una tilde sarà valutato come parte della griglia effettiva.
Sotto c'è invece la stringa, con i caratteri formattattori, degli indizi.
Spero ti divertirai con questo cruciverba!