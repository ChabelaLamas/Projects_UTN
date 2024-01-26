USE GD2C2023 
GO

CREATE TABLE DATAMINDS.BI_TIPO_INMUEBLE (
	id decimal(18,0) not null,
	descripcion varchar(255) not null
)


CREATE TABLE DATAMINDS.BI_RANGO_ETARIO(
	id decimal(18,0) not null identity(1,1),
	descripcion varchar(255) not null
)


CREATE TABLE DATAMINDS.BI_TIEMPO(
	id decimal(18,0) not null identity(1,1),
	anio decimal(18,0) not null,
	cuatrimestre decimal(18,0) not null,
	mes decimal (18,0) not null
)


CREATE TABLE DATAMINDS.BI_UBICACION (
	id decimal(18,0) not null identity(1,1),
	barrio_id decimal(18,0) not null,
	nombre_barrio varchar(255) null,
	localidad_id decimal(18,0) not null,
	nombre_localidad varchar(255) not null
)


CREATE TABLE DATAMINDS.BI_MONEDA (
	id decimal(18,0) not null,
	nombre varchar(255) not null,
)

CREATE TABLE DATAMINDS.BI_TIPO_OPERACION (
	id decimal(18,0) not null,
	descripcion varchar(255) not null,
)

CREATE TABLE DATAMINDS.BI_ESTADO_ANUNCIO (
	id decimal(18,0) not null,
	descripcion varchar(255) not null,
)

CREATE TABLE DATAMINDS.BI_TIPO_AMBIENTE (
	id decimal(18,0) not null,
	descripcion varchar(255) not null
)

CREATE TABLE DATAMINDS.BI_SUCURSAL (
    codigo_sucursal decimal(18,0) not null,
    nombre nvarchar(100) not null
)


CREATE TABLE DATAMINDS.BI_PAGO_ALQUILER (
  porcentaje_incumplimiento decimal(18,2),
  porcentaje_aumento decimal(18,2),
  cantidad_pagos decimal(18,0) not null,
  tiempo_id decimal(18,0) not null
)

CREATE TABLE DATAMINDS.BI_ALQUILER (
	porcentaje_incremento numeric(18,2), --Vista 5
	cantidad_alquileres decimal(18,0),
	tiempo_id decimal(18,0) not null,
	rango_etario_id decimal(18,0) not null, --Rango Etario
	ubicacion_id decimal(18,0) not null
)



