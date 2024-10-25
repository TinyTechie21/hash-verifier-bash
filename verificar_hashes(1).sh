#!/bin/bash


if [ $# -ne 2 ]; then
  echo "Uso: $0 <diretoria> <ficheiro_de_hashes>"
  exit 1
fi


diretoria=$1
ficheiro_hashes=$2


if [ ! -d "$diretoria" ]; then
  echo "Erro: diretoria não encontrada"
  exit 1
fi


if [ ! -f "$ficheiro_hashes" ]; then
  echo "Erro: ficheiro de hashes não encontrado"
  exit 1
fi


linha=1
while read -r hash nome_ficheiro; do
  hash_obtido=$(sha1sum "$diretoria/$nome_ficheiro" | cut -d' ' -f1)

  
  if ! ./compara "$hash" "$hash_obtido"; then
    echo "Erro na linha $linha: $nome_ficheiro"
  fi

  linha=$((linha+1))
done < "$ficheiro_hashes"


if [ $? -eq 0 ]; then
  echo "OK"
fi

