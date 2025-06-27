==============================
       Conjuntão C™
==============================

📄 Descrição:
-------------
Projeto acadêmico da disciplina **Fundamentos de Tecnologia da Computação (FTC)** – UFGD 🎓

Este programa em **linguagem C** realiza operações com conjuntos e análise de propriedades relacionais.

Você pode escolher entre:

1️⃣ Conjuntacao (operações clássicas de conjuntos):
   - União
   - Interseção
   - Diferença (A - B)

2️⃣ Propriedades Relacionais (verificação de relações):
   - Reflexiva
   - Simétrica
   - Transitiva

Tudo via terminal e com interação amigável ao usuário 🖥️✨.

---

📦 Estrutura de arquivos:
-------------------------
- `FTC.c`          → Código-fonte principal
- `FTC.o`          → Arquivo objeto (gerado na compilação)
- `output/`        → Pasta de saída com o executável (`FTC.exe`)
- `README.txt`     → Este arquivo com todas as informações

---

🔧 Como compilar:
-----------------
Usando GCC (Terminal ou VS Code):

✔️ Para gerar só o `.o`:
gcc -Wall -Wextra -c FTC.c -o FTC.o


✔️ Para gerar o `.exe`:
gcc FTC.o -o output/FTC.exe


✔️ Ou tudo de uma vez:
gcc -Wall -Wextra FTC.c -o output/FTC.exe


---

🚀 Como executar:
-----------------
Se estiver no Windows:
./output/FTC.exe

Ou, simplesmente, dê dois cliques no `.exe`.

Se estiver no Linux:
./output/FTC

*(Adapte o caminho caso precise)*

---

🧠 Conceitos trabalhados:
-------------------------
- Vetores (Arrays)
- Laços de repetição (`for`, `while`)
- Controle de fluxo com `switch`
- Funções com passagem de parâmetros
- Manipulação de entrada (controle de buffer com `getchar()`)
- Uso de booleanos (`stdbool.h`)
- Limpeza de tela com macros adaptadas pra Windows/Linux
- Testes de propriedades matemáticas em relações (Reflexiva, Simétrica, Transitiva)

---

⚠️ Observações:
---------------
- O limite de elementos por conjunto é **20** (definido por `#define MAX 20`).
- O código evita duplicatas nas operações de conjuntos.
- Entrada de dados não tem validação robusta: **siga as instruções na tela!**
- Estrutura pensada pra ser didática, mas algumas gambiarras foram inevitáveis 😅.

---

👨‍💻 Autor:
----------
Farias, Leonardo.

---

🎯 Projeto acadêmico - UFGD - 2025
