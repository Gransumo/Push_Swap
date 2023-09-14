#ifdef LIST_H
#define LIST_H

void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstclear(t_stack **lst, void (*del)(void *));
void	ft_lstdelone(t_stack *lst, void (*del)(void*));
void	ft_lstiter(t_stack *lst, void (*f)(void *));
t_stack	*ft_lstlast(t_stack *lst);
t_stack	*ft_lstmap(t_stack *lst, void *(*f)(void *), void (*del)(void *));
t_stack	*ft_lstnew(void *content);
int		ft_lstsize(t_stack *lst);

#endif