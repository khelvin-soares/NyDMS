/*  

NNNNN    NNN     YYYYY   YYYYYY     DDDDDDDDDDD     MMMMM     MMMMM     SSSSSSSSSSS
NNNNNN   NNN      YYYYY  YYYYY      DDD      DDD    MMMMMM   MMMMMM    SSS
NNN NNN  NNN       YYYYY YYYY       DDD       DDD   MMM MMM MMM MMM     SSSSS
NNN NNN  NNN         YYYYYYY        DDD       DDD   MMM  MMMMM  MMM          SSSSSSS
NNN  NNN NNN          YYYYY         DDD       DDD   MMM   MMM   MMM               SSS
NNN   NNNNNN         YYYYY          DDD      DDD    MMM         MMM              SSS
NNN    NNNNN        YYYYY           DDDDDDDDDDD     MMM         MMM     SSSSSSSSSSSS

| - +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ - |

NyDMS é uma include desenvolvida para o SA-MP (San Andreas Multiplayer), com foco na manipulação estruturada e
simplificada de dados armazenados em arquivos locais no formato `.ini`. Seu principal objetivo é oferecer uma
solução leve, modular e de fácil integração, servindo como alternativa moderna a includes populares como
*dini*, "DOF2" e *y_ini*.

O nome "NyDMS" é uma fusão entre o pseudônimo do autor, *Nyvlehk*, e a sigla *DMS*, que significa
*Data Manipulation System* (Sistema de Manipulação de Dados). A estrutura do nome representa:
(Ny)vlehk + (D)ata (M)anipulation (S)ystem.

| - +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ - |

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

| - +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ - |

⚠️ - Atenção:
 Certifique-se de utilizar o comando NyDMS_Start(); dentro da callback OnGameModeInit();.
Executá-lo em outro local ou tentar contornar essa exigência pode causar falhas no funcionamento do sistema,
afetar a integridade dos dados ou até comprometer a estabilidade do seu servidor.
Siga sempre as instruções recomendadas para garantir o uso seguro e eficiente da include.

Atenciosamente,
Nyvlehk

| - +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ - |

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

| - +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ - |

               NyDMS 2.0.0
© Copyright 2025 by Kelvin (Nyvlehk) Soares.

@author    : Nyvlehk (https://khelvinzito.vercel.app/)
@date      : 01/Jul/2025
@update    : 02/Jul/2025

Khelvinzito e Nyvlehk sao a mesma pessoas! So pra deixar claro.

*/

new bool:CheckDefinedCommand = false;
new NyDMS_String[3000];

#if defined _nydms_included
  #endinput
#endif

#define _nydms_included
#pragma library nydms

#define NYDMS_MAX_STRING            (255)

#if !defined NyDMS
	#define NyDMS static stock
#endif

#define SystemConsoleFormatted(%0,%1); format(NyDMS_String, sizeof(NyDMS_String), %0,%1); SystemConsole(NyDMS_String);

#define NyDMS_SetBool			NyDMS_SetBoolean
#define NyDMS_GetBool			NyDMS_SetGoolean

// Estrutura adaptada para uso com a biblioteca dini.
#if !defined _dini_included
    #define _dini_included
#endif

#define dini_Exists		        NyDMS_FileExists
#define dini_Remove         	NyDMS_RemoveFile
#define dini_Create         	NyDMS_CreateFile
#define dini_Set			    NyDMS_SetString
#define dini_Get         		NyDMS_GetString
#define dini_IntSet   			NyDMS_SetInt
#define dini_Int         		NyDMS_GetInt
#define dini_BoolSet            NyDMS_SetBoolean
#define dini_Bool               NyDMS_GetBoolean
#define dini_FloatSet 			NyDMS_SetFloat
#define dini_Float      		NyDMS_GetFloat
#define dini_Isset       		NyDMS_IsSet
#define dini_Unset       		NyDMS_Unset

// Estrutura adaptada para uso com a biblioteca DOF2.
#define DOF2_FileExists		        NyDMS_FileExists
#define DOF2_RemoveFile             NyDMS_RemoveFile
#define DOF2_CreateFile         	NyDMS_CreateFile
#define DOF2_SetString			    NyDMS_SetString
#define DOF2_GetString         		NyDMS_GetString
#define DOF2_SetInt   			    NyDMS_SetInt
#define DOF2_GetInt         		NyDMS_GetInt
#define DOF2_SetBool                NyDMS_SetBoolean
#define DOF2_GetBool                NyDMS_GetBoolean
#define DOF2_SetFloat 			    NyDMS_SetFloat
#define DOF2_GetFloat      		    NyDMS_GetFloat
#define DOF2_Isset       		    NyDMS_IsSet
#define DOF2_Unset       		    NyDMS_Unset

