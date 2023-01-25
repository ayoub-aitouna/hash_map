src = linked_list/ft_lstadd_back.c  linked_list/ft_lstclear.c linked_list/ft_lstiter.c \
	linked_list/ft_lstsize.c linked_list/ft_lstadd_front.c linked_list/ft_lstlast.c \
	linked_list/ft_lstnew.c hash.c map.c

obj = $(src:.c=.o)

all: $(obj)
	gcc $(obj) -o map
clean:
	rm $(obj)