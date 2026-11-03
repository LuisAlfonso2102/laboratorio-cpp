param(
    [Parameter(Mandatory = $true)]
    [string]$Archivo,

    [Parameter(Mandatory = $true)]
    [string]$Raiz
)

$ErrorActionPreference = "Stop"
$archivoCompleto = (Resolve-Path $Archivo).Path
$librerias = Join-Path $Raiz "librerias"
$salidaDir = Join-Path $Raiz "build"
$nombre = [IO.Path]::GetFileNameWithoutExtension($archivoCompleto)
$salida = Join-Path $salidaDir "$nombre.exe"

New-Item -ItemType Directory -Force -Path $salidaDir | Out-Null
$fuentes = @(
    Get-ChildItem $librerias -Filter *.cpp -File |
    ForEach-Object { $_.FullName }
)

$argumentos = @(
    "-std=c++20",
    "-Wall",
    "-Wextra",
    "-pedantic",
    $archivoCompleto
)
$argumentos += $fuentes
$argumentos += @("-I$librerias", "-o", $salida)

& g++ @argumentos
if ($LASTEXITCODE -eq 0) {
    & $salida
}
