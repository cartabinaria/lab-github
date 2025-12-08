### Slide della scorsa volta

[main.pdf](https://risorse.vercel.app/lab/2025/terminale-1/main.pdf)

# STDIO e ridirezioni

## Output

Normale output di un comando, può essere visto come un file e usato su pipe e ridirezione. `>` distruttiva, `>>` appende in fondo al file.

```bash
comando > /path/to/output_file.txt
```

## Error

```bash
comando_che_genera_errore > /path/to/output.txt
```

Il file `output.txt` viene creato (l’esecuzione non si ferma all’errore) ma `output.txt` non conterrà l’errore del comando perché non è `stdout`.

```bash
comando_che_genera_errore > /path/to/output_and_error.txt 2>&1
```

Ridirezionare lo `stderr` sullo stdout: `2>&1` . Non mostra messaggio di errore e ora `output_and_error.txt` contiene l’errore del comando.

```bash
comando_che_genera_errore > /path/to/output.txt 2> /path/to/error_file.txt
```

Crea un file di nome `error_file.txt` e `output.txt` è vuoto. Ha preso `2> /path/to/error_file.txt` come: prendi lo `stderr` e mettilo nel file specificato.

```bash
comando_che_genera_errore > /path/to/output.txt 2>/dev/null
```

Butta tutti gli errori dentro `/dev/null` e non saranno più recuperabili.

## Echo

```bash
echo /path/to/*/pattern
```

Stampa tutti i percorsi relativi delle sottocartelle (o cartelle) che corrispondono a `pattern` all'interno di `/path/to/`.

```bash
echo {1..10}
echo {a..z}
```

Stampa tutti i numeri e caratteri in mezzo ai valori definiti.

```bash
file $(ls -d /bin/* | grep utility_name)
file $(find /path/to/binaries -name "program_name" -print)
```

Il primo esempio stampa informazioni sui file che corrispondono a `utility_name` tra gli eseguibili in `/bin/`. Il secondo esempio trova il percorso di un `program_name` in `/path/to/binaries` e stampa il tipo di file. Questa sintassi è necessaria per rispettare la sintassi di `file`.

# Variabili

```bash
set src "/path/to/source_folder"
set dest "/path/to/destination_folder"
echo "$dest"
echo "$src"
cp -r "$src" "$dest"
ls /path/to/directory
```

`set` copia i valori nelle variabili locali, e `cp` copia le cartelle ricorsivamente l’una dentro l’altra.

```bash
bash -c "comando con argomenti"
```

Lancia un comando in una nuova shell.

Le variabili custom vengono eliminate al riavvio del computer.

# Shell scripting

Per specificare che interprete usare:

```bash
#!/bin/bash
```

Specifica l’interprete da usare nella prima riga del file. Dice al terminale che stiamo creando un file di scripting. Non è necessario chiamare i file di scripting `*.sh` e definire le variabili maiuscole.

```bash
#!/bin/bash
echo "Reading programs"
PROG=$(ls -d /bin/*)
NUM=$(echo "$PROG" | grep "ca" | wc -l)
echo "Number of programs containing 'ca': $NUM"
```

`NUM=$(echo "$PROG" | grep "ca" | wc -l)` stampa il contenuto di `$NUM`, che conterrà il numero di programmi che iniziano con `ca`. La variabile `$NUM` rimane locale all’esecuzione dello script, non posso neanche usare `export` perché viene trasposta ai processi figli di quel nuovo terminale creato all’inizio dello script.

`chmod +x /path/to/my_script.sh` permesso di esecuzione a user.
