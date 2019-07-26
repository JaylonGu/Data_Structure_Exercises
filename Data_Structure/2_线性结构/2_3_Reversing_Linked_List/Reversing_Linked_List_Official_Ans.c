/* 用数组下标表示链表内存地址 */

Ptr Reverse(Ptr head, int K){
    int cnt=1;
    new=head->next;
    old=new->next;

    while(cnt<K){
        tmp=old->next;
        old->next=new;
        new=old;old=tmp;
        cnt++;
    }
    head->next->next=old;

    return new;
}