#if !defined _dof2_included
	#define _dof2_included
#endif

forward NyDMS_Start();

public NyDMS_Start() {
    printf("\n\n");
    printf("NNNNN    NNN     YYYYY   YYYYYY     DDDDDDDDDDD     MMMMM     MMMMM     SSSSSSSSSSS");
    printf("NNNNNN   NNN      YYYYY  YYYYY      DDD      DDD    MMMMMM   MMMMMM    SSS");
    printf("NNN NNN  NNN       YYYYY YYYY       DDD       DDD   MMM MMM MMM MMM     SSSSS");
    printf("NNN NNN  NNN         YYYYYYY        DDD       DDD   MMM  MMMMM  MMM          SSSSSSS");
    printf("NNN  NNN NNN          YYYYY         DDD       DDD   MMM   MMM   MMM               SSS");
    printf("NNN   NNNNNN         YYYYY          DDD      DDD    MMM         MMM              SSS");
    printf("NNN    NNNNN        YYYYY           DDDDDDDDDDD     MMM         MMM     SSSSSSSSSSSS\n\n");
    printf("| +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ |");
    printf("                                           ");
    printf("                  Nyvlehk                  ");
    printf("               Version 2.0.0               ");
    printf("                01/Jul/2025                ");
    printf("      https://khelvinzito.vercel.app/      ");
    printf("  Thank you for choosing to use NyDMS. :)  ");
    printf("     (c) 2025 Kelvin (Nyvlehk) Soares.     ");
    printf("                                           ");
    printf("| +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ |\n");
	CheckDefinedCommand = true;
	SystemCheckDirectory();
    SystemCheckLogExists();
    return 1;
}

stock NyDMS_FileExists(const Filename[]) {
	if(!SystemCheckDefinedCommand(CheckDefinedCommand) == true)
		return 1;
    return SystemFileExists(Filename);
}
NyDMS SystemFileExists(const Filename[]) {
    return fexist(Filename);
}

stock NyDMS_RemoveFile(const Filename[]) {
    return SystemRemoveFile(Filename);
}
NyDMS SystemRemoveFile(const Filename[]) {
    return fremove(Filename);
}

stock NyDMS_CreateFile(const Filename[]) {
	return SystemCreateFile(Filename);
}
NyDMS SystemCreateFile(const Filename[]) {
	if(fexist(Filename))    
        return false;

	new File:FileHandle;
	FileHandle = fopen(Filename, io_write);
	if(FileHandle) {
		fclose(FileHandle);
		return true;
	}
	return false;
}

stock NyDMS_SetString(const Filename[], const Key[], const Value[]) {
	return SystemSetString(Filename, Key, Value);
}
NyDMS SystemSetString(const Filename[], const Key[], const Value[]) {
	new File:FileHandle, File:FileWriteHandle;
	new bool:Wasset = false;
	new TempResult[NYDMS_MAX_STRING];

	if(Key[0] == 0)
        return false;

	format(TempResult, sizeof(TempResult), "%s.part", Filename);
	FileHandle = fopen(Filename, io_read);
	if(!FileHandle)
        return false;

	fremove(TempResult);
	FileWriteHandle = fopen(TempResult, io_write);
	while(fread(FileHandle, TempResult)) {
		SystemRemoveNewLine(TempResult);
		if((!Wasset) && (SystemIsWitch(SystemExtractPrivateKey(TempResult), Key, true))) {
			format(TempResult, sizeof(TempResult), "%s=%s", Key, Value);
			Wasset = true;
		}
		fwrite(FileWriteHandle, TempResult);
		fwrite(FileWriteHandle, "\r\n");
	}

	if (!Wasset) {
		format(TempResult, sizeof(TempResult), "%s=%s", Key, Value);
		fwrite(FileWriteHandle, TempResult);
		fwrite(FileWriteHandle, "\r\n");
	}

	fclose(FileHandle);
	fclose(FileWriteHandle);

	format(TempResult, sizeof(TempResult), "%s.part", Filename);
	if(SystemCopyTextFile(TempResult, Filename)) {
		return fremove(TempResult);
	}
	return false;
}

