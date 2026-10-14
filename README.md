# Circuitos

Repositorio de firmware y pruebas de los circuitos gestionados desde Duo.

## Flujo

1. Los agentes trabajan en una rama y modifican `circuitos/circuitos.ino` y, cuando exista, `diagram.mokxi.json`.
2. GitHub Actions ejecuta `mokxi test` en cada push y pull request.
3. Tras fusionar en `main`, el proceso local `mokxi watch` sincroniza el repositorio con Mokxi.
4. Duo abre Mokxi en su vista **Circuitos** usando Chromium/CEF.

GitHub Actions también publica `main` en Mokxi automáticamente. Después de
vincular el proyecto, crea el secreto de repositorio `MOKXI_TOKEN` con scopes
`projects:read` y `projects:write`. Hasta que exista, el workflow de publicación
se omite de forma segura; la validación sigue funcionando sin token.

## Primera vinculación con Mokxi

Abre o crea el circuito en Mokxi, descárgalo con la CLI dentro de este repositorio y registra el proyecto:

```bash
npx @mokxi/cli login
npx @mokxi/cli pull https://mokxi.com/p/ID_DEL_PROYECTO .
git add . && git commit -m "Vincula proyecto Mokxi"
git push
```

Después deja activo el sincronizador local:

```bash
npx @mokxi/cli watch
```

El ejemplo actual es un firmware Arduino Uno mínimo para comprobar que la
automatización está operativa. Al hacer `pull`, Mokxi añadirá
`diagram.mokxi.json`; ese archivo describe placas, componentes y cableado.

