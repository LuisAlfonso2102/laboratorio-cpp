#!/usr/bin/env bash
set -Eeuo pipefail

archivo="$1"
raiz="$2"
librerias="$raiz/librerias"
salida_dir="$raiz/build"
nombre="$(basename "${archivo%.*}")"
salida="$salida_dir/$nombre"

mkdir -p "$salida_dir"
mapfile -d '' fuentes < <(
    find "$librerias" -maxdepth 1 -type f -name '*.cpp' -print0
)

g++ -std=c++20 -Wall -Wextra -pedantic \
    "$archivo" "${fuentes[@]}" \
    -I"$librerias" \
    -o "$salida"

"$salida"
