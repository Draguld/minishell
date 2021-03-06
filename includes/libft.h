/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: true <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 13:31:15 by true              #+#    #+#             */
/*   Updated: 2016/02/20 14:17:21 by true             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define T_BLACK "\033[1;30"
# define T_DARK_BLACK "\033[0;30"
# define T_RED "\033[1;31m"
# define T_DARK_RED "\033[0;31m"
# define T_GREEN "\033[1;32m"
# define T_DARK_GREEN "\033[0;32m"
# define T_YELLOW "\033[1;33m"
# define T_DARK_YELLOW "\033[0;33m"
# define T_BLUE "\033[1;34m"
# define T_DARK_BLUE "\033[0;34m"
# define T_PURPLE "\033[1;35m"
# define T_DARK_PURPLE "\033[0;35m"
# define T_CYAN "\033[1;36m"
# define T_DARK_CYAN "\033[0;36m"
# define T_GREY "\033[1;37m"
# define T_DARK_GREY "\033[0;38m"

# define CLEAN_COLOR "\033[0;00m"

# define ENDL ft_endl()

//--MINISHELL--//

char	**ft_arraydup(char **array);
char	*ft_strapp(char *s, char c);
char	*ft_strconcat(const char *s1, const char *s2);
int		ft_getaccess(char **path, char *cmd);
char	*ft_getstrenv(char **environ, char *str);

//-------------//

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(const void *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_atoi(char *str);
void				ft_bzero(void *s, size_t n);
void				ft_endl(void);
int					ft_intlen(int nb);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
int					ft_pow(int nb, int pow);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char *str);
void				ft_putendl_fd(char *str, int fd);
void				ft_putnbr(int nbr);
void				ft_putnbr_fd(int nbr, int fd);
void				ft_putstr(char *str);
void				ft_putstr_fd(char *str, int fd);
void				ft_puttab_2s(char **tab);
void				ft_puterror(char *str);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f) (char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dest, const char *src, size_t n);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *hay, const char *nee, size_t len);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(const char *s, char c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