stock NyDMS_GetString(const Filename[], const Key[]) {
	SystemGetString(Filename, Key);
	return 1;
}
NyDMS SystemGetString(const Filename[], const Key[]) {
	new File:FileHandle;
	new TempResult[NYDMS_MAX_STRING];
	new TempResult2[NYDMS_MAX_STRING];

	TempResult[0] = 0;
	FileHandle = fopen(Filename, io_read);
	if(!FileHandle)
        return TempResult;

	while(fread(FileHandle, TempResult)) {
		SystemRemoveNewLine(TempResult);
		if(SystemIsWitch(SystemExtractPrivateKey(TempResult), Key, true)) {
			TempResult2[0] = 0;
			strcat(TempResult2, SystemExtractPrivateValue(TempResult));
			fclose(FileHandle);
			return TempResult2;
		}
	}
	fclose(FileHandle);
	return TempResult;
}

stock NyDMS_SetInt(const Filename[], const Key[], Value) {
	return SystemSetInt(Filename, Key, Value);
}
NyDMS SystemSetInt(const Filename[], const Key[], Value) {
	new ValueString[NYDMS_MAX_STRING];
	format(ValueString, sizeof(ValueString), "%d", Value);
	return SystemSetString(Filename, Key, ValueString);
}

stock NyDMS_GetInt(const Filename[], const Key[]) {
   	return SystemGetInt(Filename, Key);
}
NyDMS SystemGetInt(const Filename[], const Key[]) {
   	return strval(SystemGetString(Filename, Key));
}

NyDMS Float:SystemSetFloat(const Filename[], const Key[], Float:Value) {
	new ValueString[NYDMS_MAX_STRING];
	format(ValueString, sizeof(ValueString), "%f", Value);
	return SystemSetString(Filename, Key, ValueString);
}
stock Float:NyDMS_SetFloat(const Filename[], const Key[], Float:Value) {
	return SystemSetFloat(Filename, Key, Value);
}

NyDMS Float:SystemGetFloat(const Filename[], const Key[]) {
	return floatstr(SystemGetString(Filename, Key));
}
stock Float:NyDMS_GetFloat(const Filename[], const Key[]) {
	return SystemGetFloat(Filename, Key);
}

NyDMS bool:SystemSetBoolean(const Filename[], const Key[], bool:Value) {
	new FormatValue = 0;
	if(Value == true) {
		FormatValue = 1;
	} else if(Value == false) {
		FormatValue = 0;
	} else {
		SystemConsoleFormatted("[NyDMS INFO]: Algo deu errado! O valor definido nao existe, use apenas 'true' ou 'false'.");
	}

   	new ValueString[NYDMS_MAX_STRING];
   	format(ValueString, sizeof(ValueString), "%d", FormatValue);
	SystemSetString(Filename, Key, ValueString);
   	return true;
}
stock bool:NyDMS_SetBoolean(const Filename[], const Key[], bool:Value) {
   	return SystemSetBoolean(Filename, Key, Value);
}

NyDMS bool:SystemGetBoolean(const Filename[], const Key[]) {
	new bool:StringBool = false;
	if(strval(SystemGetString(Filename, Key)) == 1) {
		StringBool = true;
	} else {
		StringBool = false;
	}
   	return StringBool;
}
stock bool:NyDMS_GetBoolean(const Filename[], const Key[]) {
	return SystemGetBoolean(Filename, Key);
}

stock NyDMS_IsSet(const Filename[], const Key[]) {
	return SystemIsSet(Filename, Key);
}
NyDMS SystemIsSet(const Filename[], const Key[]) {
	new File:FileHandle;
	new TempResult[NYDMS_MAX_STRING];
	FileHandle = fopen(Filename, io_read);

	if(!FileHandle)
		return false;

	while(fread(FileHandle, TempResult)) {
		SystemRemoveNewLine(TempResult);
		if(SystemIsWitch(SystemExtractPrivateKey(TempResult), Key, true)) {
			fclose(FileHandle);
			return true;
		}
	}
	fclose(FileHandle);
	return false;
}

stock NyDMS_UnSet(const Filename[], const Key[]) {
	return SystemUnSet(Filename, Key);
}
NyDMS SystemUnSet(const Filename[], const Key[]) {
	new TempResult[NYDMS_MAX_STRING];
	new File:FileHandle, File:FileWriteHandle;
	format(TempResult, sizeof(TempResult), "%s.part", Filename);
	FileHandle = fopen(Filename, io_read);

	if(!FileHandle)
		return false;

	fremove(TempResult);
	FileWriteHandle = fopen(TempResult, io_write);
	while(fread(FileHandle,TempResult)) {
		SystemRemoveNewLine(TempResult);
		if(SystemIsWitch(SystemExtractPrivateKey(TempResult), Key, true)) {
		} else {
			format(TempResult, sizeof(TempResult), "%s", TempResult);
			fwrite(FileWriteHandle, TempResult);
			fwrite(FileWriteHandle, "\r\n");
		}
	}

	fclose(FileHandle);
	fclose(FileWriteHandle);

	format(TempResult, sizeof(TempResult), "%s.part", Filename);
	if(SystemCopyTextFile(TempResult, Filename)) {
		return fremove(TempResult);
	}
	return false;
}

