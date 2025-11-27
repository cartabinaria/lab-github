### Elenca i file

```sh
ls /path/to/directory
```

### Entrare in una cartella

```sh
cd /path/to/directory
```

### Uscire da una cartella

```sh
cd ..
```

### Creare una cartella

```sh
mkdir /path/to/new_directory
```

### Creare file

```sh
touch /path/to/new_file.txt
```

### Controllare di che tipo è un file

```sh
file /path/to/executable
```

### Copiare file

```sh
cp /path/to/source_file.txt /path/to/destination_directory/
```

### Spostare file

```sh
mv /path/to/source_file.txt /path/to/destination_directory/
```

### Rinominare file

```sh
mv /path/to/old_name.txt /path/to/new_name.txt
```

### Eliminare file

```sh
rm /path/to/file_to_delete.txt
```

### Copiare una cartella

```sh
cp -r /path/to/source_folder /path/to/destination_folder/
```

### Manuale di un comando

```sh
man ls
```

### Leggere un file di testo

```sh
less /path/to/text_file.txt
```

### Nano e Vim

```sh
nano /path/to/file.txt
vim /path/to/another_file.txt
```

### Contare caratteri

```sh
wc -l /path/to/file.txt
```

### Ricerca di una stringa

```sh
grep "string" /path/to/file.txt
```

### Concatenazione o lettura

```sh
cat /path/to/file.txt
```

### Testa e coda

```sh
head /path/to/log_file.txt
tail -f /path/to/another_log.log
```

### Wildcard

```sh
cp *.txt /path/to/destination/
ls -d dir*
cat file?.txt
cat *.log
```

### Cambiare owner e group

```sh
chmod 755 /path/to/script.sh
chown user:group /path/to/file.txt
chgrp group /path/to/file.txt
```

### Pipe

```sh
ls /bin | less
```

### Ridezione su file

```sh
comando > /path/to/output_file.txt
```
