## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = gestion_des_equipements_agricoles

gestion_des_equipements_agricoles_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	equipements.c equipements.h

gestion_des_equipements_agricoles_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

