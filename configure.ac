AC_INIT([oglp], [0.0], [daniel@ekpyron.org])
AM_INIT_AUTOMAKE([foreign -Wall -Werror])
LT_INIT
CXXFLAGS="$CXXFLAGS -std=c++0x"
AC_PROG_CXX
AM_PROG_AR
AC_LANG([C++])
AC_LANG_CPLUSPLUS

AC_ARG_WITH([glm],
	[AS_HELP_STRING([--with-glm=DIR],
			[location of the glm headers])],
	[CPPFLAGS="-I$withval ${CPPFLAGS}"])
AC_CHECK_HEADERS(glm/glm.hpp, [], AC_MSG_FAILURE([glm headers missing]))

DX_INIT_DOXYGEN($PACKAGE_NAME, doxygen.cfg)

AC_CONFIG_FILES([Makefile src/Makefile oglp.pc])
AC_OUTPUT
