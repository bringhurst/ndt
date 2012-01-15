#########################################################################
#									#
#			   Copyright (C)  2002				#
#	     			Internet2				#
#			   All Rights Reserved				#
#									#
#########################################################################
#
#	File:		Makefile.am
#
#	Author:		Rich Carlson
#			Internet2
#
#	Date:		Fri Feb 27 13:37:24 CST 2004
#
#	Description:	toplevel build for bwctl
#

if HAVE_GCJ
SUBDIRS = @TOP_BUILD_DIRS@ src Admin Applet conf doc janalyze
else
SUBDIRS = @TOP_BUILD_DIRS@ src conf doc
endif

EXTRA_DIST = admin_description.html admin.html \
	tcpbw100.template copyright.html web100variables.html \
	web100_variables COPYRIGHT \
	DISCUSSION-LIST FILES Readme-fakewww Readme-web100srv \
	contrib/README contrib/loadmap.intro contrib/loadmap.js \
	contrib/loadmap.txt contrib/Tcpbw1001.java \
	tfw/client.py tfw/communication.py tfw/hosts.py tfw/network.py \
	tfw/Readme tfw/scenarios.py tfw/server.py tfw/traffics.py tfw/widgets.py

ndtdir = $(prefix)/ndt
ndt_DATA = admin_description.html admin.html \
	   copyright.html web100variables.html web100_variables

sdatadir:
	test -z "$(ndtdir)/serverdata" || $(mkdir_p) "$(ndtdir)/serverdata"

install: sdatadir install-recursive

nobase_include_HEADERS = bwlib/bwlib.h
EXTRA_DIST = bootstrap

MAINTAINERCLEANFILES = \
    aclocal.m4 config.guess config.xml Makefile.in \
    config.h.in config.sub configure install-sh    \
    ltconfig ltmain.sh missing mkinstalldirs       \
    stamp-h.in config.log

distclean-local:
	-(cd $(top_srcdir) && rm -rf autom4te*.cache autoscan.*)
	-(cd $(top_srcdir) && rm -rf $(PACKAGE)-*)
   
mrproper: distclean-local clean
	-(cd $(top_srcdir) && rm -rf autom4te.cache config.h config.log)
	-(cd $(top_srcdir) && rm -rf config.status libtool stamp-h1)
	-(cd $(top_srcdir) && rm -rf auxdir)
	-(cd $(top_srcdir) && rm -f configure configure.ac~)
	-(cd $(top_srcdir) && rm -f config.h.in config.h.in~)
	-(cd $(top_srcdir)/m4 && rm -f libtool.m4 ltoptions.m4)
	-(cd $(top_srcdir)/m4 && rm -f ltsugar.m4 ltversion.m4)
	-(cd $(top_srcdir)/m4 && rm -f lt~obsolete.m4)
	-find $(top_srcdir)/ -name "Makefile" -exec rm {} \;
	-find $(top_srcdir)/ -name "Makefile.in" -exec rm {} \;
	-find $(top_srcdir)/ -name ".dirstamp" -exec rm {} \;
	-find $(top_srcdir) -depth -name ".deps" -exec rm -rf {} \;
