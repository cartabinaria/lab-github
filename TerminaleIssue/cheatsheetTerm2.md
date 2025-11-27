### Slide della scorsa volta

[main.pdf](https://risorse.vercel.app/lab/2025/terminale-1/main.pdf)

# STDIO e ridirezioni

## Output

Normale output di un comando, può essere visto come un file e usato su pipe e ridirezione. > distruttiva, >> appende in fondo al file.

```bash
ls > file1 > file2
```

## Error

```bash
ls ifnrigor > mangusta
```

Il file mangusta viene creato (l’esecuzione non si ferma all’errore) ma mangusta non conterrà l’errore del comando perché non è `stdout`.

```bash
ls ifnrigor > mangusta 2>&1
```

Ridirezionare lo `stderr` sullo stdout: `2>&1` . Non mostra messaggio di errore e ora mangusta contiene l’errore di ls.

```bash
ls ifnrigor > mangusta 2>1
```

Crea un file di nome 1 e mangusta è vuoto. Ha preso `2>1` come: prendi lo `stderr` e mettilo nel file 1.

```bash
ls ifnrigor > mangusta 2>/dev/null
```

Butta tutti gli errori dentro /dev/null e non saranno più recuperabili.

## Echo

```bash
echo */lontra
```

Stampa tutti i percorsi relativi delle sottocartelle (o cartelle) chiamate lontra.

```bash
echo {1..1}
echo {a..z}
```

Stampa tutti i numeri e caratteri in mezzo ai valori definiti.

```bash
 file $(ls -d /bin/* | grep zip)
```

Permette di stampare tutti i file che hanno dentro zip e sono locati dentro `/bin/*`. Questa sintassi è necessaria per rispettare la sintassi di `file` .

# Variabili

```bash
$ set src castoro
$ set dest capybara
$ echo $dest
capybara
$ echo $src
castoro
$ cp -r $src $dest
$ ls
1  capybara  castoro  file1  file2  mangusta
```

set copia le cartelle nelle variabili locali, e cp copia le cartelle ricorsivamente l’una dentro l’altra.

```bash
bash -c [comando]
```

Lancia un comando in una nuova shell.

Le variabili custom vengono eliminate al riavvio del computer.

# Shell scripting

Per specificare che interprete usare:

```bash
 #!/bin/bash
```

Specifica l’interprete da usare nella prima riga del file. Dice al terminale che stiamo creando un file di scripting. Non è necessario chiamare i file di scripting \*.sh e definire le variabili maiuscole.

```bash
#!/bin/bash
echo "Reading programs"
PROG=$(ls -d /bin/*)
NUM=$(echo "$PROG" | grep "ca" | wc -l)
```

`NUM=$(echo "$PROG" | grep "ca" | wc -l)` stampa il contenuto di $NUM, che conterrà il numero di programmi che iniziano con ca. La variabile $NUM rimane locale all’esecuzione dello script, non posso neanche usare export perché viene trasposta ai processi figli di quel nuovo terminale creato all’inizio dello script.

`chmod +100` permesso di esecuzione a user e 0 agli altri.
