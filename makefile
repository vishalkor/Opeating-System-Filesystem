myfs: f0 f1 f2 f3 f4 f5 f6 f7 f8 f9 f10 f11 f12 f13 f14 f15 f16 f17 
	gcc shell.c initialization.o openf.o createf.o readf.o writef.o closef.o unmount.o mkdirf.o chdirf.o rmdirf.o rmf.o lsf.o namei.o ialloc.o alloc.o ifree.o free.o mount.o -o myfs

f0:	
	gcc -c initialization.c

f1:
	gcc -c openf.c

f2:
	gcc -c createf.c

f3:
	gcc -c readf.c

f4:
	gcc -c writef.c

f5:
	gcc -c closef.c

f6:
	gcc -c unmount.c

f7:
	gcc -c mkdirf.c

f8: 
	gcc -c chdirf.c

f9:
	gcc -c rmdirf.c

f10:
	gcc -c rmf.c

f11:
	gcc -c lsf.c

f12:
	gcc -c namei.c

f13: 
	gcc -c ialloc.c

f14:
	gcc -c alloc.c

f15:
	gcc -c ifree.c

f16: 
	gcc -c free.c 

f17:
	gcc -c mount.c