/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:09:27 by jjauzion          #+#    #+#             */
/*   Updated: 2018/05/28 12:05:17 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <wchar.h>
# include <locale.h>
# include "get_next_line.h"
# include <limits.h>
# include <stdint.h>
# include "ft_printf.h"

# define ABS(Value) (Value < 0) ? -Value : Value
# define WRONG_UTF8(c) ((c >= 0xD800 && c <= 0xDFFF) || c > 0x10FFFF || c < 0)

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *str, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr
(const char *str, const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
intmax_t			ft_atoim(const char *str);
void				ft_putchar(char c);
void				ft_putnbr(int n);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_ishexa(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isnumber(char *str);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
int					ft_str_itercheck(char *s, int (*f)(int));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strremap(char *s, char (*f)(char));
char				*ft_strremapi(char *s, int (*f)(int));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_imtoa(intmax_t n);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoa_base(uintmax_t n, uintmax_t base);
void				ft_putstr(const char *s);
void				ft_putendl(const char *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(const char *s, int fd);
void				ft_putendl_fd(const char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_print_mem(void *adr, size_t length);

int					ft_tab_mean(int *tab, int nb_elm);
int					ft_tab_min(int *tab, int nb_elm);
int					ft_tab_max(int *tab, int nb_elm);
int					ft_tab_itercheck(int *tab, int size, int (*f)(int));

wchar_t				*ft_wstrcnew(size_t size, wchar_t c);
int					ft_putwchar(wchar_t c);
int					ft_getnbofutf8byte(wchar_t c);
char				*ft_uni2utf8(wchar_t c);
char				*ft_wstr2str(wchar_t *src, int size);
void				ft_putwstr(wchar_t *str);
size_t				ft_wstrlen(wchar_t const *s);
wchar_t				*ft_wstrsub
(wchar_t const *s, unsigned int start, size_t len);
wchar_t				*ft_wstrdup(wchar_t const *s1);

char				*ft_strext(char **s, size_t len, size_t size);
char				*ft_strrev(char *str);
int					ft_islower(int c);
int					ft_isupper(int c);
char				*ft_strcapitalize(char *str);
char				*ft_strcnew(size_t size, char c);
int					ft_sqrt(int nb, char *option);
void				*ft_realloc(void **src, size_t len, size_t size);
long long int		ft_power(int nbr, int power);
char				*ft_str_del_char(char **str, char c);
int					ft_count_cinstr(const char *str, char c);
int					ft_max(int a, int b);
int					ft_min(int a, int b);

#endif
