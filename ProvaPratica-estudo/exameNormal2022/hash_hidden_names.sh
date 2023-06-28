#!/bin/bash
set -u

data_atual=$(date +"%Y%m%d")
user=$(whoami)
PATH="/home/${user}"
nome_ficheiro="${user}_hidden_files_list_${data_atual}.txt"
count=0

hash_hidden_files() {
    local dir=$1

    for file in "$dir"/*; do
        if [[ $(basename "$file") == .* ]]; then
            hash=$(sha1sum "$file" | awk '{print $1}')
            ((count++))
            echo "[FILE$count]$file => $hash" >> "$nome_ficheiro"
        fi

        if [[ -d "$file" ]]; then
            hash_hidden_files "$file"
        fi
    done
}

hash_hidden_files "$PATH"

echo "Your home directory \"$PATH\" has $count hidden files."
echo "The list of hidden files was saved to the file: $nome_ficheiro"
