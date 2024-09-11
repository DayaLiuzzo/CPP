NAME = btc

S = src/
O = obj/
I = inc/
D = dep/

CC = c++

LDFLAGS = -Wall -Werror -Wextra -std=c++98

CFLAGS	+=	-I$(I) 

SRCS	=	$(S)main.cpp \
			$(S)BitcoinExchange.cpp \
			$(S)checks.cpp\
			$(S)utils.cpp

RM	=	/bin/rm -rf

OBJS =	$(SRCS:$(S)%=$(O)%.o)

DEP =	$(SRCS:$(S)%=$(D)%.d)

all : $(NAME)

$(O):
	@mkdir -p $(O)

$(OBJS): | $(O)

$(OBJS): $(O)%.o: $(S)%
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(LDFLAGS) -c $< -o $@

$(D):
	@mkdir -p $(D)

$(DEP): | $(D)

$(DEP): $(D)%.d: $(S)%
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -MM -MF $@ -MT "$(O)$*.o $@" $<

$(NAME): $(OBJS) $(DEP)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

cleanobjs:
	@$(RM) $(OBJS) $(O)

cleandep: 
	@$(RM) $(DEP) $(D)

clean: cleanobjs cleandep

fclean : clean 
	@$(RM) $(NAME)

re: fclean all

include $(DEP)

.PHONY: all clean fclean re

