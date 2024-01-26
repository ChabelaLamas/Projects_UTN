# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#   * Rearrange models' order
#   * Make sure each model has one field with primary_key=True
#   * Make sure each ForeignKey and OneToOneField has `on_delete` set to the desired behavior
#   * Remove `managed = False` lines if you wish to allow Django to create, modify, and delete the table
# Feel free to rename the models, but don't rename db_table values or field names.
from django.db import models


class AsociadosEstablecimientosComunidad(models.Model):
    comunidad_id = models.BigIntegerField()
    establecimiento_id = models.BigIntegerField()

    class Meta:
        managed = False
        db_table = 'asociados_establecimientos_comunidad'


class AsociadosServiciosComunidad(models.Model):
    comunidad_id = models.BigIntegerField()
    servicio_id = models.BigIntegerField()

    class Meta:
        managed = False
        db_table = 'asociados_servicios_comunidad'


class Comunidad(models.Model):
    id = models.BigAutoField(primary_key=True)
    descripcion = models.CharField(max_length=255, blank=True, null=True)
    estaactivo = models.TextField(db_column='estaActivo', blank=True, null=True)
    nombre = models.CharField(max_length=255, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'comunidad'


class Delegado(models.Model):
    id = models.BigAutoField(primary_key=True)
    email = models.TextField(blank=True, null=True)
    nombre = models.TextField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'delegado'


class Entidad(models.Model):
    id = models.BigAutoField(primary_key=True)
    denominacion = models.TextField(blank=True, null=True)
    estaactivo = models.TextField(db_column='estaActivo', blank=True, null=True)  
    tipoentidad = models.CharField(db_column='tipoEntidad', max_length=255, blank=True, null=True) 
    tipoestablecimiento = models.CharField(db_column='tipoEstablecimiento', max_length=255, blank=True, null=True) 
    entidad_prestadora_id = models.BigIntegerField(blank=True, null=True)
    pertenece = models.TextField(blank=True, null=True)  

    class Meta:
        managed = False
        db_table = 'entidad'


class EntidadPrestadora(models.Model):
    id = models.BigAutoField(primary_key=True)
    denominacion = models.TextField(blank=True, null=True)
    delegado_id = models.BigIntegerField(blank=True, null=True)
    organismo_de_control_id = models.BigIntegerField(blank=True, null=True)
    pertenece = models.TextField(blank=True, null=True) 

    class Meta:
        managed = False
        db_table = 'entidad_prestadora'


class EntidadesXOrganismo(models.Model):
    entidad_id = models.BigIntegerField()
    organismo_de_control_id = models.BigIntegerField()

    class Meta:
        managed = False
        db_table = 'entidades_x_organismo'


class Establecimiento(models.Model):
    id = models.BigAutoField(primary_key=True)
    denominacion = models.TextField(blank=True, null=True)
    estaactivo = models.TextField(db_column='estaActivo', blank=True, null=True)
    pertenece = models.TextField(blank=True, null=True) 
    #entidad_id = models.BigIntegerField(blank=True, null=True)
    entidad = models.ForeignKey(Entidad, on_delete=models.SET_NULL, blank=True, null=True)
    localidad_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'establecimiento'


class Horariodenotificacion(models.Model):
    persona_id = models.BigIntegerField()
    horario = models.DateTimeField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'horariodenotificacion'
    class Meta:
        managed = False
        db_table = 'incidente'


class Localidad(models.Model):
    id = models.BigIntegerField(primary_key=True)
    nombre_localidad = models.CharField(max_length=255, blank=True, null=True)
    localizacion_id = models.BigIntegerField(blank=True, null=True)
    pertenece = models.TextField(blank=True, null=True) 

    class Meta:
        managed = False
        db_table = 'localidad'


class Localizacion(models.Model):
    id = models.BigIntegerField(primary_key=True)
    nombre = models.CharField(max_length=255, blank=True, null=True)
    tipo_localizacion = models.CharField(max_length=255, blank=True, null=True)
    provincia_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'localizacion'


class Menu(models.Model):
    id = models.BigAutoField(primary_key=True)
    activo = models.TextField(blank=True, null=True) 
    link = models.CharField(max_length=255, blank=True, null=True)
    nombre = models.CharField(max_length=255, blank=True, null=True)
    tipo = models.CharField(max_length=255, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'menu'


class Miembro(models.Model):
    id = models.BigAutoField(primary_key=True)
    es_administrador = models.TextField(blank=True, null=True) 
    tipo = models.CharField(max_length=255, blank=True, null=True)
    comunidad_id = models.BigIntegerField(blank=True, null=True)
    persona_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'miembro'


class Notificacion(models.Model):
    id = models.BigAutoField(primary_key=True)
    estado = models.CharField(max_length=255, blank=True, null=True)
    fechaaperturaincidente = models.DateTimeField(db_column='fechaAperturaIncidente', blank=True, null=True)  
    fechacierreincidente = models.DateTimeField(db_column='fechaCierreIncidente', blank=True, null=True)  
    mensaje = models.CharField(max_length=255, blank=True, null=True)
    persona_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'notificacion'


class Organismodecontrol(models.Model):
    id = models.BigAutoField(primary_key=True)
    denominacion = models.CharField(max_length=255, blank=True, null=True)
    delegado_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'organismodecontrol'


class Permiso(models.Model):
    id = models.BigAutoField(primary_key=True)
    nombre = models.CharField(max_length=255, blank=True, null=True)
    nombreinterno = models.CharField(db_column='nombreInterno', max_length=255, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'permiso'


class Persona(models.Model):
    id = models.BigAutoField(primary_key=True)
    email = models.TextField(blank=True, null=True)
    frecuencia_notificacion = models.CharField(max_length=255, blank=True, null=True)
    medio_de_notificacion = models.CharField(max_length=255, blank=True, null=True)
    telefono = models.TextField(blank=True, null=True)
    localidad_id = models.BigIntegerField(blank=True, null=True)
    usuario_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'persona'


class Servicio(models.Model):
    tipo = models.CharField(max_length=31)
    id = models.BigAutoField(primary_key=True)
    descripcion = models.CharField(max_length=255, blank=True, null=True)
    pertenece = models.TextField(blank=True, null=True)  # This field type is a guess.
    organismo_de_control_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'servicio'

class Prestaciondeservicio(models.Model):
    id = models.BigAutoField(primary_key=True)
    estaactivo = models.TextField(db_column='estaActivo', blank=True, null=True)  # Field name made lowercase.
    #establecimiento_id = models.BigIntegerField(blank=True, null=True)
    #servicio_id = models.BigIntegerField(blank=True, null=True)
    establecimiento = models.ForeignKey(Establecimiento, on_delete=models.SET_NULL, blank=True, null=True)
    servicio = models.ForeignKey(Servicio, on_delete=models.SET_NULL, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'prestaciondeservicio'

class Incidente(models.Model):
    id = models.BigAutoField(primary_key=True)
    abierto = models.IntegerField(blank=True, null=True)
    denominacion = models.TextField(blank=True, null=True)
    fechaapertura = models.DateTimeField(db_column='fechaApertura', blank=True, null=True)  # Field name made lowercase.
    fechacierre = models.DateTimeField(db_column='fechaCierre', blank=True, null=True)  # Field name made lowercase.
    observaciones = models.TextField(blank=True, null=True)
    comunidad_id = models.BigIntegerField(blank=True, null=True)
    creador_id = models.BigIntegerField(blank=True, null=True)
    #prestacion_de_servicio_id = models.BigIntegerField(blank=True, null=True)
    prestacion_de_servicio = models.ForeignKey(Prestaciondeservicio, on_delete=models.SET_NULL, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'incidente'



class Provincia(models.Model):
    id = models.BigIntegerField(primary_key=True)
    nombre = models.CharField(max_length=255, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'provincia'


class Rol(models.Model):
    id = models.BigAutoField(primary_key=True)
    nombre = models.CharField(max_length=255, blank=True, null=True)
    tipo = models.CharField(max_length=255, blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'rol'


class RolPermiso(models.Model):
    rol_id = models.BigIntegerField(db_column='Rol_id', primary_key=True)  # Field name made lowercase. The composite primary key (Rol_id, permisos_id) found, that is not supported. The first column is selected.
    permisos_id = models.BigIntegerField()

    class Meta:
        managed = False
        db_table = 'rol_permiso'
        unique_together = (('rol_id', 'permisos_id'),)

class ServicioCompuesto(models.Model):
    servicio_compuesto_id = models.BigIntegerField()
    servicio_id = models.BigIntegerField()

    class Meta:
        managed = False
        db_table = 'servicio_compuesto'


class Usuario(models.Model):
    id = models.BigAutoField(primary_key=True)
    contrasenia = models.TextField(blank=True, null=True)
    nombre = models.TextField(blank=True, null=True)
    rol_id = models.BigIntegerField(blank=True, null=True)

    class Meta:
        managed = False
        db_table = 'usuario'