stock NyDMS_CreateLog(const Filename[]) {
    return SystemCreateLog(Filename);
}
NyDMS SystemCreateLog(const Filename[]) {
    new File:archive = fopen(Filename, io_write);
    fclose(archive);
    return 1;
}

stock NyDMS_WriteLog(const Filename[], const StringLog[]) {
    return SystemWriteLog(Filename, StringLog);
}
NyDMS SystemWriteLog(const Filename[], const StringLog[]) {
    new StrLog[3000];
    new LogYear, LogMonth, LogDay;
	new LogHour, LogMinute, LogSecond;
	getdate(LogYear, LogMonth, LogDay);
    gettime(LogHour, LogMinute, LogSecond);
    format(StrLog, sizeof(StrLog), "(%02d/%02d/%d) - [%02d:%02d:%02d] > %s\r\n", LogDay, LogMonth, LogYear, LogHour, LogMinute, LogSecond, StringLog);

    new File:Archive = fopen(Filename, io_append);
    fwrite(Archive, StrLog);
    fclose(Archive);
    return 1;
}

stock NyDMS_DeleteLog(const Filename[]) {
    return SystemDeleteLog(Filename);
}
NyDMS SystemDeleteLog(const Filename[]) {
    return fremove(Filename);
}

stock NyDMS_FolderExists(const Folder[]) {
	return SystemFolderExists(Folder);
}
NyDMS SystemFolderExists(const Folder[]) {
    new NyDMS_LocalStr[500];
	format(NyDMS_LocalStr, sizeof(NyDMS_LocalStr), "%s/checking.log", Folder);
	NyDMS_CreateFile(NyDMS_LocalStr);
	if(fexist(NyDMS_LocalStr)) {
	    printf("[NyDMS INFO]: A pasta '%s' foi encontrada e carregado com sucesso.", Folder);
	} else if(!fexist(NyDMS_LocalStr)) {
	    printf("[NyDMS ERROR]: A pasta '%s' nao foi encontrada ou nao existe.", Folder);
		SystemConsoleFormatted("[NyDMS ERROR]: A pasta '%s' nao foi encontrada ou nao existe.", Folder);
	}
	fremove(NyDMS_LocalStr);
	return 1;
}

stock NyDMS_CheckLog(const Filename[]) {
	return SystemCheckLog(Filename);
}
NyDMS SystemCheckLog(const Filename[]) {
	if(fexist(Filename)) {
	    printf("[NyDMS INFO]: O log '%s' foi encontrado e carregado com sucesso.", Filename);
	} else if(!fexist(Filename)) {
	    printf("[NyDMS ERROR]: O log '%s' nao foi encontrado ou nao existe.", Filename);
		SystemConsoleFormatted("[NyDMS ERROR]: O log '%s' nao foi encontrado ou nao existe.", Filename);
	}
	return 1;
}



NyDMS SystemConsole(const ErrorMessage[]) {
    new Path[200] = "NyDMS/SystemConsole.log";
    if(!fexist(Path)) {
        SystemCreateLog(Path);
        SystemWriteLog(Path, ErrorMessage);
    } else if(fexist(Path)) {
        SystemWriteLog(Path, ErrorMessage);
    }
    return 1;
}

NyDMS SystemIsWitch(const Str1[], const Str2[], bool:Ignorecase) {
    if(strlen(Str1) != strlen(Str2))
        return false;
    if(strcmp(Str1, Str2, Ignorecase) == 0)
        return true;
    return false;
}

NyDMS SystemStringCopy(Dest[], const Source[]) {
	new Count = strlen(Source);

	for(new i = 0; i < Count; i++) {
		Dest[i] = Source[i];
	}
	Dest[Count] = 0;
}

NyDMS SystemRemoveNewLine(string[]) {
	new len = strlen(string);

	if(string[0] == 0)
        return ;

	if((string[len - 1] == '\n') || (string[len - 1] == '\r')) {
		string[len - 1] = 0;
		if(string[0] == 0)
            return ;
		if((string[len - 2] == '\n') || (string[len - 2] == '\r')) { string[len - 2] = 0; }
	}
}

