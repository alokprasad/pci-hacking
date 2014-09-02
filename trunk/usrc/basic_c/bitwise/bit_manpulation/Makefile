# -L -> gcc option to include the library path
# -l -> gcc option to specify link the library
# -I -> gcc option to include the header file path

exec:main.o libbit.a
	gcc -o $@ $< -L . -l bit 

# $@ -> name of the target
# $^ -> include all pre-requisite
# $< -> include the first pre-requisite

# ar -> archive command
# rcs : r -> insert the file member to archive
# 	c -> creating an archive 
# 	s -> ranlib for indexing  

libbit.a:toggle_pos.o set_pos.o reset_pos.o set_pos_left_till.o set_pos_left.o 
	ar rcs $@ $^

# pattern matching, matches .c file and builds the respective .o file
# Here the main.c is compiled to main.o
%.o:%.c
	gcc -c $^ -Wall

clean:
	rm -rf exec *.o a.out

distclean:
	rm -rf *.o exec *.a *.so a.out
