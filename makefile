all:
	gcc -Wall -ansi -pedantic src/pwl.c src/linkedlist.c src/stats.c -o pwl

deploy:
	mkdir ../file-stats-javier-c
	cp -r . ../file-stats-javier-c
	rm -rf ../file-stats-javier-c/.git
	scp -r ../file-stats-javier-c javierc@moons.cs.unm.edu:/nfs/student/j/javierc/Documents
	rm -rf ../file-stats-javier-c

clean:
	rm *o pwl

