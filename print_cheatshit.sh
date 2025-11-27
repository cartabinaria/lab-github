#!/bin/bash

# Nome dello script: stampa_file_predefiniti.sh
# Descrizione: Stampa il contenuto di due file predefiniti che si trovano
#              nella stessa cartella dello script.

# --- 1. DEFINIZIONE DEI NOMI DEI FILE ---
# Definisci qui i nomi esatti dei file che vuoi stampare.
FILE1="cheatsheetTerm1.md"
FILE2="cheatsheetTerm2.md"
# ----------------------------------------

echo "Esecuzione dello script nella cartella: $(pwd)"
echo "---"

echo "--- 📝 Contenuto di $FILE1 ---"
if [ -f "$FILE1" ]; then
    # Stampa il contenuto del primo file
    cat "$FILE1"
else
    echo "Errore: Il file '$FILE1' non esiste in questa cartella."
fi

echo "" # Aggiunge una riga vuota per separazione

echo "--- 📝 Contenuto di $FILE2 ---"
if [ -f "$FILE2" ]; then
    # Stampa il contenuto del secondo file
    cat "$FILE2"
else
    echo "Errore: Il file '$FILE2' non esiste in questa cartella."
fi

echo "--- Fine dello script ---"
