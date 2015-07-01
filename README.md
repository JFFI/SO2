# SO2
Tarea 3 del curso de Sistemas Operativos 2.

Descripcion de archivos:
-jfiservicio.c
  codigo del servicio, este servicio escribe la hora en un archivo cada 2 segundos y lleva un control de cuanto tiempo ha estado encendido
-jfiservicio_bash
  script que llama al servicio mediante los metodo start,stop,status
  este script debe renombrarse a jfiservicio y ser insertado en /etc/init.d
-jfiservicio
  servicio ya compilado, debe insertarse en /usr/sbin
