#définit les informations sur le programme
AC_PREREQ(2.67)

# Définit les informations sur le programme
AC_INIT([immo],
        [0.8.2],
        [webmaster@super-annonce.fr])

#initialisation d'automake pour le programme
AM_INIT_AUTOMAKE(AC_PACKAGE_NAME, AC_PACKAGE_VERSION)
AM_CONFIG_HEADER(config.h)

#Recherche des compilateurs
AC_PROG_CC
AM_PROG_CC_C_O

# On cherche si pkg-config est présent sur l'ordi
AC_CHECK_PROGS([PKGCONFIG], [pkg-config], [:])
if test "$PKGCONFIG" = :; then
    AC_MSG_ERROR([Package 'pkg-config' not found])
fi

# On cherche les dépendances
PKG_CHECK_MODULES(GTK, gtk+-2.0 >= 2.14)
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

#fichier Makefile à générer
AC_CONFIG_FILES([
    Makefile 
    src/Makefile 
    data/Makefile
    data/immo.desktop
    data/icons/Makefile
    data/icons/hicolor/Makefile
    data/icons/hicolor/48x48/Makefile
    data/icons/hicolor/48x48/apps/Makefile
    data/icons/hicolor/scalable/Makefile
    data/icons/hicolor/scalable/apps/Makefile
             ])

#générer les Makefiles
AC_OUTPUT
