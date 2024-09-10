# Tarea 0 - Gregorio Azócar

## Paso a paso para instalación de xv6 en WSL

1. Instalación de WSL: Se inició PowerShell como administrador y se ejecutó wsl --install para habilitar Linux en Windows.
2. Instalación de Toolchains y Librerías: Se instalaron las herramientas necesarias (git, make, gcc, qemu, gdb) utilizando sudo apt-get install en la terminal de WSL.
3. Clonación del Repositorio xv6: Se clonó el repositorio xv6-public desde GitHub mediante git clone.
4. Verificación Inicial: Se ejecutaron make qemu-nox y make qemu-nox-gdb para comprobar que la instalación fue exitosa.
5. Conexión al Kernel: Se abrió una nueva terminal para ejecutar gdb ./kernel y target remote localhost:25000, verificando la conexión con el kernel.
6. Integración con VSCode: Luego de validar en PowerShell, se utilizó VSCode, seleccionando WSL en la esquina inferior izquierda.
7. Navegación al Directorio de Trabajo: En VSCode, se navegó a ~/xv6-public con cd.
8. Ejecución de QEMU: Se lanzó QEMU usando make qemu para comenzar la interfaz gráfica.
9. Pruebas de Funcionalidades: Se realizaron pruebas de comandos como ls, echo, y cat en la interfaz de QEMU para verificar la funcionalidad del sistema operativo xv6.

## Problemas encontrados en el proceso de la tarea

Al ser la primera vez que uso xv6, me pareció un sistema muy diferente a lo que estoy acostumbrado, lo que me generó varios problemas. Por ejemplo, tuve muchas dificultades con las terminales, ya que a veces dejaba un proceso de xv6 abierto y luego no podía conectarme de nuevo, lo que me confundía porque seguía los mismos pasos que antes funcionaban. Además, tuve problemas al instalar los toolchains, ya que instalé varias versiones y causaron conflictos, lo que hizo que pareciera un error sin solución hasta que seguí un solo tutorial. Por último, me costó entender la diferencia entre usar VSCode y PowerShell, porque aunque las dependencias las instalaba en PowerShell, para ver la interfaz de QEMU necesitaba abrirlo en VSCode y ahí probar las funcionalidades.

## Capturas de pantalla - Comandos de prueba

![Captura de pantalla 2024-08-28 222523](https://github.com/user-attachments/assets/7a2ee4e1-9d3f-48c9-be68-aed30bfcd793)

![Captura de pantalla 2024-08-28 222540](https://github.com/user-attachments/assets/1f0c906d-7f8c-4c4c-bc97-6fcd72d41ad4)

![Captura de pantalla 2024-08-28 222608](https://github.com/user-attachments/assets/df608a7e-c7be-43da-8021-94059e7feec2)

# Tarea 1 - Gregorio Azócar

## Correcta implementación de getppid(void)

La llamada al sistema getppid() devuelve el PID del proceso padre del proceso que la invoca. Esto permite que un proceso pueda identificar cuál es su proceso padre dentro de la estructura jerárquica del sistema. Se implementa en sysproc.c, donde se usa la función myproc() para acceder al proceso actual, y luego retorna el PID del proceso padre. Si no existe un proceso padre, la función devuelve 0.
En cuanto a la llamada getancestor(int n), esta devuelve el PID de un ancestro específico del proceso. Dependiendo del valor de n, la función puede retornar el proceso actual (n = 0), su padre (n = 1), o su abuelo (n = 2). Si el proceso no tiene un ancestro para el valor dado, la función devuelve -1.

![image](https://github.com/user-attachments/assets/55632602-8202-42e6-901e-24c72fc19a70)

## Programa de prueba yosoytupadre.c y su integración

El programa yosoytupadre.c es un programa de prueba simple que se utiliza para verificar las nuevas llamadas al sistema getppid() y getancestor(int n) que fueron implementadas en el kernel de xv6. Este programa se integra en el sistema operativo para asegurarse de que las llamadas al sistema funcionen correctamente y devuelvan la información esperada sobre la jerarquía de procesos. Básicamente, nos sirve para testear las funcionalidades de llamadas a sistemas e integración de multifuncionalidad en diferentes componentes de código.

![image](https://github.com/user-attachments/assets/aa91e1d6-c123-4da0-a7c5-c745c171cadc)
![image](https://github.com/user-attachments/assets/0411a9f7-061d-49fe-9ce6-938c03a8c656)

## Correcta implementación de getancestor(int)

La función getancestor(int n) es una llamada al sistema que permite a un proceso obtener el PID (Process ID) de uno de sus ancestros en la jerarquía de procesos. La jerarquía de procesos en un sistema operativo está organizada de manera que cada proceso tiene un padre, y este padre, a su vez, puede tener otro padre (abuelo), formando así una cadena que se remonta hasta el proceso inicial del sistema.

![image](https://github.com/user-attachments/assets/852045d6-9480-4084-9791-ce9dcfaf58ca)

## Modificaciones realizadas

sysproc.c:
Implementación de sys_getppid() y sys_getancestor().

syscall.h:
Definición de los números de las nuevas llamadas al sistema.

syscall.c:
Mapeo de las nuevas llamadas al sistema en la tabla.

user.h:
Declaración de getppid() y getancestor() para el usuario.

usys.pl:
Generación de stubs para las nuevas llamadas al sistema.

yosoytupadre.c:
Programa de prueba para verificar las llamadas al sistema.

Makefile:
Inclusión del programa yosoytupadre en la lista de compilación.

## Dificultades

Tuve multiples dificultades en el desarrollo de esta entrega. Primeramente, a nivel hardware no tengo la potencia suficiente para trabajar en las tareas de manera eficiente, donde tuve que utilizar una maquina virtual para trabajar el xv6. Donde inicialmente tuve que solo instalar xv6 en la maquina, ahora tuve que abrir vscode, utilizar el buscador dentro de la VM y exigirle rendimiento para trabajar en esta entrega, pero fue sumamente complicado dadas las limitaciones del computador, por lo tanto, tuve que trabajar con lo que tenía y demorar más en el trabajo. 
Dentro de la entrega, también tuve complicaciones con el uso de stat.h y types.h, donde en la terminal me aparecían errores los cuales no les encontraba solución. Pero luego de investigar harto, noté que había un problema con la importación de uint como un unsigned integrer, por lo tanto, tuve que importarlo de manera manual en ese documento, donde por alguna razón que sigo desconociendo, no pudo referenciar en el documento de types/stat.
