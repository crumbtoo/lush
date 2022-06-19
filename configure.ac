AC_INIT([lush], [20.06.19-0], [hex7c@sdf.org])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_PROG_CC
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile])

AC_CHECK_LIB([lua5.4], [luaL_newstate])
AC_CHECK_HEADERS([lua.h lualib.h lauxlib.h])

AC_OUTPUT