NyDMS SystemCopyTextFile(const Oldname[], const Newname[]) {
	new File:FileHandle, File:FileWriteHandle;

	if(!fexist(Oldname))
        return false;

	FileHandle = fopen(Oldname, io_read);
	FileWriteHandle = fopen(Newname, io_write);

	new tmpres[NYDMS_MAX_STRING];
	while(fread(FileHandle, tmpres)) {
		SystemRemoveNewLine(tmpres);
		format(tmpres, sizeof(tmpres), "%s\r\n", tmpres);
		fwrite(FileWriteHandle, tmpres);
	}
	fclose(FileHandle);
	fclose(FileWriteHandle);
	return true;
}

NyDMS SystemStringLowercase(const Text[]) {
	new tmpres[NYDMS_MAX_STRING];

	tmpres[0] = 0;
	if(Text[0] == 0)
        return tmpres;

	for(new i = 0; i < strlen(Text); i++) {
		tmpres[i] = tolower(Text[i]);
	}
	tmpres[strlen(Text)] = 0;
	return tmpres;
}

NyDMS SystemExtractPrivateKey(const Line[]) {
	new StrTempResult[NYDMS_MAX_STRING];

	StrTempResult[0] = 0;
	if(strfind(Line, "=", true) == -1)
        return StrTempResult;

	SystemStringCopy(StrTempResult, SystemStringLowercase(SystemReturnMemoryCopy(Line, 0, strfind(Line, "=", true))));
	return StrTempResult;
}

NyDMS SystemExtractPrivateValue(const Line[]) {
    new tmpres[NYDMS_MAX_STRING];

    tmpres[0] = 0;
    if(strfind(Line, "=", true) == -1) {
        return tmpres;
    }
    
    SystemStringCopy(tmpres, SystemReturnMemoryCopy(Line, strfind(Line, "=" , true) + 1, strlen(Line)));
    return tmpres;
}

NyDMS SystemReturnMemoryCopy(const Source[], Index = 0, NumBytes) {
	new tmpres[NYDMS_MAX_STRING];

	tmpres[0] = 0;
	if(Index >= strlen(Source))
        return tmpres;

	if(NumBytes + Index >= strlen(Source)) { NumBytes = strlen(Source) - Index; }
	if(NumBytes <= 0)
        return tmpres;
	for(new i = Index; i < NumBytes + Index; i++) {
		tmpres[i-Index] = Source[i];
		if(Source[i] == 0)
            return tmpres;
	}
	tmpres[NumBytes] = 0;
	return tmpres;
}

NyDMS SystemCheckDirectory() {
	SystemCreateFile("NyDMS/checking.log");
	if(!fexist("NyDMS/checking.log")) {
        SystemCreateFile("nydms-error-log.log");
        if(fexist("nydms-error-log.log")) {
            SystemWriteLog("nydms-error-log.log", "[NyDMS ERROR]: A pasta 'NyDMS' nao foi encontrada. Por favor, crie-a dentro do diretorio 'scriptfiles' para que o sistema funcione corretamente.");
            SystemWriteLog("nydms-error-log.log", "[NyDMS INFO]: Apos a criacao da pasta, este arquivo sera excluido automaticamente na proxima execucao do servidor.");
        }
        SendRconCommand("exit");
	} else {
        if(fexist("nydms-error-log.log")) {
            fremove("nydms-error-log.log");
        }
    }
	fremove("NyDMS/checking.log");
	return 1;
}

NyDMS SystemCheckLogExists() {
    new Path[200] = "NyDMS/SystemConsole.log";
    if(!fexist(Path)) {
        SystemCreateLog(Path);
        printf("[NyDMS]: Log do sistema gerado e carregado corretamente.");
        SystemConsole("[NyDMS ERROR]: O log do sistema nao foi encontrado. Um novo arquivo foi criado automaticamente.");
    } else if(fexist(Path)) {
        printf("[NyDMS]: Log do sistema carregado corretamente.");
    } else {
        SystemConsole("[NyDMS ERROR]: Falha ao criar ou carregar o log do sistema. Certifique-se de que a pasta 'NyDMS' existe dentro do diretorio 'scriptfiles'.");
        SendRconCommand("exit");
    }
    return 1;
}


stock SystemCheckDefinedCommand(bool:Value) {
    if(Value == false) { 
        SystemConsole("[NyDMS WARNING]: A funcao 'NyDMS_Start();' deve ser chamada dentro da public 'OnGameModeInit()' para inicializar corretamente o sistema.");
        printf("[NyDMS WARNING]: A funcao 'NyDMS_Start();' deve ser chamada dentro da public 'OnGameModeInit()' para inicializar corretamente o sistema.");
        SendRconCommand("exit");
        return false;
    }
    return true;
}
