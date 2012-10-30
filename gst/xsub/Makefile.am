# Note: plugindir is set in configure

##############################################################################
# TODO: change libgstplugin.la to something else, e.g. libmysomething.la     #
##############################################################################
plugin_LTLIBRARIES = libgstxsub.la

##############################################################################
# TODO: for the next set of variables, name the prefix if you named the .la, #
#  e.g. libmysomething.la => libmysomething_la_SOURCES                       #
#                            libmysomething_la_CFLAGS                        #
#                            libmysomething_la_LIBADD                        #
#                            libmysomething_la_LDFLAGS                       #
##############################################################################

# sources used to compile this plug-in
libgstxsub_la_SOURCES = gstxsub.c gstxsub.h xsub.c xsub.h

# compiler and linker flags used to compile this plugin, set in configure.ac
libgstxsub_la_CFLAGS = $(GST_CFLAGS)
libgstxsub_la_LIBADD = \
    $(GST_PLUGINS_BASE_LIBS) -lgsttag-$(GST_MAJORMINOR) \
    $(GST_BASE_LIBS) $(GST_LIBS)
libgstxsub_la_LDFLAGS = $(GST_PLUGIN_LDFLAGS)
libgstxsub_la_LIBTOOLFLAGS = --tag=disable-static

# headers we need but don't want installed
# noinst_HEADERS = gstplugin.h
