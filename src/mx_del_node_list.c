#include "ush.h"

void mx_del_node_list(t_list **list, t_process **d_p) {
    t_list *cur = *list;
    t_list *tmp = NULL;
    t_process *f_p = (t_process *)cur->data;

    if (f_p->pid == (*d_p)->pid) {
        mx_del_process(d_p);
        tmp = *list;
        *list = (*list)->next;
        // free(tmp->data);
        free(tmp);
        return;
    }
    while (cur) {
        f_p = (t_process *)cur->next->data;
        if (f_p->pid == (*d_p)->pid) {
            break;
        }
        cur = cur->next;
    }
    tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    mx_del_process(d_p);
}
