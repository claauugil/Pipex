# 🔗 Pipex

**Pipex** es un programa que simula el comportamiento de las tuberías (`|`) en sistemas Unix-like. El objetivo es manejar procesos y redirecciones de entrada/salida utilizando llamadas al sistema.

---

## 📖 Descripción

El proyecto consiste en ejecutar dos comandos conectados por una tubería, redirigiendo correctamente la entrada y salida de archivos:

1. Analiza los argumentos de entrada.
2. Crea una tubería para conectar `cmd1` con `cmd2`.
3. Ejecuta ambos comandos usando llamadas al sistema, redirigiendo los descriptores de archivo.
4. Escribe el resultado de `cmd2` en `file2`.

---

## 🧪 Uso

### Sintaxis

```bash
./pipex file1 "cmd1" "cmd2" file2
```

### Argumentos

- `file1`: Archivo de entrada.
- `cmd1`: Primer comando con sus argumentos.
- `cmd2`: Segundo comando con sus argumentos.
- `file2`: Archivo donde se guardará la salida final.

El comportamiento es equivalente al comando de shell:

```bash
< file1 cmd1 | cmd2 > file2
```

---

## 🛠️ Compilación

```bash
make
```

## 💡 Ejemplo

### Ejecución:

```bash
./pipex infile "ls -l" "wc -l" outfile
```

### Equivalente en shell:

```bash
< infile ls -l | wc -l > outfile
```

---

## 🧠 Funciones Principales

### `handle_first_child` / `handle_sec_child`

- Manejan la ejecución de los procesos hijo.
- Configuran la tubería con `prep_pipe`.
- Cierran descriptores no necesarios con `close_fds`.
- Ejecutan los comandos con `exec`.
- Informan de errores si `exec` falla.

### `prep_pipe`

- Redirige descriptores de archivo para el proceso actual.
- Usa `dup2` para conectar el archivo de entrada a `STDIN_FILENO`.
- Conecta la salida al archivo o a la tubería con `STDOUT_FILENO`.

### `exec`

- Parsea el comando y sus argumentos con `ft_split`.
- Busca el ejecutable con `get_exec`.
- Llama a `execve` para ejecutar el comando.
- En caso de error, se muestra un mensaje.

### `get_path`

- Busca la variable `PATH` en el entorno.
- La divide en rutas con `ft_split`.
- Finaliza con error si no se encuentra.

### `get_exec`

- Une el nombre del comando con cada ruta del `PATH` usando `ft_strjoin`.
- Verifica con `access` si el ejecutable existe y es válido.
- Devuelve la ruta válida o `NULL` si no se encuentra.
