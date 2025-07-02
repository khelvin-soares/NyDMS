/*  

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
- `NyDMS_Unset(const Filename[], const Key[]);` – Remove a chave e seu valor associado de um arquivo.

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

               NyDMS 1.0.0
© Copyright 2025 by Kelvin (Nyvlehk) Soares.

@author    : Nyvlehk (https://khelvinzito.vercel.app/)
@date      : 01/Jul/2025
@update    : 02/Jul/2025

Khelvinzito e Nyvlehk sao a mesma pessoas! So pra deixar claro.

*/

#if defined _nydms_included
  #endinput
#endif

#define _nydms_included
#pragma library nydms

#if defined MAX_STRING
    #define NyDMS_MAX_STRING MAX_STRING
#else
    #define NyDMS_MAX_STRING 255
#endif

#if !defined NyDMS
	#define NyDMS static stock
#endif

new NyDMS_String[3000];
#define SystemConsoleFormatted(%0,%1); format(NyDMS_String, sizeof(NyDMS_String), %0,%1); SystemConsole(NyDMS_String);

// Estrutura adaptada para uso com a biblioteca dini.
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

#if !defined _dini_included
    #define _dini_included
#endif

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

new bool:CheckDefinedCommand = false;

#define function%0(%1)	forward %0(%1); public %0(%1)
function NyDMS_Start() {
    printf("\n                                           ");
    printf("| +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ |");
    printf("                                           ");
    printf("                  Nyvlehk                  ");
    printf("               Version 1.0.0               ");
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

stock NyDMS_CreateFile(const Filename[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemCreateFile(Filename);
}
NyDMS SystemCreateFile(const File[]) {
	if(fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Criacao do arquivo '%s' falhou - arquivo ja existente.", File);
        return 1;
    } else if(!fexist(File)) {
        new File:Archive = fopen(File, io_write);
        if(Archive) {
            fclose(Archive);
            return 1;
        }
    }
	return 1;
}

stock NyDMS_RemoveFile(const Filename[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemRemoveFile(Filename);
}
NyDMS SystemRemoveFile(const File[]) {
    return fremove(File);
}

stock NyDMS_FileExists(const Filename[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemFileExists(Filename);
}
NyDMS SystemFileExists(const File[]) {
    return fexist(File);
}



stock NyDMS_SetString(const Filename[], const Key[], const Value[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemSetString(Filename, Key, Value);
}
NyDMS SystemSetString(const File[], const SystemKey[], const SystemValue[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

	new Key_Length = strlen(SystemKey);
	new Value_Length = strlen(SystemValue);
    new Sum = Key_Length + Value_Length + 2;

	if(Key_Length == 0 || Sum > NyDMS_MAX_STRING) {
        if(Key_Length == 0) {
            SystemConsole("[NyDMS ERROR]: A Key fornecida na funcao 'NyDMS_SetString' esta vazia. Defina uma Key valida com valor maior que zero.");
        }
        if(Sum > NyDMS_MAX_STRING) {
            SystemConsole("[NyDMS ERROR]: O valor definido na função 'NyDMS_SetString' excede o tamanho máximo permitido para a string.");
        }
        return 1;
    }
	
	new File:SourceFile, File:SourceFileCopy;
	new TempResult[NyDMS_MAX_STRING];
	new bool:Replace = false;
	
	format(TempResult ,sizeof(TempResult), "%s.part", File);
	fremove(TempResult);
	
	SourceFile = fopen(File, io_read);
	if(!SourceFile)
        return false;
	
	SourceFileCopy = fopen(TempResult, io_write);
	if(!SourceFileCopy) {
		fclose(SourceFile);
		return false;
	}
	
	while(fread(SourceFile, TempResult)) {
		if(!Replace && TempResult[Key_Length] == '=' && !strcmp(TempResult, SystemKey, true, Key_Length)) {
			format(TempResult, sizeof(TempResult), "%s=%s", SystemKey, SystemValue);
			Replace = true;
		} else {
			SystemRemoveNewLine(TempResult);
		}
		fwrite(SourceFileCopy, TempResult);
		fwrite(SourceFileCopy, "\r\n");
	}

	if(!Replace) {
		format(TempResult, sizeof(TempResult), "%s=%s", SystemKey, SystemValue);
		fwrite(SourceFileCopy, TempResult);
		fwrite(SourceFileCopy,"\r\n");
	}

	fclose(SourceFile);
	fclose(SourceFileCopy);

	format(TempResult, sizeof(TempResult), "%s.part", File);
	if(SystemCopyDataFile(TempResult, File)) {
		return fremove(TempResult);
	}
	return 1;
}

stock NyDMS_GetString(const Filename[], const Key[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    SystemGetString(Filename, Key);
    return 1;
}
NyDMS SystemGetString(const File[], const SystemKey[]) {
    new Key_Length = strlen(SystemKey);
    new TempResult[NyDMS_MAX_STRING];
    new Sum = Key_Length + 2;

    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
    } else if(fexist(File)){
        if(Key_Length == 0 || Sum > NyDMS_MAX_STRING)
            return TempResult;
        
        new File:SourceFile;
        SourceFile = fopen(File, io_read);
        if(!SourceFile)
            return TempResult;
        
        while(fread(SourceFile, TempResult)) {
            if(TempResult[Key_Length] == '=' && !strcmp(TempResult, SystemKey, true, Key_Length)) {
                SystemRemoveNewLine(TempResult);
                strmid(TempResult, TempResult, Key_Length + 1, strlen(TempResult), NyDMS_MAX_STRING);
                fclose(SourceFile);
                return TempResult;
            }
        }
        fclose(SourceFile);
    }
    return TempResult;
}

stock NyDMS_SetInt(const Filename[], const SystemKey[], const Value) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemSetInt(Filename, SystemKey, Value);
}
NyDMS SystemSetInt(const File[], const SystemKey[], const SystemValue) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

    new NyDMS_ValueStr[NyDMS_MAX_STRING];
    format(NyDMS_ValueStr, NyDMS_MAX_STRING, "%d", SystemValue);
    return SystemSetString(File, SystemKey, NyDMS_ValueStr);
}

stock NyDMS_GetInt(const Filename[], const Key[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemGetInt(Filename, Key);
}
NyDMS SystemGetInt(const File[], const SystemKey[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

    return strval(SystemGetString(File, SystemKey));
}

stock NyDMS_SetFloat(const Filename[], const Key[], Float:Value) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemSetFloat(Filename, Key, Value);
}
NyDMS SystemSetFloat(const File[], const SystemKey[], Float:SystemValue) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

    new NyDMS_ValueStr[NyDMS_MAX_STRING];
    format(NyDMS_ValueStr, NyDMS_MAX_STRING, "%f", SystemValue);
    return SystemSetString(File, SystemKey, NyDMS_ValueStr);
}

NyDMS Float:SystemGetFloat(const File[], const SystemKey[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }
    return floatstr(SystemGetString(File, SystemKey));
}
stock Float:NyDMS_GetFloat(const Filename[], const Key[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return 0; }
    return SystemGetFloat(Filename, Key);
}

stock NyDMS_SetBoolean(const Filename[], const Key[], bool:Value){
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemSetBoolean(Filename, Key, Value);
}
NyDMS SystemSetBoolean(const File[], const SystemKey[], bool:SystemValue) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

	if(SystemValue == true)
		return SystemSetString(File, SystemKey, "1");
    if(SystemValue == false)
	    return SystemSetString(File, SystemKey, "0");

    return SystemValue;
}

stock NyDMS_GetBoolean(const Filename[], const Key[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemGetBoolean(Filename, Key);
}
NyDMS SystemGetBoolean(const File[], const SystemKey[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

    return strval(SystemGetString(File, SystemKey));
}

stock NyDMS_IsSet(const Filename[], const Key[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemIsSet(Filename, Key);
}
NyDMS SystemIsSet(const File[], const SystemKey[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }

	new Key_Length = strlen(SystemKey);
    new Sum = Key_Length + 2;
	if (Key_Length == 0 || Sum > NyDMS_MAX_STRING)
        return false;
	
	new File:SourceFile;
	SourceFile = fopen(File, io_read);
	if(!SourceFile)
        return false;
	
	new TempResult[NyDMS_MAX_STRING];
	while(fread(SourceFile, TempResult)) {
		if(TempResult[Key_Length] == '=' && !strcmp(TempResult, SystemKey, true, Key_Length)) {
			fclose(SourceFile);
			return true;
		}
	}
	fclose(SourceFile);
	return false;
}

stock NyDMS_UnSet(const Filename[], const Key[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemUnSet(Filename, Key);
}
NyDMS SystemUnSet(const File[], const SystemKey[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha ao localizar arquivo. O arquivo '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateFile(\"Filename\"); para cria-lo.", File);
        return 1;
    }
    
	new Key_Length = strlen(SystemKey);
    new Sum = Key_Length + 2;
	if (Key_Length == 0 || Sum > NyDMS_MAX_STRING)
        return false;
	
	new File:SourceFile, File:SourceFileCopy;
	new TempResult[NyDMS_MAX_STRING];
	
	format(TempResult, NyDMS_MAX_STRING, "%s.part", File);
	fremove(TempResult);
	
	SourceFile = fopen(File, io_read);
	if(!SourceFile)
        return false;
	
	SourceFileCopy = fopen(TempResult, io_write);
	if(!SourceFileCopy) {
		fclose(SourceFile);
		return false;
	}
	
	while(fread(SourceFile, TempResult)) {
		if(TempResult[Key_Length] == '=' && !strcmp(TempResult, SystemKey, true, Key_Length)) {
			// You don't need anything here! We've already taken what needs to be removed.
		} else {
			SystemRemoveNewLine(TempResult);
			fwrite(SourceFileCopy, TempResult);
			fwrite(SourceFileCopy,"\r\n");
		}
	}
	
	fclose(SourceFile);
	fclose(SourceFileCopy);

	format(TempResult, NyDMS_MAX_STRING, "%s.part", File);
	if(SystemCopyDataFile(TempResult, File)) {
		return fremove(TempResult);
	}
	return false;
}



stock NyDMS_CreateLog(const Filename[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemCreateLog(Filename);
}
NyDMS SystemCreateLog(const File[]) {
    if(fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Nao foi possivel criar o log '%s' - ele ja existe. Use NyDMS_WriteLog(\"Filename\", \"Message\"); para registrar informacoes.", File);
        return 1;
    }

    new File:archive = fopen(File, io_write);
    fclose(archive);
    return 1;
}

stock NyDMS_WriteLog(const Filename[], const StringLog[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemWriteLog(Filename, StringLog);
}
NyDMS SystemWriteLog(const File[], const SystemStringLog[]) {
    new StrLog[3000];
    new LogYear, LogMonth, LogDay;
	new LogHour, LogMinute, LogSecond;
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Falha na escrita. O log '%s' nao foi encontrado ou nao existe. Utilize NyDMS_CreateLog(\"Filename\"); para cria-lo.", File);
        return 0;
    }
    getdate(LogYear, LogMonth, LogDay);
    gettime(LogHour, LogMinute, LogSecond);
    format(StrLog, sizeof(StrLog), "(%02d/%02d/%d) - [%02d:%02d:%02d] > %s\r\n", LogDay, LogMonth, LogYear, LogHour, LogMinute, LogSecond, SystemStringLog);

    new File:archive = fopen(File, io_append);
    fwrite(archive, StrLog);
    fclose(archive);
    return 1;
}

stock NyDMS_DeleteLog(const Filename[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemDeleteLog(Filename);
}
NyDMS SystemDeleteLog(const File[]) {
    if(!fexist(File)) {
        SystemConsoleFormatted("[NyDMS ERROR]: Log '%s' nao encontrado ou nao existe. Utilize NyDMS_CreateLog(\"Filename\"); para gerar o arquivo.", File);
        return 0;
    }
    fremove(File);
    return 1;
}

stock NyDMS_FolderExists(const Folder[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemFolderExists(Folder);
}
NyDMS SystemFolderExists(const SystemFolder[]) {
    new NyDMS_LocalStr[500];
	format(NyDMS_LocalStr, sizeof(NyDMS_LocalStr), "%s/checking.log", SystemFolder);
	SystemCreateFile(NyDMS_LocalStr);
	if(fexist(NyDMS_LocalStr)) {
	    printf("[NyDMS INFO]: A pasta '%s' foi encontrada e carregado com sucesso.", SystemFolder);
	} else if(!fexist(NyDMS_LocalStr)) {
        SystemConsoleFormatted("[NyDMS ERROR]: A pasta '%s' nao foi encontrada ou nao existe.", SystemFolder);
	    printf("[NyDMS ERROR]: A pasta '%s' nao foi encontrada ou nao existe.", SystemFolder);
	}
	fremove(NyDMS_LocalStr);
	return 1;
}

stock NyDMS_CheckLog(const Filename[]) {
    if(!SystemCheckDefinedCommand(CheckDefinedCommand)) { return false; }
    return SystemCheckLog(Filename);
}
NyDMS SystemCheckLog(const File[]) {
	if(fexist(File)) {
	    printf("[NyDMS INFO]: O log '%s' foi encontrado e carregado com sucesso.", File);
	    return 1;
	} else if(!fexist(File)) {
	    printf("[NyDMS ERROR]: O log '%s' nao foi encontrado ou nao existe.", File);
	    return 1;
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




NyDMS SystemRemoveNewLine(NyDMS_Str[]) {
	new len = strlen(NyDMS_Str);
	if(NyDMS_Str[0] == 0)
        return ;
	if((NyDMS_Str[len - 1] == '\n') || (NyDMS_Str[len - 1] == '\r')) {
		NyDMS_Str[len - 1] = 0;
		if(NyDMS_Str[0]==0)
            return ;
		if((NyDMS_Str[len - 2] == '\n') || (NyDMS_Str[len - 2] == '\r')) { NyDMS_Str[len - 2] = 0; }
	}
}

NyDMS SystemCopyDataFile(const Oldname[], const Newname[]) {
	new File:SourceFile, File:SourceFileCopy;
	if(!fexist(Oldname))
        return false;
	SourceFile = fopen(Oldname, io_read);

	if(!SourceFile)
        return false;
	SourceFileCopy = fopen(Newname, io_write);
	if(!SourceFileCopy) {
		fclose(SourceFile);
		return false;
	}

	new TempResult[NyDMS_MAX_STRING];
    while(fread(SourceFile, TempResult)) {
		SystemRemoveNewLine(TempResult);
		format(TempResult, sizeof(TempResult), "%s\r\n", TempResult);
		fwrite(SourceFileCopy, TempResult);
	}

	fclose(SourceFile);
	fclose(SourceFileCopy);
	return true;
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