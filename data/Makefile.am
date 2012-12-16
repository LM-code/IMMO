SUBDIRS = icons

desktopdir = $(datadir)/applications
desktop_in_files = immo.desktop.in
desktop_DATA = $(desktop_in_files:.desktop.in=.desktop)

UPDATE_DESKTOP = update-desktop-database $(datadir)/applications || :

install-data-hook: 
	$(UPDATE_DESKTOP)
uninstall-hook: 
	$(UPDATE_DESKTOP)
