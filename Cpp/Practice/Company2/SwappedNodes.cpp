void calc(Node **a,Node **b,Node *prev,Node *root)
{
    if(!root)
        return;
    calc(a,,prev,root->left);
    if(prev && prev->data > root->data)
    {
        if(*a==NULL)
        {
            *a = prev;
        }
        *b = root;
    }
    prev = root;
    calc(a,b,prev,root->right)
}
void findSwappedNode(Node *root)
{
    Node *a=NULL,*b=NULL;
    Node *prev=NULL;
    calc(&a,&b,prev,root);
    swap(&(a->data),&(b->data));
}


