#to ignore any comment or command output precede it by @
#but must be done in rule line
CC=gcc
LFLAGS=-Wall -Werror 
ARRAYFILES=selection_sort_array.c main_array.c swap_element_arr.c display_arr.c 
OBJARRFILES=$(ARRAYFILES:%.c=%.o) #substitutional reference



ARRTARGET=arr
$(ARRTARGET):$(OBJARRFILES)
	@#$^ means names of all prerequisitic.if Put @ then command output is ignored
	$(CC) $(LFLAGS) $^ -o  $(ARRTARGET)



%.o : %.c
	@#here $< means name of first prerequistic and $@ means first target 
	@$(CC) -g -c $< -o $@  


cleanarr:
	@#to remove the .o and target file
	rm -rf *.o $(ARRTARGET)


