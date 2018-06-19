all: testapp.c 
	g++ -g -o testapp testapp.c -lcurl

clean: 
	rm testapp

install: testapp
	install -m 0755 testapp /usr/local/sbin
	install -m 0644 testapp.service /usr/lib/systemd/system/
