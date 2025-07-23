# Include NyDMS

NyDMS é uma include desenvolvida para o SA-MP (San Andreas Multiplayer), com foco na manipulação estruturada e
simplificada de dados armazenados em arquivos locais no formato `.ini`. Seu principal objetivo é oferecer uma
solução leve, modular e de fácil integração, servindo como alternativa moderna a includes populares como
*dini*, "DOF2" e *y_ini*.

O nome "NyDMS" é uma fusão entre o pseudônimo do autor, *Nyvlehk*, e a sigla *DMS*, que significa
*Data Manipulation System* (Sistema de Manipulação de Dados). A estrutura do nome representa:
(Ny)vlehk + (D)ata (M)anipulation (S)ystem.

---

📂 - Funções Disponíveis:

🔹 Inicialização do Sistema:
- `NyDMS_Start();` – Inicia o sistema.

🔹 Manipulação de Arquivos:
- `NyDMS_CreateFile(const Filename[]);` – Cria um novo arquivo.
- `NyDMS_RemoveFile(const Filename[]);` – Remove um arquivo existente.
- `NyDMS_FileExists(const Filename[]);` – Verifica se o arquivo existe.
- `NyDMS_FolderExists(const Folder[]);` – Verifica a existência de uma pasta.

🔹 Manipulação de Dados:
- `NyDMS_SetString(const Filename[], const Key[], const Value[]);` – Define uma string.
- `NyDMS_GetString(const Filename[], const Key[]);` – Obtém uma string.
- `NyDMS_SetInt(const Filename[], const Key[], const Value);` – Define um valor inteiro.
- `NyDMS_GetInt(const Filename[], const Key[]);` – Obtém um valor inteiro.
- `NyDMS_SetFloat(const Filename[], const Key[], Float:Value);` – Define um valor decimal.
- `NyDMS_GetFloat(const Filename[], const Key[]);` – Obtém um valor decimal.
- `NyDMS_SetBoolean(const Filename[], const Key[], bool:Value);` – Define um valor booleano.
- `NyDMS_GetBoolean(const Filename[], const Key[]);` – Obtém um valor booleano.
- `NyDMS_IsSet(const Filename[], const Key[]);` – Verifica se uma chave está definida.
- `NyDMS_UnSet(const Filename[], const Key[]);` – Remove a chave e seu valor associado de um arquivo.

🔹 Manipulação de Logs:
- `NyDMS_CreateLog(const Filename[]);` – Cria um arquivo de log.
- `NyDMS_WriteLog(const Filename[], const StringLog[]);` – Escreve uma entrada em um log.
- `NyDMS_DeleteLog(const Filename[]);` – Exclui o arquivo de log.
- `NyDMS_CheckLog(const Filename[]);` – Verifica a existência de um log.

---

⚠️ - Atenção:
 Certifique-se de utilizar o comando NyDMS_Start(); dentro da callback OnGameModeInit();.
Executá-lo em outro local ou tentar contornar essa exigência pode causar falhas no funcionamento do sistema,
afetar a integridade dos dados ou até comprometer a estabilidade do seu servidor.
Siga sempre as instruções recomendadas para garantir o uso seguro e eficiente da include.

Atenciosamente,
Nyvlehk

---

💰 - Apoie
Se este sistema foi útil para você e deseja colaborar com o desenvolvimento de futuras melhorias, considere fazer uma contribuição via LivePix:
🔗 https://livepix.gg/khelvinzito

Qualquer valor é bem-vindo e ajuda a manter o projeto ativo e gratuito para a comunidade.
Muito obrigado pelo apoio! 🙏

🌐 Redes sociais
Quer me acompanhar nas redes? Acesse o link abaixo e fique por dentro das novidades, projetos e lives:
🔗 https://khelvinzito.vercel.app/

Lá você encontra todos os meus perfis em um só lugar.
Te vejo por lá! 📱✨

🟣 Lives todos os dias na Twitch, às 22h! 

---

```
                 NyDMS 1.0.0
© Copyright 2025 by Kelvin (Nyvlehk) Soares.

@author    : Nyvlehk (https://khelvinzito.vercel.app/)
@date      : 01/Jul/2025
@update    : 02/Jul/2025

Khelvinzito e Nyvlehk sao a mesma pessoas! So pra deixar claro.
```
