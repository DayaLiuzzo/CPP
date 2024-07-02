
NAME = Brainzzz

S = src/
O = obj/
I = inc/
D = dep/


CC = c++

LDFLAGS = -Wall -Werror -Wextra -std=c++98

CFLAGS	+=	-I$I 

SRCS	=	$Smain.cpp

RM	=	/bin/rm -rf

OBJS =	$(SRCS:$S%=$O%.o)

DEP =	$(SRCS:$S%=$D%.d)

all : $(NAME)

$O:
	@mkdir -p $@

$(OBJS): | $O

$(OBJS): $O%.o: $S%
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$D:
	@mkdir -p $@

$(DEP): | $D

$(DEP): $D%.d: $S%
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$O$*.o $@" $<


$(NAME): $(OBJS) $(DEP)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)


cleanobjs:
	$(RM) $(OBJS) $(O)

cleandep: 
	$(RM) $(DEP) $(D)

clean: cleanobjs cleandep


fclean : clean 
	$(RM) $(NAME)

re: fclean all

include $(DEP)

.PHONY: all clean fclean re debug 