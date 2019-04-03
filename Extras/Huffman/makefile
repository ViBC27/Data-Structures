main: main.o compress.o descompress.o huff.o hash.o heap.o info.o shared.o
	gcc main.o compress.o descompress.o huff.o hash.o heap.o info.o shared.o -o VERDZIP

main.o: main.c
	gcc -c main.c

compress.o: Headers/compress.c Headers/compress.h
	gcc -c Headers/compress.c

descompress.o: Headers/descompress.c Headers/descompress.h
	gcc -c Headers/descompress.c

huff.o: Headers/huff.c Headers/huff.h
	gcc -c Headers/huff.c

hash.o: Headers/hash.c Headers/hash.h
	gcc -c Headers/hash.c

heap.o: Headers/heap.c Headers/heap.h
	gcc -c Headers/heap.c

info.o: Headers/info.c Headers/info.h
	gcc -c Headers/info.c

shared.o: Headers/shared.c Headers/shared.h
	gcc -c Headers/shared.c