CREATE TABLE DATAMINDS.BI_ANUNCIO (
	duracion_promedio decimal(18,2) , --Vista 1
	precio_promedio decimal(18,2) , --Vista 2
	cant_anuncios decimal(18,0) , 
	promedio_comision decimal(18,2),
	monto_total decimal(18,2),--Vista 9
	tiempo_id decimal(18,0) not null,
	tipo_operacion_id decimal(18,0) not null, --Tipo Operacion
	rango_etario_id decimal(18,0) not null, --Rango Etario
	rango_m2_id decimal(18,0) not null, --Rango M2
	ubicacion_id decimal(18,0) not null, --Ubicacion
	moneda_id decimal(18,0) not null, --Moneda
	sucursal_id decimal(18,0) not null, -- Sucursal
	estado_id decimal(18,0) not null, --Estado Anuncio(
	cantidad_ambiente_id decimal(18,0) not null, --Cantidad Ambiente
	tipo_inmueble_id decimal(18,0) not null --Tipo de Inmueble
)

CREATE TABLE DATAMINDS.BI_VENTA (
	precio_m2_promedio numeric(18,2) null,
	cantidad_ventas numeric(18,0) null,
	tiempo_id decimal(18,0) not null,
	moneda_id decimal(18,0) not null,
    tipo_inmueble_id decimal(18,0) not null,
	ubicacion_id decimal(18,0) not null,
)


CREATE TABLE DATAMINDS.BI_RANGO_M2(
	id decimal(18,0) not null identity(1,1),
	descripcion varchar(255) not null
)


--PK
ALTER TABLE DATAMINDS.BI_TIPO_INMUEBLE add constraint pk_tipo_inmueble_bi primary key (id)
ALTER TABLE DATAMINDS.BI_UBICACION add constraint pk_ubicacion_bi primary key (id)
ALTER TABLE DATAMINDS.BI_RANGO_ETARIO add constraint pk_rango_etario_bi primary key (id)
ALTER TABLE DATAMINDS.BI_TIEMPO add constraint pk_tiempo_bi primary key (id)
ALTER TABLE DATAMINDS.BI_MONEDA add constraint pk_moneda_bi primary key (id)
ALTER TABLE DATAMINDS.BI_TIPO_OPERACION add constraint pk_tipo_operacion_bi primary key (id)
ALTER TABLE DATAMINDS.BI_ESTADO_ANUNCIO add constraint pk_estado_anuncio_bi primary key (id)
ALTER TABLE DATAMINDS.BI_TIPO_AMBIENTE add constraint pk_tipo_ambiente_bi primary key (id)
ALTER TABLE DATAMINDS.BI_SUCURSAL add constraint pk_sucursal_bi primary key (codigo_sucursal)
ALTER TABLE DATAMINDS.BI_PAGO_ALQUILER add constraint pk_pago_alquiler_bi primary key (tiempo_id) 

ALTER TABLE DATAMINDS.BI_ALQUILER add constraint pk_alquiler_bi primary key (tiempo_id, ubicacion_id, rango_etario_id)

ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint pk_anuncio_bi primary key (tiempo_id, tipo_operacion_id, rango_etario_id, rango_m2_id, ubicacion_id, moneda_id, sucursal_id, estado_id, cantidad_ambiente_id, tipo_inmueble_id)
ALTER TABLE DATAMINDS.BI_VENTA add constraint pk_venta_bi primary key (tiempo_id, moneda_id, tipo_inmueble_id, ubicacion_id)
ALTER TABLE DATAMINDS.BI_RANGO_M2 add constraint pk_rango_m2_bi primary key (id)


--FK
ALTER TABLE DATAMINDS.BI_PAGO_ALQUILER add constraint fk_tiempo_pago_bi foreign key (tiempo_id) references DATAMINDS.BI_TIEMPO (id)

ALTER TABLE DATAMINDS.BI_ALQUILER add constraint fk_tiempo_bi foreign key (tiempo_id) references DATAMINDS.BI_TIEMPO (id)
ALTER TABLE DATAMINDS.BI_ALQUILER add constraint fk_ubicacion_alquiler foreign key (ubicacion_id) references DATAMINDS.BI_UBICACION (id)
ALTER TABLE DATAMINDS.BI_ALQUILER add constraint fk_rango_etario_inquilino_bi foreign key (rango_etario_id) references DATAMINDS.BI_RANGO_ETARIO (id)

ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_tiempo_anuncio_bi foreign key (tiempo_id) references DATAMINDS.BI_TIEMPO (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_tipo_operacion_bi foreign key (tipo_operacion_id) references DATAMINDS.BI_TIPO_OPERACION (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_rango_etario_bi foreign key (rango_etario_id) references DATAMINDS.BI_RANGO_ETARIO (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_rango_m2_bi foreign key (rango_m2_id) references DATAMINDS.BI_RANGO_M2 (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_ubicacion_bi foreign key (ubicacion_id) references DATAMINDS.BI_UBICACION (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_moneda_bi foreign key (moneda_id) references DATAMINDS.BI_MONEDA (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_sucursal_bi foreign key (sucursal_id) references DATAMINDS.BI_SUCURSAL (codigo_sucursal)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_estado_bi foreign key (estado_id) references DATAMINDS.BI_ESTADO_ANUNCIO (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_cantidad_ambiente_bi foreign key (cantidad_ambiente_id) references DATAMINDS.BI_TIPO_AMBIENTE (id)
ALTER TABLE DATAMINDS.BI_ANUNCIO add constraint fk_tipo_inmueble_bi foreign key (tipo_inmueble_id) references DATAMINDS.BI_TIPO_INMUEBLE (id)

ALTER TABLE DATAMINDS.BI_VENTA add constraint fk_tiempo_venta_bi foreign key (tiempo_id) references DATAMINDS.BI_TIEMPO (id)
ALTER TABLE DATAMINDS.BI_VENTA add constraint fk_tipo_inmueble_id foreign key (tipo_inmueble_id) references DATAMINDS.BI_TIPO_INMUEBLE (id)
ALTER TABLE DATAMINDS.BI_VENTA add constraint fk_moneda_venta_bi foreign key (moneda_id) references DATAMINDS.BI_MONEDA (id)
ALTER TABLE DATAMINDS.BI_VENTA add constraint fk_ubicacion_venta foreign key (ubicacion_id) references DATAMINDS.BI_UBICACION (id)

--UNIQUE CONSTRAINT
ALTER TABLE DATAMINDS.BI_TIEMPO add constraint unique_tiempo unique (anio,cuatrimestre,mes) 
ALTER TABLE DATAMINDS.BI_UBICACION add constraint unique_barrio unique (barrio_id) 
GO


CREATE PROCEDURE DATAMINDS.BI_MIGRACION_TIPO_INMUEBLE
AS
BEGIN
	SET NOCOUNT ON;
	insert DATAMINDS.BI_TIPO_INMUEBLE 
	select * from DATAMINDS.TIPO_INMUEBLE
END
GO


CREATE PROCEDURE DATAMINDS.BI_MIGRACION_UBICACION
AS
BEGIN
	SET NOCOUNT ON;
	insert DATAMINDS.BI_UBICACION (barrio_id, nombre_barrio, localidad_id, nombre_localidad)
	select b.id, b.nombre, l.id, l.nombre from DATAMINDS.BARRIO b
	inner join DATAMINDS.LOCALIDAD l on l.id = b.localidad_id
END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_TIPO_AMBIENTE
AS
BEGIN
	SET NOCOUNT ON;
	insert DATAMINDS.BI_TIPO_AMBIENTE
	select * from DATAMINDS.TIPO_AMBIENTE
	
END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_SUCURSAL
AS
BEGIN
	SET NOCOUNT ON;
	insert DATAMINDS.BI_SUCURSAL
	select s.codigo_sucursal, s.nombre from DATAMINDS.SUCURSAL s

END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_ESTADO_ALQUILER
AS
BEGIN
    SET NOCOUNT ON;
    insert DATAMINDS.BI_ESTADO_ALQUILER
    select * from DATAMINDS.ESTADO_ALQUILER
END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_MONEDA
AS
BEGIN
    SET NOCOUNT ON;
	insert DATAMINDS.BI_MONEDA
    select * from DATAMINDS.MONEDA

END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_ESTADO_ANUNCIO
AS
BEGIN
    SET NOCOUNT ON;
	insert DATAMINDS.BI_ESTADO_ANUNCIO
    select * from DATAMINDS.ESTADO_ANUNCIO

END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_TIPO_OPERACION
AS
BEGIN
    SET NOCOUNT ON;
	insert DATAMINDS.BI_TIPO_OPERACION
    select * from DATAMINDS.TIPO_OPERACION
END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_RANGO_M2
AS
BEGIN
	SET NOCOUNT ON;
	insert into DATAMINDS.BI_RANGO_M2(descripcion)
    values ('<35'),('35-55'), ('55-75'),('75-100'),('>100')
END
GO

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_RANGO_ETARIO
AS
BEGIN
	SET NOCOUNT ON;
	insert into DATAMINDS.BI_RANGO_ETARIO(descripcion)
    values ('<25'),('25-35'), ('35-50'),('>50')
END
GO




CREATE FUNCTION DATAMINDS.fx_rango_etario (@fecha_nac datetime)
returns decimal(18,0)
begin
	declare @id decimal(18,0)
	DECLARE @edad INT

	SET @edad  = YEAR(GETDATE()) - YEAR(@fecha_nac)

	IF @edad < 25
		SET @id = 1
	ELSE IF @EDAD BETWEEN  25 AND 35
		SET @id = 2
	ELSE IF @EDAD BETWEEN 35 AND 50
		SET @id = 3
	ELSE IF @EDAD > 50
		SET @id = 4

	return @id
end
go


CREATE FUNCTION DATAMINDS.fx_rango_m2 (@m2 numeric(18,2))
returns decimal(18,0)
begin
	declare @id numeric(18,0)

	IF @m2 < 35
		SET @id = 1
	ELSE IF @m2 BETWEEN 35 AND 55
		SET @id= 2
	ELSE IF @m2 BETWEEN 55 AND 75
		SET @id = 3
	ELSE IF @m2 BETWEEN 75 AND 100
		SET @id = 4
	ELSE IF @m2 > 100
		SET @id = 5

	return @id
end
go

CREATE FUNCTION DATAMINDS.fx_cuatrimestre (@mes int)
returns int
begin

	return CASE
        WHEN @mes IN (1, 2, 3) THEN 1
        WHEN @mes IN (4, 5, 6) THEN 2
        WHEN @mes IN (7, 8, 9) THEN 3
        WHEN @mes IN (10, 11, 12) THEN 4
        ELSE 'No valido' end
end
go

CREATE PROCEDURE DATAMINDS.BI_MIGRACION_TIEMPO
AS
BEGIN
	INSERT INTO DATAMINDS.BI_TIEMPO (anio, cuatrimestre, mes)
	SELECT 
		YEAR(anuncio.fecha_publicacion) as tiempo_anio,
		DATAMINDS.fx_cuatrimestre(MONTH(anuncio.fecha_publicacion)) as tiempo_cuatrimestre,
		MONTH(anuncio.fecha_publicacion) as tiempo_mes
	FROM DATAMINDS.ANUNCIO anuncio
	UNION
	SELECT 
		YEAR(alq.fecha_inicio) as tiempo_anio,
		DATAMINDS.fx_cuatrimestre(MONTH(alq.fecha_inicio)) as tiempo_cuatrimestre,
		MONTH(alq.fecha_inicio) as tiempo_mes
	FROM DATAMINDS.ALQUILER alq
	UNION
	SELECT 
		YEAR(venta.fecha_venta) as tiempo_anio,
		DATAMINDS.fx_cuatrimestre(MONTH(venta.fecha_venta)) as tiempo_cuatrimestre,
		MONTH(venta.fecha_venta) as tiempo_mes
	FROM DATAMINDS.VENTA venta
	UNION
	SELECT 
		YEAR(pago.fecha_pago) as tiempo_anio,
		DATAMINDS.fx_cuatrimestre(MONTH(pago.fecha_pago)) as tiempo_cuatrimestre,
		MONTH(pago.fecha_pago) as tiempo_mes
	FROM DATAMINDS.PAGO_ALQUILER pago
END
GO

EXEC DATAMINDS.BI_MIGRACION_TIPO_INMUEBLE;
EXEC DATAMINDS.BI_MIGRACION_UBICACION;
EXEC DATAMINDS.BI_MIGRACION_TIEMPO;
EXEC DATAMINDS.BI_MIGRACION_TIPO_AMBIENTE;
EXEC DATAMINDS.BI_MIGRACION_SUCURSAL;
EXEC DATAMINDS.BI_MIGRACION_MONEDA;
EXEC DATAMINDS.BI_MIGRACION_ESTADO_ANUNCIO;
EXEC DATAMINDS.BI_MIGRACION_TIPO_OPERACION;
EXEC DATAMINDS.BI_MIGRACION_RANGO_M2;
EXEC DATAMINDS.BI_MIGRACION_RANGO_ETARIO;
GO


CREATE PROCEDURE DATAMINDS.BI_MIGRACION_ANUNCIO
AS
BEGIN
	SET NOCOUNT ON;
	INSERT INTO DATAMINDS.BI_ANUNCIO (duracion_promedio, precio_promedio, cant_anuncios, promedio_comision, monto_total, tiempo_id, tipo_operacion_id, rango_etario_id, rango_m2_id, ubicacion_id, moneda_id, sucursal_id, estado_id,cantidad_ambiente_id, tipo_inmueble_id)
	SELECT 
		AVG(DATEDIFF(DAY,anuncio.fecha_publicacion, anuncio.fecha_finalizacion)) as duracion_promedio,--
		AVG(anuncio.precio) as precio_promedio,--
		COUNT(*) as cantidad_anuncios,--
		SUM(CASE WHEN venta.comision_inmobiliaria is not null then venta.comision_inmobiliaria when alq.comision is not null then alq.comision else 0 end) / COUNT(*) as promedio_comision,--
		SUM(anuncio.precio) as monto,--
		t.id as tiempo, --
		anuncio.tipo_operacion_id as operacion , 
		rango_etario.id as etario, 
		rango_m2.id as m2, 
		ubi.id as ubi,
		anuncio.moneda_id as moneda, 
		anuncio.agente_sucursal_id as sucu, 
		anuncio.estado_id as estado, 
		i.tipo_ambiente_id as ambiente, 
		i.tipo_inmueble_id as inmueble 
	FROM DATAMINDS.ANUNCIO anuncio
		INNER JOIN DATAMINDS.BI_TIEMPO t on t.anio = YEAR(anuncio.fecha_publicacion) and t.cuatrimestre = DATAMINDS.fx_cuatrimestre(MONTH(anuncio.fecha_publicacion)) and t.mes = MONTH(anuncio.fecha_publicacion)
		INNER JOIN DATAMINDS.PERSONA per on per.id = anuncio.agente_persona_id
		INNER JOIN DATAMINDS.BI_RANGO_ETARIO rango_etario on rango_etario.id = DATAMINDS.fx_rango_etario(per.fecha_nacimiento)
		INNER JOIN DATAMINDS.INMUEBLE i on anuncio.inmueble_id = i.codigo_inmueble
		INNER JOIN DATAMINDS.BI_RANGO_M2 rango_m2 on rango_m2.id = DATAMINDS.fx_rango_m2(i.superficie_total)
		INNER JOIN DATAMINDS.DIRECCION dir on dir.id = i.direccion_id
		INNER JOIN DATAMINDS.BI_UBICACION ubi on ubi.barrio_id = dir.barrio_id
		LEFT JOIN DATAMINDS.ALQUILER alq on alq.anuncio_id = anuncio.codigo_anuncio
		LEFT JOIN DATAMINDS.VENTA venta on venta.anuncio_id = anuncio.codigo_anuncio
	GROUP BY t.id, anuncio.tipo_operacion_id, rango_etario.id, rango_m2.id, ubi.id, anuncio.moneda_id, anuncio.agente_sucursal_id, anuncio.estado_id, i.tipo_ambiente_id, i.tipo_inmueble_id
	
END
GO


CREATE PROCEDURE DATAMINDS.BI_MIGRACION_VENTA 
AS 
BEGIN     
	SET NOCOUNT ON;     
	INSERT INTO DATAMINDS.BI_VENTA (precio_m2_promedio, cantidad_ventas, tiempo_id, moneda_id, tipo_inmueble_id, ubicacion_id)     
	SELECT          
		AVG(venta.precio_venta / i.superficie_total) as precio_m2_promedio,         
		COUNT(*) as cantidad_ventas,        
		t.id as tiempo,         
		venta.moneda_id as moneda_id,         
		i.tipo_inmueble_id as tipo_inmueble_id,   
		ubi.id as ubicacion
	FROM DATAMINDS.VENTA venta         
		INNER JOIN DATAMINDS.ANUNCIO anuncio on anuncio.codigo_anuncio = venta.anuncio_id         
		INNER JOIN DATAMINDS.INMUEBLE i on i.codigo_inmueble = anuncio.inmueble_id      
		INNER JOIN DATAMINDS.DIRECCION dir on dir.id = i.direccion_id
		INNER JOIN DATAMINDS.BI_UBICACION ubi on ubi.barrio_id = dir.barrio_id
		INNER JOIN DATAMINDS.BI_TIEMPO t on t.anio = YEAR(venta.fecha_venta) and t.cuatrimestre = DATAMINDS.fx_cuatrimestre(MONTH(venta.fecha_venta)) and t.mes = MONTH(venta.fecha_venta)         
	GROUP BY t.id, venta.moneda_id, i.tipo_inmueble_id, ubi.id
END 
GO


CREATE PROCEDURE DATAMINDS.BI_MIGRACION_ALQUILER
AS
BEGIN
    SET NOCOUNT ON;
    INSERT INTO DATAMINDS.BI_ALQUILER (cantidad_alquileres, tiempo_id, rango_etario_id, ubicacion_id)
    SELECT 
		COUNT(DISTINCT alq.codigo_alquiler) as cantidad_alquileres,
		t.id as tiempo,
		rango_etario.id as rango_etario_id, 
		ubi.id as ubicacion_id
	FROM DATAMINDS.ALQUILER alq
		INNER JOIN DATAMINDS.INQUILINO i on i.id = alq.inquilino_id
		INNER JOIN DATAMINDS.PERSONA p on p.id = i.persona_id
		INNER JOIN DATAMINDS.BI_RANGO_ETARIO rango_etario on rango_etario.id = DATAMINDS.fx_rango_etario(p.fecha_nacimiento)
		INNER JOIN DATAMINDS.BI_TIEMPO t on t.anio = YEAR(alq.fecha_inicio) and t.cuatrimestre = DATAMINDS.fx_cuatrimestre(MONTH(alq.fecha_inicio)) and t.mes = MONTH(alq.fecha_inicio)
		INNER JOIN DATAMINDS.ANUNCIO anuncio on anuncio.codigo_anuncio = alq.anuncio_id
		INNER JOIN DATAMINDS.INMUEBLE inmueble on anuncio.inmueble_id = inmueble.codigo_inmueble
		INNER JOIN DATAMINDS.DIRECCION dir on dir.id = inmueble.direccion_id
		INNER JOIN DATAMINDS.BI_UBICACION ubi on ubi.barrio_id = dir.barrio_id
	GROUP BY t.id, rango_etario.id, ubi.id
END
GO


CREATE FUNCTION DATAMINDS.fx_pago_a_tiempo (@vencimiento datetime, @pago datetime)
returns decimal(1,0)
begin

	declare @bool decimal(1,0) =
	case when @vencimiento > @pago then 1
	else 0 end

	return @bool
end
go



CREATE PROCEDURE DATAMINDS.BI_MIGRACION_PAGO_ALQUILER
AS
BEGIN
	SET NOCOUNT ON;
	INSERT INTO DATAMINDS.BI_PAGO_ALQUILER (tiempo_id, cantidad_pagos, porcentaje_incumplimiento, porcentaje_aumento)
	SELECT 
		t.id as tiempo, 
		COUNT(*) as cantidad_pagos, 
		100 - AVG(DATAMINDS.fx_pago_a_tiempo(pago.fecha_vencimiento, pago.fecha_pago)) * 100 as porcentaje_incumplimiento ,
		SUM(isnull((pago.importe - pago2.importe)/pago2.importe,0) * 100 ) / COUNT(*) as porcentaje_incremento
	FROM DATAMINDS.PAGO_ALQUILER pago
		INNER JOIN DATAMINDS.BI_TIEMPO t on t.anio = YEAR(pago.fecha_pago) and t.cuatrimestre = DATAMINDS.fx_cuatrimestre(MONTH(pago.fecha_pago)) and t.mes = MONTH(pago.fecha_pago)
		LEFT JOIN DATAMINDS.PAGO_ALQUILER pago2 ON pago.alquiler_id = pago2.alquiler_id AND YEAR(pago.fecha_pago) * 12 + MONTH(pago.fecha_pago) - 1 = YEAR(pago2.fecha_pago) * 12 + MONTH(pago2.fecha_pago)
	GROUP BY t.id
	
END
GO


-- EJECUCION DE PROCEDURES
EXEC DATAMINDS.BI_MIGRACION_ANUNCIO;
EXEC DATAMINDS.BI_MIGRACION_VENTA;
EXEC DATAMINDS.BI_MIGRACION_ALQUILER;
EXEC DATAMINDS.BI_MIGRACION_PAGO_ALQUILER;
GO



--VISTAS
--Vista 1
CREATE VIEW DATAMINDS.vw_duracion_promedio_dias
AS
SELECT 
	SUM(cant_anuncios * duracion_promedio) / SUM(cant_anuncios) as promedio_duracion,
	tiempo.anio as año,
	tiempo.cuatrimestre as cuatrimestre,
	tipo.descripcion as tipo_operacion,
	ubi.nombre_barrio as barrio,
	amb.descripcion as cantidad_ambientas
FROM DATAMINDS.BI_ANUNCIO anuncio
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo on tiempo.id = anuncio.tiempo_id
	INNER JOIN DATAMINDS.BI_TIPO_OPERACION tipo on tipo.id = anuncio.tipo_operacion_id
	INNER JOIN DATAMINDS.BI_UBICACION ubi on ubi.id = anuncio.ubicacion_id
	INNER JOIN DATAMINDS.BI_TIPO_AMBIENTE amb on amb.id = anuncio.cantidad_ambiente_id
GROUP BY tiempo.anio, tiempo.cuatrimestre, tipo.id, tipo.descripcion, ubi.nombre_barrio, amb.id, amb.descripcion
go


--Vista 2
CREATE VIEW DATAMINDS.vw_precio_promedio_anuncio_inmueble
AS
SELECT 
	tiempo.anio as año,
	tiempo.cuatrimestre as cuatrimestre,
	op.descripcion as tipo_operacion,
	inm.descripcion as tipo_inmueble,
	rango.descripcion as rango_m2,
	SUM(a.precio_promedio * a.cant_anuncios) / SUM(a.cant_anuncios) as precio_promedio,
	moneda.nombre as moneda
FROM DATAMINDS.BI_ANUNCIO a
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo on tiempo.id = a.tiempo_id
	INNER JOIN DATAMINDS.BI_TIPO_OPERACION op on op.id = a.tipo_operacion_id
	INNER JOIN DATAMINDS.BI_TIPO_INMUEBLE inm on inm.id = a.tipo_inmueble_id
	INNER JOIN DATAMINDS.BI_RANGO_M2 rango on rango.id = a.rango_m2_id
	INNER JOIN DATAMINDS.BI_MONEDA moneda on moneda.id = a.moneda_id
GROUP BY tiempo.anio, tiempo.cuatrimestre, op.id, op.descripcion, inm.id, inm.descripcion, rango.id, rango.descripcion, moneda.id, moneda.nombre
GO

--VISTA 3 (PARA CONSTRUIR EL TOP)
CREATE VIEW DATAMINDS.vw_barrios_por_rango
AS
	SELECT 
			tiempo.anio,
			tiempo.cuatrimestre,
			ubicacion.nombre_barrio,
			ubicacion.barrio_id,
			rango.descripcion as rango_etario,
			SUM(alq.cantidad_alquileres) as total_alquileres,
			ROW_NUMBER() OVER (PARTITION BY tiempo.anio, tiempo.cuatrimestre, rango.id ORDER BY SUM(alq.cantidad_alquileres) DESC) as rn
	FROM DATAMINDS.BI_UBICACION ubicacion
	INNER JOIN DATAMINDS.BI_ALQUILER alq ON alq.ubicacion_id = ubicacion.id
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo on tiempo.id = alq.tiempo_id
	INNER JOIN DATAMINDS.BI_RANGO_ETARIO rango on rango.id = alq.rango_etario_id
	GROUP BY tiempo.anio, tiempo.cuatrimestre, ubicacion.nombre_barrio, ubicacion.barrio_id, rango.id, rango.descripcion
GO
--VISTA 3 (SOLO EL TOP 5)
CREATE VIEW DATAMINDS.vw_barrios_top_5
as
	SELECT anio, cuatrimestre, nombre_barrio, barrio_id, rango_etario, rn
	FROM DATAMINDS.vw_barrios_por_rango as ranked
	WHERE rn <= 5
go

-- Vista 4
CREATE VIEW DATAMINDS.vw_porcentaje_incumplimiento
as
SELECT tiempo.anio, tiempo.mes, SUM(pago.porcentaje_incumplimiento * pago.cantidad_pagos) / SUM(pago.cantidad_pagos) as porcentaje_incumplimiento
	  FROM DATAMINDS.BI_PAGO_ALQUILER pago
	  INNER JOIN DATAMINDS.BI_TIEMPO tiempo ON pago.tiempo_id = tiempo.id
	  GROUP BY tiempo.anio, tiempo.mes
go

--VISTA 5
CREATE VIEW DATAMINDS.vw_porcentaje_incremento
AS
	SELECT tiempo.anio as año, tiempo.mes as mes, AVG(pago.porcentaje_aumento) as porcentaje_incremento
	FROM DATAMINDS.BI_PAGO_ALQUILER pago
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo on tiempo.id = pago.tiempo_id
group by tiempo.anio, tiempo.mes
go


-- VISTA 6
CREATE VIEW DATAMINDS.vw_precio_promedio_m2_venta_inmuebles
AS
SELECT 
    tiempo.anio as anio,
	tiempo.cuatrimestre as cuatrimestre,
	tipo_inm.descripcion as tipo_inmueble,
    ubi.nombre_localidad as localidad,
	SUM(v.cantidad_ventas * v.precio_m2_promedio) / SUM(v.cantidad_ventas) as precio_m2_promedio
FROM DATAMINDS.BI_VENTA v
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo ON tiempo.id = v.tiempo_id
    INNER JOIN DATAMINDS.BI_TIPO_INMUEBLE tipo_inm ON v.tipo_inmueble_id = tipo_inm.id
    INNER JOIN DATAMINDS.BI_UBICACION ubi ON ubi.id = v.ubicacion_id
GROUP BY tiempo.anio, tiempo.cuatrimestre, tipo_inm.descripcion, ubi.nombre_localidad
GO

--VISTA 7
CREATE VIEW DATAMINDS.vw_valor_promedio_comision
AS
SELECT 
tiempo.anio as anio,
tiempo.cuatrimestre as cuatrimestre,
tipo.descripcion as tipo,
anuncio.sucursal_id as sucursal,
SUM(anuncio.cant_anuncios * anuncio.promedio_comision) / SUM(anuncio.cant_anuncios) as promedio_comision
FROM DATAMINDS.BI_ANUNCIO anuncio
INNER JOIN DATAMINDS.BI_TIPO_OPERACION tipo on tipo.id = anuncio.tipo_operacion_id
INNER JOIN DATAMINDS.BI_TIEMPO tiempo ON tiempo.id = anuncio.tiempo_id
where anuncio.estado_id != 2
group by tiempo.anio, tiempo.cuatrimestre, tipo.descripcion, anuncio.sucursal_id
GO

-- VISTA 8
CREATE VIEW DATAMINDS.vw_porcentaje_operaciones_concretadas
AS
SELECT 
	tiempo.anio as anio,
	s.nombre as sucursal,
	r.descripcion as rango_etario,
	ROUND(SUM(CASE WHEN anuncio.estado_id != 2 THEN anuncio.cant_anuncios ELSE 0 END) * 100.0 / SUM(anuncio.cant_anuncios), 12) as porcentaje_concretadas
FROM DATAMINDS.BI_ANUNCIO anuncio
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo ON tiempo.id = anuncio.tiempo_id
	INNER JOIN DATAMINDS.BI_SUCURSAL s ON s.codigo_sucursal = anuncio.sucursal_id
	JOIN DATAMINDS.BI_RANGO_ETARIO r on r.id = anuncio.rango_etario_id
GROUP BY tiempo.anio, s.nombre, s.nombre, r.descripcion
GO


--VISTA 9
CREATE VIEW DATAMINDS.vw_monto_total_cierre_contratos
AS
SELECT
	tiempo.cuatrimestre as cuatrimestre,
    s.nombre,
	m.nombre as moneda,
    tipo_op.descripcion as tipo_operacion,
    SUM(anuncio.monto_total) as monto_total_cierre
FROM DATAMINDS.BI_ANUNCIO anuncio
	INNER JOIN DATAMINDS.BI_TIEMPO tiempo ON tiempo.id = anuncio.tiempo_id
	INNER JOIN DATAMINDS.BI_SUCURSAL s ON s.codigo_sucursal = anuncio.sucursal_id
    JOIN DATAMINDS.BI_TIPO_OPERACION tipo_op ON anuncio.tipo_operacion_id = tipo_op.id
    JOIN DATAMINDS.BI_MONEDA m ON anuncio.moneda_id = m.id
	JOIN DATAMINDS.BI_ESTADO_ANUNCIO estado ON estado.id = anuncio.estado_id
WHERE
    estado.id != 2 
GROUP BY
	tiempo.cuatrimestre,
    s.nombre,
	m.nombre,
    tipo_op.descripcion
GO