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
