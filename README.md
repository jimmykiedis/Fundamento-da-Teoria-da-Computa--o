==============================
       Conjuntão C™
==============================

📄 Descrição:
-------------
Este é um projeto em linguagem C que realiza operações clássicas de conjuntos:
1. União
2. Interseção
3. Diferença

O programa recebe dois vetores de inteiros e imprime os resultados de forma clara,
evitando duplicatas e exibindo a contagem total de elementos envolvidos.

📦 Arquivos:
------------
- FTC.c        → Código-fonte principal
- output/      → Pasta de saída com o executável (FTC.exe)
- README.txt   → Este arquivo

🔧 Como compilar:
-----------------
Usando GCC (no terminal ou no VS Code):

Para gerar só o `.o`:
    gcc -Wall -Wextra -c FTC.c -o FTC.o

Para gerar o `.exe`:
    gcc FTC.o -o output/FTC.exe

Ou tudo de uma vez:
    gcc -Wall -Wextra FTC.c -o output/FTC.exe

🚀 Como executar:
-----------------
No terminal:
    ./output/FTC.exe

Ou clique duas vezes no `.exe` (se estiver no Windows).

🧠 Conceitos usados:
--------------------
- Vetores
- Laços `for`
- Comparações entre arrays
- Funções com parâmetros
- Controle de fluxo com `switch` e `while`
- Uso de `bool`, `true` e `false` (com `<stdbool.h>`)

👨‍💻 Autor:
----------
Farias, Leonardo.

